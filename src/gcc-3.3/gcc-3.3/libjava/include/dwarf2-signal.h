// dwarf2-signal.h - Catch runtime signals and turn them into exceptions.

/* Copyright (C) 2000, 2001  Free Software Foundation

   This file is part of libgcj.

   Use this file for a target for which the dwarf2 unwinder in libgcc
   can unwind through signal handlers.

This software is copyrighted work licensed under the terms of the
Libgcj License.  Please consult the file "LIBGCJ_LICENSE" for
details.  */

#ifndef JAVA_SIGNAL_H
#define JAVA_SIGNAL_H 1

#include <signal.h>
#include <sys/syscall.h>

#define HANDLE_SEGV 1
#undef HANDLE_FPE

#define SIGNAL_HANDLER(_name)	\
static void _Jv_##_name (int, siginfo_t *_sip, void *_p)

class java::lang::Throwable;

// Unwind the stack to the point at which the signal was generated and
// then throw an exception.  With the dwarf2 unwinder we don't usually
// need to do anything, with some minor exceptions.

#ifdef __alpha__
#define MAKE_THROW_FRAME(_exception)					\
do									\
{									\
  /* Alpha either leaves PC pointing at a faulting instruction or the	\
   following instruction, depending on the signal.  SEGV always does	\
   the former, so we adjust the saved PC to point to the following	\
   instruction; this is what the handler in libgcc expects.  */		\
  struct sigcontext *_sc = (struct sigcontext *)_p;			\
  _sc->sc_pc += 4;							\
}									\
while (0)

#elif defined(__ia64__)

#define MAKE_THROW_FRAME(_exception)					\
do									\
{									\
  /* IA-64 either leaves PC pointing at a faulting instruction or the	\
   following instruction, depending on the signal.  SEGV always does	\
   the former, so we adjust the saved PC to point to the following	\
   instruction; this is what the handler in libgcc expects.  */		\
  /* Note that we are lying to the unwinder here, which expects the	\
   faulting pc, not pc+1.  But we claim the unwind information can't	\
   be changed by such a ld or st instruction, so it doesn't matter. */	\
  struct sigcontext *_sc = (struct sigcontext *)_p;			\
  _sc->sc_ip++;								\
}									\
while (0)
#elif defined(__sparc__)
/* We could do the unwind of the signal frame quickly by hand here like
   sparc-signal.h does under Solaris, but that makes debugging unwind
   failures almost impossible.  */
#if !defined(__arch64__)
#define MAKE_THROW_FRAME(_exception)					\
do									\
{									\
  /* Sparc-32 leaves PC pointing at a faulting instruction		\
   always.								\
   We advance the PC one instruction past the exception causing PC.	\
   This is done because FDEs are found with "context->ra - 1" in the	\
   unwinder.								\
   Also, the dwarf2 unwind machinery is going to add 8 to the		\
   PC it uses on Sparc.  So we adjust the PC here.  We do it here	\
   because we run once for such an exception, however the Sparc specific\
   unwind can run multiple times for the same exception and it would	\
   adjust the PC more than once resulting in a bogus value.  */		\
  struct sig_regs {							\
    unsigned int psr, pc, npc, y, u_regs[16];				\
  } *regp;								\
  unsigned int insn;							\
  __asm__ __volatile__("ld [%%i7 + 8], %0" : "=r" (insn));		\
  /* mov __NR_sigaction, %g1; Old signal stack layout */		\
  if (insn == 0x821020d8)						\
    regp = (struct sig_regs *) _sip;					\
  else									\
    /* mov __NR_rt_sigaction, %g1; New signal stack layout */		\
    regp = (struct sig_regs *) (_sip + 1);				\
  regp->pc = ((regp->pc + 4) - 8);					\
}									\
while (0)
#else
#define MAKE_THROW_FRAME(_exception)					\
do									\
{									\
  /* Sparc-64 leaves PC pointing at a faulting instruction		\
   always.								\
   We advance the PC one instruction past the exception causing PC.	\
   This is done because FDEs are found with "context->ra - 1" in the	\
   unwinder.								\
   Also, the dwarf2 unwind machinery is going to add 8 to the		\
   PC it uses on Sparc.  So we adjust the PC here.  We do it here	\
   because we run once for such an exception, however the Sparc specific\
   unwind can run multiple times for the same exception and it would	\
   adjust the PC more than once resulting in a bogus value.  */		\
  struct pt_regs {							\
    unsigned long u_regs[16];						\
    unsigned long tstate, tpc, tnpc;					\
    unsigned int y, fprs;						\
  } *regp = (struct pt_regs *) (_sip + 1);				\
  regp->tpc = ((regp->tpc + 4) - 8);					\
}									\
while (0)
#endif
#else
#define MAKE_THROW_FRAME(_exception)		\
do						\
{						\
  (void)_p;					\
}						\
while (0)
#endif

