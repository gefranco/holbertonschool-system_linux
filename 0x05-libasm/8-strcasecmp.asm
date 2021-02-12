	global asm_strcasecmp

asm_strcasecmp:

	push rbp
	mov rbp, rsp

_compare:
	cmp cl, 0
	je _ret

	mov  cl, [rdi]
	mov dl, [rsi]

	cmp dl, 96
	jg _sub1

	cmp cl, 96
	jg _sub2

	inc rdi
	inc r8

	inc rsi
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

_sub1:
        sub rdi, 32
        jmp _compare

_sub2:
        sub rsi, 32
        jmp _compare
