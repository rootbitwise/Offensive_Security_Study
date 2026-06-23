# _DAY 11 - ARRAYS AND THE LIMITS OF MEMORY_

* **Date:** Tuesday, June 23, 2026
* **Block:** 1 of Season 1 - Foundation C
* **Status:** Completed. 6/6 reasoning problems correct, Phase 1 exit conditions met.


### Phase 1 - Exit conditions

> 1. At what index does an array start and what is the last valid index in an array of size N?
> 2. What does C do when you access outside the limits of an array?
> 3. Why does C not check limits, and who is responsible then?
> 4. What is a buffer and what is a buffer overflow?

It starts at index 0 up to N-1 of the buffer size.

C does nothing. C assumes the programmer knows. What it can do is make the code produce undefined behavior.

By design C was made to be fast and does not add extra code to examine sizes. The programmer is responsible for verifying that everything is written correctly and for anticipating this.

A buffer overflow is literally reading or writing outside the limits of the buffer, memory that does not belong to the buffer.

> All four correct.

### Phase 2 - Reasoning

#### Problem 1

> ```c
> int a[4] = {100, 200, 300, 400};
> printf("%d\n", a[0]);
> printf("%d\n", a[3]);
> ```
> What does this print?

It prints the first and last value of the buffer, because the first value is index 0 and the last is index 3, since it only has 4 values and goes from 0 to 3 in this case. It prints 100 and 400.

> Correct.

#### Problem 2

> ```c
> int x[10];
> char y[3];
> int z[] = {5, 10, 15, 20};
> ```
> How many elements does each array have and what are its valid indexes?

The buffer x has 10 elements, or rather space for 10 elements since they are not explicitly declared in the code.

The buffer y also does not have its elements declared in the code, but it does have space for 3 elements available.

The buffer z did not declare any specific size but did declare 4 elements that are inside the buffer, it does not have a maximum index declared.

> Correct on the counts. Two vocabulary refinements: "not declared" vs "not initialized" - the space exists and is accessible (x[0] through x[9] are valid indexes), but reading them before assigning a value gives unpredictable garbage. For z: the empty `[]` does not mean "no limit" - it means "count them, compiler." The array has a fixed size of 4 once compiled.

#### Problem 3

> ```c
> int notas[5] = {10, 20, 30, 40, 50};
> for (int i = 0; i <= 5; i++) {
>     printf("%d\n", notas[i]);
> }
> ```
> What is wrong with this code?

The for loop condition is that while i is less than or equal, making the for access memory space outside the buffer. It is not a valid index. It would be valid with `<= 4` or `< 5`.

> Correct. This is the off-by-one error. On the sixth iteration i equals 5 and `notas[5]` reads memory that does not belong to the array. Undefined behavior.

#### Problem 4

> ```c
> int v[5] = {2, 4, 6, 8, 10};
> int suma = 0;
> for (int i = 0; i < 5; i++) {
>     suma += v[i];
> }
> printf("%d\n", suma);
> ```
> What does this print? Reason through the full loop.

suma would print 30. On each iteration the values of the buffer get added. When suma exits the for it exits with a value of 3, suma 0 + 2, +4, +6 etc.

> Correct result (30), small slip in writing: "exits with value of 3" was a typo, the described accumulation 0+2+4+6+8+10 correctly gives 30. Verified by compiling.

#### Problem 5

> ```c
> int datos[8];
> // sizeof(int) is 4 on this system
> ```
> What is the value of each expression?
> - `sizeof(datos)` = ?
> - `sizeof(datos[0])` = ?
> - `sizeof(datos) / sizeof(datos[0])` = ?

1. This is 32, 8 elements times 4 bytes.
2. This equals one element.
3. This equals 8, this gives the size of the buffer.

> Correct values. One refinement on point 2: "one element" - the exact number is 4 bytes. And on point 3: `sizeof(array) / sizeof(array[0])` gives the number of elements (8), not the size in bytes (which would be 32). The formula divides the total size by the size of one element, giving how many elements there are.

#### Problem 6

> ```c
> #include <stdio.h>
>
> int main(void)
> {
>     int numeros[6] = {15, 3, 27, 8, 42, 19};
>
>     int mayor = numeros[0];
>     int menor = numeros[0];
>
>     for (int i = 1; i < 6; i++) {
>         if (numeros[i] > mayor) {
>             mayor = numeros[i];
>         }
>         if (numeros[i] < menor) {
>             menor = numeros[i];
>         }
>     }
>
>     printf("Mayor: %d\n", mayor);
>     printf("Menor: %d\n", menor);
>
>     return 0;
> }
> ```
> Why do mayor and menor start at numeros[0]? Why does the loop start at i=1? Trace the full loop and predict the output.

First a buffer of 6 elements is declared, then two variables are declared and both store the first element of the buffer, meaning both equal 15 before entering the loop.

If the index is greater than the variable mayor then assign that value to it, but since the loop starts at index 1 the value of the buffer at that moment is 3, and 3 is not greater than the variable mayor because it has the value of 15 so it jumps to the other if. On the next iteration of the for it says if numeros which at that iteration equals 3 is greater than mayor which is still 15, then no and it jumps to the other if.

```
if 3 > 15   // no
if 27 > 15  // yes, now mayor equals 27
if 8 > 27   // no
if 42 > 27  // yes, now mayor equals 42
if 19 > 42  // no
```

mayor exits with value 42.

```
if 3 < 15   // yes, now menor equals 3
if 27 < 3   // no
if 8 < 3    // no
if 42 < 3   // no
if 19 < 3   // no
```

menor exits with value 3.

> Correct and excellent. The full trace matches. Both design questions answered correctly: mayor and menor start at numeros[0] because you need a real starting point from the array, not an arbitrary 0 (if menor started at 0, no positive number would be smaller than 0 and the result would be wrong). The loop starts at i=1 because element 0 is already loaded into the variables, so comparison starts from index 1.

### Session Summary

#### What is solid

- Indexing from 0 to N-1. Last valid index in array of size N is N-1.
- C does not check bounds by design, programmer is fully responsible.
- Off-by-one error: `<= N` instead of `< N` or `<= N-1` reaches outside the array.
- sizeof(array) gives total bytes, sizeof(array)/sizeof(array[0]) gives element count.
- Tracing min/max pattern step by step correctly.
- Buffer overflow definition: reading or writing outside the buffer limits into memory that does not belong to it.

#### Vocabulary refinements (not added to errors.md)

1. "Not declared" vs "not initialized" - the space exists and indexes are valid, the values inside are garbage until assigned.
2. Empty `[]` means "compiler count the initializers", not "no limit." Size becomes fixed at 4 once compiled.
3. `sizeof(array)/sizeof(array[0])` gives number of elements, not size in bytes.

---

*File: day_11_complete*
*Closed: Tuesday, June 23, 2026*

_AND OF DOCUMENTS_
