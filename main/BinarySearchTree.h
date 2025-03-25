#ifndef BINARYSEARCHTREE_H_INCLUDE

#define BINARYSEARCHTREE_H_INCLUDE

#include <vector>
#include <string>
template <typename T>
struct Node
{
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
struct BinarySearchTree
{
    BinarySearchTree();
    ~BinarySearchTree();

    void free(Node<T>* root);

    Node<T>* root;

    Node<T>* createNode(T data, Node<T>* currentNode);


    Node<T>* PrivateInsert(Node<T>* currentNode, T newData);
    Node<T>* insert(T newData);


    void PrivateInorder(Node<T>* root);
    void inorder();


    Node<T>* PrivateMinimum(Node<T>* root);
    Node<T>* minimum();


    Node<T>* PrivateMaximum(Node<T>* root);
    Node<T>* maximum();


    int PrivateHeight(Node<T>* root);
    int height();


    int PrivateSize(Node<T>* root);
    int size();
   

    Node<T>* PrivateFind(Node<T>* root, const T& key);
    Node<T>* find(const T& key);
    
    
    Node<T>* PrivateErase(Node<T>* root, T key);
    void erase(T key);


    //Пошук на проміжку:
    int findInRange(const T& min, const T& max);
    void split(Node<T>* Tree, const T& Border, Node<T>** L, Node<T>** R);
    void merge(Node<T>** Tree, Node<T>** L, Node<T>** R);
    void AddToResult(Node<T>* root, std::vector<T>* result);
    void EraseRange(T min, T max);


   //AVL дерево:
    int max(int a, int b);
    int NodeHeight(Node<T>* root);
    int getBalanceFactor(Node<T>* currentNode);
    Node<T>* leftRotate(Node<T>* currentNode);
    Node<T>* rightRotate(Node<T>* currentNode);
    Node<T>* nodeWithMimumValue(Node<T>* currentNode);
    
};

#include "BinarySearchTree.inl"

#endif