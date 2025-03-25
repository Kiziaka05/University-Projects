#include "HashTable.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable()
{
    maxLoadFactor = 1;
    current_size = 0;
    capacity = 2;
    bucketsArray = new LinkedList[capacity];
}

HashTable::~HashTable()
{
    // Очищуємо зв'язний список в кожній комірці
    for(int i = 0; i<current_size; i++)
    {
        bucketsArray[i].clear();
    }
    delete[] bucketsArray;
}

// Хеш-функція
int HashTable::hash(long long key)
{
    return key%capacity;
}

//Метод для перевірки числа на простоту
bool HashTable::IsPrimeNumber(int num)
{
    if (num <= 1) return false;
    if (num <= 3) return true;

    for(int i = 2; i < num - 1; i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}

// Метод для знаходження найближого простого числа
int HashTable::FindPrime(int num)
{
    while(IsPrimeNumber(num) != 1)
    {
        num--;
    }
    return num;
}


void HashTable::relocate_memory()
{
    //  cout << "rellocate start" << endl;
    // Зберігаємо попередній масив та ємність
    int prevCapacity = capacity;
    capacity = capacity*2;
    //  cout<<"capacity: "<<capacity<<endl;
    // Для більш оптимальної роботи хеш-функції, знаходимо просте число
    capacity = FindPrime(capacity);
    LinkedList* newBucketsArray = new LinkedList[capacity];
    //  cout<<"PrevCapacity: "<<prevCapacity<<endl;

    for(int i = 0; i < prevCapacity; i++)
    {
        HashNode* currentNode = bucketsArray[i].head;
        while(currentNode != nullptr)
        {
            // Дізнаємося данні, які треба перенести та за допомогою нової хеш-функції переносимо вузол на нову позицію
            Data value = currentNode->value;
            long long key = currentNode->key;
            int newIndex = hash(key);
            //  cout<<"Index: "<<newIndex<<endl;
            LinkedList* newList = &newBucketsArray[newIndex];
            newList->push_front(key, value);
            currentNode = currentNode->nextElement;
        }
    }

    delete[] bucketsArray;
    bucketsArray = newBucketsArray;
}


void HashTable::insert(long long key, Data value)
{
    //Якщо таблиця перевантажена, потрібно перевиділити пам'ять
    //Обчисюємо load factor в данний момент
    loadFactor = current_size / (float)capacity;

    if (loadFactor >= maxLoadFactor)
    {
        relocate_memory();
    }

    int index = hash(key);
    LinkedList* list = &bucketsArray[index];

    //Перевірити чи є елемент з таким ключем в списку
    Data* myData = find(key);

    if (myData != nullptr)
    {
        //Якщо такий елемент існує, то змінюєо його значення на нове
        *myData = value;
        return;
    }

    list->push_front(key, value);
    current_size++;
}

Data* HashTable::find(long long key)
{
    int index = hash(key);
    LinkedList* list = &bucketsArray[index];

    HashNode* myNode = list->head;

    while(myNode != nullptr)
    {
        if(myNode->key == key)
        {
            return &myNode->value;
        }
        myNode = myNode->nextElement;
    }
    return nullptr;
}

void HashTable::erase(long long key)
{
    int index = hash(key);
    LinkedList* list = &bucketsArray[index];

    //Перевірити чи є елемент з таким ключем в списку
    Data* myData = find(key);
    if(myData != nullptr)
    {
        //Якщо такий елемент існує, то видаляємо його
        list->remove(key);
        current_size--;
    }
}

int HashTable::size()
{
    return current_size;
}

void HashTable::print(long long key)
{
    Data* myData = find(key);
    if (myData != nullptr)
    {
        myData->print_info();
    }
    else
    {
        cout << "Element with key " << key << " not found." << endl;
    }
}
