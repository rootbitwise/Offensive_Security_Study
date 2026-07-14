# Day 2 - FLUID MANUAL CONVERSIONS

**Date:** Saturday, May 23, 2026
**Block:** 0 of Season 1 — Binary systems and number bases
**Status:** Completed with extended practice and two quizzes

### Phase 2 — Logic Gym

#### Problem 1 — the range

> With 1 nibble (4 bits) you can represent exactly 16 distinct numbers: from 0 to 15.
> With 1 byte (8 bits) you can represent exactly 256: from 0 to 255.
> Without calculating anything, tell me: with 2 bytes (16 bits), how many distinct numbers can you represent? And with 4 bytes (32 bits)?

With 2 bytes = 65,536
With 4 bytes = 16,777,216

Partially correct. 65,536 is correct. 16,777,216 corresponds to 24 bits (3 bytes), not 32 bits. The correct value for 32 bits is 4,294,967,296.

#### Problem 2 — the ceiling trick

> How much is 0xFF in decimal? (255)
> Without calculating, how much is 0xFFF? Hint: 0xFFF is 0xFF * 16 + 0xF. Think about why the formula has that form.

Because of position. It is like raising 16 to 16. 16^16 are 4 nibbles, 16 bits.

Incorrect notation. 0xFFF has 3 hex digits = 3 nibbles = 12 bits, not 4 nibbles / 16 bits. The symbol `^` means exponentiation, not multiplication. Correct form: 0xFFF = F*16^2 + F*16^1 + F*16^0 = 15*256 + 15*16 + 15*1 = 4095.

#### Problem 3 — the most significant bit

> You have the byte 1000 0000. How much is it in decimal? (It is 128, because the bit is at position 7 and 2^7 = 128.) Now: you have 0000 0001. How much is it? And 0100 0000?
> Why is the leftmost bit called MSB ("most significant")?

A human agreement to use something that can represent the sign.

Incomplete. The sign interpretation only applies to signed types. The real reason for the name: the MSB is the bit that changes the value of the number the most if you flip it. In a byte, the MSB carries weight 128. The two concrete answers were missing: 0000 0001 = 1, 0100 0000 = 64.

#### Problem 4 — the invisible shortcut

> You have the binary number 1010 1010. Without converting to decimal, give me its value in hex.
> Now flip every bit: 0101 0101. Its value in hex?
> Add the two hex values. What number do you get? Why did it have to be exactly that number?

1010 1010 = 0xAA
0101 0101 = 0x55
Sum: 1010 1010 + 0101 0101 = 1111 1111 = 0xFF (255)

This would be like adding A + (-B). I saw it in the last class, this is how a subtraction is done at the bit level theoretically.

Mechanics correct. The interpretation as "sum A + (-B)" is incorrect — that is two's complement (week 2 topic). What happens here is something else: any byte and its bitwise complement always sum to 0xFF, because wherever one has 0 the other has 1.

---

### Phase 3 — Blind Code Reading

```c
#include <stdio.h>    // standard input/output library

int main(void)        // program entry point
{
    unsigned char byte = 0xC8;    // stores a variable of type unsigned char

    printf("decimal: %d\n",  byte);     // displays the variable in decimal format
    printf("hex:     0x%X\n", byte);    // displays in hex format
    printf("binary:  ");                // prints the word "binary:"
    for (int i = 7; i >= 0; i--) {      // i = 7, while i is >= 0, subtract 1 from i
        printf("%d", (byte >> i) & 1);  // shifts bits right i positions, isolates the lowest bit
    }
    printf("\n");    // line break

    return 0;
}
```

#### Line by line annotations

`#include <stdio.h>` — library / file

`int main(void)` — entry point

`unsigned char byte = 0xC8;` — stores a variable of type char

`printf("decimal: %d\n", byte);` — displays the variable on screen in decimal format

`printf("hex: 0x%X\n", byte);` — displays in hex format

`printf("binary: ");` — prints the word "binary:"

`for (int i = 7; i >= 0; i--)` — i = 7, while i is equal to or greater than 0, subtract 1 from i

`(byte >> i) & 1` — basically doing a conversion to binary. What I understand: on each loop iteration it does an SHL operation — on the first one it moves 7 bits to the left and shows the value.

`printf("\n");` — line break

General understanding correct. Two technical errors:

1. `>>` is SHR (shift right), not SHL. SHL is `<<`. Correct direction: moves bits to the right, not to the left.
2. Output: the program prints 3 lines, not 11. What gets printed exactly:

```
decimal: 200
hex:     0xC8
binary:  11001000
```

#### Free questions from Phase 3

