.data            # Zona de datos
vector: .word 1 6
##### serie   suma = (n-1)+1: desde n = 1 hasta N
      .text      # Zona de instrucciones
main: li $v0, 1  # Llamada al sistema para print int
      lw $a0, vector ($0)
      addi $s0, $a0, 0
      syscall
      lw $a0, vector + 4($0)
      addi $s1, $a0, 0
      syscall
      addi $a0, $s0, 1
      syscall    # Muestra el segundo número en pantalla
loop: 
      addi $s0, $s0, 1
      addi $a0, $s0, 0
      syscall
      ble $s0, $s1, loop
      syscall

      li $v0, 10 # Finalizarprograma
      syscall