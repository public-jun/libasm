global _ft_strcpy

section .text

_ft_strcpy:						;dst = rdi, src = rsi
	xor r8, r8					;i = 0
	xor cl, cl					;tmp = 0
	cmp BYTE [rsi], 0
	je .end


.loop:
	cmp BYTE [rsi + r8] , 0		;if (src[i] == '\0')
	je .end						;	end()
	mov cl, BYTE [rsi + r8]		;tmp = src[i]
	mov BYTE [rdi + r8], cl		;dst[i] = tmp
	inc r8						;i++
	jmp .loop

.end:
	mov BYTE [rdi + r8], 0		;dst[i] = '\0'
	mov rax, rdi				;res = dst
	ret							;return(res)
