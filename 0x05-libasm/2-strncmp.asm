BITS 64
section .text
	global asm_strncmp

asm_strncmp:

	push rbp
	mov rbp, rsp

	mov rax, rdi
	mov rbx, rsi
	mov r8, rdx

	mov r9, 1

	mov cl, [rax]
	mov dl, [rbx]

	cmp cl, dl
	jne _ret_not

_compare:
	cmp cl, 0
	je _ret

	cmp r8, r9
	je _ret

	inc rax
	inc rbx

	inc r9

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