#if defined(__sparc__)
#if defined(__arch64__)
extern "C" {
    static void __rt_sigreturn_stub(void)
    {
      __asm__("mov %0, %%g1\n\t"
	      "ta  0x6d\n\t"
	      : /* no outputs */
	      : "i" (__NR_rt_sigreturn));
    }
    struct kernel_sigaction
    {
      void (*k_sa_sigaction)(int,siginfo_t *,void *);
      unsigned long k_sa_flags;
      void (*k_sa_restorer)(void);
      sigset_t k_sa_mask;
    };
}
#define INIT_SEGV						\
do								\
  {								\
    nullp = new java::lang::NullPointerException ();    	\
    struct kernel_sigaction act;				\
    unsigned long stub = ((unsigned long)&__rt_sigreturn_stub); \
    act.k_sa_sigaction = _Jv_catch_segv;      			\
    sigemptyset (&act.k_sa_mask);				\
    act.k_sa_flags = SA_SIGINFO;	       			\
    act.k_sa_restorer = NULL;					\
    syscall (SYS_rt_sigaction, SIGSEGV, &act, NULL,		\
             stub - 8, _NSIG / 8);				\
  }								\
while (0)  

#define INIT_FPE						\
do								\
  { 								\
    arithexception = new java::lang::ArithmeticException 	\
      (JvNewStringLatin1 ("/ by zero"));			\
    struct kernel_sigaction act;				\
    unsigned long stub = ((unsigned long)&__rt_sigreturn_stub); \
    act.k_sa_sigaction = _Jv_catch_fpe;				\
    sigemptyset (&act.k_sa_mask);				\
    act.k_sa_flags = SA_SIGINFO;		       		\
    act.k_sa_restorer = NULL;					\
    syscall (SYS_rt_sigaction, SIGFPE, &act, NULL,		\
             stub - 8, _NSIG / 8);				\
  }								\
while (0)  
#else /* __arch64__ */

extern "C" {
    struct kernel_sigaction
    {
      void (*k_sa_sigaction)(int,siginfo_t *,void *);
      unsigned long k_sa_mask, k_sa_flags;
      void (*k_sa_restorer)(void);
    };
}

#define INIT_SEGV						\
do								\
  {								\
    struct kernel_sigaction act;				\
    nullp = new java::lang::NullPointerException ();    	\
    act.k_sa_sigaction = _Jv_catch_segv;      			\
    act.k_sa_mask = 0;						\
    act.k_sa_flags = SA_SIGINFO;	       			\
    act.k_sa_restorer = NULL;					\
    syscall (SYS_sigaction, -SIGSEGV, &act, NULL);		\
  }								\
while (0)  

#define INIT_FPE						\
do								\
  { 								\
    arithexception = new java::lang::ArithmeticException 	\
      (JvNewStringLatin1 ("/ by zero"));			\
    struct kernel_sigaction act;				\
    act.k_sa_sigaction = _Jv_catch_fpe;				\
    act.k_sa_mask = 0;						\
    act.k_sa_flags = SA_SIGINFO;		       		\
    act.k_sa_restorer = NULL;					\
    syscall (SYS_sigaction, -SIGFPE, &act, NULL);		\
  }								\
while (0)  
#endif
#elif !defined(__ia64__)
#define INIT_SEGV						\
do								\
  {								\
    nullp = new java::lang::NullPointerException ();    	\
    struct sigaction act;					\
    act.sa_sigaction = _Jv_catch_segv;      			\
    sigemptyset (&act.sa_mask);					\
    act.sa_flags = SA_SIGINFO;	       				\
    syscall (SYS_sigaction, SIGSEGV, &act, NULL);		\
  }								\
while (0)  

#define INIT_FPE						\
do								\
  { 								\
    arithexception = new java::lang::ArithmeticException 	\
      (JvNewStringLatin1 ("/ by zero"));			\
    struct sigaction act;					\
    act.sa_sigaction = _Jv_catch_fpe;				\
    sigemptyset (&act.sa_mask);					\
    act.sa_flags = SA_SIGINFO;		       			\
    syscall (SYS_sigaction, SIGFPE, &act, NULL);		\
  }								\
while (0)  

/* We use syscall(SYS_sigaction) in INIT_SEGV and INIT_FPE instead of
 * sigaction() because on some systems the pthreads wrappers for
 * signal handlers are not compiled with unwind information, so it's
 * not possible to unwind through them.  This is a problem that will
 * go away once all systems have pthreads libraries that are
 * compiled with full unwind info.  */

#else  /* __ia64__ */

// On IA64, unwind information is mandatory, so we can unwind
// correctly through glibc frames.  Thus we call the ordinary
// sigaction.

#define INIT_SEGV						\
do								\
  {								\
    nullp = new java::lang::NullPointerException ();    	\
    struct sigaction act;					\
    act.sa_sigaction = _Jv_catch_segv;      			\
    sigemptyset (&act.sa_mask);					\
    act.sa_flags = SA_SIGINFO;	       				\
    sigaction (SIGSEGV, &act, NULL);				\
  }								\
while (0)  

#define INIT_FPE						\
do								\
  { 								\
    arithexception = new java::lang::ArithmeticException 	\
      (JvNewStringLatin1 ("/ by zero"));			\
    struct sigaction act;					\
    act.sa_sigaction = _Jv_catch_fpe;				\
    sigemptyset (&act.sa_mask);					\
    act.sa_flags = SA_SIGINFO;		       			\
    sigaction (SIGFPE, &act, NULL);				\
  }								\
while (0)  
#endif /* __ia64__ || __sparc__ */
#endif /* JAVA_SIGNAL_H */
