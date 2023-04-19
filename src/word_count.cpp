#include "word_count.h"
#include <iostream>


using namespace std;


void to_lowercase(std::string& str) {
    for (int i=0; i<int(str.size()); ++i) {
        str[i] = tolower(str[i]);
    }
}


std::set<std::string> load_stopwords(std::istream& stopwords) {
    set<std::string> S;
    std::string stopword = "";
    while (stopwords >> stopword) {
        to_lowercase(stopword);
        S.insert(stopword);
    }
    return S;
}


std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    map<std::string, int> M;
    std::string word = "";
    while (document >> word) {
        to_lowercase(word);
        if (stopwords.find(word) == stopwords.end()) { // This indicates nonexistence.
            M[word]++;
        }
    }
    return M;
}


void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
    for (auto element : word_counts) {
        output << element.first << ' ' << element.second << endl;
    }
}
