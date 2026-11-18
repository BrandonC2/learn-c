	.file	"volatile_demo.c"
	.text
	.p2align 4
	.globl	wait_normal
	.type	wait_normal, @function
wait_normal:
.LFB0:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	testl	%eax, %eax
	je	.L3
	ret
.L3:
	jmp	.L3
	.cfi_endproc
.LFE0:
	.size	wait_normal, .-wait_normal
	.p2align 4
	.globl	wait_volatile
	.type	wait_volatile, @function
wait_volatile:
.LFB1:
	.cfi_startproc
	endbr64
	.p2align 3
	.p2align 4
	.p2align 3
.L6:
	movl	(%rdi), %eax
	testl	%eax, %eax
	je	.L6
	ret
	.cfi_endproc
.LFE1:
	.size	wait_volatile, .-wait_volatile
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
