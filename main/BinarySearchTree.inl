#include <iostream>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>
#include "BinarySearchTree.h"
using namespace std;

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    free(root);
}

template<typename T>
void BinarySearchTree<T>::free(Node<T>* root)
{
    if (root)
    {
        free(root->left);
        free(root->right);
        delete root;
    }
}

//��������� ����
template<typename T>
Node<T>* BinarySearchTree<T>::createNode(T data, Node<T>* currentNode)
{
    Node<T>* newNode = new Node<T>();
    
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;


    return newNode;
}
//


//������� ��� avl
//template<typename T>
//Node<T>* BinarySearchTree<T>::PrivateInsert(Node<T>* currentNode, T data)
//{
//    if (root == nullptr)
//    {
//        root = createNode(data, nullptr);
//    }
//
//    if (currentNode == nullptr)
//    {
//        return createNode(data, currentNode);
//    }
//    else if (data < currentNode->data)
//    {
//        currentNode->left = PrivateInsert(currentNode->left, data);
//    }
//    else if (currentNode->data < data)
//    {
//        currentNode->right = PrivateInsert(currentNode->right, data);
//    }
//
//    return currentNode;
//}


//������� � avl
template<typename T>
Node<T>* BinarySearchTree<T>::PrivateInsert(Node<T>* currentNode, T data)
{
    if (root == nullptr)
    {
        root = createNode(data, nullptr);
    }
           
    if (currentNode == nullptr)
    {
        return createNode(data, currentNode);
    }
    else if (data < currentNode->data)
    {
        currentNode->left = PrivateInsert(currentNode->left, data);
    }
    else if (currentNode->data < data)
    {
        currentNode->right = PrivateInsert(currentNode->right, data);
    }
    else return currentNode;

    // ��������� ������
    currentNode->height = 1 + max(NodeHeight(currentNode->left), NodeHeight(currentNode->right));
    int balanceFactor = getBalanceFactor(currentNode);

    if (balanceFactor > 1) //��� �������� ����
    {
        if (data < currentNode->left->data)
        {
            return rightRotate(currentNode);
        }
        else if (data > currentNode->left->data)
        {
            currentNode->left = leftRotate(currentNode->left);
            return rightRotate(currentNode);
        }
    }
    if (balanceFactor < -1) //��� �������� ����
    {
        if (data > currentNode->right->data)
        {
            return leftRotate(currentNode);
        }
        else if (data < currentNode->right->data)
        {
            currentNode->right = rightRotate(currentNode->right);
            return leftRotate(currentNode);
        }
    }

    return currentNode;
}


template<typename T>
Node<T>* BinarySearchTree<T>::insert(T data)
{   root= PrivateInsert(root, data);
    return root;
}
//


//������ ������
template<typename T>
int BinarySearchTree<T>::PrivateHeight(Node<T>* root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return 0;
    }

    return 1+max(PrivateHeight(root->left), PrivateHeight(root->right));
    
}

template<typename T>
int BinarySearchTree<T>::height()
{
    return PrivateHeight(root);
}
//

//����� � ������������� �������
template<typename T>
void BinarySearchTree<T>::PrivateInorder(Node<T>* root)
{
    if (root != nullptr)
    {
        PrivateInorder(root->left);
        cout << root->data<<endl;
        PrivateInorder(root->right);
    }
}

template<typename T>
void BinarySearchTree<T>::inorder()
{
    return PrivateInorder(root);
}
//


//��������� �������
template<typename T>
Node<T>* BinarySearchTree<T>::PrivateMinimum(Node<T>* root)
{
    if (root->left == nullptr)
    {
        return root;
    }
    return PrivateMinimum(root->left);
}
//

template<typename T>
Node<T>* BinarySearchTree<T>::minimum()
{
    return PrivateMinimum(root);
}
//


//������������ �������
template<typename T>
Node<T>* BinarySearchTree<T>::PrivateMaximum(Node<T>* root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return PrivateMaximum(root->right);
}

template<typename T>
Node<T>* BinarySearchTree<T>::maximum()
{
    return PrivateMaximum(root);
}
//


//�����
template<typename T>
int BinarySearchTree<T>::PrivateSize(Node<T>* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return(PrivateSize(root->left) + 1 + PrivateSize(root->right));
    }
}

template<typename T>
int BinarySearchTree<T>::size()
{
    return PrivateSize(root);
}
//


