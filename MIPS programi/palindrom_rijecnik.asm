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
    	
    	# - closing the file
    	li $v0, 16              # closing the file and file descriptor(below code)
   	move $a0, $s0
    	syscall
    
 
    	
    	li $t1, 13		# /r prije
    	li $t2, 10		# /n poslje
    	
    	move $t4, $s1		# kraj rijeci $t4

petlja:
    	lb $t8, ($t4)		# u $t8 stavljamo tekuce slovo $t4
    	beqz $t8, kraj		# detekcija kraja file-a
	# ispis jednog slova/znaka
	li $v0, 11		
	move $a0, $t8
	syscall  	
    	
    	addi $t4, $t4, 1
    	bne $t8, 13, petlja     # detekcija dvostrukog znaka novog reda
    	addi $t4, $t4, 1        # znamo i pocetak i kraj rijeci ($t3) - ($t4)
    	# ispis \n - newline
    	li $v0, 11
	li $a0, 10
	syscall  	
	
	j petlja
    	
   
kraj:  	
    	
    	li $v0, 10
    	syscall
