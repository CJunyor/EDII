//############################## AVLTree.h ##########################################
#include <iostream>

using namespace std;

#ifndef AVL_TREE
#define AVL_TREE

template<class T>
class AVLNode{
public:
    AVLNode(){
        left = right = nullptr;
        height = -1;
    }
    AVLNode(const T& key){
        this->key = key;
        left = right = nullptr;
        height = 0;
    }
    AVLNode(const T& key, AVLNode *left, AVLNode *right){
        this->key = key;
        this->left = left;
        this->right = right;
        height = right->height - left->height;
    }
    int height;
    T key;
    AVLNode *left, *right;
};

template<class T>
class AVLTree{
public:
    AVLTree(){
        root = nullptr;
    }
    ~AVLTree(){
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
    AVLNode<T>*& search(const T& key) const{
        return search((AVLNode<T>*&) root, key);
    }
    void insert(const T&);
protected:
    void insert(AVLNode<T>*&, const T&);
    int height(AVLNode<T>*);
    AVLNode<T>* rotateRight(AVLNode<T>*);
    AVLNode<T>* rotateLeft(AVLNode<T>*);
    AVLNode<T>* rotateRightLeft(AVLNode<T>*);
    AVLNode<T>* rotateLeftRight(AVLNode<T>*);
    void clear(AVLNode<T>*);
    AVLNode<T>*& search(AVLNode<T>*&, const T&) const;
    void preOrder(AVLNode<T>*);
    void inOrder(AVLNode<T>*);
    void postOrder(AVLNode<T>*);
    virtual void print(AVLNode<T>* p){ cout<<p->key<<' ';}
    AVLNode<T> *root;
};

#endif // AVL_TREE
