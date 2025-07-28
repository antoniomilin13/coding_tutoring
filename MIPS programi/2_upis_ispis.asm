# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			#ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
upis: .asciiz "Upisite broj: "
ispis: .asciiz "\nUpisani broj je: "
	.globl main
	.text		

main:	
	li $v0, 4	#string poziv
	la $a0, upis
	syscall         # ISPIS 
	
	li $v0, 5	#read int  treba SAMO 1 parametar
	syscall         # ucitani int ce biti spremljen u $v0
	move $t0, $v0	#prebaciti broj spremljen iz $v0 u $t0
	
	li $v0, 4	#string
	la $a0, ispis
	syscall         # ISPIS "\nUpisani broj je: "

	li $v0, 1
	move $a0, $t0	#pribaciti iz t0 u a0(radi tablice - print int)
	syscall
	
	li $v0, 10 	# pripema za svaki syscall je navodenje konkretne vridnosti za $v0			
	syscall 	# return control to system 
