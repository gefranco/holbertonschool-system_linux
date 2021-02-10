BITS 64
section .text
	global asm_strchr
asm_strchr:

	push rbp
	mov rbp, rsp

	mov rax, rdi
	mov dl, sil
	mov cl, [rax]

	cmp cl, dl
	je _ret

_find_char:

	inc rax
	mov cl, [rax]
	cmp cl, 0
	je _ret_null
	cmp cl, dl
	jne _find_char

_ret:

	mov rsp, rbp
	pop rbp
	ret

_ret_null:

	mov rax, 0
	mov rsp, rbp
        pop rbp
        ret
