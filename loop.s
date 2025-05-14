    .section .data
going:  
    .ascii "Still going...\n"  //in ra khi trong loop
done:
    .ascii "Done!\n"           //in ra khi xong loop

    .global _start
    .section .text

_start:                        //program bat dau tu day
    mov x4, #0                 //dat thanh ghi x4 la 0

compare:    
    cmp x4, #5                 //so sanh x4 voi 5
    b.ne not_equal             //neu ko bang thi qua nhan not_equal
    
equal:                         //neu bang thi in Done! va stop progrm
    mov x0, #1                 //syscall
    adr x1, done               //tro vao msg: done
    mov x2, #7                 //doc 6 ky tu
    mov x8, 64                 //syscall write
    svc 0                      //trap

    b exit

not_equal:                     //neu ko bang 5 thi cong them 1 va in ra Still Going
    mov x0, #1                 //syscall
    adr x1, going              //tro den phan going
    mov x2, #15                //doc 14 byte
    mov x8, 64                 //syscall write
    svc 0                      //trap

    add x4, x4, #1             //cong 1 vao x4
    b compare                  //quay lai ham compare

exit:                          //thoat ra khi ok
    mov x0, #0                 //syscall
    mov x8, 93                 //syscall exit
    svc 0                      //trap
    
