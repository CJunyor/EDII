//###################################### BinaryTree.cpp ######################################
#include <iostream>
#include "BinaryTree.h"

using namespace std;

template<class T>
BTnode<T>*& BTnode<T>::rightMost(BTnode<T>*& node){
    if(node != nullptr){
        if(node->right == nullptr){
            return node;
        }
        else{
            return rightMost(node->right);
        }
    }
    return node;
}

template<class T>
BTnode<T>*& BTnode<T>::leftMost(BTnode<T>*& node){
    if(node != nullptr){
        if(node->left == nullptr){
            return node;
        }
        else{
            return leftMost(node->left);
        }
    }
    return node;
}

template<class T>
void BT<T>::insert(BTnode<T> *&p, const T& key){
    if(p != nullptr){
        if(key < p->key) insert(p->left, key);
        else insert(p->right, key);
    }
    else{
        p = new BTnode<T>(key);
    }
}

template<class T>
void BT<T>::insert(const T& key){
    BT<T>::insert(root, key);
}

template<class T>
void BT<T>::clear(BTnode<T> *&p){
    if(p != nullptr){
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

template<class T>
BTnode<T>*& BT<T>::search(BTnode<T> *&p, const T& key) const{
    if(p != nullptr){
        if(p->key == key) return p;
        else if(key < p->key) return search(p->left, key);
        else return search(p->right, key);
    }
    return p;
}

template<class T>
void BT<T>::deleteByMerging(BTnode<T>*& node){
    if(node != nullptr){
        BTnode<T>* ax = node;
        if(node->right == nullptr) node = node->left;
        else if(node->left == nullptr) node = node->right;
        else{
            BTnode<T>::rightMost(node->left) = node->right;
            node = node->left;
        }
        delete ax;
    }
}

template<class T>
void BT<T>::deleteByCopying(BTnode<T>*& node){
    if(node != nullptr){
        BTnode<T> *ax = node;
        if(node->right == nullptr) node = node->left;
        else if(node->left == nullptr) node = node->right;
        else{
            BTnode<T> *prev = node;
            ax = ax->left;
            while(ax->right != nullptr){
                prev = ax;
                ax = ax->right;
            }
            node->key = ax->key;
            if(ax == node->left) node->left = ax->left;
            else prev->right = ax->left;
        }
        delete ax;
    }
}

template<class T>
void BT<T>::findAndDeleteByMerging(const T& key){
    deleteByMerging(search(key));
}

template<class T>
void BT<T>::findAndDeleteByCopying(const T& key){
    deleteByCopying(search(key));
}


template<class T>
void BT<T>::preOrder(BTnode<T> *p){
    if(p != nullptr){
        print(p);
        preOrder(p->left);
        preOrder(p->right);
    }
}

template<class T>
void BT<T>::inOrder(BTnode<T> *p){
    if(p != nullptr){
        inOrder(p->left);
        print(p);
        inOrder(p->right);
    }
}

template<class T>
void BT<T>::postOrder(BTnode<T> *p){
    if(p != nullptr){
        postOrder(p->left);
        postOrder(p->right);
        print(p);
    }
}

template class BT<int>;
template class BT<char>;
