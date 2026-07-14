# errors.md - TOCD v2 (DAY_04 entries)
**Date:** Tuesday, May 26, 2026
**Block:** 0 - Signed, unsigned, two's complement

### [2026-05-26] - Large power calculations (recurring)

> Context: Phase 2 Problem 2. How many distinct numbers can a `short` (16 bits) represent?

**Error:** Answered 32,768 for unsigned and -16,384 to +16,383 for signed.

**Root cause:** Confused `2^15` with `2^16`. A `short` is 16 bits, so the total is `2^16` = 65,536 combinations, not 32,768. The signed asymmetry (-32,768 to +32,767) is calculated starting from the correct total, not the one I assumed.

**Fix:** Memorize the powers of 2 table up to `2^16`:

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
2^31 = 2,147,483,648
2^32 = 4,294,967,296
```

Correct values for the problem:
- short unsigned: 65,536 combinations (0 to 65,535)
- short signed: 65,536 combinations, range -32,768 to +32,767

**Learning:** This is the third error of the same type in the block:
- DAY_02 Quiz 2.1: `2^12` = 49,152 (was 4,096)
- DAY_02 verification: `2^32` = 16,777,216 (was 4,294,967,296)
- DAY_04 Phase 2 P2: `2^16` = 32,768 (was 65,536)

Clear pattern: underestimating large powers. The solution is not to memorize more calculations but to keep the table visible until it becomes automatic. Write the table on a separate sheet to have it in view during block and future block practice.

### [2026-05-26] - Two's complement procedure on `1000 0000`

> Context: Phase 2 Problem 4. Apply two's complement to `1000 0000` and observe what happens.

**Error:** After correctly obtaining `1000 0000` as the result of the procedure (invert + add 1), added the result with the original byte again, getting `1 0000 0000` and concluding that "the result is 0."

**Root cause:** Confused the procedure. Two's complement is a single addition step (invert bits, then add 1). There is no second addition with the original byte. Adding the result with the original byte is no longer the procedure - it is a different operation (verification, not construction).

**Fix:** The correct and complete procedure:

```
1000 0000          <- original byte (-128)
Invert:    0111 1111
Add 1:   + 0000 0001
         -----------
           1000 0000   <- result of the procedure
```

`1000 0000` is its own two's complement. The procedure ends here. Nothing else is done.

**Practical implication:** if a program calls `abs(-128)` on a `signed char`, the procedure returns `-128` (not `+128`, because +128 does not fit in the range). `abs(INT_MIN)` is documented as undefined behavior in `<stdlib.h>` in C.

**Learning:** Procedures end where the problem statement says they end. If unsure, re-read the procedure before adding extra steps. One extra step can lead to a completely different conclusion.

### [2026-05-26] - `1111 1111` in signed = -1, not 0

> Context: Phase 4 Set B row 3. Interpretation of the pattern `1111 1111`.

**Error:** Answered unsigned: 255, signed: 0.

**Root cause:** Did not apply the two's complement rule to the pattern. Possibly confused with `1000 0000` or assumed that "all ones means neutralized."

**Fix:** Apply the quick rule: if the pattern is signed and the MSB is on, subtract 256 from the unsigned value.

```
1111 1111   unsigned: 255
            signed:   255 - 256 = -1
```

Or by building the negative:
- `1111 1111` inverted is `0000 0000`
- + 1 = `0000 0001` = 1
- So `1111 1111` represents the negative of 1, which is -1

**Learning:** To quickly verify any signed value whose MSB is on: calculate the unsigned value, subtract 256 (for 8 bits) or `2^N` for N bits.

### [2026-05-26] - Signed integer overflow (Set D incomplete)

> Context: Phase 4 Set D. Predict overflow results in signed char.

**Errors:**
- Row 1 (`127 + 1`): no clear answer on paper.
- Row 2 (`127 + 2`): answered -128, but `127 + 2 = 129` overflows to -127, not -128. The -128 result belongs to `127 + 1`.
- Row 5 (`-100 - 50`): answered +98, but the correct result is +106. The intermediate development got tangled.

**Root cause:** Did not follow the mechanical procedure step by step. Tried to calculate the result by intuition ("-150 exceeds the range, it must be a positive") without doing the 8-bit binary addition.

**Fix:** Mechanical procedure for each signed overflow case:

1. Convert both operands to 8-bit binary (using two's complement if negative).
2. Add bit by bit.
3. Discard the final carry if it exceeds 8 bits.
4. Interpret the result as signed (look at MSB).

Applied to row 5 (`-100 - 50` = `-100 + (-50)`):

```
-100 = 1001 1100
-50  = 1100 1110
Sum: 1001 1100 + 1100 1110 = 1 0110 1010
Discard carry: 0110 1010
MSB = 0, positive: 64 + 32 + 8 + 2 = 106
Result: +106
```

**Learning:** Signed integer overflow is not solved by intuition. The mechanical procedure is the only reliable path. The rule "if it exceeds the range, it wraps to the other extreme" is generally true but does not give the exact value - for that, the binary addition must be done.

**Pending practice:** repeat Set D in full before closing Block 0 on May 31. It is the weakest concept in the block.

### Recurring errors to watch in DAY_05 and block close

1. Powers of 2 - keep the `2^8` to `2^32` table visible until it is automatic. This error has appeared 3 times in the block.
2. Complete procedures vs extra steps - do not add operations the procedure does not ask for. Re-read the problem before adding or removing steps.
3. MSB on + signed = subtract 256 - quick rule to avoid recalculating bit by bit on every interpretation.
4. Integer overflow is done mechanically - binary addition, discard carry, interpret MSB. Not by intuition.

---

*File: errors_day_04.md (entries to add to the cumulative errors.md)*
*Closed: Tuesday, May 26, 2026*

_AND OF DOCUMENTS_
