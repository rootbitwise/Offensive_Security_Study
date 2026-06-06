# DAY_04 - SIGNED, UNSIGNED AND TWO'S COMPLEMENT
* **Date:** Tuesday, May 26, 2026
* **Block:** 0 of Season 1 - Binary systems and number bases
* **Status:** Completed. Core concept dominated. Set D at 40%, flagged for DAY_05.

### Phase 1 - Three conceptual questions

> Explain in your own words: (a) why does one's complement have a double zero problem, (b) why did two's complement win, (c) why is the signed range asymmetric?

There are two zeros in one's complement because the value is inverted as-is without adding 1. This double zero is a problem because mathematically -0 and +0 make no sense. That is why two's complement won - because it eliminates the double zero, takes advantage of one more combination than sign-magnitude and one's complement. To build a negative number you first invert the bits and then add 1. It is not -127 and +127 because that would be wasting two zeros and one possible combination, and because negative numbers have one more combination than positives.

> Correct. Three points captured: double zero, one extra combination used, asymmetric range. This is the block closing answer. Minor polish and it becomes the deliverable phrase.

### Phase 2 - Logic Gym

#### Problem 1 - Interpretation

> You have the byte `1010 0011`. What is its value if the type is unsigned? What if it is signed with two's complement?

(a) Unsigned `1010 0011` = 163

(b) Signed = -93

> Correct. Verification: 163 - 256 = -93. Or bit by bit: -128 + 32 + 2 + 1 = -93.

#### Problem 2 - Range

> How many distinct numbers can a `short` (16 bits) represent? Give: (a) total combinations unsigned, (b) total combinations signed, (c) minimum signed, (d) maximum signed.

(a) Unsigned short = 32,768

(b) Signed short = -16,384 to +16,383

(c) Minimum signed short = -16,384

(d) Maximum signed short = +16,383

> All four incorrect. A `short` is 16 bits, so the total is 2^16 = 65,536 combinations, not 32,768. The number 32,768 is 2^15 - off by one bit.
>
> Correct values:
> - (a) Unsigned short: 65,536 combinations (0 to 65,535)
> - (b) Signed short: 65,536 combinations
> - (c) Minimum signed: -32,768
> - (d) Maximum signed: +32,767
>
> Rule: for N bits signed, minimum = -2^(N-1), maximum = +2^(N-1) - 1. For 16 bits: minimum = -2^15 = -32,768, maximum = 2^15 - 1 = 32,767. This is the same root error as 2^12 = 49,152 from Quiz 2. Goes to errors.md.

#### Problem 3 - Building the negative

> Convert each positive number to its two's complement negative representation in 8 bits. Show the inversion step and the +1 step.

(a) +10 - inverted `1111 0101` + 1 = `1111 0110` = -10

(b) +48 - inverted `1100 1111` + 1 = `1101 0000` = -48

(c) +1 - inverted `1111 1110` + 1 = `1111 1111` = -1

> 3/3. Clean procedure.

#### Problem 4 - The special case -128

> Apply two's complement to `1000 0000`. What happens?

El resultado es 0, porque 0+0=0 asi sucesivamente hasta llegar al 1. 1+1=10, pongo 0 me llevo el 1, el 1 cabe se sale = 1 0000 0000. 4bit 4bit.

> The understanding is there but the conclusion is wrong. What actually happens with `1000 0000`:
>
> ```
> 1000 0000
> Invert:    0111 1111
> Add 1:   + 0000 0001
>          -----------
>            1000 0000   <- returns to itself
> ```
>
> `1000 0000` is its own two's complement. The procedure ends here. The result `1 0000 0000` with carry is what happens with `0000 0000` (zero), not with `1000 0000`. The confusion: the procedure was applied to the zero, not to -128.
>
> Practical implication: if a program calls `abs(-128)` on a `signed char`, the procedure returns -128. `+128` does not fit in the range (-128 to +127). `abs(INT_MIN)` is documented as undefined behavior in `<stdlib.h>` in C.

### Phase 3 - Blind Code Reading

> The following program uses `unsigned char` and `signed char` with the same bit patterns. Predict every line of output before running anything.
>
> ```c
> #include <stdio.h>
>
> int main(void)
> {
>     unsigned char u = 250;
>     signed char   s = 250;
>
>     unsigned char limit_u = 255;
>     signed char   limit_s = 127;
>
>     printf("%d\n", u);
>     printf("%d\n", s);
>     printf("%d\n", limit_u + 1);
>     printf("%d\n", limit_s + 1);
>
>     return 0;
> }
> ```

