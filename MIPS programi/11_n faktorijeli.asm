#--FAKTORIJELI----

	.data  		
upisite_fakt:	.asciiz "Koliko uzastopnih brojeva zelite pomnoziti: "
unjeli_ste:	.asciiz "\nUnjeli ste broj: "
faktorijel_je:	.asciiz "\nFaktorijel je: "

	.globl main
	.text		
main:	
	li $v0, 4
	la $a0, upisite_fakt
	syscall
	
	li $v0, 5
	syscall   # procitani broj se nalazi u $v0
	
	move $t0, $v0  # sacuvali smo procitani broj
	li $v0, 4
	la $a0, unjeli_ste
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
#----FAKTORIJELE PETLJA----
	# u = 1;
	# for (i=2; i<=n; i++){
	# 	u = u *i }
	# cout << "n! =" << u;
	
#          $t0 -> n
	li $t1, 1	# u = 1 ( u je umnozak)
	li $t2, 2	# i = 2
	
petlja:
	mul $t1, $t1, $t2	# $t1 = $t1 * $t2  ->  u = u *i 
	addi $t2, $t2, 1 
	ble $t2, $t0, petlja

	li $v0, 4
	la $a0, faktorijel_je
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 10 				
	syscall
