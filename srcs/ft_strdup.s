extern ___error
extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text
	global _ft_strdup

_ft_strdup:							;char *strdup(const char *s1)
	push rbp
	mov rbp, rsp					;rbp = rsp
	sub rsp, 0x10					;rsp = rsp - 0x10 
	mov QWORD [rbp - 0x08], rdi		;[rsp - 0x08] = s1 
	call _ft_strlen					;len = ft_strlen(rdi)
	mov rdi, rax					;
	inc rdi							;len + 1
	call _malloc
	cmp rax, 0x0					;if (p == NULL)
	je .end
	mov rdi, rax					;char *dst = rdi
	mov rsi, QWORD [rbp - 0x08]		;char *src = [rbp - 0x08]
	call _ft_strcpy
	jmp .end

.end:
	leave
	ret
