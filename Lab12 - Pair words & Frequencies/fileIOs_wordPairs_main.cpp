//
// Created by Joseph Esquivel on 11/10/25.
//

#include "fileIOs_wordPairs.h"

int main() {
    cout << "==================================================" << endl;
    cout << "   LAB 12: Word-Pair Frequency Analyzer" << endl;
    cout << "==================================================" << endl << endl;

    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    // Step 1: Split into sentences
    vector<string> sentences;
    sentenceSplitter(filename, sentences);
    cout << "Sentences found: " << sentences.size() << endl;

    // Step 2: Map word-pairs
    map<pair<string,string>, int> wordpairFreq_map;
    wordpairMapping(sentences, wordpairFreq_map);
    cout << "Unique word-pairs: " << wordpairFreq_map.size() << endl;

    // Step 3: Flip to multimap
    multimap<int, pair<string, string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);

    // Step 4: Print results
    string outputFilename;
    int topCnt, botCnt;

    cout << "Enter output filename: ";
    cin >> outputFilename;
    cout << "Enter top count: ";
    cin >> topCnt;
    cout << "Enter bottom count: ";
    cin >> botCnt;

    printWordpairs(freqWordpair_mmap, outputFilename, topCnt, botCnt);

    cout << "\nAnalysis complete! Check " << outputFilename << endl;

    return 0;
}