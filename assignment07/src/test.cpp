//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]") {
  SECTION("Queue w/ int tests") {
    Queue<int> q1 = Queue<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE

    CHECK(q1.getCount() == 0);

    for (int i = 0; i < 10; i++) {
      q1.push(i);
    }

    CHECK(q1.getCount() == 10);

    CHECK(q1.peek() == 0);
    q1.pop();
    CHECK(q1.peek() == 1);
    q1.pop();
    CHECK(q1.peek() == 2);

    for (int i = 5; i < 10; i++) {
      q1.remove(i);
    }

    CHECK(q1.getCount() == 3);

    CHECK(q1.peek() == 2);

    q1.pop();
    CHECK(q1.peek() == 3);



  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE

    CHECK(q2.getCount() == 0);

    string Words[10] = {
      "hello",
      "goodbye",
      "???",
      "test",
      "111",
      "12345",
      "jace",
      "jupiter",
      "earth",
      "(0.0)"
    };

    for (int i = 0; i < 10; i++) {
      q2.push(Words[i]);
    }

    CHECK(q2.getCount() == 10);

    CHECK(q2.peek() == Words[0]);
    q2.pop();
    CHECK(q2.peek() == Words[1]);
    q2.pop();
    CHECK(q2.peek() == Words[2]);

    for (int i = 5; i < 10; i++) {
      q2.remove(Words[i]);
    }

    CHECK(q2.getCount() == 3);

    CHECK(q2.peek() == Words[2]);
    q2.pop();
    CHECK(q2.peek() == Words[3]);

  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE

    CHECK(s1.getCount() == 0);

    for (int i = 0; i < 10; i++) {
      s1.push(i);
    }

    CHECK(s1.getCount() == 10);

    CHECK(s1.peek() == 9);
    s1.pop();
    CHECK(s1.peek() == 8);
    s1.pop();
    CHECK(s1.peek() == 7);

    for (int i = 0; i < 5; i++) {
      s1.remove(i);
    }

    CHECK(s1.getCount() == 3);

    CHECK(s1.peek() == 7);
    s1.pop();
    CHECK(s1.peek() == 6);

  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE

    CHECK(s2.getCount() == 0);

    string Words[10] = {
      "hello",
      "goodbye",
      "???",
      "test",
      "111",
      "12345",
      "jace",
      "jupiter",
      "earth",
      "(0.0)"
    };

    for (int i = 0; i < 10; i++) {
      s2.push(Words[i]);
    }

    CHECK(s2.getCount() == 10);

    CHECK(s2.peek() == Words[9]);
    s2.pop();
    CHECK(s2.peek() == Words[8]);
    s2.pop();
    CHECK(s2.peek() == Words[7]);

    for (int i = 0; i < 5; i++) {
      s2.remove(Words[i]);
    }

    CHECK(s2.getCount() == 3);

    CHECK(s2.peek() == Words[7]);
    s2.pop();
    CHECK(s2.peek() == Words[6]);

  }
}
