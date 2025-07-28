# Upis - ispis
	
	.data  		# sa labelom .data oznacavamo adresu di pocinju nasi podaci u RAMu
			#ona je unaprid odredena i uvik iznosi 0x1001 0000 (sirina 4 byte-a)
opci_clan: 	.asciiz "Opci clan aritmetickog niza ima oblik:\n        an = a0 + n*d\n"
upis_1_clana:	.asciiz "\nUpisite prvi clan (a0) aritmetickog niza: "
upis_koraka: 	.asciiz "\nUpisite korak (d) za povecanje aritmetickog niza: "
zadnji_index:	.asciiz "\nDo kojeg clana zelite ispisati red: "
arit_niz_glasi: .asciiz "\nAritmeticki niz:\n"
razmak:		.asciiz " "

	.globl main
	.text		

main:	
	li $v0, 4
	la $a0, opci_clan
	syscall
	
#-------Upis prvog clana-------
	li $v0, 4
	la $a0, upis_1_clana
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0   # $t0 = $v0  /  $t0 je nulti clan reda
	
#-------Upis koraka-------
	li $v0, 4
	la $a0, upis_koraka
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0	# $t1 je korak (d)	
	
#-------Upis koraka-------
	li $v0, 4
	la $a0, zadnji_index
	syscall
	
	li $v0, 5
	syscall
	move $t2, $v0	# $t2 je zadnji index (n)

#-------Arit. niz glasi-------
	li $v0, 4
	la $a0, arit_niz_glasi
	syscall
	
#-------RACUN------------ an = a0 + n*d  ili     a_n+1 = a_n + d
# a0, a1, ..., an  - to NISU registri nego clnovi aritm. niza
# $t0 - a0
# $t1 - d
# $t2 - n (zadnji index)
# $t3 - an opci clan
	
	move $t3, $t0   # $t3 = a0
	move $t4, $t2   # iskopirati iznos n u $t4
ispis_trenutacnog_clana:
	# 1. korak = ISPIS trenutnog clana
	li $v0, 1
	move $a0, $t3
	syscall
	
	# 2. ISPIS razmak
	li $v0, 4
	la $a0, razmak
	syscall
	
	# 3. korak = Izracun novog clana
	add $t3, $t3, $t1   # rekurzija -> a_n+1 = a_n + d
	sub $t4, $t4, 1
	bnez $t4, ispis_trenutacnog_clana

	li $v0, 10 				
	syscall
