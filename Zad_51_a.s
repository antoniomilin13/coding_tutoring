# antonio milin    - # je komentar

ime:    - tekstualni pred procesor zamijenjuje u citavom tekstu(program) sve rici koje pocinju
          slovima "ime" sa nizom slova koji je definiran tekstom izmedu navodnika koi slijede
          u istom redu
                npr:    str1:   .asciiz "\n\n\nThe sum of "
        - predprocesor ce uvik zamijeniti string "str1" sa nizom slova "\n\n\nThe sum of "
        - labela predstavlja adresu u memoriji gdje pocinje navedeni string
        - .word podrazumijeva grupu od 32 ili 64 bita(4 ili 8 bajta zajedno)
        - .ascii   znači navedenu labelu zamijeni sa danim stringom, ali kojega nemoj zavrsiti sa terminatorom stringa ("\0")
        - .asciiz  znači navedenu labelu zamijeni sa danim stringom, ali zavrsi string sa terminatorom stringa ("\0")

        .data
sum_of:   .asciiz "\n\n\nThe sum of "
and:   .asciiz " and "
is:   .asciiz " is "
new_line:   .asciiz ".\n"

        .text
        # .text <address>  # daje nam mogucnost da u opcionalne adrese u memoriji smjestimo stringove koji sljede
        # njih ne moramo navesti (opcionalno) ali ako ih navedemo tada mozemo na tocno odredjenu adresu smjestiti
        # neki string


# li $v0, 4   LOAD IMMEDIATE VALUE:  4->$v0

main:
        li $t0,4        #napunimo registar $t0 sa vrijednoscu 4
        li $t1,10       #napunimo registar $t1 sa vrijednoscu 10
        addi $t2, $t0, $t1      # $t2 = $t0 + $t1

        li $v0, 4       #odredjuje funkciju print a string unutar syscall-a
        la $a0, sum_of  #load the address (labelu/label na eng)  of string
        syscal          # na ekranu ce biti ispisano "\n\n\nThe sum of "

        li $v0, 5       #odredjuje funkciju print a integer unutar syscall-a
        la $a0, $t0  #load the address (labelu/label na eng)  of integer
        syscal          # na ekranu ce biti ispisan prvi broj

        li $v0, 4
        la $a0, and
        syscal

        li $v0, 5
        la $a0, $t1
        syscal

        li $v0, 4
        la $a0, is
        syscal

        li $v0, 5
        la $a0, $t2
        syscal

        li $v0, 10
        syscall
