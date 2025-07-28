#Antonio Milin
#lab 6 - semester project phase one

    .data
str1:       .asciiz "\nAntonio Milin\n\nSemester project - phase one\n\n"
filename:   .asciiz "/usr/share/dict/cracklib-small"

    .text
    .globl main
main:
    # - preparing to print a string
    li $v0, 4
    la $a0, str1            # loading address of string
    syscall

    # - opening a file
    li $v0, 13              # open file
    la $a0, filename        # load filename
    li $a1, 0               # open file for reading
    syscall


    move $s1, $v0           # this is to return file descriptor in $s0

    # - allocating memory for the buffer
    li $v0, 9
    li $a0, 512000          # allocating 512000 bytes of memory
    syscall

    move $s0, $v0           # $s0 has the address (buffer) of beggining of the dictionary

    # - read the file
    li $v0, 14
    move $a0, $s1           # file descriptor
    move $a1, $s0	    # a1 adresa buffera
    li $a2, 500000          # reading 500000characters
    syscall



#----pointeri----

    #move $s2, $s0           # pointer 1(d)
    #move $s3, $s0           # pointer 2(p)

pocetak:
	li $t0, 0		# brojac -> koliko je dugacak string
    	li $t1, 10              # ASCII od \newline
    	la $t2, ($s0)          	# pozicija trenutnog slova
petlja:
	lb $t3, ($t2)           # pozicija trenutnog slova
    	addi $t2, $t2, 1
    	addi $t0, $t0, 1
    	bne $t1, $t3, petlja

   	subi $t0, $t0, 1	# oduzimanje 1 jer je 1 previse ubrojan
   	subi $t2, $t2, 2        # pokazivac na zadnje slovo DESNI = index_r
	la $t1, ($s0)          # pozicija trenutnog LIJEVOG slova = index_l

	move $t3, $t0           # broj prolazaka "while" petlje 
	srl $t3, $t3, 1         # je jednak polovici duljine rijeci

provjera_palindroma:

	lb $t4, ($t1)		# lijevo slovo
	lb $t5, ($t2)		# desno slovo
	addi $t1, $t1, 1        # povecavamo left index
	subi $t2, $t2, 1	# smanjujemo right index
	subi $t3, $t3, 1	# dekrementiramo brojac petlje
	beq $t3,-1, kraj	# prekid zbog postizanja maximalnog broja prolaza
	beq $t4, $t5, provjera_palindroma



top:
    lb $t1, ($s3)           # seting t1 as a pointer(*p)
    beq $t1, $0, palindrom  # go to label 'done' if its equal to 0
    li $t2, 10

newline_t:
    lb $t1, ($s3)                   # load character the address of $s3
    beq $t1, $t2, word_ending       # test if the word is ended(jump to word_ending if it is)
    addiu $s3, $s3, 1               # increment by one if its not
    j top

word_ending:
    sb $0, ($s3)            # at the end of a word is a null terminator

    addiu $s3, $s3, 1       # incrementing $s3 by one
    move $s2, $s3
    j newline_t

done:
    li $v0, 16              # closing the file and file descriptor(below code)
    move $a0, $s1
    syscall
    li $v0, 10              # exiting the program
    syscall

newline:
    li $v0, 11              # showing the character
    li $a0, 10              # ASCII value for newline
    syscall
    jr $ra                  # returning to the $ra address
                                                                        
