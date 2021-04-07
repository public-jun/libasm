global _ft_strlen:
section .data

section .text

_ft_strlen:
	mov rax, 0
	jmp .loop

.loop:
	cmp BYTE [rdi + rax], 0x0
	je .endloop
	inc rax
	jmp .loop

.endloop:
	ret
	
