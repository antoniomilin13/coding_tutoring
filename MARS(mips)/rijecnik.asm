 	.data
filename:   	.asciiz "/D:/programiranjeINST/MARS(mips)/rijecnik.txt"
palin:		.asciiz "Palindrom!\n"
nije:		.asciiz "Nije palindrom!\n"
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
    	
    	
top:    	
    	# priprema za petlju - pronalazenje duljine upisane rijeci 	
    	li $t0, 0		# brojac -> koliko je dugacak string
    	li $t1, 10              # ASCII od \newline  0x0A
    	li $t6, 13		# ASCII od \r
    	li $t7, 0		# ASCII od \0
    	move $t2, $s1          	# pozicija trenutnog slova
    	lb $t3, ($t2)

petlja:
	lb $t3, ($t2)           # pozicija trenutnog slova	
    	addi $t2, $t2, 1
    	addi $t0, $t0, 1
    	beq $t3, $t7, nastavi
    	beq $t3, $t6, provjera_novi_red
    	j petlja
provjera_novi_red:
    	beq $t3, $t1, nastavi
nastavi:
	move $t9, $t3
   	subi $t0, $t0, 1	# oduzimanje 1 jer je 1 previse ubrojan
   	subi $t2, $t2, 2        # pokazivac na zadnje slovo DESNI = index_r
	move $t1, $s1          	# pozicija trenutnog LIJEVOG slova = index_l
		
#  01234
#  rijec                    index_l   index_r = len(rijeci)-1
#  0   4       4 = 5-1         0         4
#   1 3        3 = 5-2 = 3     1         3
#    2         2 = 5-3 = 2     2         2
#                              3         1
	move $t3, $t0           # broj prolazaka "while" petlje 
	srl $t3, $t3, 1         # je jednak polovici duljine rijeci

provjera_palindroma:
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
    	la $a0, palin           # printing "is palindrome"
    	syscall
    	
    	beq $t9, $t7, closeFile_exit
    	j prijelaz_newline
	
nije_palindrom:
	li $v0, 4
    	la $a0, nije           	# printing "is not palindrome"
    	syscall
    	beq $t9, $t7, closeFile_exit
    	
prijelaz_newline:

	li $v0, 11              # showing the character
    	li $a0, 10              # ASCII value for newline
    	syscall
    	j petlja                  	

closeFile_exit:
    	# - closing the file
    	li $v0, 16              # closing the file and file descriptor(below code)
   	move $a0, $s0
    	syscall
    	
    	li $v0, 10
    	syscall
