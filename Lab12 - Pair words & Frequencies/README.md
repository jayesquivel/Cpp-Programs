# Lab 12: Word-Pairs & Frequencies

## Project Overview

This project analyzes Steve Jobs' famous 2005 Stanford University commencement speech. The program processes the speech to identify all co-occurring word-pairs and their frequencies.

### Key Concepts

- **Co-occurring words**: Two words that appear in the same sentence
- **Word-pair**: A pair of co-occurring words
- **Frequency**: The number of sentences containing a specific word-pair

You can [download the speech here](link) to test your program locally before submitting to zyBook.

---

## Required Files

1. `designDoc.h`
2. `fileIOs_wordPairs.h` - Function prototypes
3. `fileIOs_wordPairs.cpp` - Function implementations
4. `fileIOs_wordPairs_main.cpp` - Test driver

---

## Function Specifications

### 1. `sentenceSplitter`

```cpp
void sentenceSplitter(string& fname, vector<string>& sentences);
```

**Purpose**: Converts a text file into a list of sentences.

**Parameters**:
- `fname`: Input filename
- `sentences`: Vector to store extracted sentences (in order of appearance)

**Sentence Delimiters**:
- Period: `.`
- Question mark: `?`
- Period + double quotation: `。"`
- Question mark + double quotation: `?"`
- Newline character (end of paragraph) - handles paragraphs ending with colons

**Example Input**:
```
The first story is about connecting the dots.

I dropped out of Reed College after the first 6 months, but then stayed around as a drop-in for another 18 months or so before I really quit. So why did I drop out?

It started before I was born. My biological mother was a young, unwed college graduate student, and she decided to put me up for adoption...
```

**Example Output** (12 sentences extracted):
- The first story is about connecting the dots
- I dropped out of Reed College after the first 6 months, but then stayed around as a drop-in for another 18 months or so before I really quit
- So why did I drop out
- It started before I was born
- *(and 8 more sentences...)*

---

### 2. `wordpairMapping`

```cpp
void wordpairMapping(vector<string>& sentences, map<pair<string,string>, int>& wordpairFreq_map);
```

**Purpose**: Identifies unique word-pairs and calculates their frequencies.

**Parameters**:
- `sentences`: Input vector of sentences
- `wordpairFreq_map`: Map to store word-pairs (key) and their frequencies (value)

**Important Rules**:
- **Case insensitive**: All words converted to lowercase
- **Whitespace delimiters**: Used for tokenization
- **No duplicate words**: Word-pairs like `<the, the>` are excluded
- **Lexicographical order**: `<college, that>` and `<that, college>` are treated as the same pair

**Implementation Suggestions**:
- Use `istringstream` for tokenization
- Use `set` to store unique tokens per sentence

**Example Input** (3 identical sentences):
```
The first story is about connecting the dots.
The first story is about connecting the dots.
The first story is about connecting the dots.
```

**Example Output** (21 word-pairs identified):
```
<about, connecting>: 3
<about, dots>: 3
<about, first>: 3
<about, is>: 3
<about, story>: 3
<about, the>: 3
<connecting, dots>: 3
...
<story, the>: 3
```

---

### 3. `freqWordpairMmap`

```cpp
void freqWordpairMmap(map<pair<string,string>, int>& wordpairFreq_map, 
                      multimap<int, pair<string, string>>& freqWordpair_mmap);
```

**Purpose**: Flips the map to order word-pairs by frequency (ascending).

**Parameters**:
- `wordpairFreq_map`: Input map (word-pair → frequency)
- `freqWordpair_mmap`: Output multimap (frequency → word-pair)

**Note**: A multimap is required because multiple word-pairs can have the same frequency.

**Example Output**:
```
3: <about, connecting>
3: <about, dots>
3: <about, first>
3: <about, is>
3: <about, story>
```

---

### 4. `printWordpairs`

```cpp
void printWordpairs(multimap<int, pair<string, string>>& freqWordpair_multimap, 
                    string outFname, int topCnt, int botCnt);
```

**Purpose**: Writes the most and least frequent word-pairs to a file.

**Parameters**:
- `freqWordpair_multimap`: Input multimap (already sorted by frequency)
- `outFname`: Output filename
- `topCnt`: Number of most frequent word-pairs to output
- `botCnt`: Number of least frequent word-pairs to output

**Output Format**: `<word1, word2>: frequency` (one per line)

**Implementation Tips**:
- Use `iterator` for least frequent word-pairs
- Use `reverse_iterator` for most frequent word-pairs

**Example Output** (top 10 most frequent, if `topCnt = 10`):
```
<story, the>: 3
<is, the>: 3
<is, story>: 3
<first, the>: 3
<first, story>: 3
<first, is>: 3
<dots, the>: 3
<dots, story>: 3
<dots, is>: 3
<dots, first>: 3
```

---

## Implementation Requirements

### `fileIOs_wordPairs.h`
Include all function prototypes listed above. Feel free to add helper functions as needed.

### `fileIOs_wordPairs.cpp`
Implement all functions declared in the header file.

### `fileIOs_wordPairs_main.cpp`
Create a `main()` function to test all four functions.

---

## Testing

Test your program locally with the provided Steve Jobs speech before submitting to zyBook.
