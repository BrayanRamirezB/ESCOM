.data            	#Zona de datos
vector: .word 3 10 1 0		#Vector a cargar
#####
      .text      	#Zona de instrucciones
main: li $v0, 1  		#Llamada al sistema para print int
      lw $a0, vector ($0)	#Cargamos el primer numero (posición inicial)
      addi $s0, $a0, 0		#Salvamos el primer numero
      #syscall			#Llamada a sistema

      lw $a0, vector + 4($0)	#Cargamos el segundo numero (posición final)
      addi $s1, $a0, 0		#Salvamos el segundo numero
      #syscall			#Llamada a sistema

      lw $a0, vector + 8($0)	#Cargamos el tercer numero (Sn-1 = 1)
      addi $s2, $a0, 0		#Salvamos el tercer numero
      syscall			#Llamada a sistema

      lw $a0, vector + 8($0)	#Cargamos el cuarto numero (Sn-2 = 1)
      addi $s3, $a0, 0		#Salvamos el cuarto numero
      syscall			#Llamada a sistema

      lw $a0, vector + 12($0)	#Cargamos el quinto numero (Resultado)
      addi $s4, $a0, 0		#Salvamos el quinto numero
      #syscall			#Llamada a sistema

loop: 			#Inicio del ciclo
      add $s4, $s2, $s3		#Suma fibonacci
      addi $a0, $s4, 0		#Copiamos el valor $s4
      syscall			#Imprimimos en consola
      
      addi $s2, $s3, 0		#Actualizamos valores s2 = s3
      addi $s3, $s4, 0		#Actualizamos valores s3 = s4
      
      addi $s0, $s0, 1		#Incrementamos en 1 nuestro contador
      addi $a0, $s0, 0		#Copiamos el valor $s0

      ble $s0, $s1, loop	#$s0 Less than or equal to $s1
				#Salto a la etiqueta "loop"

      li $v0, 10		#Finalizar programa
      syscall