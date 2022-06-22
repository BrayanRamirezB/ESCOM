#Multiplicacion de dos numeros

main:
 .text
   addi $t0,$0,20 #Valor a escribir en $t0
   addi $t1,$0,30 #Valor a escribir en $t1
   mul $a0, $t0, $t1
   addi $v0,$0,1 #Función 1, print integer 
   syscall #Escribe en consola $a0

   addi $v0, $0, 10   #Funtion 10, exit
   syscall            #Acaba el programa