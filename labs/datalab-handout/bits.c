/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


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

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x&~y)&~(x&y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // 步骤1：计算x+1（Tmax+1=Tmin，其他数则无此特征）
    int x_plus_1 = x + 1;
    // 步骤2：验证x+1的取反是否等于x（Tmax的核心特征）
    int check1 = ~x_plus_1;
    int is_equal = !(check1 ^ x);  // 异或为0则相等，!后为1
    // 步骤3：排除x=-1的情况（x=-1时x+1=0，~0=全1=x，但x不是Tmax）
    int is_not_neg1 = !!x_plus_1;  // x+1=0时!为1，!!为0；否则为1
    // 最终结果：同时满足两个条件才是Tmax
    return is_equal & is_not_neg1;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    int mask = 0xAA+(0xAA<<8);
     mask=mask+(mask<<16);
     return !((mask&x)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 步骤1：计算 x - 0x30（判断是否 ≥ 0x30）
    int lower = x + (~0x30 + 1);  // 等价于 x - 0x30（补码减法：a-b = a + (~b +1)）
    // 步骤2：计算 0x39 - x（判断是否 ≤ 0x39）
    int upper = 0x39 + (~x + 1);  // 等价于 0x39 - x
    // 步骤3：判断 lower 和 upper 的最高位是否为0（正数/0）
    // 32位整数最高位是第31位，右移31位后：正数→0，负数→0xffffffff（全1）
    int lower_non_neg = !(lower >> 31);  // 1表示x≥0x30，0表示x<0x30
    int upper_non_neg = !(upper >> 31);  // 1表示x≤0x39，0表示x>0x39
    // 步骤4：两个条件同时满足则返回1
    return lower_non_neg & upper_non_neg;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    x = !!x;
    x = ~x+1;
    return (x&y)|(~x&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // 步骤1：计算 y - x = y + (~x + 1)（补码减法）
    int neg_x = ~x + 1;       // -x 的补码表示
    int diff = y + neg_x;     // y - x 的结果
    
    // 步骤2：获取diff的符号位（31位，补码最高位为符号位）
    int sign = diff >> 31;    // 符号位右移到最低位（正数为0，负数为-1）
    
    // 步骤3：符号位取反后，用!转成布尔值（0→1，-1→0）
    return !sign;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // 步骤1：计算 -x（补码中 -x = ~x + 1）
    int neg_x = ~x + 1;
    // 步骤2：x | -x 得到结果（非0数符号位为1，0的符号位为0）
    int or_result = x | neg_x;
    // 步骤3：右移31位取符号位（1→-1，0→0），再加1后与1按位与（限制结果为0/1）
    return (or_result >> 31) + 1 & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 步骤1：处理符号，负数取反（统一转为找最高位1的问题）
    int sign = x >> 31;          // 符号位：0(正) / -1(负)
    int x_abs = (sign & ~x) | (~sign & x); // 正数不变，负数取反（等价于abs(x)的位运算）
    
    // 步骤2：二分法找最高位1的位置（从16位开始，逐步缩小）
    int bit16, bit8, bit4, bit2, bit1;
    
    // 检查高16位是否有1，有则右移16位，记录偏移量
    bit16 = !!(x_abs >> 16) << 4; // 有1则bit16=16，否则0
    x_abs = x_abs >> bit16;       // 右移16位（仅高16位有1时生效）
    
    // 检查高8位是否有1
    bit8 = !!(x_abs >> 8) << 3;   // 有1则bit8=8，否则0
    x_abs = x_abs >> bit8;
    
    // 检查高4位是否有1
    bit4 = !!(x_abs >> 4) << 2;   // 有1则bit4=4，否则0
    x_abs = x_abs >> bit4;
    
    // 检查高2位是否有1
    bit2 = !!(x_abs >> 2) << 1;   // 有1则bit2=2，否则0
    x_abs = x_abs >> bit2;
    
    // 检查高1位是否有1
    bit1 = !!(x_abs >> 1);        // 有1则bit1=1，否则0
    x_abs = x_abs >> bit1;
    
    // 步骤3：计算总偏移量（最高位1的位置）
    int total_shift = bit16 + bit8 + bit4 + bit2 + bit1 + x_abs;
    
    // 步骤4：总位数=偏移量+1（符号位），0的情况单独处理（total_shift=0时返回1）
    return total_shift + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 提取符号位、指数位、尾数位
    unsigned sign = uf & 0x80000000;  // 符号位：第31位
    unsigned exp = uf & 0x7F800000;   // 指数位：第30~23位
    unsigned frac = uf & 0x007FFFFF;  // 尾数位：第22~0位

    // 情况1：NaN 或无穷大（exp=0xFF，即255），直接返回原数
    if (exp == 0x7F800000) {
        return uf;
    }

    // 情况2：非规格化数（exp=0），尾数位左移1位（等价于乘以2）
    if (exp == 0) {
        frac <<= 1;
        // 左移后若尾数位溢出（最高位为1），需将溢出位并入指数位（变为规格化数）
        // 例如：frac=0x007FFFFF <<1 = 0x00FFFFFE，无溢出；若frac=0x00400000<<1=0x00800000，溢出到exp
        if (frac & 0x00800000) {
            exp = 0x00800000;  // 指数位变为1（0x00800000对应exp=1）
            frac &= 0x007FFFFF;// 尾数位清空溢出位
        }
    } 
    // 情况3：规格化数（0 < exp < 255），指数位+1
    else {
        exp += 0x00800000;  // 指数位每加1，对应真实指数+1（0x00800000是exp位的1个单位）
        // 若加1后exp变为255（无穷大），清空尾数位（符合IEEE 754规范）
        if (exp == 0x7F800000) {
            frac = 0;
        }
    }

    // 拼接符号位、指数位、尾数位，返回结果
    return sign | exp | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // 提取符号位、指数位、尾数位
    unsigned sign = uf & 0x80000000;   // 符号位：1位（31位）
    unsigned exp = (uf >> 23) & 0xFF;  // 指数位：8位（30~23位）
    unsigned frac = uf & 0x007FFFFF;   // 尾数位：23位（22~0位）
    
    // 计算真实指数（exp_bias = exp - 127）
    int exp_bias = exp - 127;
    
    // 情况1：超出范围（指数过大/过小、NaN、无穷大）
    // 1. 指数 < 0 → 数值在(-1,1)之间，转整数为0？不，先判断范围；
    // 2. 指数 >= 31 → 超过int最大值(2^31-1)；
    // 3. exp=255 → NaN或无穷大；
    if (exp == 0xFF || exp_bias >= 31) {
        return 0x80000000u;
    }
    if (exp_bias < 0) {
        return 0;  // 数值在(-1,1)之间，转整数为0
    }
    
    // 情况2：有效范围，构造尾数（1 + frac/2^23）
    unsigned mantissa = frac | 0x00800000;  // 补上隐含的前导1（23位→24位）
    
    // 调整尾数：根据指数偏移量移位
    if (exp_bias > 23) {
        // 指数偏移量 > 尾数位长度 → 尾数左移（exp_bias - 23）位
        mantissa <<= (exp_bias - 23);
    } else {
        // 指数偏移量 ≤ 尾数位长度 → 尾数右移（23 - exp_bias）位（截断小数）
        mantissa >>= (23 - exp_bias);
    }
    
    // 处理符号：负数则取反，正数直接保留
    if (sign) {
        mantissa = ~mantissa + 1;  // 补码取反（负数）
    }
    
    // 最终检查：若符号位为1且数值为0x80000000（即-2^31），合法；否则返回结果
    return mantissa;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
// 定义关键常量
    unsigned sign = 0;                  // 2^x恒为正数，符号位为0
    unsigned inf = 0x7F800000;          // 正无穷的位模式
    int exp_bias = 127;                 // 单精度浮点数指数偏移量
    int max_exp = 254;                  // 规格化数最大指数（255为无穷大）
    int min_denorm_exp = -149;          // 非规格化数最小可表示指数（2^-149）

    // 情况1：结果过大，返回正无穷
    if (x > max_exp - exp_bias) {       // x > 254-127 → x > 127
        return inf;
    }

    // 情况2：结果过小，返回0
    if (x < min_denorm_exp) {           // x < -149
        return 0;
    }

    // 情况3：非规格化数（-148 ≤ x ≤ -127）
    if (x < -exp_bias + 1) {            // x < -126 → 指数位无法表示为规格化数
        // 非规格化数：指数位为0，尾数 = 1 << (x - min_denorm_exp)
        int shift = x - min_denorm_exp;
        unsigned frac = 1 << shift;
        return sign | 0 | frac;         // 指数位0，拼接符号位和尾数位
    }

    // 情况4：规格化数（-126 ≤ x ≤ 127）
    unsigned exp = (x + exp_bias) << 23;// 指数位左移23位（放到30~23位）
    return sign | exp | 0;              // 尾数位0，拼接符号位和指数位
}
