//#include "linked_stack.hpp"
#include "RStack.hpp"
//#include "static_stack.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "StackTests.h"
#include "doctest.h"

// using IntStack = Stack<int>;
using IntStack = RStack<int>;
// using IntStack = LinkedStack<int>;

/*TEST_CASE("Default constructor creates empty stack") {
    IntStack s;
    CHECK(s.empty());
}

TEST_CASE("Move constructor is being called") {
    IntStack s;
    std::vector<IntStack> vec;
    vec.push_back(IntStack());
}

TEST_CASE("Pushing an element creates a non-empty stack") {
    IntStack s;
    s.push(42);
    CHECK(!s.empty());
}

TEST_CASE("Top retrieves the element that was just pushed") {
    IntStack s;
    const int X = 24;
    s.push(X);
    CHECK(s.top() == X);
}

TEST_CASE("Pop after push preserves the stack") {
    const int N = 10;

    SUBCASE("Pop after push preserves the empty stack") {
        IntStack s;
        s.push(N);
        s.pop();
        CHECK(s.empty());
    }

    SUBCASE("Pop after push preserves a non-empty stack") {
        IntStack s;
        for (int i = 0; i < N; i++)
            s.push(i);

        s.push(N);
        s.pop();

        for (int i = N - 1; i >= 0; i--)
            CHECK(s.pop() == i);

        CHECK(s.empty());
    }
}*/