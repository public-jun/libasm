extern ___error

section .text
	global _ft_read

_ft_read:				;ssize_t read(int fd, void *buf, size_t nbytes)
	push rbp
	mov rbp, rsp		;rbp = rsp
	push rbx			;var(rbx)
	mov rax, 0x2000003	;read
	syscall
	jc .err
	jmp .end

.err:
	push rax			;rax = errno
	call ___error		;rax = errno memory address
	pop rbx				;rbx = errno
	mov [rax], rbx		;*(errno memory address) = errno
	mov rax, -1

.end:
	pop rbx
	leave				;mov rsp, rbp
						;pop rbp
	ret
