# Substitution-ciphers

A substitution cipher substitutes each alphabet with another alphabet, and only you or your friend may know the exact substitution. 
Given that there are 26! possible substitutions that could be possible, it can be hard for anybody to use pure brute force to break the cipher. 
Here is a program to convert a given text into its cipher text: #"substcipher.c"#.
But you can be clever and use some recurring patterns of the English language to be efficient.
The programs give you the most frequently occuring alphabets, bigrams, and trigrams, in a given a piece of text:"analysis-alpha.c","analysis-bigrams.c","analysis-trigrams.c".
 You can take any ciphertext and find the most frequent alhpabets, bigrams, and trigrams, to manually find mappings for at least 9-10 alphabets, most likely you will be able to solve for at least e/a/t/i/o/h/n/g/d/r. This program does the analysis for you: "substdecode.c".