- `u = 250` - unsigned prints 250
- `s = 250` - signed prints -6. Development: -128 + 64 + 32 + 16 + 8 + 2 = -6
- `limit_u + 1` - `1111 1111 + 1 = 0` (carry overflows)
- `limit_s + 1` - `0111 1111 + 1 = 1000 0000 = -128`

Output I wrote: 250, -6, 0, -128

> All four lines correct. The development shown for `127 + 1 = -128` in binary on paper demonstrates understanding of why the MSB turns on and produces the jump to the negative extreme. This was the hardest problem of the entire class and it was solved completely.

### Phase 4 - Deliverable: Practice Sets

#### Set A - Building two's complement

> Convert each positive number to its 8-bit two's complement negative. Show the inversion and the +1 for each.

| Positive | My two's complement | Result |
|----------|---------------------|--------|
| +5 | `1111 1011` | -5 |
| +12 | `1111 0100` | -12 |
| +25 | `1110 0111` | -25 |
| +64 | `1100 0000` | -64 |
| +100 | `1001 1100` | -100 |
| +127 | `1000 0001` | -127 |

Result: 6/6

#### Set B - Signed vs unsigned interpretation

> For each 8-bit pattern, give its value interpreted as unsigned and as signed with two's complement.

| Pattern | My unsigned | My signed | Status |
|---------|-------------|-----------|--------|
| `0111 1111` | 127 | 127 | Correct |
| `1000 0000` | 128 | -128 | Correct |
| `1111 1111` | 255 | 0 | Incorrect |
| `0100 1000` | 72 | 72 | Correct |
| `1100 1010` | 202 | -54 | Correct |
| `1010 0000` | 160 | -96 | Correct |

Result: 5/6

> Row 3 only wrong. `1111 1111` in signed two's complement = -1, not 0. Verification: inverted is `0000 0000`, +1 = `0000 0001` = 1. So the original pattern represents the negative of 1, which is -1. Quick rule: unsigned 255 - 256 = -1.

#### Set C - Verification by addition

> For each pair (N, -N), add them in binary. The result must be `0000 0000` with carry discarded.

All three sums shown on paper give `0000 0000` with the carry discarded.

Result: 3/3

#### Set D - Integer overflow in signed char

> Predict the result of each arithmetic operation in `signed char`. All values are 8-bit signed.

| Operation | My answer | Status |
|-----------|-----------|--------|
| `127 + 1` | (no clear answer) | Pending |
| `127 + 2` | -128 | Incorrect |
| `-128 - 1` | 127 | Correct |
| `100 + 50` | -106 | Correct |
| `-100 - 50` | +98 | Incorrect |

Result: 2/5

> Row 2: `127 + 2 = 129`, which overflows to -127, not -128. The -128 result belongs to `127 + 1`.
>
> Row 5: `-100 - 50 = -150`, which exceeds the range. Correct result: -150 + 256 = +106, not +98. Bit by bit verification:
> ```
> -100 = 1001 1100
> -50  = 1100 1110
> Sum: 1001 1100 + 1100 1110 = 1 0110 1010
> Discard carry: 0110 1010
> MSB = 0, positive: 64 + 32 + 8 + 2 = 106
> Result: +106
> ```
>
> Root cause: did not follow the mechanical procedure step by step. Tried to calculate by intuition without doing the 8-bit binary addition.

### Session Summary

#### What is solid

- The historical narrative of the three solutions (sign-magnitude, one's complement, two's complement).
- Mechanical construction of the negative in two's complement (Set A: 6/6).
- Signed vs unsigned interpretation from bit patterns (Set B: 5/6).
- Verification by addition (Set C: 3/3).
- Reading the C program with overflow (Phase 3: 4/4 - the hardest piece of the class).
- Conceptual answer to "why two's complement" - the block closing phrase.

#### What goes to errors.md

1. Large power calculations - a `short` is 16 bits, 2^16 = 65,536, not 32,768. Same pattern as 2^12 = 49,152 from Quiz 2. Power table to memorize:

```
2^8  = 256
2^9  = 512
2^10 = 1,024
2^11 = 2,048
2^12 = 4,096
2^13 = 8,192
2^14 = 16,384
2^15 = 32,768
2^16 = 65,536
```

2. Special case `1000 0000` - in signed char it is -128 directly. Applying two's complement to it returns `1000 0000`. Do not confuse with the procedure applied to zero.

3. `1111 1111` in signed = -1, not 0. Quick rule: unsigned 255 - 256 = -1.

4. Signed integer overflow (Set D) - practice more cases before block close. Mechanical procedure: binary addition, discard carry, interpret MSB. Not by intuition.

---

*File: DAY_04_COMPLETE.md*
*Closed: Tuesday, May 26, 2026*

_AND OF DOCUMENTS_
