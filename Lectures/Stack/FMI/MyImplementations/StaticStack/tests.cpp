#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "StaticStack.inl"
#include "doctest.h"

TEST_SUITE("Static Stack test") {
    TEST_CASE("Default constructor") {
        StaticStack<int> s;
        CHECK(s.empty());
    }

    TEST_CASE("Push an element") {
        StaticStack<int> s;
        s.push(20);
        CHECK(!s.empty());
    }

    TEST_CASE("Get the top element and pop it") {
        StaticStack<int> s;
        s.push(20);
        CHECK(s.top() == 20);
        CHECK(s.pop() == 20);
        CHECK(s.empty());
    }

    TEST_CASE("Pushing & popping many times") {
        const int N = 10;

        SUBCASE("Pop after push preserves a non-empty stack") {
            StaticStack<int> s;
            for (int i = 0; i < N; i++)
                s.push(i);

            s.push(N);
            s.pop();

            for (int i = N - 1; i >= 0; i--)
                CHECK(s.pop() == i);

            CHECK(s.empty());
        }
    }
}