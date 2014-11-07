
; GC_push_regs function. Under some optimization levels GCC will clobber
; some of the non-volatile registers before we get a chance to save them
; therefore, this can't be inline asm.

.text
	.align 2
	.globl _GC_push_regs
_GC_push_regs:
    
    ; Prolog
	mflr r0
	stw r0,8(r1)
	stwu r1,-80(r1)

	; Push r13-r31
	mr r3,r13
	bl L_GC_push_one$stub
	mr r3,r14
	bl L_GC_push_one$stub
	mr r3,r15
	bl L_GC_push_one$stub
	mr r3,r16
	bl L_GC_push_one$stub
	mr r3,r17
	bl L_GC_push_one$stub
	mr r3,r18
	bl L_GC_push_one$stub
	mr r3,r19
	bl L_GC_push_one$stub
	mr r3,r20
	bl L_GC_push_one$stub
	mr r3,r21
	bl L_GC_push_one$stub
	mr r3,r22
	bl L_GC_push_one$stub
	mr r3,r23
	bl L_GC_push_one$stub
	mr r3,r24
	bl L_GC_push_one$stub
	mr r3,r25
	bl L_GC_push_one$stub
	mr r3,r26
	bl L_GC_push_one$stub
	mr r3,r27
	bl L_GC_push_one$stub
	mr r3,r28
	bl L_GC_push_one$stub
	mr r3,r29
	bl L_GC_push_one$stub
	mr r3,r30
	bl L_GC_push_one$stub
	mr r3,r31
	bl L_GC_push_one$stub

    ; 
    lwz r0,88(r1)
    addi r1,r1,80
	mtlr r0
    	
	; Return
	blr

; PIC stuff, generated by GCC

.data
.section __TEXT,__picsymbolstub1,symbol_stubs,pure_instructions,32
	.align 2
L_GC_push_one$stub:
	.indirect_symbol _GC_push_one
	mflr r0
	bcl 20,31,L0$_GC_push_one
L0$_GC_push_one:
	mflr r11
	addis r11,r11,ha16(L_GC_push_one$lazy_ptr-L0$_GC_push_one)
	mtlr r0
	lwzu r12,lo16(L_GC_push_one$lazy_ptr-L0$_GC_push_one)(r11)
	mtctr r12
	bctr
.data
.lazy_symbol_pointer
L_GC_push_one$lazy_ptr:
	.indirect_symbol _GC_push_one
	.long dyld_stub_binding_helper
