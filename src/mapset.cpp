#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "mapset.hpp"


using namespace std;

string to_lowercase(const string& str) {
    string r = str;
    transform(r.begin(), r.end(), r.begin(),
              [](char c) { return tolower(c); });
    return r;
}

set<string> load_stopwords(istream& stopwords) {
    set<string> s;
    for_each(istream_iterator<string>(stopwords), istream_iterator<string>(), [&](string w) { s.insert(to_lowercase(w)); });
    return s;
}

map<string, int> count_words(istream& document, const set<string>& stopwords) {
    map<string, int> c;
    for_each(istream_iterator<string>(document), istream_iterator<string>(), [&](string w) { if (stopwords.find(to_lowercase(w)) == stopwords.end()) c[to_lowercase(w)]++; });
    return c;
}

void output_word_counts(const map<string, int>& word_counts, ostream& output) {
    for_each(word_counts.begin(), word_counts.end(), [&](const auto& sw) { output << sw.first << " " << sw.second << endl; });
}
    

