//
// Created by Carlos  Escamilla on 3/11/24.
//
#include "BinaryDictionary.h"

BinaryDictionary::BinaryDictionary() {
    root = new Node;
    numValues = 0;
}

BinaryDictionary::BinaryDictionary(const BinaryDictionary &otherDict) {
    root = new Node;
    numValues = 0;
    copyOther(otherDict);
}

// This returns the reference to a dictionary
BinaryDictionary& BinaryDictionary::operator=(const BinaryDictionary &otherDict) {
    // Need to avoid self reference issue.
    // For example:
    // myDict = myDict;
    if (this != &otherDict) {
        copyOther(otherDict);
    }

    // return self
    return *this;
}

void BinaryDictionary::Add(string digits) {
    // Start at the root
    Node* curr = root;

    // For each digit in the binary string...
    for (int i = 0; i < digits.size(); i++) {
        // Pick which digit branch to go to.
        if (digits[i] == '0') {
            if (curr->zero == nullptr) {
                curr->zero = new Node;
            }
            curr = curr->zero;
        } else if (digits[i] == '1') {
            if (curr->one == nullptr) {
                curr->one = new Node;
            }
            curr = curr->one;
        } else {
            throw BadDigit();
        }
    }

    curr->isNum = true;
    numValues ++;
}

bool BinaryDictionary::Contains(string digits) {
    // Start at the root
    Node* curr = root;

    // For each digit in the binary string...
    for (int i = 0; i < digits.size(); i++) {
        // If we run into a null, then we know this
        // binary string does not exist in the dictionary
        if (curr == nullptr) {
            return false;
        }

        // Pick which digit branch to go to.
        if (digits[i] == '0') {
            curr = curr->zero;
        } else if (digits[i] == '1') {
            curr = curr->one;
        } else {
            throw "Bad digit";
        }
    }

    return curr->isNum;
}
