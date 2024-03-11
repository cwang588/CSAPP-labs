/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * @author Fulun Ma <fulunm@andrew.cmu.edu>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Instructions to Students:

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  long Funct(long arg1, long arg2, ...) {
      // brief description of how your implementation works
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  2. Function arguments and local variables (no global variables).
  3. Local variables of type int and long
  4. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  5. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  6. Casting from int to long and from long to int

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  //
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
  //
  long pow2plus1(long x) {
     // exploit ability of shifts to compute powers of 2
     // Note that the 'L' indicates a long constant
     return (1L << x) + 1L;
  }

  //
  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
  //
  long pow2plus4(long x) {
     // exploit ability of shifts to compute powers of 2
     long result = (1L << x);
     result += 4L;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

CAUTION:
  Do not add an #include of <stdio.h> (or any other C library header)
  to this file.  C library headers almost always contain constructs
  that dlc does not understand.  For debugging, you can use printf,
  which is declared for you just below.  It is normally bad practice
  to declare C library functions by hand, but in this case it's less
  trouble than any alternative.

  dlc will consider each call to printf to be a violation of the
  coding style (function calls, after all, are not allowed) so you
  must remove all your debugging printf's again before submitting your
  code or testing it with dlc or the BDD checker.  */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 1
/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7L, 0xEL) = 0xFFFFFFFFFFFFFFF6L
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
long bitMatch(long x, long y) {
    // long a = x & y;
    // long b = (~x) & (~y);
    // return ~((~a) & (~b));
   return ~(~(x&y)&~((~x)&(~y)));
}
// 2
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96L) = 0x20L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
long leastBitPos(long x) {
    return x & ((~x) + 1);
}
/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {
    // long a = (x >> (0x3f)) & 1L;
    // long b = x & ((1L << n) + ~(0x00L));
    // return (x >> n) + (a & (!!b));

    return (x>>n)+!!((x>>63)&(x&((1l<<n)+(~0))));
}
/*
 * implication - given input x and y, which are binary
 * (taking  the values 0 or 1), return x -> y in propositional logic -
 * 0 for false, 1 for true
 *
 * Below is a truth table for x -> y where A is the result
 *
 * |-----------|-----|
 * |  x  |  y  |  A  |
 * |-----------|-----|
 * |  1  |  1  |  1  |
 * |-----------|-----|
 * |  1  |  0  |  0  |
 * |-----------|-----|
 * |  0  |  1  |  1  |
 * |-----------|-----|
 * |  0  |  0  |  1  |
 * |-----------|-----|
 *
 *
 *   Example: implication(1L,1L) = 1L
 *            implication(1L,0L) = 0L
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
long implication(long x, long y) {
    return (!x) | y;
}
/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
long oddBits(void) {
    long a = 0xaaL;
    a = a | (a << 8);
    a = a | (a << 16);
    a = a | (a << 32);
    return a;
}
// 3
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
    long a = x << n;
    long b = 64L + (~n) + 1L;
    long c = (x >> b) & ((1L << n) + ~(0x00L));
    return a | c;
}
/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4L,5L) = 1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
long isLess(long x, long y) {
    long a = x + (~y) + 1L;
    long b = (a >> 63L);
    long c = (x >> 63L);
    long d = (~(y >> 63L));
    long e = c & d;
    long f = c | d;
    return (b | e) & f & 1L;
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 7 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 7 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
long replaceByte(long x, long n, long c) {
    long a = n << 3L;
    long b = ~(0xffL << a);
    long d = c << a;
    long e = (x & b) | d;
    return e;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4L,5L) = 4L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long conditional(long x, long y, long z) {
    long a = ~(!!x) + 1L;
    return (y & a) | (z & ~a);
}
// 4
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1L) = 64L, leftBitCount(0xFFF0F0F000000000L) = 12L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
long leftBitCount(long x) {
    long ans = 0L;

    long mask_64 = ~(0L);
    long has_64 = !(x ^ mask_64);
    long has_64_mask = (~has_64) + 1L;

    long mask_32 = mask_64 << 32L;
    long has_32 = !((x & mask_32) ^ mask_32);
    long zero_or_32 = ((~has_32) + 1L) & 32L;
    ans = ans + zero_or_32;
    x = x << zero_or_32;

    long mask_16 = mask_32 << 16L;
    long has_16 = !((x & mask_16) ^ mask_16);
    long zero_or_16 = ((~has_16) + 1L) & 16L;
    ans = ans + zero_or_16;
    x = x << zero_or_16;

    long mask_8 = mask_16 << 8L;
    long has_8 = !((x & mask_8) ^ mask_8);
    long zero_or_8 = ((~has_8) + 1L) & 8L;
    ans = ans + zero_or_8;
    x = x << zero_or_8;

    long mask_4 = mask_8 << 4L;
    long has_4 = !((x & mask_4) ^ mask_4);
    long zero_or_4 = ((~has_4) + 1L) & 4L;
    ans = ans + zero_or_4;
    x = x << zero_or_4;

    long mask_2 = mask_4 << 2L;
    long has_2 = !((x & mask_2) ^ mask_2);
    long zero_or_2 = ((~has_2) + 1L) & 2L;
    ans = ans + zero_or_2;
    x = x << zero_or_2;

    return (has_64_mask & 64L) |
           ((~has_64_mask) & (ans + (!!(x & (1L << 63)))));
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no
 * overflow) Legal ops: ! ~ & ^ | + << >> Max ops: 20 Rating: 4
 */
