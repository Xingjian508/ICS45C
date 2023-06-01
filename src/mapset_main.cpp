#include <fstream>

#include "mapset.hpp"

using namespace std;

int main() {
    ifstream stopwords_file{"src/stopwords.txt"};
    const auto stopwords = load_stopwords(stopwords_file);

    ifstream document{"src/sample_doc.txt"};
    const auto word_counts = count_words(document, stopwords);

    ofstream output{"frequency.txt"};
    output_word_counts(word_counts, output);
}
