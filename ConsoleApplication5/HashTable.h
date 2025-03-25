#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "LinkedList.h"

using namespace std;


struct HashTable
{
	HashTable();
    ~HashTable();
    int current_size;
    int capacity;
    LinkedList* bucketsArray;


    // load factor = N/M, �� N - ������� ������� �����, � M - ������ ������
    float maxLoadFactor;
    float loadFactor;

    // ������ ��� ����� ������ ���-�������
    bool IsPrimeNumber(int num);
    int FindPrime(int num);

    int hash(long long key);
    void insert(long long key, Data value);
    void relocate_memory();
    Data* find(long long key);
    void erase(long long key);
    int size();
    void print(long long key);
};


#endif
