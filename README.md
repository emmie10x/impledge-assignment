# Word Composition Problem Solution

## Overview
This is a C++ solution to the Word Composition Problem. The program reads alphabetically sorted lists of words from text files, identifies the longest and second-longest compounded words, and reports the time taken to process the file.

## Approach
1. **Data Structure**: The solution reads all words into a `std::vector` and stores them in a `std::unordered_set` to allow for O(1) average time complexity for word lookups.
2. **Sorting**: Words are sorted primarily by length in descending order. This means the first compounded word we find is guaranteed to be the longest, and the second one found will be the second longest.
3. **Memoized Recursion**: For each word, a recursive function checks if it can be constructed from smaller words. It tries matching prefixes in the `unordered_set`. To avoid redundant computations and ensure high performance, an array `failed` is used for memoization within each word evaluation.

## How to Compile and Run
1. Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
2. Open a terminal or command prompt in the project directory.
3. Compile the solution using `g++`:
   ```bash
   g++ -O3 solution.cpp -o solution
   ```
4. Run the executable:
   - On Windows: `.\solution.exe`
   - On Linux/macOS: `./solution`

## Complexity
- **Time Complexity**: Finding the answer takes `O(N * L^2)` in the worst case, where `N` is the number of words and `L` is the maximum word length. Sorting the words takes `O(N log N)`. 
- **Space Complexity**: `O(N * L)` to store the words in the vector and unordered set.

## Output format
The program processes `Input_01.txt` and `Input_02.txt` (if present) and displays:
- Longest Compound Word
- Second Longest Compound Word
- Time taken to process the file in milliseconds
