#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

static void flip3(uint8_t* p, size_t n)
{
  static const uint8_t masks[3] = { 0x24, 0x92, 0x49 };

  size_t i;

  for (i = 0; i < n; ++i)
  {
    const uint8_t m = masks[i % 3];
    const uint8_t x = p[i];
    p[i] ^= m;
  }
}

int main(int ac, char** av)
{
  /* uint8_t s[4] = { 0x24, 0x92, 0x49, 0x24 }; */
  uint8_t s[4] = { 0x00, 0x00, 0x00, 0x00 };
  flip3(s, sizeof(s));
  return 0;
}
