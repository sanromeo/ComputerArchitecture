.syntax unified
.cpu cortex-m4
.thumb

// Global memory locations.
.global vtable_kernel
.global __kernel_reset__

.type vtable_kernel, %object
.type __kernel_reset__, %function

.section .interrupt_vector
vtable_kernel:
    .word __stack_start 
    .word __kernel_reset__+1
    .size vtable_kernel, .-vtable_kernel

.section .rodata
    data: .asciz "kernel started!\n"
    final: .asciz "Value in register #6: "
.section .text
__kernel_reset__:
    ldr r0, =data
    bl dbgput_line
    
    mov r2, #4
    mov r3, #6
    mov r4, #8
    mul r0, r2, r3
    cmp r0, #6
    ite ge
    orrGE r6, r2, r3
    andLT r6, r2, r3
    mul r6, r4

    ldr r0, =final
    bl dbgput
    mov r0, r6
    bl dbgput_num
    
    end:
    b end

