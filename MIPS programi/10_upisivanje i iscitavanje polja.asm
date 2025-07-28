# Upis - ispis
	
	.data  		

#int array[1024];  	- deklaraciju(rezerviranje) polja bez unosenja inicijalnih vrijednosti u assembleru postizemo
			#  sa .space naredbom. Pri tome assembler pita operativni sistem da mu alocira sloboni prostor u duljini
			# navedenoj u .space naredbi i ta hexadec. adresa je ustvari pointer kojeg pozivamo sa imenom labele
			#array: .space 4096   vrijednost  elemenata polja je pri tome slucajna

#int polje[16] ={ 1, 2, 4, 8, 16, 32,...}	- deklaracija + inicijalizacija elemenata polja u RAMu
polje:	.word 1, 2, 4, 8, 16, 32	#	- asembleru naredujemo da za svaku navedenu vrijednost rezervira po 4 bajta(word)
					#	  i da navedene vrijednosti pretvori iz dek. u bin.
polje2:	.byte 1,2,4,8,16,32,64,255,512	# 	- svaki broj zauzima SAMO 1 byte
polje_je:	.asciiz "Polje je: \n"
razmak:		.asciiz ", "

	.globl main
	.text		
main:	
	li $v0, 4
	la $a0, polje_je
	syscall

# $t1 - brojac za broj brojeva u polju	
# $t2 - brojac(4 + )
	
	li $t1, 6 # zelimo 6 puta ponavljanje
	la $t0, polje  # ispis broja
	
ispis_broja:
	li $v0, 1
	lw $a0, ($t0)
	syscall
	
	li $v0, 4  # iuspis razmaka
	la $a0, razmak
	syscall

	addi $t0, $t0, 4
	subi $t1, $t1, 1
	bnez $t1, ispis_broja

	li $v0, 10 				
	syscall
