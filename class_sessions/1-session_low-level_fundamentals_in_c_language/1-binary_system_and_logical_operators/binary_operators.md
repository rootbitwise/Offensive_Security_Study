# DAY_03 - BINARY OPERATIONS (AND, OR, XOR, NOT, SHIFTS)
**Date:** Saturday, May 23, 2026 (session completed Monday, May 25)
**Block:** 0 of Season 1 - Binary systems and number bases
**Status:** Completed. Approximately 17 of 20 operations correct, above the day's criterion.

### Phase 2 - Logic Gym

#### Problem 1 - Masking

> You have the byte `1101 0110`. Design the mask you need to:
> (a) Isolate only the 4 high bits (bits 7-4).
> (b) Isolate only the 4 low bits (bits 3-0).
> (c) Isolate only bit 5.
> For each case, draw the mask and perform the AND by hand, column by column.

**(a) Isolate the 4 high bits (bits 7-4):**

```
    1101 0110
AND 1111 0000
  -----------
    1101 0000
```

Mask: `1111 0000`

**(b) Isolate the 4 low bits (bits 3-0):**

```
    1101 0110
AND 0000 1111
  -----------
    0000 0110
```

Mask: `0000 1111`

**(c) Isolate only bit 5:**

Interpreted "isolate 5 bit" instead of "isolate bit 5" - understood the question as "isolate 5 of the 8 bits." Under that reading:

```
    1101 0110
AND 1101 0110   (keeping bits 1, 2, 4, 6, 7)
  -----------
    1101 0110
```

> The question was asking to isolate bit 5 (singular, position 5). The correct answer under the correct reading:
> ```
>     1101 0110
> AND 0010 0000   (mask with only bit 5 on)
>   -----------
>     0000 0000   (bit 5 was off in the original byte)
> ```

#### Problem 2 - Set and Clear

> You have the byte `0100 0001`. You want to:
> (a) Turn on bit 5 without touching the others. What operation do you use and with what mask?
> (b) Turn off bit 0 without touching the others. What is the mask?

**(a) Turn on bit 5:**

To turn on a bit you use OR = 1, you only have to place a 1 on the bit you want to turn on, the rest must stay at 0.

```
   0100 0001
OR 0010 0000
 -----------
   0110 0001
```

**(b) Turn off bit 0:**

To turn off a bit I need to isolate the bits I do not want turned off, and then with OR I keep the bits I want on. First isolate, then turn off. AND then OR.

```
    0100 0001
AND 1111 0000   (isolate the high bits)
  -----------
    0100 0000

OR  0100 0000
 -----------
    0100 0000
```

> The two-step technique (AND then OR) works but is not the idiomatic form in C. The standard approach is a single operation:
> ```
>     0100 0001
> AND 1111 1110   (mask with all 1s except the bit being cleared)
>   -----------
>     0100 0000
> ```
> Standard C idiom: `x &= ~mask`.

#### Problem 3 - XOR as toggle

> You have the byte `1010 1010`. You apply XOR with the mask `0000 1111`.
> (a) What is the result?
> (b) You apply XOR with the same mask again. What happens? Why?
> (c) If you applied XOR with `1111 1111`, what would happen to all the bits?

**(a) First application:**

```
    1010 1010
XOR 0000 1111
  -----------
    1010 0101
```

**(b) Second application (same mask):**

```
    1010 0101
XOR 0000 1111
  -----------
    1010 1010   (back to the original value)
```

The first XOR mask reveals where they differ. Applying XOR to the result that differs from the original coincides with the original.

My own analogy: if you take an exam where there are only two answers A or B, and all your answers are wrong, if you get the same exam again you will know exactly which answer is correct. If you filled everything with B and it was wrong then all the answers are A. XOR means the result shows where it is different.

> This analogy captures exactly the reversible property of XOR. It is the intuitive basis of XOR encoding that attackers use to obfuscate shellcode.

**(c) XOR with `1111 1111`:**

XOR is reversible because only two answers exist: 0s and 1s.

```
    1010 1010
XOR 1111 1111
  -----------
    0101 0101   (the opposite)

    0101 0101
XOR 1111 1111
  -----------
    1010 1010   (original value)
```

Conclusion: `A XOR B XOR B = A`. Applying XOR with `1111 1111` flips every bit (equivalent to bitwise NOT). Applying it twice returns the original.

