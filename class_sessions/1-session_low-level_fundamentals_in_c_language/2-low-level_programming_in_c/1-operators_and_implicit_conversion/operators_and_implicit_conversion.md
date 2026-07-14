# DAY_09 - OPERATORS AND IMPLICIT CONVERSIONS
* **Date:** Thursday, June 11, 2026
* **Block:** 1 of Season 1 - Foundation C
* **Status:** Completed. All five predictions correct, vocabulary refinements noted.

### Vim tip of the day

`.` (the dot) repeats the last edit command. Example: change several `int` to `int32_t` across lines. Position the cursor on the first `int`, run `ciw int32_t Esc` to change it, move to the next `int` with `j` and position the cursor, then press `.` to repeat the entire change without retyping. Combine with search: `/int Enter` finds the next occurrence, `n` jumps to it, `.` applies the repeated change. The combination `n` + `.` is one of the fastest ways to do repetitive edits in Vim.

### Conceptual questions before Phase 2

> Are implicit conversions always happening? Meaning, is arithmetic not done between numbers of different types like a char + int? Is there integer promotion to char, because there is no number smaller than char, or does it happen?

Integer promotion is when there is an implicit conversion, a smaller type gets promoted to a larger type causing checks or comparisons to fail when reading numbers larger than expected for the program. Being more precise, the bugs tend to be in the logic written by the programmer plus the silent promotions.

This is dangerous because it is silent. If it is not someone who is conscious that this can happen, most likely it will happen, and when it happens they will not know what is going on, will not know what to do, or worse, the error will remain in the code for a long time.

The smaller number always gets promoted to the larger number. If it is a number smaller than int, then before doing the arithmetic the smaller number gets promoted to int.

> Not always - only when there is a type mismatch or when a type is smaller than int. char/short always promote upward to int, never the other way. char is the minimum unit (1 byte), there is no standard integer type smaller than char, so char is always the one being promoted, never the destination of a promotion. The definition given is correct, with one vocabulary refinement: what was described (checks failing on larger numbers) is more specifically the signed to unsigned conversion, not integer promotion in general. Integer promotion is char/short to int. The signed to unsigned conversion is the one that turns -1 into 4 billion. Both are "implicit conversions" but they are different mechanisms.

### Phase 2 - Reasoning

#### Problem 1

> ```c
> int a = 7;
> int b = 2;
> printf("%d\n", a / b);
> printf("%d\n", a % b);
> ```
> What does this print?

By truncation, the division with "/" will print 3. By the ALU, this prints "1" - this is like taking the remainder of a division, or literally is.

> Both correct. 7/2 in integer division is 3, 7%2 is 1 because 2*3=6 and 7-6=1.

#### Problem 2

> ```c
> printf("%d\n", 7 / 2);
> printf("%f\n", 7 / 2.0);
> ```
> Reason: in the first, both are integers. In the second, one is double. What difference does it make?

The difference is that it shows results with decimals. The first one does truncation, does not use decimals, and the second one is forced to use decimals in the division. 7 / 2.0 = 3.5

> Correct. 7/2 = 3 (integer, truncated), 7/2.0 = 3.5 (one operand is double, forces floating point division).

#### Problem 3

> ```c
> unsigned int a = 10;
> int b = -20;
>
> if (a + b > 0) {
>     printf("positivo\n");
> } else {
>     printf("negativo o cero\n");
> }
> ```
> Reason: a + b mixes unsigned with signed. What conversion happens? a is 10, b is -20. Mathematically 10 + (-20) = -10. But what happens when b converts to unsigned before the addition?

The variable unsigned int a "rules, not literally" first because of its size, so b is going to be promoted to an unsigned int b. Since it is a negative number it has the MSB at 1, and by sign extension the new bits of b get filled with 1s. So what happens after the promotion is the addition: a + b = 1111 1111 1111 1111 1111 1111 1110 1100 > 0 = true. Or in the same way, the -10 in binary also goes through this because the if reads it as unsigned numbers for these comparisons.

> Correct and well reasoned. The result of a + b is 1111 1111 1111 1111 1111 1111 1111 0110, which as unsigned is 4,294,967,286 (which is -10 reinterpreted). Greater than 0, prints "positivo". One vocabulary refinement: there is no width extension here (both are already 32 bits) - it is reinterpretation of the same bit pattern from signed to unsigned. The bits of -20 were already 1111...1110 1100 in 32-bit signed; the conversion to unsigned does not change the bits, only how they are read. Sign extension would apply going from 8 or 16 bits to 32.

#### Problem 4

> ```c
> char a = 100;
> char b = 100;
> int  resultado = a + b;
> printf("%d\n", resultado);
> ```
> Reason: a and b are char, but by integer promotion they promote to int before adding. Does the result overflow or not? The sum is done in int. Does 200 fit in int?

It does not overflow because it fits, and even if int were unsigned the same would happen because they are positive numbers, the value does not change because the new bits are 0s, meaning the binary of each number stays "intact."

> Correct. Does not overflow. 100 + 100 = 200, the sum is done in int (by promotion), 200 fits comfortably in int. Stored in int, it stays 200. The extra observation about int being unsigned is also correct - it would not matter, because 200 is positive and fits in both, and the bits remain intact.

#### Problem 5

> ```c
> char a = 100;
> char b = 100;
> char resultado = a + b;
> printf("%d\n", resultado);
> ```
> Reason: identical to the previous one BUT the result is stored in char, not int. The sum is done in int (200 fits), but assigning to char truncates. What value remains? Compare with Problem 4.

Here it does overflow, because: first the sum of a + b is promoted to int, up to that point everything is fine, the result of that sum gives 0000 0000 0000 0000 0000 0000 1100 1000. But when storing the result in a smaller variable, truncation happens, and since this variable is signed, 200 has the MSB on leaving the result as -56. The promotion happens, but in this case the result is stored in a variable smaller than 32 bits, so truncation occurs discarding the rest of the bits, including the MSB at 0 of the sum result in int, leaving the MSB at 1 because only the 8 lowest bits were taken.

> Correct and excellent explanation. The sum promotes to int: 0000 0000 0000 0000 0000 0000 1100 1000 (200). Stored in char (8 bits), it truncates to the low 8 bits: 1100 1000. Since char is signed and the MSB ended up at 1, it is interpreted as -56. The distinction between Problem 4 (stores in int, no truncation, stays 200) and Problem 5 (stores in char, truncates, becomes -56) is exactly the concept of the day: where you store the result determines whether truncation happens, regardless of where the operation was performed.

### Session Summary

#### What is solid

- Integer division truncates toward zero, modulo gives the remainder.
- Floating point division requires at least one operand to be double.
- The trap in Problem 3: signed converts to unsigned when compared at the same width, -10 becomes a huge positive number, "positivo" prints.
- Integer promotion: char/short always promote to int before arithmetic.
- The difference between operating in int (no truncation, Problem 4) and storing in char (truncation, Problem 5).

#### Vocabulary refinements (not errors, not added to errors.md)

1. Integer promotion (char/short to int) versus signed to unsigned conversion (reinterpretation). Two different mechanisms under the umbrella of "implicit conversions."
2. Sign extension (width change, fills new bits) versus reinterpretation (same width, same bits, different reading). Problem 3 was reinterpretation, not extension.

Expected compiled output: P1 gives 3 and 1, P2 gives 3 and 3.500000, P3 gives "positivo", P4 gives 200, P5 gives -56.

---

_AND OF DOCUMENTS_
