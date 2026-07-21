# BLOCK_0_CLOSE - BINARIOS_LAB
**Date:** Tuesday, June 2, 2026
**Block:** 0 of Season 1 - Binary systems and number bases
**Type:** Block closing deliverable
**Status:** Completed

### Conceptual foundation - why binary and two's complement

For decision making, computers use logic gates such as AND, OR, XOR, etc. These logic gates are built from transistors, which work with electricity - either allowing current to pass or not. 5V equals on or 1, and 0 volts equals off or 0. Anything the computer processes, numbers or any other information, is represented with binary numbers, meaning 0s and 1s.

> Note: the correct notation is 5V (5 volts), not V5.

When performing arithmetic operations, to identify whether a number is negative or positive, it was decided that the leftmost bit would be the sign bit, which made it the most significant bit, MSB.

That brought the first mechanism: the MSB and the other 7 bits represented the total of the number (sign and magnitude). It was logical but had several problems, among them a double representation for 0, meaning -0 and +0, which makes no sense in mathematics. It also required an extra operation for a neutral 0, which caused sums to be inexact. The range was also asymmetric but wasteful.

Then came one's complement. This method solved some of the problems sign and magnitude had, like the asymmetry problem and the transition between positive and negative. But it still had -0 and was still wasting one possible combination.

Then came the most efficient solution to this day: two's complement. This method first avoids the double representation of 0, takes advantage of all possible combinations, and the math of adding a number with its negative representation gives 0, making arithmetic exact. +3 + (-3) = 0.

### Two's complement - key questions

> Why is the pattern `1000 0000` not -0 in two's complement?

Because in two's complement, to represent a negative number you invert it and add 1, which means 0 has no -0 representation. `0000 0000` inverted is `1111 1111`, add 1 and the result goes back to `0000 0000` with a carry of 1 that is discarded. 0 will always be 0.

> What happens when you add `+127 + 1` in signed char?

Because of how binary additions work, the result is -128, because the counter resets. In binary to count you start at 0, then 1, when digits run out it resets, the 1 moves left and we count again: 0, 1, 10, 11, 100, etc. What happens is an addition that leaves the most significant bit on. `0111 1111 + 0000 0001 = 1000 0000` (-128). This number has the MSB on, leaving a negative result = -128.

### Conversion table

| Decimal | Binary | Hexadecimal |
|---------|--------|-------------|
| 0 | 0000 0000 | 0x00 |
| 10 | 0000 1010 | 0x0A |
| 16 | 0001 0000 | 0x10 |
| 25 | 0001 1001 | 0x19 |
| 31 | 0001 1111 | 0x1F |
| 42 | 0010 1010 | 0x2A |
| 64 | 0100 0000 | 0x40 |
| 77 | 0100 1101 | 0x4D |
| 100 | 0110 0100 | 0x64 |
| 127 | 0111 1111 | 0x7F |
| 128 | 1000 0000 | 0x80 |
| 171 | 1010 1011 | 0xAB |
| 200 | 1100 1000 | 0xC8 |
| 240 | 1111 0000 | 0xF0 |
| 255 | 1111 1111 | 0xFF |
| 256 | 0000 0001 0000 0000 | 0x100 |
| 420 | 0000 0001 1010 0100 | 0x1A4 |
| 1023 | 0000 0011 1111 1111 | 0x3FF |

---

### Integer overflow

Data overflows. In machine language, arithmetic does not fail - what fails is the interpretation. The computer keeps following the same behavior it is supposed to follow. The problem is that an attacker knowing this can use it to overwrite data and redirect the program to malicious code.

What happens in the signed case, example with a signed char: first the logic - a char is a byte, meaning 8 bits. Adding 1 to 127 resets the counter leaving the MSB on. Remembering that if the MSB is 1 the number is negative and if it is 0 it is positive. In two's complement, positive 128 does not exist because there is one more negative number than positive.

The arithmetic or logic of the computer does not fail. What happens is that the result jumps to the first negative number because that is the result of the binary addition.

```c
x = 127; x = x + 1;
```

```
   0111 1111    (+127)
+  0000 0001    (+1)
-----------
   1000 0000    (-128)
```

