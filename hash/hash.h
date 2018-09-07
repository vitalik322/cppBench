#include <string>

#define HASH_BASE 67
#define MIN_STR_LEN 3
#define MAX_STR_LEN 10
#define HASH_TABLE_SIZE 60000

#define POLYNOM_HASH 0
#define FNV1_HASH 1
#define HASH_TYPE 0

unsigned int myHash(const std::string &s, int hashType=HASH_TYPE);

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
    void insert(const std::string &s);
    bool find(const std::string &s);
    void remove(const std::string &s);
    ~HashTableLinear() { delete[] table_; }
};

// List hash table

struct HashNode {
    HashNode(std::string v) { value = std::string(v); }
    std::string value;
    HashNode *next = nullptr;
};

struct List {
    HashNode *root_ = nullptr;
    void push(const std::string &value);
    void remove(const std::string &strToRemove);
    bool find(const std::string &strToFind);
    ~List() {
        register HashNode *node = root_;
        while (node != nullptr) {
            node = root_->next;
            delete root_;
            root_ = node;
        }
    }
};

struct HashTableList {
    List* table_ = new List[HASH_TABLE_SIZE];
    int collisions = 0;
    int inserts = 0;
    int removes = 0;

    HashTableList();
    void insert(const std::string &s);
    bool find(const std::string &s);
    void remove(const std::string &s);
    ~HashTableList() { delete[] table_; }
};

void benchHashTableList (int numOps);
void benchHashTableLinear (int numOps);
