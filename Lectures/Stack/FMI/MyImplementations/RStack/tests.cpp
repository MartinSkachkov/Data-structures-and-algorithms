#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "RStack.inl"
#include "doctest.h"

TEST_SUITE("Resizeable Stack test") {
    TEST_CASE("Default constructor and default size") {
        RStack<int> s;
        CHECK(s.empty());
        CHECK(s.getCapacity() == 10);
    }

    TEST_CASE("Push an element") {
        RStack<int> s;
        s.push(20);
        CHECK(!s.empty());
    }

    TEST_CASE("Get the top element and pop it") {
        RStack<int> s;
        s.push(20);
        CHECK(s.top() == 20);
        CHECK(s.pop() == 20);
        CHECK(s.empty());
    }

    TEST_CASE("Pushing & popping many times") {
        const int N = 10;

        SUBCASE("Pop after push preserves a non-empty stack") {
            RStack<int> s;
            for (int i = 0; i < N; i++)
                s.push(i);

            CHECK(s.full());

            s.push(N);
            s.pop();

            for (int i = N - 1; i >= 0; i--)
                CHECK(s.pop() == i);

            CHECK(s.empty());
            CHECK(s.getCapacity() == 20);
        }
    }
}