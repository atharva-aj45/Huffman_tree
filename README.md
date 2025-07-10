# Huffman_tree
This project implements the Huffman coding, which implements the file compression

---

##  Objectives
The goal of the project is to implement a file compression Algorithm. And the features of the code is:
- Accepts user input (string/text)
- Builds frequency map of characters
- Constructs Huffman Tree using a **min-heap**
- Generates optimal binary codes
- Encodes and decodes the text
- Calculates compression ratio
- Clean console-based interface

---
## Data Structures & Algorithms Used

- **Greedy Algorithm**
- **Priority Queue**
- **min-heap**
- **Binary Tree**
- **Hash Maps**
- **Recursion**

---

## Working 
1. The user enters a text.
2. The program counts the frequency of each character.
3. A **Huffman Tree** is built using a min-heap.
4. Binary codes are assigned to each character (shorter for frequent ones).
5. The text is encoded into binary.
6. The encoded binary is then decoded back to the original string.
7. Compression ratio is calculated and displayed.

---
## Sample Input/Output

```text
Enter text to encode: hello world
Huffman Codes:
d: 000
e: 001
h: 010
l: 011
o: 10
r: 1100
w: 1101
 : 111

Encoded Text: 010001011011011111101101100000
Decoded Text: hello world

Original Size: 88 bits
Compressed Size: 33 bits
Compression Ratio: 37.5%
```

## Applications
1. Use to compress different files
2. Files like mp3, zip, png, jpeg files can be compressed which leads to lesser storage use

---
# Author
*Atharva Joshi* <br>
 **3rd year Btech student** <br>
 **IIT Hyderabad**
