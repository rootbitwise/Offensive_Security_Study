# DAY_05 - SIGN EXTENSION AND INTEGER OVERFLOW REINFORCEMENT
**Date:** Wednesday, May 27, 2026
**Block:** 0 of Season 1 - Binary systems and number bases (week 2)
**Status:** Completed with detailed answers and two serious errors to correct.

### Phase 2 - Logic Gym

#### Problem 1 - Manual extension

> For each value, calculate the result when extending from 8 bits to 16 bits. Write the original 8-bit byte and the 16-bit result. Identify which rule you applied (zero or sign extension).

**(a) `unsigned char x = 100;` to `unsigned short y = x;`**

Result: `0000 0000 0110 0100` = zero extension

> Correct.

**(b) `unsigned char x = 200;` to `unsigned short y = x;`**

Result: `0000 0000 1100 1000` = zero extension

> Correct.

**(c) `signed char x = 100;` to `signed short y = x;`**

Result: `0000 0000 0110 0100` = sign extension

> Correct. MSB was 0, so sign extension fills with zeros - coincides with zero extension when the source is positive.

**(d) `signed char x = -100;` to `signed short y = x;`**

Result: `1111 1111 1001 1100` = sign extension

> Correct. The MSB of -100 was 1, so sign extension fills with ones.

Result: 4/4

#### Problem 2 - The crossed bug

> ```c
> signed char a = -1;    // bits: 1111 1111
> unsigned int b = a;    // what value does b take?
> ```
> What is the decimal value of `b`?

Sign extension to 32 bits: `1111 1111 1111 1111 1111 1111 1111 1111`
Reinterpreted as unsigned int = 4,294,967,296

> Almost perfect. The procedure is correct but the final number is off by 1. `2^32 = 4,294,967,296` is the total number of combinations, not the maximum value. The maximum value of a 32-bit unsigned int is `2^32 - 1 = 4,294,967,295`. When all bits are 1, that is the maximum value, which is `2^32 - 1`. The unsigned range of N bits is 0 to `2^N - 1`. Since the range includes 0, it cannot reach `2^N` - that would be one extra pattern. Correct result: 4,294,967,295.

#### Problem 3 - The inverse problem (truncation)

> `int x = 300;` to `signed char y = x;` - how much is `y`?
> Hint: 300 in 32 bits is `... 0000 0001 0010 1100`. Truncating to 8 bits takes only `0010 1100`.

44 = `0010 1100`

> Correct. The high bit (0) leaves the value positive in signed char. Direct application of weights: 32 + 8 + 4 = 44.

#### Problem 4 - The case with MSB on after truncation

> `int x = 200;` to `signed char y = x;` - how much is `y`?
> 200 in 32 bits: the 8 low bits are `1100 1000`. The MSB ends up on.

256 negative (written as "256 negative")
32 bits: `0000 0000 0000 0000 0000 0000 1100 1000`
Signed `1100 1000` = -56

> The correct answer is -56, not -256. The 32-bit calculation and the final signed interpretation are right. 256 is not a valid signed char value (the range is -128 to +127) - likely a slip when writing. The following procedure (`1100 1000` = -56 in signed) is correct and was self-corrected below.
>
> Correct comparison:
> - `1100 1000` as `unsigned char` = 200
> - `1100 1000` as `signed char` = -56
> - Same bit pattern, different interpretation depending on the type.

### Phase 3 - Blind Code Reading

> ```c
> signed char    a = -1;
> unsigned char  b = -1;
>
> int  x = a;
> int  y = b;
> unsigned int z = a;
>
> printf("a as int:           %d\n", x);
> printf("b as int:           %d\n", y);
> printf("a as unsigned int:  %u\n", z);
> ```
> Narrate: input, transformation, and output for each variable.

#### Line by line annotations

`signed char a = -1` - a variable with sign is declared and a negative value is passed directly, the MSB does not influence.

`unsigned char b = -1` - zero extension, when passing (-1 = `1111 1111`) since `1111 1111` is being passed directly: `0000 0000 0000 0000 0000 0000 1111 1111`

`int x = a` - implicit assignment = signed int a = `1111 1111 1111 1111 1111 1111 1111 1111`

`int y = b` - `0000 0000 0000 0000 0000 0000 1111 1111`

`unsigned int z = a` - implicit assignment: `1111 1111 1111 1111 1111 1111 1111 1111`

`printf("a as int", x)` - prints a as an int = -1

`printf("b as int", y)` - prints b as an int = "in decimal format" = 255

`printf("a as unsigned int", z)` - prints a as an unsigned int = unsigned whole number = 4,294,967,296

#### My narration

