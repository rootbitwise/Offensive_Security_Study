# Season 1 - Foundation C

### Overview

This season is about building C from the ground up, starting at binary
systems and ending with C applied to security.

Most people learn to program with Python or JavaScript. They learn to tell
the computer what to do without understanding how it does it. That works
for general software development. It does not work for offensive security.

C forces you to manage memory by hand. There is no garbage collector and
no automatic safety net. A mistake with a pointer breaks the program, or
worse, makes it behave in ways you did not intend. That friction is not a
flaw. It is the point. It is the most effective way to understand how
memory, the stack, the heap, and the processor actually work.

The guiding principle of the season is kernel out: every concept is
understood from the lowest level possible before moving up to abstraction.

### Goals

By the end of this season I should be able to:

- Explain what the compiler does with code at each stage: preprocessing,
  compilation, assembly, and linking.
- Diagram the memory layout of a process: stack, heap, data, text.
- Use pointers with confidence, including pointer arithmetic.
- Compile, debug, and analyze binaries with GCC, GDB, and Valgrind.
- Read C code written by others and describe what it does.
- Recognize the classic vulnerability classes in C: buffer overflow,
  integer overflow, use-after-free, format string.

### Blocks

| Block | Focus | Status |
|-------|-------|--------|
| 0 | Binary systems and number representation. | Complete |
| 1 | C from scratch. Compilation, types, control flow. | Complete |
| 2 | Functions, arrays, and strings. | Active |
| 3 | Pointers and memory. The critical block. | Planned |
| 4 | Structs, files, and processes. | Planned |
| 5 | C for security and the closing project. | Planned |

### Closing Artifact

The season closes with the first serious portfolio project: a process
monitor written in C that reads from /proc, formatted output, documented,
and published as its own repository.

### Status

Block 0 - Binary systems and number representation.
Started May 2026.
