#include "hash.h"

//
// Linear hash table
//

unsigned int polynomHash(const std::string &s) {
    register unsigned int hash = 0;
    for (auto c : s) {
        hash = hash * HASH_BASE + c;
    }
    return hash % HASH_TABLE_SIZE;
}

HashTableLinear::HashTableLinear() {
    for (register int i = 0; i < HASH_TABLE_SIZE; ++i)
        table_[i].str = std::string();
}

// Supposing string doesn't exist in list
void HashTableLinear::insert(const std::string &strToInsert) {
    inserts++;
    register int originalHash = polynomHash(strToInsert);
    register int hash = originalHash;
    for (; !table_[hash].str.empty(); hash = (hash + 1) % HASH_TABLE_SIZE);
    if (hash != originalHash) collisions++;
    table_[hash].str = strToInsert;
} 

bool HashTableLinear::find(const std::string &strToFind) {
    register int hash = polynomHash(strToFind);
    while (!table_[hash].str.empty() || table_[hash].isDeleted) {
        if (table_[hash].str == strToFind)
            return true;
        hash = (hash + 1) % HASH_TABLE_SIZE;
    }
    return false;
}

// Supposing string exists in list
// Removing: find last entry with same hash and replace deleted one
void HashTableLinear::remove(const std::string &strToRemove) {
    removes++;
    register int originalHash = polynomHash(strToRemove);
    register int hash = originalHash;
    register int idxToRemove = 0;
    register int lastEntryIdx = 0;
    while (!table_[hash].str.empty() || table_[hash].isDeleted) {
        if (polynomHash(table_[hash].str) == originalHash) {
            lastEntryIdx = hash;
            if (table_[hash].str == strToRemove)
                idxToRemove = hash;
        }
        hash = (hash + 1) % HASH_TABLE_SIZE;
    }

    table_[idxToRemove].str = table_[lastEntryIdx].str;
    table_[lastEntryIdx].isDeleted = true;
}

//
// List hash table
//

void List::push(const std::string& value) {
    register HashNode *newNode = new HashNode(value);

    if (root_ == nullptr) {
        root_ = newNode;
        return;
    }

    register HashNode *currNode = root_;
    for (;currNode->next != nullptr; currNode = currNode->next);

    currNode->next = newNode;
}

// Supposing string exists in list
void List::remove(const std::string &strToRemove) {
    register HashNode *prevNode = root_;
    if (root_->value == strToRemove) {
        root_ = root_->next;
        delete prevNode;
        return;
    }

    for (;prevNode->next->value != strToRemove; prevNode = prevNode->next);

    register HashNode *nodeToRemove = prevNode->next;
    prevNode->next = nodeToRemove->next;
    delete nodeToRemove;
}

bool List::find(const std::string &strToFind) {
    for(register HashNode *currNode = root_; currNode != nullptr; currNode = currNode->next) {
        if (currNode->value == strToFind)
            return true;
    }
    return false;
}

HashTableList::HashTableList() {
    for (register int i = 0; i < HASH_TABLE_SIZE; ++i)
        table_[i] = List();
}

// Supposing string do not exists in table
void HashTableList::insert(const std::string &strToInsert) {
    ++inserts;
    register int hash = polynomHash(strToInsert);
    if (table_[hash].root_ != nullptr) ++collisions;  // tmp
    table_[hash].push(strToInsert);
}

// Supposing string do exists in table
void HashTableList::remove(const std::string &strToRemove) {
    ++removes;
    register int hash = polynomHash(strToRemove);
    table_[hash].remove(strToRemove);
}

bool HashTableList::find(const std::string &strToFind) {
    register int hash = polynomHash(strToFind);
    return table_[hash].find(strToFind);
}

//
// Bench functions
//


#include <iostream>

static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
static std::string getRandomString() {
    std::string randStr;
    int strLen = rand() % MAX_STR_LEN;
    for (register int j = 0; j < std::max(strLen, MIN_STR_LEN); ++j)
        randStr.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
    return randStr;
}

void benchHashTableList (int numOps) {
    HashTableList hashTable;
    for (register int i1 = 0; i1 < numOps; ++i1)
        for (register int i2 = 0; i2 < numOps; ++i2) {
            // Gen random str
            std::string randStr = getRandomString();

            // Insert or delete from table
            if (hashTable.find(randStr))
                hashTable.remove(randStr);
            else
                hashTable.insert(randStr);
        }
    std::cout << hashTable.inserts << std::endl;
    std::cout << hashTable.removes << std::endl;
    std::cout << hashTable.collisions << std::endl;
}

void benchHashTableLinear (int numOps) {
    HashTableLinear hashTable;
    for (register int i1 = 0; i1 < numOps; ++i1)
        for (register int i2 = 0; i2 < numOps; ++i2) {
            // Gen random str
            std::string randStr = getRandomString();

            // Insert or delete from table
            if (hashTable.find(randStr))
                hashTable.remove(randStr);
            else
                hashTable.insert(randStr);
        }
    std::cout << hashTable.inserts << std::endl;
    std::cout << hashTable.removes << std::endl;
    std::cout << hashTable.collisions << std::endl;
}
