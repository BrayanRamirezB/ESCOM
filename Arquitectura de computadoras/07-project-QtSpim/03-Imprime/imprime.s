# Imprimir en consola

main:
 .text
   addi $a0,$0,600 #Valor a escribir en $a0 
   addi $v0,$0,1 #Función 1, print integer 
   syscall #Escribe en consola $a0

   addi $v0, $0, 10   #Funtion 10, exit
   syscall            #Acaba el programa