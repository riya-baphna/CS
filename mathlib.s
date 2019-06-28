;mathlib.s
;riya baphna
;rb4nk
;3/24/19

global product
global power


section .text


product:  
	xor rax,rax    ;sets accumulator equal to 0
	xor	r10, r10	 ; zero out the counter i


productloop:
    cmp	r10, rsi	 ; compares i to y
	je endLoop		 ; if so, we are done with the loop
	add rax, rdi
	inc r10
	jmp productloop

endLoop:
	ret



power:
	cmp rsi, 1
	je end
	dec rsi
	call power
	mov rsi, rax
	call product
	ret


end:
    mov rax, rdi
	ret


























