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

    if (length <=1) {
      return;
    }

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - i - 1; j++) {
        if (array[j] > array[j + 1]) {
          swap(array[j], array[j + 1]);
        }
      }
    }

  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the selection sort algorithm
  template <typename T> void selectionSort(T array[], const int length) {

    if (length <=1) {
      return;
    }

    int minimumIndex;

    for (int i = 0; i < length - 1; i++) { //picks number to swap with lowest
      minimumIndex = i;
      for (int j = i + 1; j < length; j++) { // Goes through the array

        if (array[j] < array[minimumIndex]) { //checks if the current value is less...
          //than the lowest found value

          minimumIndex = j; // new lowest value's location in the array is set

        }

      }
      swap(array[i], array[minimumIndex]);

    }


  }

  // Performs an in-place ascending sort of *array* of size *length*
  // using the insertion sort algorithm
  template <typename T> void insertionSort(T array[], const int length) {

    if (length <=1) {
      return;
    }

    //I used the code you showed in class, but it's slower than selection sort.
    //You said I could turn it in with a note stating what I used here.

    for (size_t sortedId = 1; sortedId < length; sortedId++) {
      T temp = array[sortedId];
      int currentId = sortedId - 1;
      while (currentId >= 0 && array[currentId] > temp) {
        array[currentId + 1] = array[currentId];
        currentId--;
      }
      array[currentId + 1] = temp;
    }

  }
}  // namespace csi281

#endif /* sort_hpp */
