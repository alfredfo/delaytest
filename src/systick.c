#include "systick.h"

enum {
  B_ENABLE = 1 << 0,
  B_TICKINT = 1 << 1,
  B_CLKSOURCE = 1 << 2,
  B_COUNTFLAG = 1 << 16
};

void delay_250ns(struct systick *stk) {
  stk->ctrl = 0;
  stk->load = 42;
  stk->val = 0;
  stk->ctrl |= (B_ENABLE | B_CLKSOURCE);
  while ((stk->ctrl & 0x10000) == 0)
    ;
  stk->ctrl = 0;
}

void delay_micro(struct systick *stk, unsigned int us) {
  for (int i = 0; i < us; i++) {
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
  }
}

void delay_milli(struct systick *stk, unsigned int ms) {
  for (int i = 0; i < ms; i++) {
    delay_micro(stk, 1000);
  }
}
