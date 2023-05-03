#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

#include "string.hpp"

using namespace std;

TEST(StringClass, Constructors) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);

    String t(s);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(s.size(), 5);
}

TEST(StringClass, Print) {
    String s("foo");
    stringstream out;
    s.print(out);
    EXPECT_STREQ(out.str().c_str(), "foo");

    stringstream out2;
    String().print(out2);
    EXPECT_STREQ(out2.str().c_str(), "");

    stringstream out3;
    out3 << s << s << String("bar");
    EXPECT_STREQ(out3.str().c_str(), "foofoobar");
}

TEST(StringClass, Comparisons) {
    EXPECT_LT(String("aaaa"), String("aaab"));
    EXPECT_LE(String("aaaa"), String("aaab"));
    EXPECT_EQ(String("foo"), String("foo"));
    EXPECT_NE(String("foo"), String("fooo"));
}

TEST(StringClass, Assignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = String();
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}


TEST(StringClass, MoreAssignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    const String k = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);
    EXPECT_EQ(s[1], t[1]);
    EXPECT_EQ(k[1], s[1]);

    s = String();
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}


TEST(StringClass, Reversal) {
    String a("hell");
    String b = a.reverse();
    String c("lleh");
    EXPECT_EQ(b, c);
}


TEST(StringClass, Indexing) {
    String a("Something");
    EXPECT_EQ(a.indexOf('e'), 3);
    EXPECT_NE(a.indexOf('e'), 4);
    String b("thin");
    EXPECT_EQ(a.indexOf(b), 4);
    String c("ome");
    EXPECT_EQ(a.indexOf(c), 1);
}


TEST(StringClass, Concatenation) {
    String a("Begin");
    String b("End");
    String c(a+b);
    String d("BeginEnd");
    EXPECT_EQ(c, d);
    a += b;
    EXPECT_EQ(a, c);
    EXPECT_EQ(a, d);
}


