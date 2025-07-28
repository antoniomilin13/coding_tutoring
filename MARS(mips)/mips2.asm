    .data
filename:   .asciiz "/D:/programiranjeINST/MARS(mips)/rijecnik.txt"
buffer:     .space 240
pal:        .asciiz "PALINDROM"
not_pal:    .asciiz "not"

    .text
        .globl main
main:
        li $v0, 13              # open file
        la $a0, filename        # load filename
        li $a1, 0               # open file for reading
        li $a2, 0               # mode is ignored
        syscall
        move $s0, $v0           # file descriptor cuvamo u $s0

        # - allocating memory for the buffer
        li $v0, 9               # 9 -> sbrk: alokacija memorije
        li $a0, 512000          # allocating 512000 bytes of memory
        syscall
        move $s1, $v0           # u $s1 cuvamo adresu pocetka alocirane memorije

        # - read the file
        li $v0, 14
        move $a0, $s0           # file descriptor
        move $a1, $s1           # a1 adresa buffera
        li $a2, 512000          # reading 500000 characters
        syscall


        # - closing the file
        li $v0, 16              # closing the file and file descriptor(below code)
        move $a0, $s0
        syscall


        li $t1, 10              # \n
        li $s3, 0
        move $s2, $s1           # address of beginning of allocated memory
        lb $t8, ($s2)
        #j petlja

first_letter:
        move $t9, $s2
petlja:
        lb $t8, ($s2)
        beqz $t8, kraj          # detecting end of file

        # displaying each letter
        #li $v0, 11
        #move $a0, $t8
        #syscall

        addi $s3, $s3, 1

        addi $s2, $s2, 1
        bne $t8, 13, petlja

        sub $s3, $s3, 2
        move $s4, $s2
        sub $s4, $s4, 2

        #li $v0, 1
        #move $a0, $s3
        #syscall



    # $s3 -> duljina rijeci
    # $t9 -> pocetak rijeci ( lijevo slovo)
    # $s4 -> zadnje slovo { desno slovo)
        move $s7, $t9
        move $s6, $s3
        move $t5, $s3           # number of while loop
        srl $t5, $t5, 1         # shift left to get double the size

palindrom_check:
        lb $t6, ($t9)
        lb $t7, ($s4)
                addi $t9, $t9, 1
        sub $s4, $s4, 1
        sub $t5, $t5, 1
        beq $t5, -1, exit
        beq $t6, $t7, palindrom_check
exit:
        addi $t5, $t5, 1
        bnez $t5, not_palindrome
#        li $v0, 4
#        la $a0, pal
#        syscall


printing_pal:
        lb $t8, ($s7)
        beqz $t8, kraj          # detecting end of file

        # displaying each letter
        li $v0, 11
        move $a0, $t8
        syscall

        #addi $s3, $s3, 1

        addi $s7, $s7, 1
        bne $t8, 10, printing_pal

        # display \n
        li $v0, 11
        li $a0, 10
        syscall

        j continue



not_palindrome:
#        li $v0, 4
#        la $a0, not_pal
#        syscall

continue:

        move $s3, $zero
        # display \n
        #li $v0, 11
        #li $a0, 10
        #syscall

        j first_letter
kraj:
        li $v0, 10
        syscall

