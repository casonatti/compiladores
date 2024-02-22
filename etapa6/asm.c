#include "asm.h"

void create_asm(TAC *src_tac, AST *ast) {
  FILE *asm_file = fopen("asm.s", "w");
  int BL = 0;
  int LC = 2;

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

  switch() {
    case TAC_PRINT:
      fprintf(asm_file, "\tmovq	%%rsp, %%rbp\n"
                        "\tleaq	.LC0(%%rip), %%rdi\n"
                        "\tmovl	$0, %eax\n"
                        "\tcall	printf@PLT\n"
                        "\tmovl	$0, %eax")
  }
}