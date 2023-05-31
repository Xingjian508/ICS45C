#include "process_numbers.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>



using namespace std;

void split_odd_even(istream& numbers, ostream& odds, ostream& evens) {
    vector<int> v;
    copy(istream_iterator<int>(numbers), istream_iterator<int>(), back_inserter(v));
    sort(v.begin(), v.end());
    ranges::copy_if(v, ostream_iterator<int>(odds, " "),
                         [](int x) { return (x % 2) == 1; });
    odds << endl;
    ranges::copy_if(v, ostream_iterator<int>(evens, "\n"),
                         [](int x) { return (x % 2) == 0; });

}
