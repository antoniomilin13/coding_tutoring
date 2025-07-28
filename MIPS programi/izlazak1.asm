# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			#ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
prompt: .asciiz "A"

	.globl main
	.text		# sa labelom .text oznacavamo adresu di pocinje program u RAMu 
			#ona je unaprid odredena i uvik iznosi 0x0040 0000

main:	
	li $v0, 10 	# pripema za svaki syscall je navodenje konkretne vridnosti za $v0
			#taj program uvik mormao zavrsiti vracanjem kontrole operativnom sistemu, a to postizemo sa podfunkcijom syscall
			#poziva koja ima znacenje exit, a prepoznaje se po ulaznom argumentu $v0 = 10
			#ponekad je potrebno i 2 ulazna parametra ispuniti prije poziva syscalla kako bi ispravno odredili zeljenu podfunkc
			#parametre svih 10 podfukcija mozemo naci u tablici u file-u syscall.txt
			#i najmanji program mora sadrzavati pripremu i izlazak putem syscalla(exit)
			
	syscall 	# return control to system 
