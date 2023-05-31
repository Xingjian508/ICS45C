#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;

string to_lowercase(const string& str) {
    transform(str.begin(), str.end(), str.begin(),
    [](char c){ return tolower(c); });
}

set<string> load_stopwords(istream& stopwords) {
    set<string> s;
    copy(istream_iterator<string>(stopwords), istream_iterator<string>(), back_inserter(s));
    return s;
}

map<string, int> count_words(istream& document, const set<string>& stopwords) {
    map<string> c;
    

