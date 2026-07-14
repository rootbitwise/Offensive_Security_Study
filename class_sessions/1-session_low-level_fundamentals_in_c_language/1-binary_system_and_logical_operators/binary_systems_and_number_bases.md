# block_0_recap_initial — Filled
**Date:** Saturday, May 16, 2026
**Block:** 0 — Binary systems and number bases
**Status:** Completed without notes, Google, or AI assistance

---

## 1. Decimal ↔ Binary

**What I understand solidly:**
To convert a number from decimal to binary, divide the number by 2 and take the remainder. Then do the same with the quotient — not the remainder — and repeat. The remainders are collected to represent the number in binary, where the last remainder becomes the leftmost digit ("the last shall be first"). Then you take the 1s — the "on" bits — add them up, and the result should equal the original number.

**What I've seen but don't have down:**
Negative numbers. I don't fully have them down. Also, not all arithmetic operations with binary numbers.

**What I don't know at all:**
Binary subtraction and binary division.

---

## 2. Hexadecimal

**What I understand solidly:**
What I remember is that when you reach 11 or 12, you stop using numbers and use a combination of characters and numbers.

**What I've seen but don't have down:**
The full system. I don't have this topic down.

**What I don't know at all:**
Most of it.

---

## 3. Octal

**What I understand solidly:**
I've seen it and tried it, but I don't remember it well — even though it's one of the easier systems to absorb.

**What I've seen but don't have down:**
The topic as a whole. I don't have it down.

**What I don't know at all:**
—

---

## 4. Binary operations (AND, OR, XOR, NOT, shifts)

**What I understand solidly:**
Binary operations allow the computer to understand and perform what we want. They can manipulate bit by bit — they are essentially the scalpel of C. You can manipulate bits with high precision.

- `AND` = `&` — result is 1 only if both bits are 1
- `OR` = `|` — result is 1 if at least one bit is 1
- `XOR` = `^` — exclusive operator; both bits must be different; same inputs produce 0
- `NOT` = `!` — negation; produces the opposite of the input
- **Shifts** — operators that physically move a bit left or right by N positions

**What I've seen but don't have down:**
—

**What I don't know at all:**
—

---

## 5. Representation of negative numbers

**Sign and magnitude:**
—

**One's complement:**
Unsigned — without sign.

**Two's complement:**
Signed — with sign. The range is split into positive and negative halves to avoid having -0 in the equation. A 1 in the most significant bit represents a negative number; a 0 represents a positive.

**Why does C use two's complement?**
C uses two's complement because most programs deal with both negative and positive numbers, and two's complement makes that representation clean — no duplicate zero, consistent arithmetic.

---

## 6. Related concepts I remember

- **bit / byte:** understood
- **signed and unsigned variables:** understood
- **decimal ↔ binary conversion:** understood
- **logical operators:** understood
- **word:** uncertain
- **endianness:** not noted
- **overflow:** not noted
- **sign extension:** not noted

---

## 7. Honest self-assessment

| Topic | Score |
|-------|-------|
| Decimal/binary/hex conversions without a calculator | 5/10 |
| Binary operations (AND, OR, XOR, shifts) | 10/10 |
| Two's complement with small numbers (8-bit) | 4/10 |
| Two's complement with large numbers (32-bit) | 4/10 |
| Explain why C uses two's complement | 2/10 |

---

## 8. What I expect from this block

By the end of Block 0 (May 31, 2026), I expect to be able to:

- Progress in my study path, review and fully understand C and how computers work at a low level
- Be better equipped to build tools and solve hardware and/or software problems in the future
- Establish the foundation of my understanding and career as an Offensive Security Engineer

---

> This file is not modified after today. It will be compared against `block_0_recap_close.md` on May 31 to measure real progress.
