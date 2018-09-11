//################################### AVLTree.cpp ############################################
#include "AVLTree.h"
#include <iostream>

using namespace std;

template<class T>
int AVLTree<T>::height(AVLNode<T> *p){
    if(p != nullptr) return p->height;
    return -1;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T> *node){
    AVLNode<T> *ax = node->left;
    node->left = ax->right;
    ax->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    ax->height = max(height(ax->left), height(ax->right)) + 1;
    return ax;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T> *node){
    AVLNode<T> *ax = node->right;
    node->right = ax->left;
    ax->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    ax->height = max(height(ax->left), height(ax->right)) + 1;
    return ax;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateRightLeft(AVLNode<T> *node){
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLeftRight(AVLNode<T> *node){
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

template<class T>
void AVLTree<T>::insert(AVLNode<T>*& node, const T& key){
    if(node != nullptr){
        if(key < node->key){
            insert(node->left, key);
            if(abs(height(node->right) - height(node->left)) == 2)
                if(key < node->left->key) node = rotateRight(node);
                else node = rotateLeftRight(node);
        }
        else{
            insert(node->right, key);
            if(abs(height(node->right) - height(node->left)) == 2)
                if(key > node->right->key) node = rotateLeft(node);
                else node = rotateRightLeft(node);
        }
    }
    else{
        node = new AVLNode<T>(key);
    }
    node->height = max(height(node->left), height(node->right)) +1;
}

template<class T>
void AVLTree<T>::insert(const T& key){
    insert(root, key);
}

template<class T>
void AVLTree<T>::clear(AVLNode<T> *node){
    if(node != nullptr){
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<class T>
AVLNode<T>*& AVLTree<T>::search(AVLNode<T>*& node, const T& key) const{
    if(node != nullptr){
        if(key == node->key) return node;
        else if(key < node->key) return search(node->left, key);
        else return search(node->right, key);
    }
    return node;
}

template<class T>
void AVLTree<T>::preOrder(AVLNode<T>* p){
    if(p != nullptr){
       print(p);
       preOrder(p->left);
       preOrder(p->right);
    }
}

template<class T>
void AVLTree<T>::inOrder(AVLNode<T>* p){
    if(p != nullptr){
        inOrder(p->left);
        print(p);
        inOrder(p->right);
    }
}

template<class T>
void AVLTree<T>::postOrder(AVLNode<T>* p){
    if(p != nullptr){
        postOrder(p->left);
        postOrder(p->right);
        print(p);
    }
}

template class AVLTree<int>;
template class AVLTree<char>;
