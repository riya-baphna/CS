; Riya Baphna
; rb4nk
; 8/4/19
; threexplusone.s
; optimizations include using shr instead of idiv, not pushing any registers onto the stack and also did not set up base pointer but instead used xor to make the accumulator equal to zero.


global threexplusone
section .text

threexplusone:
xor rax, rax ; counter for number of steps is 0
	cmp rdi, 1
	je done
	test rdi, 1
	jne odd    ; jump to odd
	jz even


even:
	shr rdi, 1
	call threexplusone
	add rax, 1   ; adds 1 to the counter
	jmp done

odd:
	imul rdi, 3
	add rdi, 1
	call threexplusone
	add rax, 1
	jmp done


done:
	ret