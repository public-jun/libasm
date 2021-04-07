global _main:

section .data
message: db 'Hello, world!', 10


section .text
_main:
	mov rax, 0x2000004

	mov rdi, 1
	mov rsi, message
	mov rdx, 14
	syscall

	ret
