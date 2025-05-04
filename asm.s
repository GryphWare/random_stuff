    .global _start
    //khu vuc code
    .section .text

_start:
    mov x0, 1      //1 la stdout
    adr x1, msg    //tro den msg
    mov x2, 12     //so ki tu "hello world"
    mov x8, 64     //syscall write
    svc 0

    //end
    mov x8, 93     //syscall exit
    mov x0, 0
    svc 0

    .section .data
msg:
    .ascii "Hello World\n"
    
