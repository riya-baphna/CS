       
























        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    Sport::Sport() [base object constructor]
        mov     edx, OFFSET FLAT:vtable for Basketball+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        nop
        leave
        ret













        mov     edi, 16
        call    operator new(unsigned long)
        mov     rbx, rax
        mov     QWORD PTR [rbx], 0
        mov     DWORD PTR [rbx+8], 0
        mov     rdi, rbx
        call    Basketball::Basketball() [complete object constructor]
        mov     QWORD PTR [rbp-24], rbx