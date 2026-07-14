# day_01_corrections.md
**Date:** Saturday, May 16, 2026
**Source:** Claude feedback on BRAIN_OS_DAY01_responses + block_0_recap_initial_filled
**Purpose:** Document errors, corrections, and open questions to resolve during Block 0

---

## BRAIN OS — Block A (9 coins)

**What was right:**
The procedure works logically. Fixing one coin and comparing one by one does eventually identify the fake coin — either a side drops or the fixed coin turns out to be the light one.

**What was wrong:**
The question asked for the *guaranteed minimum*. Comparing one at a time against a fixed coin requires up to **8 weighings** in the worst case — not 6. The "6" had no reasoning behind it; it was an estimate.

**The real gap:**
The balance was being used as if it only gives **two outcomes**. It gives **three**: left heavier, right heavier, balanced. With 3 outcomes per weighing, N weighings distinguish **3^N states**.

**Open question (carry into DAY_02):**
- How many outcomes does the balance give per weighing?
- With that number: how many states can you distinguish with 2 weighings?
- Given 9 coins — how do you split them on the first weighing?

*Do not look up the answer. Reason it out before Tuesday.*

---

## BRAIN OS — Block B (binary mind map)

**What was solid:**
> "All data is 0s and 1s. Physical memory reserves regions of one byte = 8 bits. Those 8 bits are literally 8 digits that can be 0 and/or 1."

That is the correct hardware model to start from. Keep it.

**Correction 1 — the leftmost bit:**
The statement "positive = 0 on the left, negative = 1 on the left" is only true for **signed numbers**. For **unsigned** numbers, there is no sign bit — all 8 bits carry value, and `1111 1111` = 255, not -1.

→ **Gap to log:** *"I don't yet distinguish when the leftmost bit is a sign bit and when it is part of the value."*

**Correction 2 — word size:**
A "word" is not a fixed 4 bytes. It is the natural register size of the CPU — architecture-dependent. On x86-64 (the MSI), the working word is **64 bits**. Historically "word" meant 16 bits. The term is ambiguous. Low-priority for now.

**Correction 3 — hexadecimal:**
The intuition ("combines numbers and letters") points in the right direction but misses the *why*. Hex was not invented to look clean. There is an exact relationship between one hex digit and a specific number of bits. This gets built in **DAY_04**. Do not research it before then.

**Stack/heap note:**
Not knowing how to draw the storage (stack vs. heap) is not a gap — it is not in scope until Block 3 (August). Correctly identified as out of scope.

---

## BRAIN OS — Block C (pseudocode bug)

**What was right:**
> "`/` in C uses the ALU. `5 / 3` = 1. No decimals."

Correct. Integer division truncates toward zero. That is the kind of detail an attacker exploits and an analyst catches. This point is solid.

**Correction 1 — operand order was reversed:**
The code reads `counter / length(list)`. That is `counter ÷ length`. The response read it as `length ÷ counter`. Rule: the operand to the **left** of `/` is divided by the operand to the **right**.

Also: `1 / 1 = 1`, not `0`.

**Correction 2 — what `return` does:**
The statement *"this line makes the list always empty"* is incorrect. `return` **computes a value and returns it to the caller**. It does not modify the list, empty it, or touch it in any way. A function that returns `counter / length(list)` leaves the list exactly as it was.

→ **Fix this now, before writing any real C.** `return` will appear in every function you write.

**The actual bug (not identified):**
The exercise gave a direct hint: *"What happens if `list` is empty?"*

- If `list` has no elements, `length(list)` = **0**
- The line `return counter / length(list)` becomes `counter / 0`
- Division by zero in C on an integer type is **undefined behavior** — the program may crash, produce garbage, or behave unpredictably depending on the platform

→ That is the bug. An attacker who controls `list` can pass an empty list and trigger undefined behavior. In certain contexts that is exploitable.

**Open question (answer before DAY_02):**
What does a C program actually do at runtime when integer division by zero occurs? Look at it from the OS/CPU level — what signal gets raised?

---

## block_0_recap_initial — Corrections

### AND operator

**Written:** *"result is 1 if both are equal"*
**Correct:** `AND` is 1 **if and only if both bits are 1**. `0 AND 0` = 0 — both are equal but result is 0. The word "equal" is wrong here and will cause errors.

### NOT operator

**Written:** `NOT = !`
**Correct:** In C there are two distinct NOT operators:
- `!` — **logical NOT** (operates on true/false: `!5` = `0`)
- `~` — **bitwise NOT** (inverts every bit: `~0000 0101` = `1111 1010`)

For binary operations, the operator is `~`, not `!`. This distinction is covered in **DAY_03**.

### XOR operator

**Written:** *"both must be different — mandatory"*
**Status:** Incomplete, not wrong. Describes when XOR gives 1 but omits the other case: when both bits are the same, XOR gives **0**.

### Corrected 10/10 self-score on binary operations

The actual score based on the above corrections is approximately **6/10**. The *concept* is there; the *exact mechanics* are not. This is not a setback — it is what the block exists to fix.

### Complement notation — critical cross-wire

**Written:** *"one's complement = unsigned / two's complement = signed"*
**Correct:** This is wrong at the root. Two separate concepts were conflated:

| Concept | What it means |
|---------|---------------|
| signed / unsigned | Whether a type allows negative values |
| one's complement / two's complement | Two different *methods* for representing negatives |

One's complement and two's complement are **both** methods for signed numbers. Unsigned has no negatives to represent — it uses neither. This is the core of Block 0 week 2 (May 25–31).

### Why C uses two's complement — still open

The answer given (*"because most programs use both positive and negative numbers"*) does not answer the question. That is why signed/unsigned exists — not why C chose two's complement over one's complement. This is the **block closing condition**. It must be answerable out loud, without notes, by May 31.

---

## Adjusted self-assessment table

| Topic | Self-score | Corrected score | Action |
|-------|-----------|-----------------|--------|
| Decimal/binary conversion | 5/10 | 7/10 | Quick review, no new theory |
| Hexadecimal | — | 2/10 | Build from scratch — DAY_04 |
| Octal | — | 2/10 | Build from scratch — DAY_04 |
| Binary operations (AND/OR/XOR/NOT/shifts) | 10/10 | ~6/10 | Correct AND, NOT, XOR — DAY_03 |
| Two's complement (8-bit) | 4/10 | 3/10 | Core of week 2 |
| Why C uses two's complement | 2/10 | 2/10 | Block closing condition — May 31 |

---

## Open questions before DAY_02 (Tuesday, May 19)

1. **Coins:** How do you split 9 coins using the 3-outcome property of the balance? How many weighings minimum?
2. **Division by zero:** What does the CPU/OS actually do when integer division by zero occurs in C? What signal?
3. **Block 0 goal rewrite:** Rewrite section 8 of `block_0_recap_initial_filled.md` with three concrete, measurable outcomes — not career motivation.

---

> This file is read-only after today. It documents the state of knowledge at the start of Block 0 — errors included.
