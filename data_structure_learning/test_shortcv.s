	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushl	%ebp
Lcfi0:
	.cfi_def_cfa_offset 8
Lcfi1:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
Lcfi2:
	.cfi_def_cfa_register %ebp
	pushl	%esi
	pushl	%eax
Lcfi3:
	.cfi_offset %esi, -12
	calll	L0$pb
L0$pb:
	popl	%eax
	subl	$8, %esp
	leal	L_.str-L0$pb(%eax), %esi
	pushl	$0
	pushl	%esi
	calll	_printf
	addl	$8, %esp
	pushl	$1
	pushl	%esi
	calll	_printf
	addl	$16, %esp
	xorl	%eax, %eax
	addl	$4, %esp
	popl	%esi
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