#### Problem 4 - Reasoned shifts

> Without calculating: you have `0000 0101` (which in decimal is 5). What decimal value does each give you:
> (a) `0000 0101 << 1`?
> (b) `0000 0101 << 3`?
> (c) `0000 0101 << 5`? Be careful with this one - these are 8 bits.

**(a) `0000 0101 << 1`:**

```
0000 0101 << 1 = 0000 1010 = 10
```

**(b) `0000 0101 << 3`:**

```
0000 0101 << 3 = 0010 1000 = 40
```

**(c) `0000 0101 << 5`:**

```
0000 0101 << 5 = 1010 0000 = 160
```

Important observation: in (c) the high bit of the 5 stayed inside the byte. If it had been `<< 6`, the upper `1` would have gone outside the byte. That is integer overflow by shift, a key concept for vulnerabilities.

---

### Phase 3 - Blind Code Reading

```c
#include <stdio.h>

int main(void)
{
    unsigned char flags = 0;     // unsigned variable, starts at zero

    flags |= (1 << 0);   // turns on bit 0  -> flags = 0000 0001
    flags |= (1 << 2);   // turns on bit 2  -> flags = 0000 0101 (bits accumulate, OR does not replace)
    flags |= (1 << 5);   // turns on bit 5  -> flags = 0010 0101 = 0x25

    printf("flags after sets: 0x%02X\n", flags);   // prints 0x25

    if (flags & (1 << 2)) {          // checks if bit 2 is on -> true, bit 2 was set above
        printf("bit 2 is set\n");    // this line executes
    }

    flags &= ~(1 << 0);  // turns off bit 0 -> flags = 0010 0100 = 0x24
    printf("flags after clear: 0x%02X\n", flags);   // prints 0x24

    flags ^= 0xFF;       // flips all bits -> flags = 0xDB
    printf("flags after toggle: 0x%02X\n", flags);  // prints 0xDB

    return 0;    // returns exit code 0 to the operating system
}
```

#### Line by line annotations

`int main(void)` - entry point

`unsigned char flags = 0` - unsigned variable

`flags |= (1 << 0)` - turns on bit 0, `0000 0001`, `0x01`

`flags |= (1 << 2)` - turns on bit 2, `0000 0100`, `0x04`

`flags |= (1 << 5)` - turns on bit 5, wrote `1000 0000`, `0x80`

> Correction: `1 << 5` produces `0010 0000` = `0x20`, not `1000 0000` = `0x80`. That would be `1 << 7`. Positions are counted from 0.

`printf("flags after sets: 0x%02X\n", flags)` - displays in hex the value after being moved

`if (flags & (1 << 2))` - if the bit at position 2 is on, then show the printf

`flags &= ~(1 << 0)` - turns off bit 0

`printf("flags after clear: 0x%02X\n", flags)` - displays flags after clearing

`flags ^= 0xFF` - flips all bits

`printf("flags after toggle: 0x%02X\n", flags)` - displays after flipping

`return 0` - wrote: "Return Stack Pointer (RSP)"

> Correction: `return 0` returns the value 0 to the operating system as the program's exit code. It is not RSP (Register Stack Pointer, x86-64 CPU register). Coincidence of initials.

#### My transformation narration

After `flags |= (1 << 0)`: `flags` = `0000 0001`

After `flags |= (1 << 2)`: `flags` = `0000 0100`

After `flags |= (1 << 5)`: `flags` = `1000 0000`

The `if`: the condition is false, because the bit already moved 5 positions before the `if`.

After `flags &= ~(1 << 0)`:

```
    0000 0001
AND 1111 1110
  -----------
    0000 0000
```

After `flags ^= 0xFF`:

```
    0000 0000
XOR 1111 1111
  -----------
    1111 1111
```

Output I wrote: `0x01`, `0x04`, `0x80`

> Corrections to apply: OR operations accumulate bits, they do not replace them. After the three assignments, `flags` = `0010 0101` (bits 0, 2, and 5 on at the same time). The `if (flags & (1 << 2))` is true, not false - bit 2 is still on. The values I wrote (`0x01`, `0x04`, `0x80`) were the intermediate mask values, not the accumulated value of `flags`. The actual output of the program:
> ```
> flags after sets: 0x25
> bit 2 is set
> flags after clear: 0x24
> flags after toggle: 0xDB
> ```

