#include "Turbine.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm> // to be able to use random_shuffle
using namespace std;


int main() {
    ofstream outFile1, outFile2, outFile3, outFile4;
    vector<Turbine> turbines;
    //vector with digits 1-100 in random order using random.org
    vector<int> random {65, 78, 15, 85, 36, 84, 17, 95, 98, 3, 83, 71, 87, 20, 81, 58, 38, 19, 59, 54, 5, 96, 62, 4, 100, 88, 80, 68, 53, 32, 50, 30, 45, 14, 47, 64, 97, 12, 79, 13, 43, 72, 1, 25, 76, 29, 11, 94, 8, 42, 49, 6, 46, 48, 7, 33, 34, 67, 40, 69, 91, 18, 86, 70, 92, 23, 2, 55, 60, 28, 22, 44, 90, 82, 51, 56, 75, 37, 21, 35, 10, 77, 9, 57, 16, 24, 27, 39, 52, 66, 73, 89, 26, 99, 63, 41, 93, 31, 61, 74};

    //Make integer (1-100) tree in order addition for BST, AVL, splay
    BinarySearchTree<int> bst1;
    AVLTree<int> AVL1;
    SplayTree<int> splay1;
    for(int i=1; i<=100; i++){
       bst1.add(i);
       AVL1.add(i);
       splay1.add(i);
    }

    //Find each integer in order and record depth in file
    outFile1.open("../data/OrderInt-Data.csv");
    outFile1 << "Value looked" << "," << "Depth BST" << "," << "Depth AVL" << "," << "Depth splay" << endl;
    for(int i=1; i<=100; i++){
        outFile1 << i << "," << bst1.findDepth(i) << "," << AVL1.findDepth(i) << "," << splay1.findDepth(i) << endl;
    }
    outFile1.close();

    //Checking understanding
    cout << "Should print 1: " << bst1.findDepth(0) << endl;
    cout << "Should print 100: " << bst1.findDepth(101) << endl;
    cout << "Should print 100: " << bst1.findDepth(102) << endl;
    cout << "" << endl;

    //adding elements in random vector to AVL, Splay
    BinarySearchTree<int> bst2;
    AVLTree<int> AVL2;
    SplayTree<int> splay2;

    for(int i =  0 ; i < random.size(); i++) {
        bst2.add(random[i]);
        AVL2.add(random[i]);
        splay2.add(random[i]);
    }

    //Find each integer in order and record depth in file

    outFile2.open("../data/RandomInt-Data.csv");
    outFile2 << "Value looked" << "," << "Depth BST" << "," << "Depth AVL" << "," << "Depth splay" << endl;
    for(int i=1; i<=100; i++){
        outFile2 << i << "," << bst2.findDepth(i) << "," << AVL2.findDepth(i) << "," << splay2.findDepth(i) << endl;
    }
    outFile2.close();

    //Make vector with all items on csv file and add to trees
    BinarySearchTree<Turbine> bst3;
    AVLTree<Turbine> AVL3;
    SplayTree<Turbine> splay3;
    if(getDataFromFile(turbines)) {
        for (int i = 0; i < turbines.size(); ++i) {
            bst3.add(turbines[i]);
            AVL3.add(turbines[i]);
            splay3.add(turbines[i]);
        }
        //print size of trees
        cout << "Vector turbines size: " << turbines.size() - 1 << endl;
        cout << "BST size: " << bst3.getSize() << endl;
        cout << "AVL size: " << AVL3.getSize() << endl;
        cout << "Splay size: " << splay3.getSize() << endl;

        //Find items in order and record their depth
        outFile3.open("../data/Turbines-Data.csv");
        outFile3 << "Value looked" << "," << "Depth BST" << "," << "Depth AVL" << "," << "Depth splay" << endl;
        for (int i = 0; i < turbines.size() ; ++i) {
            outFile3 << i << "," << bst3.findDepth(turbines[i]) << "," << AVL3.findDepth(turbines[i]) << "," << splay3.findDepth(turbines[i]) << endl;
        }
        outFile3.close();

        //Create another splay tree with 500 items
        SplayTree<Turbine> splay4;
        for (int i = 0; i < turbines.size(); ++i) {
            splay4.add(turbines[i]);
        }
        //Find each item 5 times and record depth
        outFile4.open("../data/TSplayTurb-Data.csv");
        outFile4 << "Value looked" << "," << "Depth splay" << endl;
        for (int i = 0; i < turbines.size(); ++i) {
            for(int j = 0; j < 5; j++) {
                outFile4 << splay3.findDepth(turbines[i]) << ",";
            }
            outFile4 << endl;
        }
        outFile4.close();

    }
    return 0;
}