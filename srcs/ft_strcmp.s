global _ft_strcmp

section .text

_ft_strcmp:				;rdi = s1, rsi = s2
	push r8
	xor r8, r8			;i = 0

.loop:
	mov al, BYTE [rdi + r8]	;
	mov cl, BYTE [rsi + r8]	;
	cmp al, 0  
	je .end
	cmp cl, 0
	je .end
	cmp al, cl
	jne .end
	inc r8
	jmp .loop

.end:
	movzx rax, BYTE [rdi + r8]
	movzx rbx, BYTE [rsi + r8]
	sub rax, rbx
	pop r8
	ret