---

### Phase 4 - Deliverable: Practice Sets

#### Set A - Bitwise AND

> Perform each AND operation bit by bit and write the result.

| Operation | My answer | Status |
|-----------|-----------|--------|
| `1100 1010 AND 1010 1110` | `1000 1010` | Correct |
| `1111 0000 AND 0000 1111` | `0000 0000` | Correct |
| `1010 1010 AND 0101 0101` | `0000 0000` | Correct |
| `1101 0011 AND 1111 0000` | `1101 0000` | Correct |
| `0110 1101 AND 0000 0010` | `0000 0000` | Correct |

Result: 5/5

#### Set B - Bitwise OR

> Perform each OR operation bit by bit and write the result.

| Operation | My answer | Status |
|-----------|-----------|--------|
| `1100 1010 OR 0011 0101` | `1111 1111` | Correct |
| `1010 0000 OR 0000 0101` | `1010 0101` | Correct |
| `0001 0000 OR 0000 1000` | `0001 1000` | Correct |
| `1111 1111 OR 0000 0000` | `1111 1111` | Correct |
| `0110 1101 OR 1001 0010` | `1111 1111` | Correct |

Result: 5/5

Note on problem 3: if after that I apply AND with `0000 1111`, I keep only bit 3.

#### Set C - Bitwise XOR

> Perform each XOR operation bit by bit and write the result.

| Operation | My answer | Status |
|-----------|-----------|--------|
| `1100 1010 XOR 1010 1100` | `0110 1001` | Incorrect |
| `1111 1111 XOR 1010 0101` | `0101 1010` | Correct |
| `1010 1010 XOR 0000 0000` | `1010 1010` | Correct |
| `1010 1010 XOR 1010 1010` | `0000 0000` | Correct |
| `1100 0011 XOR 0011 1100` | `1111 1111` | Correct |

Result: 4/5

> Correction on problem 1: checking bit by bit, the correct result is `0110 0110`. Bits 0 and 3 were wrong.

#### Set D - Shifts

> Perform each shift operation and write the result in binary and decimal.

| Operation | My answer | Status |
|-----------|-----------|--------|
| `0000 0101 << 2` | `0001 0100` | Correct |
| `0010 1110 >> 3` | `0000 0101` | Correct |
| `1000 0001 << 1` | `0000 0010` | Correct |
| `1111 1111 >> 4` | `0000 1111` | Correct |
| `0000 0011 << 5` | `0110 0000` | Correct |

Result: 5/5

Note on problem 3: the high bit went outside the byte - overflow by shift. Note on problem 5: one of the 1s also went outside.

Phase 4 total: approximately 17/20 operations correct.

---

### Session Summary

#### What is solid

- AND, OR, XOR, bitwise NOT at the mechanical level.
- Shifts including overflow by shift (observed in Set D problems 3 and 5).
- Reversible property of XOR: `A XOR B XOR B = A`. Captured with my own two-answer exam analogy.
- Bitwise operations as primitive building blocks of digital computation.
- Mask to isolate high nibble and low nibble from a byte.

#### My own analogies and reasoning captured

1. Exam analogy (XOR): "If all your answers are wrong and you get the same exam again, you will know exactly which answer is correct." Captures XOR reversibility.
2. Set reasoning: "To turn on a bit you use OR = 1, you only have to place a 1 on the bit you want on, the rest must stay at 0."
3. XOR as difference detector: "XOR means the result shows where it is different."
4. Reversibility reasoning: "XOR is reversible because only two answers exist: 0s and 1s."

#### Corrections to keep in mind

1. Confusion between "isolate 5 bit" and "isolate bit 5" - read carefully.
2. `1 << N` counts from 0: `1 << 5` = `0010 0000`, not `1000 0000`.
3. OR does not replace, it accumulates: three `flags |= (1 << N)` leave all three bits on at the same time.
4. `return 0` is not RSP - it is the program's exit code.
5. Set and clear is ONE operation in standard C: `x |= mask` (set), `x &= ~mask` (clear). The two-step technique works but is not idiomatic.

---

*File: DAY_03_COMPLETE.md*
*Closed: Monday, May 25, 2026*

_END OF DOCUMENT_
