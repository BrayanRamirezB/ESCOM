# helloworld.s
#
# Print out "Hello World"
#
# Copyright (c) 2013, James R. Larus.
# All rights reserved.
#

        .data
msg:   .asciiz "Hello World"
	.extern foobar 4

        .text
        .globl main
main:   li $v0, 4       # syscall 4 (print_str)
        la $a0, msg     # argument: string
        syscall         # print the string
        lw $t1, foobar
        
        jr $ra          # retrun to caller
