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
    	
    	li $v0, 10
    	syscall
