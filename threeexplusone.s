; Riya Baphna
; rb4nk
; 8/4/19
; threeexplusone.s


global _threeexplusone
section .text

_threeexplusone:
xor rax, rax ; counter for number of steps is 0
	cmp rdi, 1
	je done
	shr rdi, 1
	cmp rdi, 0 ; if remainder is 0, jump to even
	jmp reven
	cmp rdi, 1
	jmp odd    ; jump to odd


even:
	shr rdi, 1
	call _threexplusone
	add rax, 1   ; adds 1 to the counter
	jmp done

odd:
	imul rdi, 3
	add rdi, 1
	call _threeexplusone
	add rax, 1
	jmp done




done:
	ret