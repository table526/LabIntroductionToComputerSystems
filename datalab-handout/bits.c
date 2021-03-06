/* 
 * CS:APP Data Lab 
 * 
 * <Name: Qichen Pan	AndrewId: pqichen>
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  /* Concatenate four "0101" together */
	int fourbits = 0x55; 
	int eightbits = (fourbits << 8) + fourbits;
  int result = (eightbits << 16) + (eightbits);
	return result;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* return the ban value of x xor y */
	int result = !(x ^ y);
	return result;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	/* Step 1: get the actual postions of nth and mth bytes.
		 Step 2: get the actual values of nth and mth bytes.
		 Step 3: erase nth byte and add mth byte to that position.
		 Step 4: erase mth byte and add nth byte to that position.*/
	int nOffset = n << 3;
	int mOffset = m << 3;
	int allones = 0xff;
	int nthByte = (x & (allones << nOffset)) >> nOffset & allones;
	int mthByte = (x & (allones << mOffset)) >> mOffset & allones;
	x = x ^ (nthByte << nOffset);
	x = x + (mthByte << nOffset);
	x = x ^ (mthByte << mOffset);
	x = x + (nthByte << mOffset);
	return x;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
	/* 
	 * Step 1: get the right most bits that are rotated.
	 * Step 2: right shift x by n bits.
	 * Step 3: make left most n bits to be 0s.
	 * Step 4: add rotated bits to the left most positions.
	 * */
	int maskOnes = (1 << n) + ~1 + 1;
	int rotatedPart = x & maskOnes;
	int maskZeros = ~(maskOnes << (32 + ~n + 1));
	int result = ((x >> n) & maskZeros) + (rotatedPart << (32 + ~n + 1));
	return result;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* 
	 * Step 1: get the inverse number of x.
	 * Step 2: get the union of most significant bits of x and inverse x.
	 * Step 3: return 1 - Output from Step 2.
	 * */
	int opposite = ~x + 1;
	int flag = (1 & (x >> 31)) | (1 & (opposite >> 31));
	int result = 1 + ~flag + 1;
	return result;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	/* Get 0x7fffffff */
  int result = ~(1 << 31);
	return result;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	/*
	 * Step 1: use '!' to distinct 0 from other integers
	 * Step 2: use left most bit to distinct positive numbers from negtive numbers
	 * */				
  int flag = !!x;
  int result = ((x >> 30) & (~1)) + flag;
	return result;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	/*
	 * Step 1: diff is the value of x - y.
	 * Step 2: mask is: 1 when x is positive and y is negative;
	 										0xffffffff when x is negative and y is positive;
											0 otherwise.
	 * Step 3: flag represents diff is positive or not.
	 * Step 4: !!diff can be used to see if diff is 0.
	 */
	int diff = x + ~y + 1;
  int mask = (x >> 31) + ~(y >> 31) + 1;
	int flag = (diff >> 31) + 1;
	int result = (!!diff) & (((mask | flag) + 1) >> 1);
	return result;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  int mask = (x >> 31) + ~(y >> 31) + 1;
	int diff = x + ~y + 1;
	int flag = (diff >> 31) + 1;
	int result = !(mask & (((mask + 1) >> 1) ^ flag));
	return result;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
	/*
	 * Step 1: use flag to record overflow behavior.
	 * Step 2: flag can be used as a weight of origin sum and overflow value.
	 * Step 3: return weighted sum of origin result and maxPos or minNeg.
	 */
	int sum = x + y; 
	int SignX = (x >> 31) & 1;
	int SignY = (y >> 31) & 1;
	int SignSum = (sum >> 31) & 1;
	int flag = (((!(SignX ^ SignY)) & (SignX ^ SignSum)) << 31) >> 31;
	int result = ((~flag) & sum) + (flag & ((~(1 << 31)) + SignX));
	return result;
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
	/*
	 * Step 1: Convert negative number x to ~x. remain nonnegative number.
	 * Step 2: Judge if left-most 16bits are all 0s. If yes, result += 16, pick the left 16 bits for further calculation. Otherwise, pick the right 16bits for further calculation.
	 * Step 3: repeat doing step 2 but change the number to 8bits, 4bits, 2bits, and 1bit.
	 * Step 4: return result.
	 */
	int sign = x >> 31;
	int reverseX = ((~sign) & x) + (sign & (~x));
  int tmp = reverseX >> 16;
	int flag = ((!!(tmp)) << 31) >> 31;
	int result = 1 + (flag & 0x10);
	int remain = (flag & tmp) + ((~flag) & (reverseX));

	tmp = remain >> 8;
	flag = ((!!(tmp)) << 31) >> 31;
	result = result + (flag & 0x08);
	remain = (flag & tmp) + ((~flag) & remain);

	tmp = remain >> 4;
	flag = ((!!(tmp)) << 31) >> 31;
	result = result + (flag & 0x04);
	remain = (flag & tmp) + ((~flag) & remain);

	tmp = remain >> 2;
	flag = ((!!(tmp)) << 31) >> 31;
	result = result + (flag & 0x02);
	remain = (flag & tmp) + ((~flag) & remain);
	
	tmp = remain >> 1;
	flag = ((!!(tmp)) << 31) >> 31;
	result = result + (flag & 0x01);
	remain = (flag & tmp) + ((~flag) & remain);

	result = result + (~(result >> 5)) + 1;
  result = result + (!!x) + (!!(~x)) + (~0);
	return result;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	/*
	 * Step 1: Get exp part, fraction part, and round part(last 2-bits).
	 * Step 2: if exp == 0x00, right shift frac by 1 bit, do rounding.
	 * Step 3: if exp == 0x01, right shift frac by 1 bit, do rounding, plus 0x400000.
	 * Step 4: otherwise, exp--.
	 */
	unsigned result;
	unsigned exp = (uf & 0x7f800000) >> 23;
	unsigned frac = (uf & 0x007fffff);
	unsigned round = frac & 0x03;
	//printf("exp: %u\nfrac: %u\n",exp,frac);
	if(exp == 0x00 || exp == 0x01)
	{
		if(round == 0x03)
		{
			frac = (frac >> 1) + 1;
		}else
		{
			frac = frac >> 1;
		}
		if(exp == 0x01)
		{
			frac = 0x400000 + frac;
		}
		result = (uf & 0x80000000) + frac;
	}else if(exp == 0xff)
	{
		return uf;
	}else{
		exp = exp - 1;
		result = (uf & 0x807fffff) + (exp << 23);
	}
	//printf("result: %u\n", result);
	return result;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  /*
	 * Step 1: get sign, exp, frac parts respectively.
	 * Step 2: calculate the actual offset that frac needs to be shifted.
	 * Step 3: take overflow into consideration.
	 */
	unsigned result;
	unsigned sign = uf >> 31;
	unsigned exp = (uf & 0x7f800000) >> 23;
	unsigned frac = (uf & 0x007fffff);
	unsigned offset = exp - 150;
	unsigned offset_sign = offset >> 31;
	if(exp != 0x00)
	{
		frac = frac | 0x00800000;				
	}
	if(offset_sign == 0)
	{
		if(offset < 8)
		{
			result = frac << offset;
		}else
		{
			result = 0x80000000;
		}
	}else 
	{
		if(((~offset) + 1) < 24)
		{
			result = frac >> ((~offset) + 1);				
		}else
		{
			result = 0x00;
		}
	}
	if(sign == 0x01)
	{
		result = ~result + 1;
	}
	return result;
}

