extern ___error

section .text
	global _ft_write

_ft_write:				;ssize_t write(int fd, const void *buf, size_t count)
	push rbp
	mov rbp, rsp		;rbp = rsp
	push rbx			;var(rbx)
	mov rax, 0x2000004	;write
	syscall
	jc .err
	jmp .end

.err:
	push rax			;rax = errno
	call ___error		;rax = errno memory address
	pop rbx				;rbx = errno
	mov [rax], rbx		;*(errno memory address) = errno
	mov rax, -1			;rax = -1

.end:
	pop rbx
	leave				;mov rsp rbp 
						;pop rbp
	ret
