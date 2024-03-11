#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TMin LONG_MIN
#define TMax LONG_MAX

#include "bits.h"
#include "btest.h"

test_rec test_set[] = {
//1
 {"bitMatch", (funct_t) bitMatch, (funct_t) test_bitMatch, 2, "& | ~", 14, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//2
 {"leastBitPos", (funct_t) leastBitPos, (funct_t) test_leastBitPos, 1, "! ~ & ^ | + << >>", 6, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"dividePower2", (funct_t) dividePower2, (funct_t) test_dividePower2, 2,
    "! ~ & ^ | + << >>", 15, 2,
  {{TMin, TMax},{0,62},{TMin,TMax}}},
 {"implication", (funct_t) implication, (funct_t) test_implication, 2, "! ~ ^ |", 5, 2,
     {{0,1},{0,1},{TMin,TMax}}},
 {"oddBits", (funct_t) oddBits, (funct_t) test_oddBits, 0,
    "! ~ & ^ | + << >>", 8, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//3
 {"rotateLeft", (funct_t) rotateLeft, (funct_t) test_rotateLeft,
   2, "! ~ & ^ | + << >>", 25, 3,
  {{TMin, TMax},{0,63},{TMin,TMax}}},
 {"isLess", (funct_t) isLess, (funct_t) test_isLess, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"replaceByte", (funct_t) replaceByte, (funct_t) test_replaceByte, 3,
    "! ~ & ^ | + << >>", 10, 3,
  {{TMin, TMax},{0,3},{0,255}}},
 {"conditional", (funct_t) conditional, (funct_t) test_conditional, 3, "! ~ & ^ | << >>", 16, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//4
 {"leftBitCount", (funct_t) leftBitCount, (funct_t) test_leftBitCount, 1, "! ~ & ^ | + << >>", 60, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"trueThreeFourths", (funct_t) trueThreeFourths, (funct_t) test_trueThreeFourths, 1,
    "! ~ & ^ | + << >>", 20, 4,
  {{TMin,TMax},{TMin,TMax},{TMin,TMax}}},
 {"howManyBits", (funct_t) howManyBits, (funct_t) test_howManyBits, 1, "! ~ & ^ | + << >>", 70, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{
    "", NULL, NULL, 0, "", 0, 0, {
        {0, 0}, {0, 0}, {
            0, 0
        }
    }
}
}
;
