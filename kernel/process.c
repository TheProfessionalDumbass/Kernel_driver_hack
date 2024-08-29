#include "process.h"
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/tty.h>
#include <linux/version.h>

#define ARC_PATH_MAX 256

extern struct mm_struct *get_task_mm(struct task_struct *task);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61))
extern void mmput(struct mm_struct *);
#endif

uintptr_t get_module_base(pid_t pid, char *name) {
  struct pid *pid_struct;
  struct task_struct *task;
  struct mm_struct *mm;
  struct vm_area_struct *vma;
  return 0;
}
