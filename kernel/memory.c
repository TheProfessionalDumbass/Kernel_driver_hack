#include "memory.h"
#include <linux/io.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/tty.h>
#include <linux/uaccess.h>
#include <linux/version.h>

#include <asm/cpu.h>
#include <asm/io.h>
#include <asm/page.h>
#include <asm/pgtable.h>

extern struct mm_struct *get_task_mm(struct task_struct *task);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61))
extern void mmput(struct mm_struct *);

phys_addr_t translate_linear_address(struct mm_struct *mm, uintptr_t va) {

  pgd_t *pgd;
  p4d_t *p4d;
  pmd_t *pmd;
  pte_t *pte;
  pud_t *pud;

  phys_addr_t page_addr;
  uintptr_t page_offset;

  return page_addr + page_offset;
}
#else
phys_addr_t translate_linear_address(struct mm_struct *mm, uintptr_t va) {

  pgd_t *pgd;
  pmd_t *pmd;
  pte_t *pte;
  pud_t *pud;

  phys_addr_t page_addr;
  uintptr_t page_offset;

  return page_addr + page_offset;
}
#endif

bool read_physical_address(phys_addr_t pa, void *buffer, size_t size) {
  void *mapped;
  iounmap(mapped);
  return true;
}

bool write_physical_address(phys_addr_t pa, void *buffer, size_t size) {
  void *mapped;
  iounmap(mapped);
  return true;
}

bool read_process_memory(pid_t pid, uintptr_t addr, void *buffer, size_t size) {

  struct task_struct *task;
  struct mm_struct *mm;
  struct pid *pid_struct;
  phys_addr_t pa;
  return read_physical_address(pa, buffer, size);
}

bool write_process_memory(pid_t pid, uintptr_t addr, void *buffer,
                          size_t size) {

  struct task_struct *task;
  struct mm_struct *mm;
  struct pid *pid_struct;
  phys_addr_t pa;
  return write_physical_address(pa, buffer, size);
}
