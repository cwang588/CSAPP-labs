/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
    union {
        unsigned u;
        float f;
    } a;
    a.u = u;
    return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
    union {
        unsigned u;
        float f;
    } a;
    a.f = f;
    return a.u;
}
//1
long test_bitMatch(long x, long y)
{
    int i;
    long result = 0;
    for (i = 0; i < 64; i++) {
        long mask = 1L << i;
        long bit = (x & mask) == (y & mask);
        result |= bit << i;
    }
    return result;
}
//2
long test_leastBitPos(long x) {
  long mask = 1L;
  if (x == 0)
    return 0;
  while (!(mask & x)) {
    mask = mask << 1;
  }
  return mask;
}
long test_dividePower2(long x, long n)
{
    long p2n = 1L<<n;
    return x/p2n;
}
long test_implication(long x, long y)
{
  return !(x && (!y));
}
long test_oddBits(void) {
  long result = 0;
  long i;
  for (i = 1; i < 64; i+=2)
    result |= 1L<<i;
  return result;
}
//3
long test_rotateLeft(long x, long n) {
  unsigned long u = (unsigned long) x;
  long i;
  for (i = 0; i < n; i++) {
      unsigned long msb = u >> 63;
      unsigned long rest = u << 1;
      u = rest | msb;
  }
  return (long) u;
}
long test_isLess(long x, long y)
{
    return (long) (x < y);
}
long test_replaceByte(long x, long n, long c)
{
    switch(n) {
    case 0:
      x = (x & 0xFFFFFFFFFFFFFF00L) | c;
      break;
    case 1:
      x = (x & 0xFFFFFFFFFFFF00FFL) | (c << 8);
      break;
    case 2:
      x = (x & 0xFFFFFFFFFF00FFFFL) | (c << 16);
      break;
    case 3:
      x = (x & 0xFFFFFFFF00FFFFFFL) | (c << 24);
      break;
    case 4:
      x = (x & 0xFFFFFF00FFFFFFFFL) | (c << 32);
      break;
    case 5:
      x = (x & 0xFFFF00FFFFFFFFFFL) | (c << 40);
      break;
    case 6:
      x = (x & 0xFF00FFFFFFFFFFFFL) | (c << 48);
      break;
    default:
      x = (x & 0x00FFFFFFFFFFFFFFL) | (c << 56);
      break;
    }
    return x;
}
long test_conditional(long x, long y, long z)
{
  return x?y:z;
}
//4
long test_leftBitCount(long x) {
  long result = 0;
  long i;
  for (i = 63; i >= 0; i--) {
      long bit = (x >> i) & 0x1;
      if (!bit)
          break;
      result ++;
  }
  return result;
}
long test_trueThreeFourths(long x)
{
  return (long) (((__int128) x * 3L)/4L);
}
long test_howManyBits(long x) {
    long cnt;
    if (x < 0)
        /* Flip the bits if x is negative */
        x = ~x;
    unsigned long a = (unsigned long) x;
    for (cnt=1; a; a>>=1, cnt++)
        ;
    return cnt;
}
