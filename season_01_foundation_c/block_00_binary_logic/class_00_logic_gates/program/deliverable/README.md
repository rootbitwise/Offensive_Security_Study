# Class 00 - Deliverable algorithm (data manipulation)

### Problem 

Give a byte of data, check the state of a specific bit, reverse another bit, and validate that the 
data is acceptable before processing it. All with data of type `unsigned char` (1-byte)

---

* Input 

```

* data = 0x4B (binary : 0100 1011)

```

* Output 

```
* OFF/ON depending on whether the "exec" bit(bit3) is on or off
* The 0x4B data after inverting bit 0, in hex format
* The original unmodified data, in hex format
* Error message if the data is invalid

```

### Specifications

```

* Data type: unsidned char
* Output format: hex and decimal

```

### Program steps

```
1. Declare the data
2. Declare the validation mask and apply it to the data
3. Evalue if the data is valid (it is not the sentinel 0xff, it is not 0)
4. Declare the mask to verify permission (bit3)
5. Apply the mask to the original ata and normalize to 1/0
6. Show ON/OFF message based on the bit
7. Declare the mask to invert bit 0
8. Apply XOR to the original data with that mask
9. Display the data after the XOR
10. Display the original data without XOR

```

### Limit cases considered

```
1. That the data is malformed
2. Tat the data is a negative number
3. That the data is 0
4. That the data is greater than 1 byte
5. Characters that do not fit within 1 byte

```

### Mitigations 

```
1. Limit the type of data that can enter (unsigned char)
2. Check the size/range of the data before operating it
3. Compare the data and verify the input format

```

### Pseudocode 

```
unsigned char data = 0x4B
unsigned char mask_0xFF = 0xFF      # validation mask

unsigned char applying_mask = mask_0xFF & data


// validation 

IF (applying_mask == mask_0xFF)
    THEN print "[ERROR] thi is the sentinal 0xFF"
ELSE IF (data == 0)
    THEN print "[ERROR] thi is 0"
ELSE 
    // Check bit 3
unsigned char mask_exec = 0x08
unsigned char permission = (mask_exec & data) != 0
    IF (permission)
        THEN print "EXEC ON"
    ELSE 
        THEN print "EXEC OFF"

// invert 0 bit
unsigned char mask_bit0 = 0x01
unsigned char invert = data ^ mask_bit0
print data original (hex)
print invert (hex)

```

---

#_AND OFF DOCUMENT_
