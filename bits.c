/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return (~(x&y)&~(~x&~y));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if (!x)
    {
        if(!y)
        {
            return 1;
        }
        else
            return 0;
    }
    else
    {
        if(!y)
        {
            return 0;
        }
        else
        {
            return !(x>>31 ^ y>>31);
        }
    }
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int cnt=0,k=((v>0xFFFF)<<4);
    cnt=cnt|k;
    v=v>>k;
    cnt=cnt|((v>0xFF)<<3);
    v=v>>((v>0xFF)<<3);
    cnt=cnt|((v>15)<<2);
    v=v>>((v>15)<<2);
    cnt=cnt|((v>3)<<1);
    v=v>>((v>3)<<1);
    cnt=cnt|(v>1);
    return cnt;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int M=m<<3,N=n<<3;
    int s=(x>>M)&0xFF;
    int t=(x>>N)&0xFF;
    int k=s^t;
    x=((k<<M)+(k<<N))^x;
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v=((v>>1)&0x55555555)|((v&0x55555555)<<1);
    v=((v>>2)&0x33333333)|((v&0x33333333)<<2);
    v=((v>>4)&0x0F0F0F0F)|((v&0x0F0F0F0F)<<4);
    v=((v>>8)&0x00FF00FF)|((v&0x00FF00FF)<<8);
    v=(v>>16)|(v<<16);
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    x=(x>>n)&(0xFFFFFFFF>>n);
    return x;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int s=0;
    int cnt=0;
    s=(!(~(x>>16)))<<4;
    cnt=cnt+s;
    x=x<<s;
    s=(!(~(x>>24)))<<3;
    cnt=cnt+s;
    x=x<<s;
    s=(!(~(x>>28)))<<2;
    cnt=cnt+s;
    x=x<<s;
    s=(!(~(x>>30)))<<1;
    cnt=cnt+s;
    x=x<<s;
    s=(!(~(x>>31)))<<0;
    cnt=cnt+s;
    x=x<<s;
    cnt=cnt+!(~(x>>31));
    return cnt;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    if(!x)
    {
        return 0;
    }
    if(x==0x80000000)
    {
        return 0xcf000000;
    }
    int t=x&0x80000000;
    if(x<0)
    {
        x=~x+1;
    }
    x=x<<1;
    int cnt=1;
    while((!(x&0x80000000))&(cnt<32))
    {
        x=x<<1;
        cnt=cnt+1;
    }
    int X=(x>>8)&0x7FFFFF;
    if((x&0xFF)>0x80)
    {
        X=X+1;
    }
    else if((x&0xFF)==0x80)
    {
        if(X&1)
        {
            X=X+1;
        }
    }
    return (t|((31-cnt+127)<<23))+X;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    if(uf==0)
    {
        return 0;
    }
    if(uf==0x80000000)
    {
        return 0x80000000;
    }
    int a=uf&0x80000000,b=uf&0x7f800000,c=uf&0x007fffff;
    if(b==0)
    {
        if(c>=0x400000)
        {
            c=(c<<1)&0x7fffff;
            b=(1<<23);
        }
        else
        {
            c=(c<<1);
        }
    }
    else
    {
        if(b==0xff)
        {
            return uf;
        }
        else
        {
            if(b<0x7f800000)
            {
                b=b+(1<<23);
            }
        }
    }
    int ans=((a|b)|c);
    return ans;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int fu=uf2&0x80000000,ans=0;
    int mi=((uf2>>20)&0x7ff);
    mi=mi-1023;
    if(mi<0)
    {
        return 0;
    }
    else
    {
        if(mi<=30)
        {
            int k=((1<<mi)|(((uf2<<12)>>(31-mi))>>1));
            if(mi<=20)
            {
                ans=k;
            }
            else
            {
                ans=(k|(uf1>>(52-mi)));
            }
        }
        else
        {
            return 0x80000000;
        }
    }
    if(fu)
    {
        return(~ans+1);
    }
    else
    {
        return ans;
    }
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
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x>=128)
    {
        return 0x7f800000;
    }
    else
    {
        if(x>=-126)
        {
            return((x+127)<<23);
        }
        else
        {
            if(x>=-149)
            {
                return(1<<(x+149));
            }
            else
            {
                return 0;
            }
        }
    }
}
