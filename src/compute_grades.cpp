#include "compute_grades.hpp"
#include <compare>
#include <iosfwd>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>


using namespace std;


void Student::validate() const {
    for_each(quiz.begin(), quiz.end(), [&](int x) { if (0>x || x>100) throw domain_error("Error: invalid percentage " + x); });
    for_each(hw.begin(), hw.end(), [&](int x) { if (0>x || x>100) throw domain_error("Error: invalid percentage " + x); });
    if (final_score < 0 || final_score > 100) throw domain_error("Error: invalid percentage " + to_string(final_score));
}



vector<string> get_all_lines(istream& in) {
    vector<string> v;
    string k;
    while (getline(in, k)) {
        if (k.empty()) break;
        else v.push_back(k);
    }
    return v;
}

istream& operator>>(istream& in, Student& s) {
    vector<string> v = get_all_lines(in);
    // for (auto r : v) cout << r << " ";
    // cout << endl;
    // It is all good here.
    string keyword;
    for (string k : v) {
        istringstream str(k);
        str >> keyword;
        int n;
        if (keyword == "Name") {
            str >> s.first_name;
            str >> s.last_name;
        }
        else if (keyword == "Quiz") {
            while (str >> n) { s.quiz.push_back(n); }
        }
        else if (keyword == "HW") {
            while (str >> n) { s.hw.push_back(n); }
        }
        else if (keyword == "Final") {
            str >> s.final_score;
        }
    }

    return in;
}


istream& operator>>(istream& in, Gradebook& b) {
    Student s;
    while (in >> s) {
        b.students.push_back(Student(s));
        s = Student();
    }
    return in;
}

void Student::compute_quiz_avg() {
    double avg = 0.0;
    for_each(quiz.begin(), quiz.end(), [&](int x) { avg += x; });

}

void Student::compute_hw_avg() {
}

void Student::compute_course_score() {
}

void Gradebook::compute_grades() {
}

void Gradebook::sort() {
}

void Gradebook::validate() const {
}

std::ostream& operator<<(std::ostream& out, const Gradebook& b) {
    for_each(b.students.begin(), b.students.end(), [&](Student s) { out << s; });
    return out;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << s.first_name << endl;
    out << s.last_name << endl;
    for (auto element : s.quiz) {
        out << element << " ";
    }
    out << endl;
    for (auto element : s.hw) {
        out << element << " ";
    }
    out << endl;
    out << s.final_score << endl;

    out << endl;
    return out;
}

