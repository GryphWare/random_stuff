    .section .data
msg:
    .ascii "Done\n" //in ra thong bao bang nhau
msg2:
    .ascii "Fine\n" //in ra thong bao khac nhau
    
    .global _start
    .section .text
_start:
    mov x0, #1      //cho thanh x0 la 1
    mov x1, #1      //cho thanh x1 la 0

    //so sanh
    cmp x0, x1
    beq equal
    
not_equal:
    mov x0, #1       //stdout           
    adr x1, msg2      //tro den msg      
    mov x2, #5       //doc 5 ky tu      
    mov x8, #64      //syscall write    
    svc #0                              
    b exit           //jump den exit    
equal:
    mov x0, #1       //stdout
    adr x1, msg     //tro den msg
    mov x2, #5       //doc 5 ky tu
    mov x8, #64      //syscall write
    svc #0       

    mov x0, #0
    mov x8, #93
    svc 0
    
exit:   
    //syscall exit
    mov x0, #0
    mov x8, #93
    svc #0
