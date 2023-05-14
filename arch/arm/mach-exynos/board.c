#include <common.h>
#include <config.h>
#include <asm/io.h>

void s_init(void)
{
   /* led test */
   writel(0x10, 0x11000060);
   writel(0x2, 0x11000064);

   writel(0x1, 0x11000100);
   writel(0x1, 0x11000104);
}
