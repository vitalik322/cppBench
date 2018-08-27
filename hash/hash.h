#include <string>

#define HASH_BASE 31
#define HASH_TABLE_SIZE 40000
#define MAX_STR_LEN 10
#define MIN_STR_LEN 3

unsigned int polinomHash(std::string &s);

// Linear hash table

struct LinearTableEntry {
    std::string str;
    bool isDeleted = false;
};

struct HashTableLinear {
    LinearTableEntry* table_ = new LinearTableEntry[HASH_TABLE_SIZE];
    int collisions = 0;
    int inserts = 0;
    int removes = 0;

    HashTableLinear();
    void insert(std::string &s);
    bool find(std::string &s);
    void remove(std::string &s);
};

// List hash table

struct Node {
    Node(std::string v) { value = std::string(v); }
    std::string value;
    Node *next = nullptr;
};

struct List {
    Node *root_ = nullptr;
    void push(std::string &value);
    void remove(std::string &strToRemove);
    bool find(std::string &strToFind);
};

struct HashTableList {
    List* table_ = new List[HASH_TABLE_SIZE];
    int collisions = 0;
    int inserts = 0;
    int removes = 0;

    HashTableList();
    void insert(std::string &s);
    bool find(std::string &s);
    void remove(std::string &s);
};

void benchHashTableList (int numOps);
void benchHashTableLinear (int numOps);
