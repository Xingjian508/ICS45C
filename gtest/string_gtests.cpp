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

TEST(StringClass, Swapping) {
    String t("this");
    String k = t;
    String s("shiz");
    String p = s;
    t.swap(s);
    EXPECT_EQ(t, p);
    EXPECT_EQ(s, k);
}

TEST(StringClass, InOrEquality) {
    String a("");
    String b("");
    String c("s");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(StringClass, Indexing) {
    String a("");
    EXPECT_EQ(a.indexOf('4'), -1);
    String b("something4you");
    EXPECT_EQ(b.indexOf('4'), 9);
}

TEST(StringClass, Reversal) {
    String a("BARACK");
    String b(a.reverse());
    a = a.reverse();
    EXPECT_EQ(a, b);
}

TEST(StringClass, Concatenation) {
    String a("BCD");
    String b("EFG");
    String c = a+b;
    EXPECT_EQ(c, String("BCDEFG"));
    c += a;
    c += b;
    EXPECT_EQ(c, String("BCDEFGBCDEFG"));
}

TEST(StringClass, Bounding) {
    String a("ABCDEFG");
    EXPECT_TRUE(a.in_bounds(4));
    EXPECT_FALSE(a.in_bounds(7));
}

TEST(StringClass, Sizing) {
    String a("");
    EXPECT_EQ(a.size(), 0);
    String b("a");
    EXPECT_EQ(b.size(), 1);
}


