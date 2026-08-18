# Class 00 - Logic Gates & Bit Manipulation

* **Date:** 19-08-2026
* **Bloack:** Binary Logic
* **Season:** 01 : Foundaction C
* **Topics:** Logic Gate, Bit Masking 

--- 

### What's in this document it  

Consists  of two parts: a ssesion on logic gates and a session on bit masking and XOR in C.

---

### (Part 1) - Logic Gates

A logic gate takes one or more binary inputs (0 or 1) and produces an output according to a fixed boolean rule. It always gives the same output for the same input. At the hardware level, a gate is a small arrangement of transistors switching on or off based on voltage.

Everything a CPU does comes down to billions of these switching gates.

---

### The seven gates 

* AND : 1 when both inputs are 1.
* OR : is 1 if At least one entry is 1.
* NOT : is 1 if the inputs is 0, it is 0 if the inputs is 1.
* NAND : It is opposite of AND, Universal Gate.
* NOR : It is opposite of OR, Universal Gate.
* XOR : Is is 1 when the inputs are different. 
* XNOR : Is the opposite of XOR, It's 1 when the inputs are equal.

### Universal Gates 

A universal door can biuld any other door on its own. **NAND And NOR are the two universal gates.**
For example: Connecting both inputs of a NAND gate to the same signal gives NOT: 

`NAND(A,A) equals = (A & A)'  which is equal to = A'`


### XOR propieties 

```
A XOR 0 = A          # Zero changes nothing
A XOR A = 0          # Anything XOR itself is ZERO
(A XOR B) XOR B =A   # Applying the same key twice reverts the result
A XOR B = B XOR A    # Commutative

```
> The third propiety is why XOR is used in both encryption and decryption: the same key and the same encode and decode operation. For this reason, XOR is one of the most abused operations in malware. 

---

### (Part 2) - Bit Masking in C 

### Operations and their use cases

```c

// (1) check if a specific bit is set (normalize to 1 or 0)

int result = (flags & mask) !=0;

// (2) Get the masked value without normalizing 

unsigned char masked = flags & mask;

// (3) Invert a specific bit

unsigned char flipped = flags ^ mask;

// (4) Set a bit (force it a to 1)

unsigned char set = flags | mask;

```

* Distinction: `flags ans mask` returns the **masked** value, not a bollean. the comparison `!=0` normalizes it to 1 or 0. 

* `!=0` is used when you need a true/false answer. 

---

### Bit indexing 

Bits are numbered from 0, starting at the rightmost (least significant) position: 

```
position: 7   6   5  4  3  2  1  0  
weight: 128  64  32 16  8  4  2  1 

```

To check the N-bit, the mask has a 1 at the position you want to check and 0 everywhere.

```c 

// Check bit 3 (weight 8)

unsigned char mask_bit3 = 0x08; # binary : 0000 1000
unsigned char bit_03 = 0x28     # binary : 0010 1000

unsigned char bit_on = (bit_03 & mask_bit3) != 0;

// Invert bit 0

unsigned char mask_bit0 = 0x01;  # binary : 0000 0001
unsigned char bit_0 = 0x51;      # binary : 0101 0001

unsigned char invert_bit0 = bit_0 ^ mask_bit0; 

0000 0001
0101 0001 ^
---------
0101 0000 = 0x50

invert_bit0 = 0x50

```

### GCC flags

```bash

gcc -Wall -Wextra -Wpedantic -Werror file.c -o file

```
These flags catch type mismatches, unused variables, implicit conversions, and other issues before the binary runs. `-Werror` makes every warning a build failure - useful for enforcing clean code during development.

---

### Files of this class

``` 
class_00_logic_gates/ 
        program/ 
            flags_and_mask.c               # AND masking + permission check normalization demo
            bit02_mask.c                   # Checking exec bit with mask 0x04
            debug_error.c                  # Bug: OR used instead of NAD, then corrected
            xor_encrypt_decrypt.c          # XOR reversibility: encrypt and recover a byte
            xor_malware_decrypt.c          # Xor single-byte decode loop (malware pattern)
            deliverable/
                class_deliverable.c        # Final exercise: check bit 3, invert bit 0 on 0x48
            reasoning
                engineering_reasoning.md   # How the gates work, truth tables, XOR properties
                offensive_reasoning.md     # XOR in malware, decode patern, debug analysis

```
---

### CTI connection

XOR single-byte obfuscation is the most common technique used to hide strings and payloads in malware.
The decode loop in `xor_malware_decrypt.c` is functionally identical to what runs inside thousands of real samples before they use a sensitive string. 

**MITRE ATT&CK**

* `T1027` :  Obfuscated files or information
* `T1140` :  Deobfuscate / Decode files or information

---

# _AND OF DOCUMENTS_
