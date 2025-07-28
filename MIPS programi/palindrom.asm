
    .data
str1:		.asciiz "Upisite recenicu:  "
buffer:		.space 360
palin:		.asciiz "Palindrom!\n"
nije:		.asciiz "Nije palindrom!\n"

    	.text
    	.globl main
main:
	li $v0, 4
    	la $a0, str1            # loading address of string
    	syscall
    	
    	li $v0, 8
    	la $a0, buffer
    	li $a1, 100
    	syscall

# priprema za petlju - pronalazenje duljine upisane rijeci 	
    	li $t0, 0		# brojac -> koliko je dugacak string
    	li $t1, 10              # ASCII od \newline  0x0A
    	la $t2, buffer          # pozicija trenutnog slova
petlja:
	lb $t3, ($t2)           # pozicija trenutnog slova
    	addi $t2, $t2, 1
    	addi $t0, $t0, 1        # $t0 sadrzi duljinu rijeci
    	bne $t1, $t3, petlja
	
   	subi $t0, $t0, 1	# oduzimanje 1 jer je 1 previse ubrojan
   	subi $t2, $t2, 2        # pokazivac na zadnje slovo DESNI = index_r
	la $t1, buffer          # pozicija trenutnog LIJEVOG slova = index_l
		
#  01234
#  rijec                    index_l   index_r = len(rijeci)-1
#  0   4       4 = 5-1         0         4
#   1 3        3 = 5-2 = 3     1         3
#    2         2 = 5-3 = 2     2         2
#                              3         1
	move $t3, $t0           # broj prolazaka "while" petlje 
	srl $t3, $t3, 1         # je jednak polovici duljine rijeci

provjera_palindroma:
	
	#   anbna
	#   a b a
	#    n n
	#     b
	# petlju ponavljamo sve dok nam brojac petlje nije 0 i dok je lijevo slovo jednako desnom ( L = D )

	lb $t4, ($t1)		# lijevo slovo
	lb $t5, ($t2)		# desno slovo
	addi $t1, $t1, 1        # povecavamo left index
	subi $t2, $t2, 1	# smanjujemo right index
	subi $t3, $t3, 1	# dekrementiramo brojac petlje
	beq $t3,-1, kraj	# prekid zbog postizanja maximalnog broja prolaza
	beq $t4, $t5, provjera_palindroma  # usporedbu lijevog i desnog slova

kraj:
	# - ako je $t3 ( brojac prolaza petlje ) jednak = 0, tada je petlja prosla sve parove i nije pekinuta zbog toga 
	# sto su svi parovi bili jednaki zakljucujemo da je nasa rijec palindrom
	# - ako je $t3 veci od nule onda svi parovi nisu jednaki i rijec nije palindrom
	
	addi $t3, $t3, 1
	bnez $t3, nije_palindrom
	li $v0, 4
    	la $a0, palin            # printing "is palindrome"
    	syscall
    	
    	j izlazak
	
nije_palindrom:
	li $v0, 4
    	la $a0, nije           # printing "is not palindrome"
    	syscall

izlazak:
    	li $v0, 10
    	syscall
