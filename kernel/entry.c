#include "comm.h"
#include "memory.h"
#include "process.h"
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/tty.h>

#define DEVICE_NAME "JiangNight"

int dispatch_open(struct inode *node, struct file *file) { return 0; }

int dispatch_close(struct inode *node, struct file *file) { return 0; }

long dispatch_ioctl(struct file *const file, unsigned int const cmd,
                    unsigned long const arg) {
  static COPY_MEMORY cm;
  static MODULE_BASE mb;
  static char key[0x100] = {0};
  static char name[0x100] = {0};
  static bool is_verified = false;

  if (cmd == OP_INIT_KEY && !is_verified) {
  }
  switch (cmd) {
  case OP_READ_MEM: {
    break;
  }
  case OP_WRITE_MEM: {
    break;
  }
  case OP_MODULE_BASE: {
    break;
  }
  default:
    break;
  }
  return 0;
}

struct file_operations dispatch_functions = {
    .owner = THIS_MODULE,
    .open = dispatch_open,
    .release = dispatch_close,
    .unlocked_ioctl = dispatch_ioctl,
};

struct miscdevice misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &dispatch_functions,
};

int __init driver_entry(void) {
  int ret;
  return ret;
}

void __exit driver_unload(void) {}

module_init(driver_entry);
module_exit(driver_unload);

MODULE_DESCRIPTION("Linux Kernel.");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("JiangNight");
