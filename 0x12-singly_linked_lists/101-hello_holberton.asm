global main
	section .text
main:
	mov rdi, 1
	mov rsi, msg
	mov rdx, 17
	mov rax, 1
	syscall

	mov eax, 60
	xor rdi, rdi
	syscall
msg:
	db "Hello, Holberton", 10