//�����
template<typename T>
Node<T>* BinarySearchTree<T>::PrivateFind(Node<T>* root, const T& key)
{
    if (root == nullptr || key == root->data)
    {
        return root;
    }

    if (key < root->data)
    {
        return PrivateFind(root->left, key);
    }
    else
    {
        return PrivateFind(root->right, key);
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::find(const T& key)
{
    return PrivateFind(root, key);
}
//


//��������� ��� avl
//template<typename T>
//Node<T>* BinarySearchTree<T>::PrivateErase(Node<T>* root, T key)
//{
//    if (root == nullptr)
//    {
//        return root;
//    }
//
//    if (key < root->data)
//    {
//        root->left = PrivateErase(root->left, key);
//    }
//    else if (key> root->data)
//    {
//        root->right = PrivateErase(root->right, key);
//    }
//    else
//    {
//        //���� ����� � ����� �������� �� ����������, ��  key == root, ����� ������� �������� � ���� ����� ��������
//        if (root->left == nullptr)
//        {
//            Node<T>* temp = root->right;
//            delete root;
//            return temp;
//        }
//        else if (root->right == nullptr)
//        {
//            Node<T>* temp = root->left;
//            delete root;
//            return temp;
//        }
//        else// � ����� � ��� �������
//        {
//            Node<T>* next_min = PrivateMinimum(root->right);
//            root->data = next_min->data;
//            root->right = PrivateErase(root->right, next_min->data);
//        }
//    }
//  
//   
//        return root;
//
//}

//��������� � avl
template<typename T>
Node<T>* BinarySearchTree<T>::PrivateErase(Node<T>* root, T key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (key < root->data)
    {
        root->left = PrivateErase(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = PrivateErase(root->right, key);
    }
    else//key==root
    {   
        if (root->left == nullptr)
        {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node<T>* temp = nodeWithMimumValue(root->right);
            root->data = temp->data;
            root->right = PrivateErase(root->right, temp->data);
        }
    }


    root->height = 1 + max(NodeHeight(root->left), NodeHeight(root->right));
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)//left left
    {
        return rightRotate(root);
    }
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)//left right
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) //right right
    {
        return leftRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) //right left
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

template<typename T>
void BinarySearchTree<T>::erase(T key)
{
    PrivateErase(root, key);
}
//


//����� �� �������


//��������� ������
template<typename T>
void BinarySearchTree<T>::split(Node<T>* current, const T& Border, Node<T>** L, Node<T>** R)
{
   if (!current)
  {
      *L = nullptr;
        *R = nullptr;
    }
    else if (current->data < Border || current->data == Border)
    {
        *L = current;
        split(current->right, Border, &(current->right), R);
    }
    else
    {
        *R = current;
        split(current->left, Border, L, &(current->left));
   }
}
//


//��'������� �����
template<typename T>
void BinarySearchTree<T>::merge(Node<T>** Tree, Node<T>** L, Node<T>** R)
{
    if (!(*L))
    {
        *Tree = *R;
    }
    else if (!(*R))
    {
        *Tree = *L;
    }
    else if ((*R)->data < (*L)->data)
    {
        merge(&((*L)->right), &((*L)->right), R);
        *Tree = *L;
    }
    else
    {
        merge(&((*R)->left), L, &((*R)->left));
        *Tree = *R;
    }
}
//


template<typename T>
void BinarySearchTree<T>::AddToResult(Node<T>* root, std::vector<T>* result)
{
    if (root != nullptr)
    {
        AddToResult(root->left, result);
        result->push_back(root->data);
        AddToResult(root->right, result);
    }
}


//����� �� �������
template<typename T>
int BinarySearchTree<T>::findInRange(const T& min, const T&  max)
{
    Node<T>* L1 = nullptr;
    Node<T>* R1 = nullptr;

    split(root, min, &L1, &R1);

    Node<T>* L2 = nullptr;
    Node<T>* R2 = nullptr;
    split(R1, max, &L2, &R2);

    vector<T> result;
    AddToResult(L2, &result);

    merge(&R1, &L2, &R2);
    merge(&root, &L1, &R1);

    return result.size();
}
//


//��������� �� �������
template<typename T>
void BinarySearchTree<T>::EraseRange(T min, T max) {
    Node<T>* L1 = nullptr;
    Node<T>* R1 = nullptr;

    // ��������� ������ �� �� �������: L1 (�������� ����� �� min) � R1 (�������� ����� ��� ��� min)
    split(root, min, &L1, &R1);

    Node<T>* L2 = nullptr;
    Node<T>* R2 = nullptr;

    // ��������� R1 �� �� �������: L2 (�������� ����� ��� ��� max) � R2 (�������� ����� �� max)
    split(R1, max, &L2, &R2);

    // �'������ L1 � R2, ���������� L2 (�������� � ������� [min, max])
    merge(&root, &L1, &R2);

    // ��������� ������� ������� (L2)
    while (L2 != nullptr) {
        L2 = PrivateErase(L2, L2->data);
    }

}
//


//���


//������
template<typename T>
int BinarySearchTree<T>::NodeHeight(Node<T>* currentNode)
{
    if (currentNode == nullptr)
    {
        return 0;
    }

    return currentNode->height;
}
//


//������������ �������
template<typename T>
int BinarySearchTree<T>::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
//


//������ ������������
template<typename T>
int BinarySearchTree<T>::getBalanceFactor(Node<T>* currentNode)
{
    if (currentNode == nullptr)
    {
        return 0;
    }
        

    return NodeHeight(currentNode->left) - NodeHeight(currentNode->right);
}
 //


//������� ����
template<typename T>
Node<T>* BinarySearchTree<T>::leftRotate(Node<T>* currentNode)
{
    Node<T>* son = currentNode->right;
    Node<T>* leftGrandson = son->left;

    son->left = currentNode;
    currentNode->right = leftGrandson;

    currentNode->height = 1 + max(NodeHeight(currentNode->left), NodeHeight(currentNode->right));
    son->height = 1 +max(NodeHeight(son->left), NodeHeight(son->right));

    return son;
}
//


//������� �������
template<typename T>
Node<T>* BinarySearchTree<T>::rightRotate(Node<T>* currentNode)
{
    Node<T>* son = currentNode->left;
    Node<T>* rightGrandson = son->right;

    son->right = currentNode;
    currentNode->left = rightGrandson;

    currentNode->height = 1 + max(NodeHeight(currentNode->left), NodeHeight(currentNode->right));
    currentNode->height = 1 + max(NodeHeight(currentNode->left), NodeHeight(currentNode->right));
    son->height = 1 + max(NodeHeight(son->left), NodeHeight(son->right));

    return son;
}
//


//��������� �������
template<typename T>
Node<T>* BinarySearchTree<T>::nodeWithMimumValue(Node<T>* currentNode)
{
    Node<T>* current = currentNode;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}
//
