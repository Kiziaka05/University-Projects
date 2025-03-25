#include "LinkedList.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

static string colors[8] = {"green", "blue", "pink", "yellow", "silver", "grey", "white", "black"};
Data::Data()
{
    serial_number = rand()%30000;
    color = colors[rand()%8];
    charger = rand()%2;
}

void Data::print_info()
{
    cout<<"Serial number: "<<serial_number<<endl;
    cout<<"Iphone has "<<color<<" color"<<endl;
    if(charger == 1)
    {
        cout<<"there is a charger"<<endl;
    }
    else
    {
        cout<<"there is no charger"<<endl;
    }
};

HashNode::HashNode()
{
    Data value;
    long long key = 0;
    HashNode* nextElement = nullptr;
}

// конструктор зв'язного списку
LinkedList::LinkedList()
{
    head = nullptr;
}

// деструктор
LinkedList::~LinkedList()
{
    HashNode* current = head;
    HashNode* next = nullptr;
    while (current != nullptr)
    {
        next = current->nextElement;
        delete current;
        current = next;
    }

    head = nullptr;
}

void LinkedList::clear()
{
    HashNode* current = head;
    HashNode* next = nullptr;
    while (current != nullptr)
    {
        next = current->nextElement;
        delete current;
        current = next;
    }

    head = nullptr;
}

void LinkedList::push_front(long long key, Data value)
{
    HashNode* newHashNode = new HashNode();

    if (head != nullptr)
    {
        newHashNode->nextElement = head;
    }
    else
    {
        newHashNode->nextElement = nullptr;
    }

    newHashNode->key = key;
    newHashNode->value = value;
    head = newHashNode;
}

void LinkedList::remove(long long key)
{
    HashNode* prev = nullptr;
    HashNode* current = head;

    while(current != nullptr && current->key != key)
    {
        prev = current;
        current = current->nextElement;
    }

    if(current == nullptr)
    {
        return;
    }

    if(prev != nullptr)
    {
        prev->nextElement = current->nextElement;
    }
    else
    {
        //Якщо елемент, який потрібно видалити знаходиться в голові списку
        head = current->nextElement;
    }

    delete current;
}

void LinkedList::print()
{
    HashNode* current = head;

    if(current == nullptr)
    {
        cout<<"List is empty!"<<endl;
    }
    else
    {
        while(current != nullptr)
        {
            current->value.print_info();
            cout<<"key: "<<current->key<<endl;
            cout<<endl;
            current = current->nextElement;
        }
    }
}
