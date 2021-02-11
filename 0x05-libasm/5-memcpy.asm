BITS 64
section .text
	global asm_memcpy

asm_memcpy:

	push rbp
	mov rbp, rsp

	mov r8, rdx

	mov r9, 0


	cmp r9, r8
	je _ret

_cpy:
	cmp r9, r8
	je _ret


	mov cl, [esi + r9d]
	mov [edi + r9d], cl

	inc r9
	cmp r9, r8
	jle _cpy

_ret:
        mov rsp, rbp
        pop rbp
        ret