> "How, without converting to binary, can I know if a hexadecimal number is positive or negative? Without transforming it to binary, or is the transformation mandatory?"

Look only at the first hex digit. If it starts with 0-7, MSB = 0 (positive in signed). If it starts with 8-F, MSB = 1 (negative in signed). But this only applies if the type is signed. Bits carry no sign label — only the TYPE carries it.

> "In binary, do multiple combinations exist to represent the same number?"

Different width, same value: YES. 5 can be 101, 0101, 0000 0101, etc. Leading zeros do not change the value, only the space in memory.
Same width, same value: NO. Within a fixed width, each number has exactly one representation.

> "How do I determine if a number is unsigned or signed? It can start with 8 and not necessarily be negative."

Bits do not tell you if the value is signed or unsigned. Only the TYPE declared in the code does. `unsigned char a = 0xC8` is 200. `signed char b = 0xC8` is -56. Same bits, two different values. In offensive analysis it is inferred from context — addresses, sizes, and counters are typically unsigned.

---

### Phase 4 — Deliverable: Practice Sets

#### Set A — Decimal to Binary (8 bits)

| Decimal | My binary answer | Status |
|---------|-----------------|--------|
| 12 | 0000 1100 | Correct |
| 25 | 0001 1001 | Correct |
| 37 | 0010 0101 | Correct |
| 56 | 0011 1000 | Correct |
| 88 | 0101 1000 | Correct |
| 109 | 0110 1101 | Correct |
| 145 | 1001 0001 | Correct |
| 200 | 1100 1000 | Correct |
| 211 | 1101 0011 | Correct |
| 254 | 1111 1110 | Correct |

Result: 10/10

#### Set B — Binary to Hexadecimal

| Binary | My hex answer | Status |
|--------|--------------|--------|
| 0000 1010 | 0x0A | Correct |
| 0011 0101 | 0x35 | Correct |
| 0100 1110 | 0x4E | Correct |
| 0110 0110 | 0x66 | Correct |
| 0111 1111 | 0x7F | Correct |
| 1000 0001 | 0x81 | Correct |
| 1010 1010 | 0xAA | Correct |
| 1011 1100 | 0xBC | Correct |
| 1101 0011 | 0xD3 | Correct |
| 1111 0000 | 0xF0 | Correct |

Result: 10/10

#### Set C — Hexadecimal to Decimal

| Hex | My decimal answer | Status |
|-----|------------------|--------|
| 0x0F | 15 | Correct |
| 0x10 | 16 | Correct |
| 0x2A | 42 | Correct |
| 0x4D | 77 | Correct |
| 0x80 | 128 | Correct |
| 0xAB | 171 | Correct |
| 0xFF | 255 | Correct |
| 0x100 | 256 | Correct |
| 0x1A4 | 420 | Correct |
| 0x3FF | 1023 | Correct |

Result: 10/10
Bonus: 0xFFF = 4,095 — calculated correctly at the margin.

#### Set D — Decimal to Hexadecimal

| Decimal | Intermediate binary | My hex | Status |
|---------|---------------------|--------|--------|
| 10 | 0000 0000 0000 1010 | 0xA | Correct |
| 31 | 0000 0000 0001 1111 | 0x1F | Correct |
| 48 | 0000 0000 0011 0000 | 0x30 | Correct |
| 75 | 0000 0000 0100 1011 | 0x4B | Correct |
| 128 | 0000 0000 1000 0000 | 0x80 | Correct |
| 175 | 0000 0000 1010 1111 | 0xAF | Correct |
| 200 | 0000 0000 1100 1000 | 0xC8 | Correct |
| 240 | 0000 0000 1111 0000 | 0xF0 | Correct |
| 350 | 0000 0001 0101 1110 | 0x15E | Correct |
| 512 | 0000 0010 0000 0000 | 0x020 | Incorrect |

Result: 9/10
Error on row 512: the binary is correct but the nibbles were read in reverse order. Correct: 0010 0000 0000 reads as 2, 0, 0 which gives 0x200, not 0x020.

Phase 4 total: 39/40 conversions correct.

---

### Quiz 1 — Conversion Mechanics

#### Q1.1

> Convert decimal 173 to 8-bit binary.

1010 1101

Correct.

#### Q1.2

> Convert binary 1011 0111 to hexadecimal.

0xB7

Correct.

#### Q1.3

> Convert hexadecimal 0xC4 to decimal. Show the development (coefficient times power).

13*1 = 13 + 4*1 = 4, total 17

Incorrect. Error: both digits treated as position 0. Correct: 0xC4 = C*16^1 + 4*16^0 = 12*16 + 4*1 = 192 + 4 = 196.

#### Q1.4

