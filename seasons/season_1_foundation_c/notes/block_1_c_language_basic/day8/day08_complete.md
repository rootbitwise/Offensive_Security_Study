# DAY_08 - PRIMITIVE TYPES, SIZEOF AND FORMAT SPECIFIERS
**Date:** Monday, June 8, 2026
**Block:** 1 of Season 1 - Foundation C
**Status:** Completed

### Vim tip of the day

`ciw` = change inner word. Executed in normal mode.

Steps: position the cursor over any letter of a word, type `c`, then `i`, then `w`. Vim deletes the full word and drops into insert mode automatically. Type the replacement, then press `Esc` to return to normal mode.

| Command | What it does |
|---------|--------------|
| `ciw` | Change word without surrounding spaces |
| `caw` | Change word with surrounding spaces |
| `ci"` | Change content inside double quotes |
| `ci'` | Change content inside single quotes |
| `ci(` | Change content inside parentheses |
| `ci[` | Change content inside brackets |
| `ci{` | Change content inside braces |
| `cit` | Change content inside HTML/XML tags |

General rule: `c` + `i` + delimiter = change inside that delimiter. Replace `c` with `d` to delete without entering insert. Replace with `y` to copy.

### Phase 2 - Reasoning

#### Problem 1

> ```c
> char x = 200;
> printf("%d\n", x);
> ```
> What does this code print?

x = 200 is interpreted as -56, char in this case is of type signed which means its range is -128 to +127, 200 does not fit in that range so read in binary in that range it would be -56, the value would be making a "jump" not literally. printf would be interpreting 200 as -56 because %d shows the signed value.

> Correct.

#### Problem 2

> ```c
> unsigned char x = 250;
> unsigned char y = 10;
> unsigned char z = x + y;
> printf("%u\n", z);
> ```
> What does this code print?

Something similar to the previous would be happening, the value does not fit, but being an unsigned value with a range of 0 to 255, the binary sum gives a smaller value than what would be expected. printf would interpret the value as unsigned char, z would not be 260 but would show...

> Correct reasoning, incomplete - the final value was not given. The correct answer is 4.

#### Problem 3

> ```c
> int       a = -1;
> long long b = a;
> printf("%lld\n", b);
> ```
> What does this code print?

int a = -1 is a 32 bit variable, when passed to a long long variable (64 bits) it receives the value 1111 1111 1111 1111... continues until the 64 bits are on, by sign extension it is still -1, the value did not change. printf lld shows -1, printf interprets long long signed so the value is still -1.

> Correct.

#### Problem 4

> ```c
> int8_t   a = 100;
> int8_t   b = 50;
> int8_t   suma = a + b;
>
> uint32_t big = 0xDEADBEEF;
> char     letra = 65;
>
> printf("suma = %d\n", suma);
> printf("big = %u\n", big);
> printf("big = 0x%X\n", big);
> printf("letra como char: %c\n", letra);
> printf("letra como int:  %d\n", letra);
> ```
> Predict the 5 exact lines of output.

The three first variables are declared as exact 8-bit integers, when showing the value in printf with %d the value is shown with sign -106, in this case what happened in the previous problems happens, it is a data overflow, the binary sum is correct, where confusion happens is in the interpretation of this data, first a sum is being made that does not fit within the signed range, this would be a UB, and then it is being interpreted as signed.

The uint32_t variable is reserving exactly 32 bits, when passed to printf with the format %u it is being interpreted as unsigned value so it does not matter that the MSB is on it is not taken as reference of the value, the value is 3,735,928,559. When passed to printf with the format %X the value is interpreted as hex number in uppercase.

The char variable is interpreted as signed in this case, when passed with the format %c it is being interpreted as a character from the ASCII table specifically the character that corresponds to number 65, and when passed with the format %d it is being interpreted as a signed decimal variable that shows the literal value it contains: 65.

> Correct on all five lines.

---

### Phase 3 - Blind Code Reading

#### First comparison

> ```c
> int8_t   a = -1;
> uint8_t  b = 255;
>
> if (a == b) {
>     printf("son iguales\n");
> } else {
>     printf("son diferentes\n");
> }
> ```
> What prints? Are the bits the same? How does C compare them?

```c
int8_t   a = -1;    // valid, -1 fits inside an int8_t variable
uint8_t  b = 255;   // valid, it is the exact maximum that fits
```

"son diferentes" prints on screen because they are different.

> Correct.

#### Second comparison

> ```c
> int      x = -1;
> unsigned y = 4294967295U;
>
> if (x == y) {
>     printf("x == y\n");
> } else {
>     printf("x != y\n");
> }
> ```
> What prints?

```c
int      x = -1;            // valid, the compiler assumes int as signed
unsigned y = 4294967295U;   // I do not know if writing only unsigned without
                            // specifying what type of data is valid, I do not
                            // know if the compiler assumes it is an int or char
                            // so I cannot predict the output of this line of code
```

"x != y" prints on screen.

> Incorrect. The program prints "x == y". When one operand is signed and the other is unsigned at the same width, C converts the signed to unsigned before comparing. -1 as unsigned 32-bit becomes 4,294,967,295. Both sides become identical bits. Also: writing only `unsigned` is valid in C - the compiler assumes `unsigned int` by default.

#### C compares bits or values?

> Does C compare bits or values?

The values are really bits, the text editor or IDE shows them in a more human-friendly way but they are really bits.

> Partially correct. More precise: C compares the bits AFTER promoting both operands to a common type. The promotion can change the interpretation before the comparison happens.

---

### Phase 4 - format_demo.c observation

> After running `format_demo.c`, are the outputs for `valor_signed` and `valor_unsigned` identical or different? Why?

It looks like the compiler forces the data to be shown with sign regardless of whether the variable is unsigned, because the data is being passed to printf with the signed format so it interprets the data as signed.

> Correct reasoning, one precision needed: it is not the compiler doing this at runtime - the compiler already finished its work. What decides how the bytes are read is the format specifier in the printf call. `printf` cannot see the declared type of the variable, only the bytes on the stack and the format string. The format string is the only authority.

---

### Session Summary

#### What is solid

- char as signed by default in GCC x86-64, overflow to -56 when 200 is assigned.
- unsigned overflow is modular and predictable, not UB.
- Sign extension from int to long long preserves the numeric value.
- Format specifier controls how printf reads bytes, not the declared type.
- 0xDEADBEEF as uint32_t reads as 3,735,928,559 unsigned.
- ASCII 65 = A, readable with both %c and %d.
- `unsigned` alone is valid C, compiler assumes `unsigned int`.

#### What to watch

- Problem 2: always give the exact decimal value at the end of the reasoning, not just the direction. The prediction is incomplete without a concrete number.
- Second if comparison: when signed and unsigned of same width meet in a comparison, the signed converts to unsigned. -1 becomes 4,294,967,295. The result is equality, not difference.
- The distinction between what the compiler does at compile time and what printf does at runtime.

---

*File: DAY_08_COMPLETE.md*
*Closed: Monday, June 8, 2026*

_AND OF DOCUMENTS_
