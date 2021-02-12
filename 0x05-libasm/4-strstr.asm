BITS 64
section .text
	global asm_strstr

asm_strstr:

	push rbp
	mov rbp, rsp

	mov rax, rdi
	mov rbx, rsi

	mov cl, [rax]
	mov dl, [rbx]

	cmp cl, dl
	jne _ret_not

_compare:
	cmp cl, 0
	je _ret

	inc rax
	inc rbx
	mov cl, [rax]
	mov dl, [rbx]
	cmp cl, dl
	je _compare

_ret_not:
	sub cl, dl
	cmp cl, 0
	jg _retg
	mov rax, -1

	mov rsp, rbp
        pop rbp
        ret
_retg:
	mov rax, 1
	mov rsp, rbp
        pop rbp
        ret

_ret:
        mov rax, 0

        mov rsp, rbp
        pop rbp
        ret

