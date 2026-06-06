# binarios labs

**Date:** Tuesday, May 19, 2026
**Block:** 0 - Binary systems and number bases
**Session type:** Technical class - 6 phases
**Topic:** Number systems - decimal, binary, hexadecimal

---

### Phase 1 — Exit condition

> Explain, without looking at this document: (a) why the machine uses base 2, (b) why hexadecimal exists, and (c) why one hex digit is exactly equivalent to 4 bits.

**A) Why does the machine use base 2?**
The machine uses base 2 because it is the simplest and most useful system for hardware, because it can only have two states - on or off.

**B) Why does hexadecimal exist?**
Hexadecimal exists to fill the gap between binary numbers and human language, since reading binary all the time is very tedious and "costly in time" - some numbers can get very long.

**C) Why does one hex digit equal exactly 4 bits?**
One hex digit is a nibble. "A nibble is 4 bits." Basically, one hex digit is 4 bits compressed into 1.

---

### Phase 3 — Blind code reading

**Question: If you had converted to decimal first and then to hex, would you have gotten the same result? Why or why not?**

Not literally. If I take `1011` and `B` - both have the same value, which is 11. But if I convert `1011` to decimal first, the result is `11`. However, `11` in hex is not "11" - it would be `1` `1`, two separate nibbles. You would have to be very specific for those two `1`s - that is, `1 1` - to still be "11" when converted to hex.

```
1011 = B     0110 = 6
3 = 0011     F = 1111
total 8 bits = 0011 1111 - only two nibbles, not 4.
If two nibbles = 8 bits. If four nibbles = 16 bits.
```

`FF` is simply a human representation for exactly `1111 1111`.

---

### Phase 3 — Code analysis: `printf` with multiple bases

**Input: How many distinct numeric values are there in this program?**
There is only one numeric value. The others are hex and octal representations.

**Transformation: Does the variable `n` change between one line and the next?**
The variable is actually still the same. For the machine, `205` is the same 0s and 1s whether it is in hex, octal, or anything else. What changes is what gets displayed on screen - and that is what the format instructions `%d`, `%x`, `%o` are for.

**Output: What changes between the three printed lines, and what does NOT change?**
What never changes is the number in binary format - "the data" is the same across all representations. What does change is how the screen shows it. But it is the same information.

---

### Phase 4 — Deliverable: Conversion table

*Completed by hand.*

| Decimal | Binary (8 bits) | Hexadecimal |
|---------|-----------------|-------------|
| 0       | 0000 0000       | 0x00        |
| 10      | 0000 1010       | 0x0A        |
| 16      | 0001 0000       | 0x10        |
| 31      | 0001 1111       | 0x1F        |
| 64      | 0100 0000       | 0x40        |
| 127     | 0111 1111       | 0x7F        |
| 128     | 1000 0000       | 0x80        |
| 200     | 1100 1000       | 0xC8        |
| 255     | 1111 1111       | 0xFF        |

---

### Notes

- Phase 1 exit condition: **met**
- Phase 3 key insight confirmed: base is a display layer; the underlying binary value does not change
- Phase 4 deliverable: completed
