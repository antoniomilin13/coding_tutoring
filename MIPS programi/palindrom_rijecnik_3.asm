 	.data
filename:   	.asciiz "/D:/programiranjeINST/MARS(mips)/rijecnik.txt"
palin:		.asciiz "Palindrom!\n"
nije:		.asciiz "Nije palindrom!\n"
buffer:		.space 360

      	.text
    	.globl main
main:

	li $v0, 13              # open file
    	la $a0, filename        # load filename
    	li $a1, 0               # open file for reading
    	li $a2, 0		# mode is ignored
    	syscall
    	move $s0, $v0           # file descriptor cuvamo u $s0

    	# - allocating memory for the buffer
    	li $v0, 9		# 9 -> sbrk: alokacija memorije
    	li $a0, 512000          # allocating 512000 bytes of memory
    	syscall
    	move $s1, $v0           # u $s1 cuvamo adresu pocetka alocirane memorije 

    	# - read the file
    	li $v0, 14
    	move $a0, $s0           # file descriptor
    	move $a1, $s1    	# a1 adresa buffera
    	li $a2, 512000         	# reading 500000 characters
	syscall
    	
    	# - closing the file
    	li $v0, 16              # closing the file and file descriptor(below code)
   	move $a0, $s0
    	syscall

###########################

    	
    	li $t1, 13		# /r prije
    	li $t2, 10		# /n poslje
    	
    	move $t3, $s1		# pocetak rijeci
    	move $t4, $s1		# kraj rijeci $t4
	la $t9, buffer
petlja:
    	lb $t8, ($t4)		# u $t8 stavljamo tekuce slovo ($t4)
    	sb $t8, ($t9)           # tekuce slovo stavljamo u buffer za 1 rijec
    	addi $t9, $t9, 1        # inkrementiramo poziciju za sljedece slovo buffera
    	beqz $t8, kraj		# detekcija kraja file-a

    	addi $t4, $t4, 1        # inkremetiramo poziciju zadnjeg slova u file bufferu
    	bne $t8, $t1, petlja     # detekcija dvostrukog znaka novog reda
    	subi $t4, $t4, 2
    	move $t7, $t4		# desno slovo u bufferu za file
    	subi $t9, $t9, 1        # kraj rijeci ($t4)
    	sb $t2, ($t9)           # oznacavanje kraja rijeci u bufferu za 1 rijec
    	
	sub $t0, $t4, $t3
	addi $t0, $t0, 1        # $t0 je duljina rijeci
    	
    	# ovdi dolazi palindrom chec  	
    	la $s7, buffer          # pozicija trenutnog LIJEVOG slova = index_l
     	    	
     	move $t3, $t0           # broj prolazaka "while" petlje 
	srl $t3, $t3, 1         # je jednak polovici duljine rijeci

provjera_palindroma:
	
	#   anbna
	#   a b a
	#    n n
	#     b
	# petlju ponavljamo sve dok nam brojac petlje nije 0 i dok je lijevo slovo jednako desnom ( L = D )

	lb $t6, ($s7)		# lijevo slovo
	lb $t5, ($t4)		# desno slovo
	addi $s7, $s7, 1        # povecavamo left index
	subi $t4, $t4, 1	# smanjujemo right index
	subi $t3, $t3, 1	# dekrementiramo brojac petlje
	beq $t3,-1, kraj	# prekid zbog postizanja maximalnog broja prolaza
	beq $t6, $t5, provjera_palindroma  # usporedbu lijevog i desnog slova

	# - ako je $t3 ( brojac prolaza petlje ) jednak = 0, tada je petlja prosla sve parove i nije pekinuta zbog toga 
	# sto su svi parovi bili jednaki zakljucujemo da je nasa rijec palindrom
	# - ako je $t3 veci od nule onda svi parovi nisu jednaki i rijec nije palindrom
	
	addi $t3, $t3, 1
	bnez $t3, nije_palindrom
	li $v0, 4
    	la $a0, palin            # printing "is palindrome"
    	syscall
	
	la $t9, buffer		# za svaku novu rijec koristimo isti buffer	    	
    	j petlja                # prelazak na novu rijec
nije_palindrom:
	li $v0, 4
    	la $a0, nije           # printing "is not palindrome"
    	syscall
     	    	    	
    	la $t9, buffer		# za svaku NOVU RIJEC koristimo isti buffer	    	
    	j petlja                # prelazak na novu rijec
 
kraj:  		
    	li $v0, 10
    	syscall
