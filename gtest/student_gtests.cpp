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
    EXPECT_EQ(String::strcmp("BA", "BCD"), -('C'-'A'));
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("something", "somethina", 5), 0);
    EXPECT_EQ(String::strncmp("A", "BC", 0), 0);
    EXPECT_EQ(String::strncmp("A", "BC", 100), ('A' - 'B'));
    EXPECT_EQ(String::strncmp("", "", 10), 0);
    EXPECT_EQ(String::strncmp("BA", "BCD", 1), 0);
    EXPECT_EQ(String::strncmp("BA", "BCD", 2), -('C' - 'A'));
    EXPECT_TRUE((String::strncmp("test", "testa", 10)) < (0));
}

TEST(StringFunction, reverse_cpy) {
    char a[100] = "CRAZYMOTHERFATHER";
    char b[20];
    String::reverse_cpy(b, a);
    EXPECT_STREQ(b, "REHTAFREHTOMYZARC");
    char c[5] = "some";
    char d[6] = "thing";
    String::reverse_cpy(d, c);
    EXPECT_STREQ(d, "emos");
}

TEST(StringFunction, strchr) {
    char str[5] = "ABCD";
    const char* ptr1 = String::strchr(str, 'D');
    int index = ptr1-str+1;
    EXPECT_EQ(index, 4);
    const char* ptr2 = String::strchr(str, 'Q');
    EXPECT_EQ(nullptr, ptr2);
    char str2[10] = "ABCDEFGHI";
    const char* ptr3 = String::strchr(str2, 'H');
    EXPECT_EQ(8, ptr3-str2+1);
    char tstr[1] = "";
    const char* ptr4 = String::strchr(tstr, 'a');
    EXPECT_EQ(nullptr, ptr4);
    char str3[4] = "abc";
    const char* ptr5 = String::strchr(str3, '\0');
    EXPECT_EQ(4, ptr5-str3+1);
    char haystack[4] = "AJF";
    const char* ptr6 = String::strchr(haystack, '\0');
    EXPECT_EQ(4, ptr6-haystack+1);
}

TEST(StringFunction, strstr) {
    char str[200] = "I cannot believe that you are searching through this incredibly long string.";
    char word1[20] = "cannot";
    char word2[20] = "believe";
    char word3[20] = "spectacular";
    char word4[20] = "nonsense";
    char word5[20] = "incredibly";
    char word6[20] = "incred";
    char word7[20] = ".";
    char word8[20] = "ing.";
    char word9[20] = "";
    const char* ptr1 = String::strstr(str, word1);
    const char* ptr2 = String::strstr(str, word2);
    const char* ptr3 = String::strstr(str, word3);
    const char* ptr4 = String::strstr(str, word4);
    const char* ptr5 = String::strstr(str, word5);
    const char* ptr6 = String::strstr(str, word6);
    const char* ptr7 = String::strstr(str, word7);
    const char* ptr8 = String::strstr(str, word8);
    const char* ptr9 = String::strstr(str, word9);
    EXPECT_EQ(3, ptr1-str+1);
    EXPECT_EQ(10, ptr2-str+1);
    EXPECT_EQ(nullptr, ptr3);
    EXPECT_EQ(nullptr, ptr4);
    EXPECT_EQ(54, ptr5-str+1);
    EXPECT_EQ(54, ptr6-str+1);
    EXPECT_EQ(String::strlen(str), ptr7-str+1);
    EXPECT_EQ(String::strlen(str)-3, ptr8-str+1);
    EXPECT_EQ(str, ptr9);

    char haystack[10] = "somethin";
    const char* p = String::strstr(haystack, "");
    EXPECT_EQ(haystack, p);
}

