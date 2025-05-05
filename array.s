    .section .bss
buffer:
    .space 10 //tao array la 10 byte

    .global _start
    .section .text

_start:
    mov w1, #'Z' //them z (ascii) vao thanh ghi w1
    mov w2, #'A' //them a (ascii) vao thanh ghi w2
    adr x3, buffer //thanh ghi x3 tro vao dau tien cua "mang"
    strb w1, [x3] //luu thanh ghi w1 vao dia chi cua x3 hien tai la 0
    add x3, x3, #1 //tang len 1 byte
    strb w2, [x3] //luu thanh ghi w2 vao dia chi cua x3 hien tai la 1

    
    mov x0, 1 //stdout
    adr x1, buffer //x1 giong x3
    mov x2, 2 //in ra 1 byte = Z
    mov x8, 64 //syscall write
    svc 0

    mov x8, 93 //syscall exit
    mov x0, 0 //exit
    svc 0
    
    
