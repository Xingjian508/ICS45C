#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, Comparison) {
    Node* const head1 = list::from_string("I said so.");
    Node* const head2 = list::from_string("I did not.");
    Node* const head3 = list::from_string("I said so.");
    Node* const head4 = list::from_string("I said");
    ASSERT_NE(list::compare(head1, head2), 0);
    ASSERT_NE(list::compare(head2, head3), 0);
    ASSERT_EQ(list::compare(head1, head3), 0);
    ASSERT_EQ(list::compare(head1, head1), 0);
    ASSERT_EQ(list::compare(head2, head2, 2), 0);
    ASSERT_EQ(list::compare(head1, head2, 1), 0); 
    ASSERT_NE(list::compare(head1, head4), 0);
    ASSERT_NE(list::compare(head4, head1), 0);
    ASSERT_EQ(list::compare(head4, head1, 6), 0);
    ASSERT_EQ(list::compare(head1, head4, 6), 0);
    list::free(head1);
    list::free(head2);
    list::free(head3);
    list::free(head4);
}

TEST(ListTests, Copying) {
    Node* const head = list::from_string("something");
    Node* const chead = list::copy(head);
    ASSERT_EQ(list::compare(head, chead), 0);
    list::free(head);
    list::free(chead);
}


TEST(ListTests, Reveral) {
    Node* const head = list::from_string("abracadabra");
    Node* const erhead = list::from_string("arbadacarba");
    Node* const rhead = list::reverse(head);
    EXPECT_EQ(list::compare(rhead, erhead), 0);
    list::free(head);
    list::free(erhead);
    list::free(rhead);

    Node* const h1 = list::from_string("");
    Node* const rh1 = list::reverse(h1);
    EXPECT_EQ(list::compare(rh1, h1), 0);
    list::free(rh1);
    list::free(h1);

}


TEST(ListTests, Appending) {
    Node* const a = list::from_string("");
    Node* const b = list::from_string("");
    Node* const c = list::append(a, b);
    Node* const d = list::append(c, c);
    EXPECT_EQ(list::compare(c, d), 0);

    Node* const e = list::from_string("some");
    Node* const f = list::from_string("thing");
    Node* const g = list::append(e, f);
    Node* const h = list::from_string("something");

    EXPECT_EQ(list::compare(g, h), 0);

    list::free(a);
    list::free(b);
    list::free(c);
    list::free(d);
    list::free(e);
    list::free(f);
    list::free(g);
    list::free(h);
}
