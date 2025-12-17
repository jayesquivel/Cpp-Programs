#include "fileIOs_wordPairs.h"

// Function 1: sentenceSplitter

// This function reads a file and splits it into individual sentences.
// Sentence delimiters include: . ? ! and newLine

// How it works:
// 1. Reads a file line by line
// 2. Build up current sentence character by character
// 3. When we hit a delimiter, save the sentence and start a new one

void fileIOs_wordPairs::sentenceSplitter(string& fname, vector<string>& sentences) {
    ifstream inputFile(fname);

    if(!inputFile.is_open()) {
        cerr << "Error: Could not open file " << fname << endl;
        return;
    }

    string currentSentence = "";
    string line;

    // Read the file line by line
    while (getline(inputFile, line)) {
        // Process each character
        for (size_t i = 0; i < line.length(); i++) {
            currentSentence += line[i];

            // Check for delimiters "." or "?"
            if (i + 1 < line.length() && (line[i] == '.' || line[i] == '?') &&
            line[i+1] == '"') {

            // Include qoute
            currentSentence += '';
            // Skip next character since we already processed
            i++;

            // Trim white space and remove ending punctatuion
            size_t start = currentSentence.find_first_not_of(" \t\n\r");
            size_t end = currentSentence.find_last_not_of(" \ t \n\r");

            if (start != string::npos) {
                string trimmed = currentSentence.substr(start, end - start + 1);

                // Remove ending
                if (trimmed.length() >= 2) {
                    if(trimmed.substr(trimmed.length()- 2) == ".\"" ||
                        trimmed.substr(trimmed.length()-2) == "?\"") {
                            trimmed = trimmed.substr(0, trimmed.length-2);
                        }
                }

                if (!trimmed.empty()) {
                    sentence.push_back(trimmed);
                }
            }
            currentSentence = "";
        }

        // Check for . or ? (single-character delimiters, not followed by ")
            else if ((line[i] == '.' || line[i] == '?') &&
                     (i + 1 >= line.length() || line[i + 1] != '"')) {

                // Trim whitespace
                size_t start = currentSentence.find_first_not_of(" \t\n\r");
                size_t end = currentSentence.find_last_not_of(" \t\n\r");

                if (start != string::npos) {
                    string trimmed = currentSentence.substr(start, end - start + 1);

                    // Remove ending . or ?
                    if (!trimmed.empty() && (trimmed.back() == '.' || trimmed.back() == '?')) {
                        trimmed = trimmed.substr(0, trimmed.length()-1);
                    }

                    if (!trimmed.empty()) {
                        sentences.push_back(trimmed);
                    }
                }
                currentSentence = "";
            }
        }

        // End of line = newline delimiter (handles paragraphs ending with :)
        if (!currentSentence.empty()) {
            size_t start = currentSentence.find_first_not_of(" \t\n\r");
            size_t end = currentSentence.find_last_not_of(" \t\n\r");

            if (start != string::npos) {
                string trimmed = currentSentence.substr(start, end - start + 1);
                if (!trimmed.empty()) {
                    sentences.push_back(trimmed);
                }
            }
            currentSentence = "";
        }
    }

    inputFile.close();
}

// Function 2: wordpairMapping
// Like finding which ingredients appear together in recipes

// The function creates all possible word-pairs from each sentence and counts how many sentences contain each pairs
// How it works:
// 1. For each sentence do the following:
//      a. Extract all unique words (using a set of to avoid duplicates)
//      b. Generates all combos of 2 words
//      c. Stores all pairs in lexicograpical order
// 2. Count the frequency for each pair across the sentenceSplitter
// Example: "The first story"
//           Created Pairs:
//          <first, story>, <first, the>, <story, the>

void fileIOs_wordPairs::wordpairMapping(vector<string>& sentences, map<pair<string, string>, int>& wordpairFreq_map) {

    // Process each sentence
    for (const string& sentence : sentences) {
        // Using SET to store unique words as it automatically handles duplicates
        set<string> uniqueWords;

        // Tokenize sentence using istringstream (splits by whitespace)
        istringstream iss(sentence);
        string word;

        while (iss >> word) {
            string cleanedWord = cleanWord(word);

            if(!cleanedWord.empty()) {
                uniqueWords.insert(cleanedWord);
            }
        }

        // Generates all combos of word-pairs from this sentence
        // Uses two iterators to avoid duplicates and self-pairs
        for(auto it1 = uniqueWords.begin(); it1 != uniqueWords.end(); ++it1) {
            auto it2 = it1;
            // Start from the next word to avoid duplicates
            ++it2;

            for (; it2 != uniqueWords.end(); ++it2) {
                // Since set keeps words sorted, pairs are already in lexicograpical order
                pair<string, string> wordPair(*it1, *it2);

                // Increment frequency
                wordpairFreq_map[wordPair]++;
            }
        }
    }
}

// Fucntion 3: freqWordpairMmap

// Like flipping a dictionary, instead of looking for a defintion
// you can find words by their "importance level"

// This function "flips" the map so we can sort by frequency instead of by word.
// OG map: word-pair -> frequency
// Multimap: frequency -> word-pair

// Why use mutlimap? because multiple word-pairs have the same frequency
void fileIOs_wordPairs::freqWordpairMmap(map<pair<string, string>, int>& wordpairFreq_map, mutlimap<int, pair<string, string>>& freqWordpair_mmap) {

    // First, iterate through the original map
    for (const auto& entry : wordpairFreq_map) {
        // entry.first = word-pair (key)
        // entry.second = frequency (value)

        // insert itno mutlimap with flipped key-value
        freqWordpair_mmap.insert({entry.second, entry.first});
    }
}

// Function 4: printWordpairs
// This function outputs the most frequent and least frequent word-pairs

// How it works:
// 1. Use REVERSE iterator for top N (Highest frequencies)
// 2. Use FORWARD iterator for bottom N (Lowest frequencies)
void fileIOs_wordPairs::printWordpairs(multimap<int, pair<string, string>>& freqWordpair_multimap, string outFname, int topCnt, int botCnt) {
    ofstream outputfile(outFname);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file " << outFname << endl;
        return;
    }

    // Top N - Most Frequent
    outputFile << "Top " << topCnt << " most frequent word-pairs:" << endl;
    outputFile << "========================================" << endl;

    // Use REVERSE iterator (goes from end to beginning = highest to lowest)
    auto rit = freqWordpair_multimap.rbegin();
    int count = 0;

    while (rit != freqWordpair_multimap.rend() && count < topCnt) {
        outputFile << "<" << rit->second.first << ", " << rit->second.second << ">: "
                   << rit->first << endl;
        ++rit;
        ++count;
    }

    outputFile << endl;

    // Bottom N - Least Frequent
    outputFile << "Bottom " << botCnt << " least frequent word-pairs:" << endl;
    outputFile << "========================================" << endl;

    // Use FORWARD iterator (goes from beginning = lowest to highest)
    auto it = freqWordpair_multimap.begin();
    count = 0;

    while (it != freqWordpair_multimap.end() && count < botCnt) {
        outputFile << "<" << it->second.first << ", " << it->second.second << ">: "
                   << it->first << endl;
        ++it;
        ++count;
    }

    outputFile.close();
    cout << "Results written to " << outFname << endl;
}

// Helper function: cleanWord
// This function removes all punctatuion and converts it to lowercase
string fileIOs_wordPairs::cleanWord(const string& word) {
    string cleaned = "";

    for (char c : word) {
        // Only keep alphabetic characters
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }

    return cleaned;
}