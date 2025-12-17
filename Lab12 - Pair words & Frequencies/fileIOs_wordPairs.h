//
// Created by Joseph Esquivel on 11/10/25.
//

#ifndef FILEIOS_WORDPAIRS_H
#define FILEIOS_WORDPAIRS_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function 1: Split text file into sentences
void sentenceSplitter(string& fname, vector<string>& sentences);

// Function 2: Map word-pairs to their frequencies
void wordpairMapping(vector<string>& sentences,
                     map<pair<string,string>, int>& wordpairFreq_map);

// Function 3: Flip map to multimap (frequency becomes key)
void freqWordpairMmap(map<pair<string,string>, int>& wordpairFreq_map,
                      multimap<int, pair<string, string>>& freqWordpair_mmap);

// Function 4: Print top N and bottom N word-pairs to file
void printWordpairs(multimap<int, pair<string, string>>& freqWordpair_multimap,
                    string outFname, int topCnt, int botCnt);

// Helper function: Clean word (remove punctuation, convert to lowercase)
string cleanWord(const string& word);

#endif //LABASSIGNMENTS_FILEIOS_WORDPAIRS_H