**1. Input:**
- `a` (signed char): `1111 1111` (two's complement of -1)
- `b` (unsigned char): the literal -1 converts to unsigned = 255 = `1111 1111`
- Same bits, different type.

**2. Transformation:**
- `int x = a`: signed extension applied = 32 bits all on
- `int y = b`: zero extension, 8 bits on
- `unsigned int z = a`: 4 billion (correct conceptually)

**3. Output:**
- A = -1 (`int x = a = -1`)
- B = 255 (`int y = b = 255`)
- C = 4 billion (`unsigned int z = 4,294,967,296`)

> Reading of the flow is correct. Only the final value of `z` needs to be corrected to 4,294,967,295 for the same reason as Problem 2 - all bits at 1 is `2^N - 1`, not `2^N`. This was the densest code reading of the block and the flow was extracted correctly. Confirmed understanding of:
> - The same bits can mean different things depending on the type
> - Sign extension fills with the source MSB
> - Zero extension fills with zeros
> - Assigning a signed to an unsigned does sign extension first and then reinterprets

### Phase 4 - Deliverable: Practice Sets

#### Set A - Signed integer overflow reinforcement

> For each operation in `signed char`, perform the full 8-bit binary addition, discard carry if needed, and interpret the result as signed.

**Problem A: 127 + 1 in signed char**

```
   0111 1111 = 127
+  0000 0001 = 1
-----------
   1000 0000 = -128
```

My answer: -128

> Correct.

**Problem B: 127 + 5 in signed char**

```
   0111 1111 = +127
+  0000 0101 = +5
-----------
   1000 0100 = -120
```

My answer: -120

> The binary `1000 0100` is correct. Signed interpretation: MSB = 1, so it is negative. Correct calculation: -128 + 4 = -124, not -120. The bit on in `1000 0100` is at position 2 (weight 4), not position 3 (weight 8). Likely added -128 + 8 = -120 by accident. Real result: -124.

**Problem C: -128 - 1 in signed char**

```
  1 1000 0000 = -128
    1111 1111 = -1
  -----------
  1/0111 1111 = +127
```

My answer: +127

> Correct. The final carry (1) is discarded. The result within 8 bits is `0111 1111` = +127.

**Problem D: -128 - 5 in signed char**

```
  1000 0000 = -128
  1111 1011 = -5
  ---------
  0111 1011 = +121
```

My answer: +121

> Correct.

**Problem E: 60 + 80 in signed char**

```
  0011 1100 = 60
  0101 0000 = 80
  ---------
  1000 1100 = -116
```

My answer: -116

> Correct.

Set A result: 4/5. Only Problem B with the wrong weight calculation.

#### Set B - Sign extension from 8 to 16 bits

> For each value and type combination, write the 16-bit result and its decimal value.

| Value and type | My 16-bit result | My decimal | Status |
|----------------|-----------------|------------|--------|
| `0x42` as `signed char` to `signed short` | `0000 0000 0100 0010` | 66 | Correct |
| `0x42` as `unsigned char` to `unsigned short` | `0000 0000 0100 0010` | 66 | Correct |
| `0xFF` as `signed char` to `signed short` | `1111 1111 1111 1111` | -1 | Correct |
| `0xFF` as `unsigned char` to `unsigned short` | `0000 0000 1111 1111` | 255 | Correct |
| `0x80` as `signed char` to `signed short` | `1111 1111 1000 0000` | -384 | Incorrect |

> The bits on problem 5 are correct: sign extension of `1000 0000` (MSB = 1) fills with ones to produce `1111 1111 1000 0000`. But the decimal value is wrong.
>
> Faster approach: if the signed char was `0x80` = -128, then in signed short it is still -128. Sign extension preserves the numeric value, it does not change it.
>
> Verification: `1111 1111 1000 0000` = `0xFF80` = 65,408 unsigned. 65,408 - 65,536 = -128. Correct result: -128, not -384.

Set B result: 4/5. Error on problem 5 when calculating the decimal value, though the bits were correct.

#### Set C - Start of the `binarios_lab.md` deliverable

Pending: the three sections of the deliverable (conversion table, two's complement explanation in my own words, integer overflow example with connection to CVE-2021-3156) remain work-in-progress. They are finalized in DAY_06 (block close).

### Session Summary

#### What is solid

- Difference between zero extension and sign extension.
- Identifying which rule applies based on the source type.
- Truncation from 32 to 8 bits using the low bits.
- Same bit pattern with two interpretations depending on the type (signed/unsigned).
- Reading the flow in C code with three different implicit assignments.
- Mechanics of signed overflow (`127 + 1 = -128`, `-128 - 1 = +127`).

#### What goes to errors.md

1. `2^N` vs `2^N - 1` - the maximum value of unsigned N bits is `2^N - 1`, not `2^N`. If the range includes 0, the ceiling drops by 1. `unsigned int` max = 4,294,967,295. `unsigned short` max = 65,535. `unsigned char` max = 255. This is a final calculation error, not a conceptual one - the understanding that all bits at 1 is the maximum is correct, just need to subtract the 1.

2. Identifying weights when interpreting signed - Problem B (`127 + 5`): the bit on in `1000 0100` is at position 2 (weight 4), not position 3 (weight 8). Correct result: -128 + 4 = -124. When a signed pattern has the MSB on plus a few low bits, calculate `-128 + (sum of weights on to the right)`. Do it bit by bit, not by estimation.

3. Sign extension preserves the numeric value - Set B problem 5: if the source was -128 in signed char, the destination is still -128 in signed short. Sign extension does not change the value - it only adds the bits needed to represent it in the new width. If the bit calculation gives a different number than the original value, there is an error in the calculation.

#### My own notes and reasoning captured

- "The MSB does not influence" when the source is signed positive or zero - correct observation, the result of zero extension and sign extension coincide in that case.
- "Since `1111 1111` is being passed directly" - captures well that the literal -1 assigned to an unsigned converts by wrap-around to `1111 1111` = 255 (256 - 1).
- "Implicit assignment" as a term - well applied. Correctly identified that without an explicit cast the compiler does the conversion automatically, which is exactly where signedness bugs are born.

---

*File: DAY_05_COMPLETE.md*
*Closed: Tuesday, June 2, 2026*

_AND OF DOCUMENTS_
