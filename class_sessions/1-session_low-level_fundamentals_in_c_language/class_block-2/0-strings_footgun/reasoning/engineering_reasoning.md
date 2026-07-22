# Engineering Reasoning - Class 13

* **Date :** 22-07-2026 
* **Topic :** Strings, null terminator, buffer sizing, memory vs length

### Assigment 2.1 

```c
char a[] = "C";
char b[] = "Hello";
char c[] = "";
char d[10] = "Hello";

```

* char a[] = takes up two bytes, the byte reserved for the character and the one reserved for the null terminator

* char b[] = takes up six bytes, the 5 of the characters plus the byte of the null terminator

* char c[] = it is empty, it is not a space, it is literalyy '\0', literally the value 0 ('\0') not the character '0'

* char d[] = 10 bytes are reserved, although only 5 bytes are used for the characters in the data and the rest, the
other 5 bytes, are at 0, making a total of 11 bytes in memory. But sizing it like this only makes sense if you know 
you're going to add bytes later.


### Assigment 2.2 

```c

char text[] = "ABCDE";
printf("%d\n", (int)strlen(text)); 
printf("%c\n", text[0];
printf("%c\n", text[4);

```
It counts characters until it finds the '\0' byte it does not include it in the count

printf("%d\n", (int)strlen(text)) printd 5.

* text[0] = the character at index 0, the latter: A (the first character)
* text[4] = the charcter at index 4, the letter: E (in this case the last one)
* text[5] = the '\0' null terminator 

### Assigment 2.3

```c

char d[10] = "Hello";
b[2] = '\0'; 
printf("%s\n", d); 

```

Its real position did not change in memory, printf is only told to stop reading at character 2. This prints "Ho". 
If the code is modified, printing the null buffer before changing the position of the null terminator, you notice
that the data in memory is not beign modified.


### Assigment 2.4 

```c

char destiny[5]; 
char origin[] = "This chain is too long";
strcpy(destiny, origin); 

```

This is footgun, it is trying to copy data that is much larger than the available space to store ir and a serious
footgun occurs, this is an OOB Write, a buffer overflow: this type of bug gives control over the program because you 
can overwrite the return address and make the program jump to malicious code.

That safest thing using the same logic of this code would be: let the compiler assume the size of the destination so it
would reseve exactly the number of the bytes the string takes up plus the null terminator '\0' "which is the stop signal.


_AND OF DOCUMENTS_ 

