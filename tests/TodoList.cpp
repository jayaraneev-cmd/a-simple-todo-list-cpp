#include <catch2/catch_test_macros.hpp>
#include "../src/TodoList.hpp"

TEST_CASE("Add and complete tasks") {
    TodoList list;

    list.add("milk");
    list.add("eggs");

    list.complete("eggs");

    REQUIRE(list.isCompleted("eggs") == true);
    REQUIRE(list.isCompleted("milk") == false);
}

TEST_CASE("Clear tasks") {
    TodoList list;

    list.add("task1");
    list.add("task2");

    list.clear();

    REQUIRE(list.isCompleted("task1") == false);
}