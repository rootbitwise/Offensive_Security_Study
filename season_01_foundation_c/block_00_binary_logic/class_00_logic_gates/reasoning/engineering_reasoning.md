# Day 00 : Reasoning for class Logic Gates

* **Date :** 2026-08-11
* **Topics :** Logic Gates

> Reasoning note for the theory of class 00

### What is a Logic Gate: 

Underlying everything a computer does is a physical component called a transistor which is a voltage-controlled switch.
without voltage at its control terminal, it does not conduct, and this is read as a 0. With voltage at its control terminal
it does conduct, and this is read 1. A transistor is 1 or 0 depending on whether curent flows through it or not.

A logic gate is a small arrays of transistors that takes one or more input signals (1s or 0s) and produces an ouput according 
to a fixed rule. That rule is a boolean operation. The gate doesn't think; it simply responds the same way to the same input 
every time.

### The seven logic gates and their rules: 

```

AND    X = A . B       *  It is 1 only if both signals are 1
OR     X = A + B       *  It is 1 if at least one of the signals is 1
NOT    X = A'          *  Inverts the input signal 
NAND   X = (A . B)'    *  Inverted AND is UNIVERSAL
NOR    X = (A + B)'    *  Inverted OR is also UNIVERSAL 
XOR    X = A'B + AB'   *  It is 1 only if the input signals are opposite
XNOR   X = (A xor B)'  *  Inverted XOR: is 1 only when the signals are equal

```

### The four basic truth tables: 

```text

   AND            OR            NOT           XOR
 A B | X       A B | X        A | X        A B | X
 0 0 | 0       0 0 | 0        0 | 1        0 0 | 0
 0 1 | 0       0 1 | 1        1 | 0        0 1 | 1
 1 0 | 0       1 0 | 1                     1 0 | 1
 1 1 | 1       1 1 | 1                     1 1 | 0

```

### Why are NAND and OR universal:

Universal in this means that by using only one of these gates repeatedly, any of the seven gates can be created, and therefore
any circuit

Example: If the two inputs of a NAND gate are connected to the same signal, the result is the same as the NOT gate: 

```
NAND (A, A) It's the same as negating the output of an AND gate with two equal input signal, and that produces the same result
as a NOT gate

signal = 1:  NAND(1,1) = 0 y NOT 1 = 0 (they agree)
signal = 0:  NAND(0,0) = 1 y NOT 0 = 1 (they agree)

```

### XOR Properties

XOR is useful for encrypting or decrypting; it appears in shellcode, malware obfuscation, cryptography, and much more
Its properties are what it useful.

```

A xor 0 = A            * Zero doesn't change anything
A xor A = 0            * Something within itself is cancelled
(A xor B) xor B = A    * Applying the same key twice reverses 

```

The third property is one of the most useful:  applying a key to data encrypts it, and applying that same key 
to the encrypted data decrypts it

--- 

### Phase : (Logic Gym) 

Exercise 1: Truth table of XOR

* The result is 1 the inputs are different and 0 if they are the same :

```

 A B | A xor B
 0 0 | 0
 0 1 | 1
 1 0 | 1
 1 1 | 0

```

Exercise 2: Solve : `(A AND B) OR (NOT B)`
A = 1, B = 0.

```
( 1 & 0 ) | (0') = 1

1 AND 0 = 0 OR 1 = 1
--------------------

A AND B = 0        (AND requires both inputs to be 1)
NOT B   = 0' = 1   (NOT reverses the input)
0 OR 1  = 1        (OR only requires one input to be 1)

output : 1

```

Exercise 3: Build NOT only NAND 

To build a NOT gate using only NAND, you just need to connect both inputs to the same signal. 
As long as the signal is the same at both NAND inputs, the result will match the result of NOT.

```
NAND        NOT
1 1 = 0     1 = 0
0 0 = 1     0 = 1

```

_END OF DOCUMENTS_
