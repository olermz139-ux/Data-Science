#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "sorting-algorithms/printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, int& reads, int& writes) {
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
                // Update haveSwapped
                haveSwapped = true;
                reads += 5;
                writes += 3;
            }
        }
        // Update numPasses
        ++numPasses;

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    cout << "Bubble Sort" << endl;
    cout << "Reads: " << reads << endl;
    cout << "Writes: " << writes << endl;

    return vec;
}

#endif
