;mathlib.s
;riya baphna
;rb4nk
;3/24/19

global _product
global power

section .data
i    DQ 1


section .text


_product:  ;do i need this underscore
	xor rax,rax    ;sets accumulator equal to 0
	xor	r10, r10	 ; zero out the counter i


productloop:
    cmp	r10, rsi	 ; compares i to y
	je endLoop		 ; if so, we are done with the loop
	add rax, rdi
	inc r10
	jmp productloop

endloop:
	ret
	add rsp,8

power:
	cmp rsi, i 
	je endrecurse
	add rax, 
























