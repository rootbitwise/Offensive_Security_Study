# errors V1

Log of errors found during the track. Each entry includes context, observed error, root cause, fix, and learning.



### [2026-05-23] — Digit position in multi-digit hex

**Context:** Quiz 1, Q1.3. Convert 0xC4 to decimal showing the development with coefficient times power.

**Error:** Answered `13*1 = 13, 4*1 = 4, total 17`. Treated both digits as if they were at position 0 (both multiplied by 1).

**Root cause:** Did not internalize that in positional notation, each digit has its own position. In a number of N digits, positions are N-1, N-2, ..., 1, 0 counted from the right. For 0xC4 (2 digits):
- C is at position 1 — C*16^1 = 12*16 = 192
- 4 is at position 0 — 4*16^0 = 4*1 = 4
- Total: 192 + 4 = 196, not 17.

**Fix:** Before calculating, write the position of each digit explicitly on paper. For 0xC4: write "C(pos 1) 4(pos 0)" above each digit.

**Learning:** This is the same error as `0xF001` from Monday May 18. Recurring pattern. The universal rule: digit times base^position, where position is counted from the right starting at 0. No shortcuts.

---

### [2026-05-23] — Calculating 2^12

**Context:** Quiz 2, Q2.1. How many combinations can be represented with 12 bits, using doubling from 256 = 2^8.

**Error:** Answered 49,152.

**Root cause:** Did not verify the procedure. 49,152 is not a power of 2 (it is 256 times 192, unrelated to successive doubling).

**Fix:** Correct doubling method:
- 8 bits = 256
- 9 bits = 512
- 10 bits = 1,024
- 11 bits = 2,048
- 12 bits = 4,096

Each additional bit doubles the total, never adds.

**Learning:** For small to medium powers of 2, the doubling method from a known power is faster and safer than trying to calculate 2^N directly.

---

### [2026-05-23] — Misreading the problem statement in Quiz 1

**Context:** Quiz 1, Q1.4. "What is the largest binary number that fits in 6 bits?"

**Error:** Answered `1111 1100 = 252, 0xFC`, assuming 8 bits with 6 bits turned on.

**Root cause:** Did not read the problem carefully. "6 bits" refers to the register width, not to the number of bits turned on inside an 8-bit register.

**Fix:** Correct reading of the problem:
- 6 bits wide: `111111` (all ones)
- Decimal: 63
- Hex: 0x3F

**Learning:** On quiz problems, read twice before answering. Distinguish between "register width" and "bits turned on in a register" — they are different concepts.

---

### [2026-05-23] — Asymmetric signed range

**Context:** Quiz 2, Q2.3. Interpretation of `1000 0000` as signed with two's complement.

**Error:** Answered -127.

**Root cause:** Assumed symmetry in the signed range (-127 to +127). In reality, two's complement gives an asymmetric range because it eliminates the duplicate zero (there is no -0 and +0, only 0).

**Fix:** Correct range for 8-bit signed with two's complement:
- Minimum: -128 (bits: `1000 0000`)
- Maximum: +127 (bits: `0111 1111`)

The bit pattern `1000 0000` represents -128, not -127. There is one more negative than positive because zero is counted only once.

**Learning:** Note and memorize: signed N-bit has range -2^(N-1) to +2^(N-1) - 1. Asymmetric. Week 2 topic of the block, but the numeric pattern goes into the error log now.

---

### [2026-05-23] — NOP sled forgotten

**Context:** Quiz 2, Q2.7. Long run of bytes 0x90 in a memory dump.

**Error:** Answered "ASCII/BIN/BASH" — a technically meaningless answer, possibly confused with Q2.5.

**Root cause:** Did not recall the concept even though it was explicit in the CTI Overlay of DAY_02 itself. Retention failure, not a comprehension failure.

**Fix:** Correct answer:
- Technique observed: NOP sled
- 0x90 is the x86 NOP instruction ("no operation")
- Use: padding before shellcode so the execution flow "slides" to the real code when the attacker does not know the exact address
- MITRE: T1055 (Process Injection)

**Learning:** CTI Overlay concepts must go into active notes, not just be read in class. Create a `cti_overlay_block_0.md` document with a one-minute-reviewable summary of each MITRE technique seen.

---

### [2026-05-23] — Nibble order in decimal to hex conversion

**Context:** Phase 4 Set D, row 512.

**Error:** Converted 512 to `0000 0010 0000 0000` and answered 0x020.

**Root cause:** Read the nibbles in reverse order. The binary is correct: 0010 0000 0000. But when translating the nibbles, kept the wrong order.

**Fix:** Nibbles are read left to right, same as any hex number:
- High nibble (leftmost): `0010` = 2
- Middle nibble: `0000` = 0
- Low nibble (rightmost): `0000` = 0
- Result: 0x200, not 0x020.

**Learning:** Nibble order is not reversed the way division remainders are. The reversal only applies to the successive division method for converting decimal to binary, where the remainder is read bottom to top. Once you have the binary, it is already in the correct order.

---

### [2026-05-22] — SHR confused with SHL

**Context:** DAY_02 Phase 3. Reading C code with `(byte >> i) & 1`.

**Error:** Described `>>` as "moving bits to the left."

**Root cause:** Confusion between the two shift operators. Did not memorize the arrow direction as a mnemonic.

**Fix:**
- `<<` is SHL (Shift Left) — moves bits to the left
- `>>` is SHR (Shift Right) — moves bits to the right

Mnemonic: the arrows point in the direction the bits move.

**Learning:** Operators with explicit visual direction (arrows) should be memorized by the graphic direction, not by the name. Formal close in DAY_03.

---

### [2026-05-22] — Power notation with the `^` symbol

**Context:** Phase 2 Problem 2. Reasoning through the formula for 0xFFF.

**Error:** Wrote `16^16 are 4 nibbles 16 bits`, meaning to say "16 raised to positions 0, 1, 2."

**Root cause:** The symbol `^` was used as if it meant multiplication. In mathematical notation `^` is exponentiation.

**Fix:** Correct notation:
- `16^2` (read "16 squared") = 256
- `16^1` (read "16 to the one") = 16
- `16^0` (read "16 to the zero") = 1
- `16^16` means 16 raised to the 16th power, an astronomically large number

**Learning:** In mathematical and programming notation, `^` between numbers is always exponentiation. The confusing part is that in C, `^` is XOR — but that is a bitwise operation, not mathematical notation.

---

### Universal rules derived from these errors

1. Position governs: in any base, the value of a digit = digit times base^position. Position is counted from the right starting at 0.

2. N bits = 2^N combinations. Every bit added doubles the total.

3. Padding goes to the left. Padding to the right multiplies the number.

4. Nibbles are grouped from the right but read from left to right.

5. Shift direction equals arrow direction. `<<` left, `>>` right.

6. The symbol `^` in math is exponentiation, in C it is XOR. Context governs.

7. The type, not the bits, determines whether a value is signed or unsigned. The same bit pattern can mean different things depending on the type.

8. Signed with two's complement has an asymmetric range: -2^(N-1) to +2^(N-1) - 1.

---

_AND OF DOCUMENTS_
*Last updated: Saturday, May 23, 2026*
