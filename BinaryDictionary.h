//
// Created by Carlos  Escamilla on 3/11/24.
//

#ifndef BINARYDICTIONARYEXAMPLE_BINARYDICTIONARY_H
#define BINARYDICTIONARYEXAMPLE_BINARYDICTIONARY_H

#include <string>
#include <fstream>

using namespace std;

class BadDigit{};

class BinaryDictionary {
public:
    BinaryDictionary();
    ~BinaryDictionary();

    // copy constructor
    BinaryDictionary(const BinaryDictionary& otherDict);

    // Saves all the words in the tree to a file
    void SaveDictionary(string filename);

    BinaryDictionary& operator=(const BinaryDictionary& otherDict);

    void Add(string binValue); // Add value to the tree
    bool Contains(string value); // Determines if value is in the tree

    void MakeEmpty(); // Remove all binary words

    int Size(); // Number of binary values

private:
    struct Node {
        Node* zero = nullptr;
        Node* one = nullptr;
        bool isNum = false;
    };

    Node* root;
    int numValues;

    // The helper function is used by the copy constructor and the
    // assignment operator
    void copyOther(const BinaryDictionary& otherDict);

    // Used for de-constructor
    void DestroyHelpher(Node* node);
    void CopyHelper(Node*& thisTree, Node* otherTree);
    void SaveDictionaryHelper(Node* node, string currPrefix, ofstream& outFile);
};

#endif //BINARYDICTIONARYEXAMPLE_BINARYDICTIONARY_H