long trueThreeFourths(long x) {
    long t = x >> 1;
    long d = (x >> (0x3f)) & 1L;
    long a = x & t & 1L;
    long b = t + (t >> 1) + (a & (~d));
    long c = ((x & 1L) & d) + (((x >> 1) & 1) & d);
    return b + c;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12L) = 5L
 *            howManyBits(298L) = 10L
 *            howManyBits(-5L) = 4L
 *            howManyBits(0L)  = 1L
 *            howManyBits(-1L) = 1L
 *            howManyBits(0x8000000000000000L) = 64L
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 70
 *  Rating: 4
 */
long howManyBits(long x) {
    long a = (x >> (0x3f)) & 1L;
    long b = (~a) + 1;
    long c = (b & x) | ((~b) & (~x));
    x = c;

    long ans = 0L;

    long mask_64 = ~(0L);
    long has_64 = !(x ^ mask_64);
    long has_64_mask = (~has_64) + 1L;

    long mask_32 = mask_64 << 32L;
    long has_32 = !((x & mask_32) ^ mask_32);
    long zero_or_32 = ((~has_32) + 1L) & 32L;
    ans = ans + zero_or_32;
    x = x << zero_or_32;

    long mask_16 = mask_32 << 16L;
    long has_16 = !((x & mask_16) ^ mask_16);
    long zero_or_16 = ((~has_16) + 1L) & 16L;
    ans = ans + zero_or_16;
    x = x << zero_or_16;

    long mask_8 = mask_16 << 8L;
    long has_8 = !((x & mask_8) ^ mask_8);
    long zero_or_8 = ((~has_8) + 1L) & 8L;
    ans = ans + zero_or_8;
    x = x << zero_or_8;

    long mask_4 = mask_8 << 4L;
    long has_4 = !((x & mask_4) ^ mask_4);
    long zero_or_4 = ((~has_4) + 1L) & 4L;
    ans = ans + zero_or_4;
    x = x << zero_or_4;

    long mask_2 = mask_4 << 2L;
    long has_2 = !((x & mask_2) ^ mask_2);
    long zero_or_2 = ((~has_2) + 1L) & 2L;
    ans = ans + zero_or_2;
    x = x << zero_or_2;

    long res = (has_64_mask & 64L) |
           ((~has_64_mask) & (ans + (!!(x & (1L << 63)))));

    return 66L + (~res);
}
