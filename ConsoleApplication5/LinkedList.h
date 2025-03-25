#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

using namespace std;

struct Data
{
    long long serial_number;
    string color;
    bool charger;

    Data();
    void print_info();
};

struct HashNode
{
    Data value;
    long long key;
    HashNode* nextElement;

    HashNode();
};

struct LinkedList
{
    HashNode* head;

    LinkedList();
    ~LinkedList();

    void push_front(long long key, Data value);
    void remove(long long key);
    void clear();
    void print();

};

#endif
