#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
    EXPECT_EQ(String::strlen("something"), 9);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];
    EXPECT_EQ(String::strncpy(result, "foo", 3), result);
    EXPECT_STREQ(result, "foo");
    
    EXPECT_EQ(String::strncpy(result, "", 0), result);
    EXPECT_EQ(String::strncpy(result, "", 1), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "Somethingelse", 4), result);
    EXPECT_STREQ(result, "Some");
}

TEST(StringFunction, strcat) {
    char result[80] = "Thing";
    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(String::strcat(result, "foo"), "Thingfoo");
    EXPECT_STREQ(String::strcat(result, "bar"), "Thingfoobar");
    EXPECT_STREQ(String::strcat(result, ""), "Thingfoobar");
}

TEST(StringFunction, strncat) {
    char result[100] = "Thing";
    EXPECT_EQ(String::strncat(result, "", 1), result);
    EXPECT_STREQ(String::strncat(result, "foo", 3), "Thingfoo");
    EXPECT_STREQ(String::strncat(result, "barfoo", 3), "Thingfoobar");
    EXPECT_STREQ(String::strncat(result, "", 0), "Thingfoobar");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("something", "something"), 0);
    EXPECT_EQ(String::strcmp("A", "BC"), ('A'-'B'));
    EXPECT_EQ(String::strcmp("", ""), 0);
    EXPECT_NE(String::strcmp("BA", "BCD"), ('A' - 'D'));
    EXPECT_EQ(String::strcmp("BA", "BCD"), -(('C'-'A')));
}
/*
TEST(StringFunction, strncmp) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
*/
