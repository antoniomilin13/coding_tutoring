# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			#ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
upis1: 		.asciiz "Upisite PRVI broj: "
upis2: 		.asciiz "Upisite DRUGI broj: "
ispis: 		.asciiz "\nUpisani broj je: "
zbroj:		.asciiz "\nZbroj je: "
	.globl main
	.text		

main:	
	#--------Upis prvog broja---------------
	li $v0, 4	#string poziv
	la $a0, upis1
	syscall         # ISPIS 
	
	li $v0, 5	#read int  treba SAMO 1 parametar
	syscall         # ucitani int ce biti spremljen u $v0
	move $t0, $v0	#prebaciti broj spremljen iz $v0 u $t0
	
	#--------Upis drugog broja---------------
	li $v0, 4	#string poziv
	la $a0, upis2
	syscall         # ISPIS 
	
	li $v0, 5	#read int  treba SAMO 1 parametar
	syscall         # ucitani int ce biti spremljen u $v0
	move $t1, $v0	#prebaciti broj spremljen iz $v0 u $t1
	
	li $v0, 4	#string
	la $a0, zbroj
	syscall         # "\nZbroj je: "

	#--------Zbrajanje dva broja--------------
	add $t2, $t0, $t1  #t2 = t1 + t0
	
	li $v0, 1
	move $a0, $t2	#pribaciti iz t0 u a0(radi tablice - print int)
	syscall
	
	li $v0, 10 	# pripema za svaki syscall je navodenje konkretne vridnosti za $v0			
	syscall 	# return control to system 
