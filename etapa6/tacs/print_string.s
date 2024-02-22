.LC0:
	.string	"1"
	.text
.globl	main
main:
.LFB0:
	movq	%rsp, %rbp
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
