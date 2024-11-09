# Christos Dallas - csd4864 #

Project Overview:

In this project, I implemented a series of cryptographic algorithms and a key-value storage system as part of the coursework for the "Introduction to Information Security Systems" class at the University of Crete. The assignment was guided by Professor Evangelos Markatos and focused on both theoretical and practical aspects of cryptography.

What I Did:

Cryptographic Algorithms:
One-Time Pad: I developed functions to encrypt and decrypt messages using a randomly generated key, applying XOR operations to each character of the plaintext.
Affine Cipher: I implemented encryption and decryption functions using mathematical transformations, specifically the formulae (5x + 8) mod 26 for encryption and 21(y - 8) mod 26 for decryption.
Substitution Cipher Decryptor: I created a tool to decrypt text without knowing the cipher alphabet, utilizing frequency analysis to assist in the decryption process.
Trithemius Cipher: I implemented this polyalphabetic substitution cipher using a tabula recta for both encryption and decryption.
Scytale Cipher: I developed functions to encrypt and decrypt messages using a cylindrical tool, simulating the ancient method of wrapping a strip of parchment around a rod.
Rail Fence Cipher: I implemented functions to rearrange text in a zigzag pattern across multiple lines, encrypting and decrypting messages by reading them diagonally.
Key-Value Storage System:
I wrote a program in C to securely store key-value pairs in a database. The system supports adding, reading, and range-reading operations, with all data encrypted using AES in CBC mode via the OpenSSL library. This ensures the security of the database file and each individual key-value pair.
Tools and Technologies Used:

Programming Language: C
Cryptographic Library: OpenSSL for AES encryption
Development Environment: Linux-based systems


Run:
1)make
2)./main
