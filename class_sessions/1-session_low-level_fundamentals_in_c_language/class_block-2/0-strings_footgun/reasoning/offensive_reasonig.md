# Offensive Reasoning - Class 13

* **Date :** 222-07-2026
* **Topic :** Attacking developer assumptions, OOB read, info leak

> Note  : Claude corrections are at the end of this document.


### Code under analysis

``` c

int main(void)
{

    char quote[] = "security";
    int length = (int)strlen(quote);
    int vowels = 0;

    for (int i = 0; i < length; i++)
    {
     char c = quote[i];
        if  (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        vowels++;   
    
    /* a date that does not affect on this occasion but later if you want to add another 
        statement to the IF may not be executed because it does not have scope then you 
        would only be ensuring the ececution of the first line after the condition of the IF
    */
    
    }

    printf("Length : %d\nVowels: %d\n, length, vowels);
    return 0; 




}

```

### Quesion 1 - What did the developer assume? 

1. It is assuming the code will not be updated to a version that works with input given by the user.
 That is the most common update. 

2. It is assuming that length will always be a reasonable soze. 

3. The developer assumed that the buffer always has its '\0'


### Question 2 - What happens if I attack each assumption??

If the input changes from a fixed value to user input, an attacker could enter malicious data or simply use the same
logic of the program to break it, like adding a negative value or directly a gigantic value.

Since the `strlen()` function cannot return a negative number, it does not verify the size, but counts until it finds
a null terminator. With a buffer without '\0', `strlen` will count beyound the buffer until it finds a '\0' by chance, 
and return a large size that fits in a positive `int` (for example 5000). Then length = 5000, the loo runs 5000 times, 
traverses foreign memory: OOB read

The attack waould be to make the length variable end up as a gigantic positive number, so the loop traverses taht size 
ans c aptures memory it should not read, seeking to leak information tat could be useful later.

### Question 3 - Which violation gives control, not just a crash ??

The statement `char c = quote[i];` is the start of the information capture, then it moves to the check where the data
must be valid with the IF condition. This generates a bug and leaks information, but the information that comes out would 
not be complete because the IF condition is that it equals a vowel. This limits the variety of characters the bug captures.
It is an OOB read that serves to do and info leak , but in itself it would serve to see what information can be collected -
serious but does not give total control of information filtering or overwriting. It is more of data leak. 

Obvious limitation: the attacker only has control over the size of the loop interactions, so really it would be controlling
the loop in a limited  way.

### Question 4 - What would it serve for in a real operation? 

This serves for a reconnaissance phase, where the goal is to find some type of information useful for carrying out an attack later.


_AND OF DOCUMENTS_ 
