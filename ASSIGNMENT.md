Word Composition Problem

As part of our interview process, we would like for you to write a solution to the following problem,
focusing on correctness, approach, quality and performance.

Problem Statement
Write a program that:
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
o longest compounded word
o second longest compounded word
o time taken to process the input file
Note: A compounded word is one that can be constructed by combining (concatenating) shorter words
also found in the same file
Input 01
Input_01.txt is a small word list, consisting following words
cat
cats
catsdogcats
catxdogcatsrat
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat

Answer:
Longest Compound Word ratcatdogcat
Second Longest Compound Word catsdogcats
Time taken to process file Input_02.txt 500 milli seconds
Note:
Hippopotamuses is the longest word but that is not the answer as it is not a compounded word

Input 02
Input_02.txt is a long word list, consisting 100,000+ items
Answer:
Longest Compound Word ethylenediaminetetraacetates
Second Longest Compound Word electroencephalographically
Time taken to process file Input_02.txt 8000 milli seconds

Solution Requirements
This is not just a puzzle or classroom assignment; it is your opportunity to demonstrate your engineering
judgment and your technical knowledge in a way that you cannot do in a personal interview. Proper
usage of data structures to reduce time complexity of search. Performance matters, the program should
return results quickly even for very large lists (100,000+ items).