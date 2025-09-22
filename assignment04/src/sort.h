//
//  sort.h
//
//  Functions for bubble sort, selection sort, and insertion sort.
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

#ifndef sort_hpp
#define sort_hpp

#include <algorithm>  // for swap()

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  // Performs an in-place ascending sort of *array* of size *length*
  // using the bubble sort algorithm
  template <typename T> void bubbleSort(T array[], const int length) {

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - i - 1; j++) {
        if (array[j] > array[j + 1]) {
          swap(array[j], array[j + 1]);
        }
      }
    }

    /*
    bool sorted = false;
    int index = 0;
    bool swapped = false;

    while (!sorted) {

      swapped = false;

      if (array[index] > array[index + 1] && index > length - 1) {

        swap(array[index], array[index + 1]);

        swapped = true;

      }

      if (index > length - 1 && !swapped) {

        sorted = true;

      }

      index++;

      if (!swapped) {sorted = true;}

    }
    */

  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the selection sort algorithm
  template <typename T> void selectionSort(T array[], const int length) {

    int lowest = 0;
    int toswap = 0;
    bool sorted = false;

    while (!sorted) {

      for (int i = toswap; i < length - 2; i++) {

        if (array[i] < array[i + 1]) {
          lowest = i;
        }
        else {
          lowest = i+1;
        }

      }

      swap(array[lowest], array[toswap]);
      toswap++;

      if (toswap == length - 1) {sorted = true;}

    }

  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the insertion sort algorithm
  template <typename T> void insertionSort(T array[], const int length) {

    if (length <=1) {
      return;
    }

    for (size_t sortedId = 1; sortedId < length; sortedId++) {
      for (size_t i = sortedId; i>0; i--) {
        if (array[i-1], array[i]) {
          swap(array[i-1], array[i]);
        }
        else {
          break;
        }
      }
    }

    /*
    bool sorted = false;
    int sortPoint = 1;

    for (int i = 1; i < length; i++) {

      while (!sorted) {

        if (array[i] < array[sortPoint]) {
          swap(array[i], array[sortPoint + 1]);
          sortPoint--;
          if (sortPoint == 0) {sorted = true;}
        }
        else {
          sorted = true;
        }

      }

    }
    */
  }
}  // namespace csi281

#endif /* sort_hpp */
