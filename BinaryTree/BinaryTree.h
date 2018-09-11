//######################### BinaryTree.h #####################################
#include <iostream>
#define c(x) cout<<x<<endl

using namespace std;

#ifndef BINARY_TREE
#define BINARY_TREE

template<class T>
class BTnode{
public:
    BTnode(){
        left = right = nullptr;
    }
    BTnode(const T& key, BTnode *left = nullptr, BTnode *right = nullptr){
        this->key = key;
        this->left = left;
        this->right = right;
    }
    static BTnode*& rightMost(BTnode<T>*&);
    static BTnode*& leftMost(BTnode<T>*&);
    T key;
    BTnode *left, *right;
};

template<class T>
class BT{
public:
    BT(){
        root = nullptr;
    }
    ~BT(){
        clear();
    }
    void clear(){
        clear(root);
        root = nullptr;
    }
    bool isEmpty(){
        return root == nullptr;
    }
    void preOrder(){
        preOrder(root);
    }
    void inOrder(){
        inOrder(root);
    }
    void postOrder(){
        postOrder(root);
    }
    BTnode<T>*& search(const T& key) const{
        return search((BTnode<T>*&) root, key);
    }
    void insert(const T&);
    void findAndDeleteByMerging(const T&);
    void findAndDeleteByCopying(const T&);
protected:
    void insert(BTnode<T>*&, const T&);
    void clear(BTnode<T>*&);
    BTnode<T>*& search(BTnode<T>*&, const T&) const;
    void deleteByMerging(BTnode<T>*&);
    void deleteByCopying(BTnode<T>*&);
    void preOrder(BTnode<T>*);
    void inOrder(BTnode<T>*);
    void postOrder(BTnode<T>*);
    virtual void print(BTnode<T>* p){ cout<<p->key<<' ';}
    BTnode<T> *root;
};
#endif // BINARY_TREE
