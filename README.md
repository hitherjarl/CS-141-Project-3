# Prog 3: Decipher


Write a program to figure out what some encrypted line of text says by trying all possible decryption possibilities. For each decryption possibility look up all the words in a dictionary to see if it is recognizable English. The steps will be: 

1) Take the original input line where words are separated by white space (space, tab, or return)
2) Transpose each character by some amount. This approach is called the Caesar cipher. For instance transposing by +1 would convert "abc" to "bcd", and would convert "xyz" to "yza", where transposing letters at the end of the alphabet "wraps around" back to the beginning of the alphabet.  Similarly, if using this approach with all printable ASCII characters between character 32 (space) and character 126, then transposing "hey \~Z" by 1 would give: "ifz!] ["   Note that in this case we have 95 characters total, and again the character '~' at the end wraps around to the space character at the beginning of the range.
3) Take the resulting transposed text and find the first white-space separated string.  Look it up in the dictionary and keep track of whether or not it was found.  Repeat for the next string and keep going until you have reached the end of the input or you have processed enough strings to have a good idea of whether or not many of the strings were found in the dictionary.  Repeat this whole step where the entire line is reversed.  Store these statistics.
4) After trying all possibilities (both forwards and backwards), the transposition and direction with the greatest number of words found in the dictionary is the one selected to be displayed as the decrypted text.

** rest of the description is on https://sites.google.com/site/uic141spring2016/programs/prog-3-decipher **