It is undefined behavior (UB): it occurs when the code violates the rules of the standard. When this happens, the C standard imposes no restriction on what the program can do - anything. The compiler can assume it never happens because in the arithmetic or logic of binary operations nothing outside of normal is happening. The problem arises when another function receives that data and was expecting a different specific value.

#### Integer overflow signed - practical example

```c
signed char x = -100;
x = x + -50;

// -100 in binary is 1001 1100
// -50 in binary is 1100 1110
    11 1
  1001 1100
+ 1100 1110
------------
1 0110 1010 = 106

// this is a potential bug: if the result of the sum were a value that does
// not overflow, when passed to a function expecting unsigned size it would
// be interpreted as a large size, by implicit sign assignment
```

#### Signedness bug in a real check

```c
if (user_size < 100) {
    copy_to_buffer(buffer, user_data, user_size);
}
```

If `user_size` is signed and the attacker forces it to be negative (-1 for example), the check `< 100` passes because it is a value less than 100. But `copy_to_buffer` expects unsigned. `-1` reinterpreted as unsigned in 32 bits is `0xFFFFFFFF`, which is a huge number. The function tries to copy four billion bytes, producing a massive buffer overflow.

---

### Hex to decimal and binary conversion

> Convert `0xDEAD` to binary and to signed decimal.

`0xDEAD` = `1101 1110 1010 1101`

Taking the MSB as negative and adding the rest of the on bits as positives, the result is -17,235.

> Incorrect. `0xDEAD` as unsigned 16-bit = 57,005. As signed 16-bit: 57,005 - 65,536 = -8,531. The bit-by-bit breakdown:
>
> | Position | Weight | Bit |
> |----------|--------|-----|
> | 15 | -32,768 | 1 |
> | 14 | +16,384 | 1 |
> | 13 | 0 | 0 |
> | 12 | +4,096 | 1 |
> | 11 | +2,048 | 1 |
> | 10 | +1,024 | 1 |
> | 9 | +512 | 1 |
> | 8 | 0 | 0 |
> | 7 | +128 | 1 |
> | 6 | 0 | 0 |
> | 5 | +32 | 1 |
> | 4 | 0 | 0 |
> | 3 | +8 | 1 |
> | 2 | +4 | 1 |
> | 1 | 0 | 0 |
> | 0 | +1 | 1 |
>
> -32,768 + 16,384 + 4,096 + 2,048 + 1,024 + 512 + 128 + 32 + 8 + 4 + 1 = -8,531. Goes to errors.md.

---

### Bitwise operations practice

#### 1 - AND mask to isolate the 4 low bits

```
  1 0 1 0 0 1 1 0
& 0 0 0 0 1 1 1 1
------------------
  0 0 0 0 0 1 1 0
```

#### 2 - Turn on bit at position 3 with OR

```
  1 0 1 0 0 1 1 0
| 0 0 0 0 1 0 0 0
------------------
  1 0 1 0 1 1 1 0
```

#### 3 - Flip all bits with XOR and with NOT bitwise

```
  1 0 1 0 0 1 1 0
^ 1 1 1 1 1 1 1 1
------------------
  0 1 0 1 1 0 0 1
```

```
~ 1 0 1 0 0 1 1 0
------------------
  0 1 0 1 1 0 0 1
```

### Q and A

> What decimal value does `0x80` have interpreted as signed char? And as unsigned char?

```
signed:   -128
unsigned: 128
```

> How much is `1111 1010` interpreted as signed char?

```
-6
```

> What is the range of an unsigned int (32 bits)?

4 billion = 4,294,967,295

### Shift operators

`<<` moves bits to the left (SHL) = multiplies by 2^N

`>>` moves to the right (SHR) = divides by 2^N

### Signedness bug - closing example

```c
signed char count = get_user_input();
if (count < 100) {
    process(buffer, count);   // process expects size_t
}
```

If the user inserts a negative number it passes as valid since it is less than 100, but buffer does not expect a signed value, so it reinterprets the number as unsigned, which converts that negative number into a huge number, creating a buffer overflow.

---

*File: BLOCK_0_CLOSE_binarios_lab.md*
*Closed: Tuesday, June 2, 2026*

_AND OF DOCUMENTS_
