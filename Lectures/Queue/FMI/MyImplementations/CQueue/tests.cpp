#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "CQueue.inl"
#include "doctest.h"

TEST_SUITE("Circular queue tests!") {
    TEST_CASE("Create queue") {
        CQueue<int> q;
        CHECK(q.empty());
    }
    TEST_CASE("Insert & pop elements / get the front element") {
        CQueue<int> q;

        q.push(1);
        CHECK(!q.empty());
        q.push(2);
        q.push(3);
        CHECK(q.full());

        CHECK(q.pop() == 1);
        CHECK(!q.full());
        q.push(8);
        CHECK(q.full());
        CHECK(q.front() == 2);
        CHECK(q.size() == 3);
    }
}