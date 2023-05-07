	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%esi, %esi
	movl	$0, -4(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_open
	movl	$1000, %esi             ## imm = 0x3E8
	movl	%esi, %edx
	movq	-16(%rbp), %rsi
	movl	%eax, %edi
	callq	_read
	movl	%eax, %edi
	movl	%edi, -8(%rbp)
	cmpl	$0, %edi
	jge	LBB0_2
## %bb.1:
	movl	$0, -4(%rbp)
	jmp	LBB0_3
LBB0_2:
	movq	-16(%rbp), %rax
	movslq	-8(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movl	-8(%rbp), %esi
	movq	-16(%rbp), %rdx
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -4(%rbp)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
LBB0_3:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"text"

L_.str.1:                               ## @.str.1
	.asciz	"%d, %s\n"


.subsections_via_symbols
