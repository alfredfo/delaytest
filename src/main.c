#include "board-constants.h"
#include "gpio.h"
#include "systick.h"

int main() {
  struct gpio *gpio_e = (struct gpio *)GPIO_E_ADDR;
  struct systick *stk = (struct systick *)SYSTICK_ADDR;

  gpio_e->moder = 0x55555555;
  gpio_e->odr.l = 0x55;
  delay_250ns(stk);
  gpio_e->odr.l = 0xFF;
  delay_milli(stk, 1);
  gpio_e->odr.l = 0x00;
  delay_milli(stk, 100000);
  gpio_e->odr.l = 0xF0;

  return 0;
}
