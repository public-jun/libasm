global _ft_strcpy

section .text

_ft_strcpy:			;dst = rdi, src = rsi
	xor rcx, rcx	;i = 0
	xor cl, cl		;tmp = 0

.loop:
	cmp BYTE [rsi + rcx] , 0x0	;if (src[i] == '\0')
	je .endloop					;	endloop()
	mov cl, BYTE [rsi + rcx]		;tmp = src[i]
	mov BYTE [rdi + rcx], cl		;dst[i] = tmp
	inc rcx						;i++
	jmp .loop

.endloop:
	mov BYTE [rdi + rcx], 0x0
	mov rax, rdi		;res = dst
	ret				;return(res)
