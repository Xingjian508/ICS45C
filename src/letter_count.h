int char_to_index(char ch) {
    if (isupper(ch)) {
        return ch - 'A';
    }
    else if (islower(ch)) {
        return ch - 'a';
    }
    else {
        return -1;
    }
}

char index_to_char(int i) {
    char output = char(i+65);
    if (islower(output)) {
        return toupper(output);
    }
    return output;
}

void count(string s, int counts[]) {
    for (auto &ch : s) {
        int index = char_to_index(ch);
        counts[index] = counts[index]+1;
    }
}

void print_counts(int counts[], int len) {
    for (int i=0; i<len; i++) {
        char letter = index_to_char(i);
        int count = counts[i];
        cout << letter << ' ' << count << endl;
    }
}
