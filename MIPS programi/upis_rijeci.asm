# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			# ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
			# to je adresa u heksadekadskom a ne u binarnom
upisite_broj: 	.asciiz "Upisite broj: "
broj_kvadrat:	.asciiz "\n na kvadrat je: "
broj_kub:	.asciiz "\n na kub je: "
nastavak:	.asciiz "\nZelite li nastaviti sa novim brojem (d/n): "
zavrsili_ste:	.asciiz "\n\nZavrsili ste sa programom."
upisali_ste:	.asciiz "\nUpisali ste:  "
broj:		.word 0    # TAKO PRIMORAVAMO ASSEMBLER DA REZERVIRA 1 mjesto od 4 byta (1 worda) na ISPRAVNOJ ADRESI
input_buffer:	.space 32  #- rezervacija za ucitani string duljine 9 (dodatno mjesto nam treba za \0)
                           #- ovo je pointer na POCETAK string varijable
                           #- ako smo buffer stavili na pocetak .data podrucja tada duljina svakog buffera mora biti visekratnik od 4,
                           #kako bi ostali bufferi takoder pocinjali na ispravnoj adressi
                           #- 2.nacin osiguravanja ispravne adrese za input buffer je umetanje brojevne dummy konstante
                           # NEPOSREDNO ISPRED input_buffera !
                           #- dummy konst. mora postojati ali njena vrijednost nije bitna
                           # dummy_broj: .word 0 - ali je bitna njezina duljina(tj. prostor koji zauzima)
                           #- buduci da je zahtjevana velicina word, sam asembler pronalazi prvu ispravnu adresu sa koje cemo moci
                           #ocitati vrijednost dummy_broj -a. Zbog toga je i prva sljedeca adresa(input_buffer) takoder ispravna
broj2:		.word 0
input_buffer2:	.space 24	#za svaki sljedeci buffer osiguravamo pravilni pocetak na jedan od 2 nacina
				#1. - ponovno stavljamo jos jednu dummy varijalbu sirine word
				#2. - prethodni buffer mora biti duljine 4 puta cijeli broj

	.globl main
	.text		# sa labelom .text oznacavamo adresu di pocinje nas program u RAMu
			# ona je unaprid odredena i uvik iznosi 0x0040 0000 (sirina 4 byte-a)
main:	
#-----------------
# $t1 -> upisani broj
# $t2 -> kvadrat
# $t3 -> kub
# $t4 -> ASCII vrijednost od d (da):
# $t5 -> upis d ili n (D ili N)
#-----------------

	li $v0, 4
	la $a0, upisite_broj
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0

#----kvadrat + kub----
	#mult	mult $s, $t	hi:lo = $s * $t	Multiply  - dobivamo rezultat u SVIH 64 bita
	mul $t2, $t1, $t1	#kvadrat - dobivamo rezultat SAMO u 32 bita - +/- ~ 2 000 000 000
	mul $t3, $t2, $t1	#kub - moramo paziti na maximalnu vrijednost rezultata
	
#----ispis kvadrata i kuba----
	li $v0, 4
	la $a0, broj_kvadrat
	syscall
	
	li $v0, 1
	move $a0, $t2		#ispis BROJA = kvadrat
	syscall
	
	li $v0, 4
	la $a0, broj_kub
	syscall
	
	li $v0, 1
	move $a0, $t3
	syscall

#----ispis poruke "zelite li jos"----
	li $v0, 4
	la $a0, nastavak
	syscall

#|------------------------------------------------------------------|
#| Service	| $v0(ULAZ)| 	  $a0(ULAZ)	|     $a1(ULAZ)	    |
#|------------------------------------------------------------------|
#| read string  |	  8|Addr. of Input Buff	|max length of str. |
#|------------------------------------------------------------------|

	li $v0, 8  # odabiremno funciju read string (zahtijeva 3 ulazna parametra)
	la $a0 input_buffer  # odredili smo adresu POCETKA input buffera
	li $a1, 2  # max duljina stringa - 1 = 4-1 =3
	syscall    # ucitavanje stringa
	
	# $t5 -> upis d ili n (D ili N)
	lb $t5, ($a0)   # ako je lb onda u $t5 upisujemo SAMO prvi byt-e (1 znak)
			# ako je lw onda k+$a0 MORA BITI visekratnik od 4
	li $v0, 4
	la $a0, upisali_ste
	syscall
	
	li $v0, 4
	la $a0, input_buffer   	#ispis stringa
	syscall

	# $t4 -> ASCII vrijednost od d (da):
	li $t4, 100   # ASCII od malo d
	
	beq $t5, $t4, main	#ako je jednako ide na "main" labelu


	li $v0,4
	la $a0, zavrsili_ste
	syscall
	
#----Izlazak iz programa----	
	li $v0, 10 				
	syscall