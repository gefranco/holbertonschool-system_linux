BITS 64
section .text
	global asm_strlen
asm_strlen:
	
	push rbp
	mov rbp, rsp
	
	mov rax, rdi
	mov rbx, 0
	mov cl, [rax]
	cmp cl, 0
	je _ret
	
_count_chars:

	inc rbx
	inc rax
	mov cl, [rax]
	cmp cl, 0
	jne _count_chars

_ret:	
	mov rax, rbx
	
	mov rsp, rbp
	pop rbp
	ret
