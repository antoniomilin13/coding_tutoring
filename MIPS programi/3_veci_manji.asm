# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			#ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
upis1: 		.asciiz "Upisite PRVI broj: "
upis2: 		.asciiz "Upisite DRUGI broj: "
veci:		.asciiz "\nVeci broj je: "
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
	
	#-------"Veci broj je"---------------------
	li $v0, 4	#string
	la $a0, veci
	syscall         # "\nVeci broj je: "

	#--------Pronalazak veceg broja--------------
	bgt $t0, $t1, t0_je_veci		#bgt Rs, Rt, Label

t1_je_veci:
	li $v0, 1	#ispis int
	move $a0, $t1
	syscall
t0_je_veci:
	li $v0, 1	#ispis int
	move $a0, $t0
	syscall
	
	li $v0, 10 				
	syscall