> What is the largest binary number that fits in 6 bits? How much is it in decimal? How much in hex?

1111 1100 = 252, 0xFC. "Assuming 8 bits with only 6 turned on."

Incorrect due to misreading the problem. "6 bits" means width 6, not width 8 with 6 bits on. Correct: 111111 (6 bits) = 63 = 0x3F.

#### Q1.5

> Convert 1024 (decimal) to hexadecimal.

Unclear in the image, not readable.

Pending verification. Correct: 1024 = 0x400.

#### Q1.6

> You have binary 11 0101 0010. Convert it to hex applying the nibble rule correctly.

```
0011 0101 0010
  3    5    2   = 0x352
```

Correct. Right-to-left grouping with left padding applied correctly.

#### Q1.7

> True or false: to convert decimal 27 to binary I can pad with zeros to the right until reaching 8 bits. Justify in one line.

No, you must pad with zeros to the left.

Correct.

Quiz 1 total: 4 correct, 2 incorrect, 1 pending (out of 7 questions).

---

### Quiz 2 — Reasoning About Bases

#### Q2.1

> With 12 bits, how many distinct combinations can be represented? Reach the number without calculating large powers — use doubling from 256 = 2^8.

49,152

Incorrect. Correct: 2^12 = 4,096. Doubling method: 256 (8 bits), 512, 1,024, 2,048, 4,096 (12 bits).

#### Q2.2

> Why is a byte in hexadecimal ALWAYS written with two digits (from 00 to FF) and never with three or one? Justify with the relationship between bits and nibbles.

Because a nibble is 4 bits and a byte is 8 bits, they are exactly 2 nibbles.

Correct.

#### Q2.3

> You have binary 1000 0000 in one byte. How much is it if interpreted as unsigned? As signed with two's complement, is it the same number or not?

128 unsigned. No, with two's complement it is -127. (Note at margin: "2-1-0 1 2 = two's complement, eliminates the -0")

Partially correct. Unsigned = 128 correct. But signed with two's complement: 1000 0000 = -128, not -127. The signed 8-bit range is asymmetric: -128 to +127.

#### Q2.4

> Without converting anything to decimal, sort from smallest to largest: 0x80, 0xA, 0x100, 0xFF. Justify the order in one line.

0xA, 0x80, 0xFF, 0x100. "The more characters, the more positions, the larger the number."

Correct.

#### Q2.5

> An attacker wants to hide the ASCII string /bin/sh inside a script. They encode it byte by byte in hex. How many characters will the resulting hex string have? Why exactly that number?

"I do not remember, I think it is the standard x90 x90 x90"

Incorrect. /bin/sh is 7 ASCII characters. Each character encodes to 2 hex digits (1 byte). Total: 14 hex characters. Reason: 1 byte = 2 nibbles = 2 hex characters.

#### Q2.6

> Your program prints a 32-bit value and shows: 0xDEADBEEF. How many bytes is it? How many nibbles? Why is that string popularly called a "magic value" in debugging?

It is 8 nibbles, 4 bytes.

Correct on counts, incomplete on explanation. Missing: 0xDEADBEEF spells a readable English phrase ("dead beef") using only valid hex digits (0-9, A-F). It is used as a debugging marker because if you see it in a memory dump you know something intentional arrived, not garbage.

#### Q2.7

> If I see a long run of bytes 0x90 in a memory dump, what exploitation technique am I possibly observing? What is the associated MITRE code as seen in day 2?

ASCII/BIN/BASH

Incorrect. Correct answer: NOP sled (from day_02 CTI Overlay). 0x90 is the x86 NOP instruction. MITRE: T1055 (Process Injection).

Quiz 2 total: 3 correct, 4 incorrect (out of 7 questions).

---

### Session Summary

What is solid:
- Decimal, binary, and hex conversions in all 4 directions (39/40 in practice sets).
- Power notation: digit times 16^position. Set C confirmed this.
- Nibble grouping from the right with left padding.
- Comparing hex magnitudes without converting (Q2.4).
- Why one byte equals 2 hex digits (Q2.2).

What remains weak (to errors.md):
1. Digit position in multi-digit hex (Q1.3) — error repeated from Monday.
2. Reading quiz problem statements (Q1.4) — "6 bits" means width 6, not 8 with 6 on.
3. Calculating 2^12 (Q2.1) — confused with another number, not 4,096.
4. Asymmetric signed range (Q2.3) — -128 to +127, not -127 to +127.
5. NOP sled (Q2.7) — concept from day 2 itself, not recalled.
6. Set D row 512 — nibble order reversed. 0x200, not 0x020.

---

_AND OF DOCUMENTS_

*Closed: Saturday, May 23, 2026*
