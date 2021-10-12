.global lab1
.syntax unified
#define A #4
#define B #6
#define C #8

lab1: push {r0, r1, r2, r3, r4, lr}
mov r2, A
mov r3, B
mov r4, C
mul r0, r2, r3
cmp r0, #6
ite ge
orrGE r1, r2, r3
andLT r1, r2, r3
mul r1, r4
pop {r0, r1, r2, r3, r4, pc}
