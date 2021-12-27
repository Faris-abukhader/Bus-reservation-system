//  BinaryTree.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/26.
#include <iostream>
#include "BinaryNode.cpp"
#ifndef BINARY_TREE
#define BINARY_TREE
using namespace std;
template <typename Key ,typename E> class  BinarySearchTree{
private:
  BinaryNode<Key,E>* root;
  int nodecount;         
    
    
    void printhelp(BinaryNode<Key, E>* root, int level) const {
      if (root == nullptr) return;
      printhelp(root->left(), level+1);
      for (int i=0; i<level; i++)
      cout << "  ";
      cout << root->key() << "\n";
      printhelp(root->right(), level+1);
    }
    
    
    void clearhelp(BinaryNode<Key, E>* root) {
      if (root == nullptr) return;

      if(root->left() != nullptr)
      clearhelp(root->left());
      if(root->right()!=nullptr)
      clearhelp(root->right());

      delete root;
        
    }
    
    BinaryNode<Key, E>*removehelp(BinaryNode<Key, E>* rt, const Key& k) {
        if (rt == nullptr){ return nullptr;    // k is not in tree
        }else if (k < rt->getKey()){
        rt->setLeft(removehelp(rt->left(), k));
        }else if (k > rt->getKey()){
        rt->setRight(removehelp(rt->right(), k));
        }else {
            
        BinaryNode<Key, E>* temp = rt;
        if (rt->left() == nullptr) {
        rt = rt->right();
        delete temp;
        }
        else if (rt->right() == nullptr) {
        rt = rt->left();
        delete temp;
        }else{
          BinaryNode<Key, E>* temp = getmin(rt->right());
          rt->setElement(temp->element());
          rt->setKey(temp->getKey());
          rt->setRight(deletemin(rt->right()));
          delete temp;
        }
    }
    return rt;
        
    }

    
    
    
    E findhelp(BinaryNode<Key, E>* root,const Key& k) const {
      if (root == nullptr) return E();
        if (k < root->getKey()){
           return findhelp(root->left(), k);
        }else if (k > root->getKey()){
           return findhelp(root->right(), k);
        }else{
           return root->element();
        }
    }
    
    bool findhelps(BinaryNode<Key, E>* root,const Key& k) const {
        bool result;
      if (root == nullptr) return false;
        if (k < root->getKey()){
           result =  findhelps(root->left(), k);
        }else if (k > root->getKey()){
           result =  findhelps(root->right(), k);
        }else{
            result = true;
        }
        return result;
    }

    
    
    BinaryNode<Key, E>* inserthelp(BinaryNode<Key, E>* root, const Key& k, const E& it) {
      if (root == nullptr)
        return new BinaryNode<Key, E>(k, it, nullptr, nullptr);
      if (k < root->getKey())
        root->setLeft(inserthelp(root->left(), k, it));
      else root->setRight(inserthelp(root->right(), k, it));
      return root;
    }
    
    BinaryNode<Key, E>* deletemin(BinaryNode<Key, E>* rt) {
    if (rt->left() == nullptr){
        return rt->right();
    }else {
        rt->setLeft(deletemin(rt->left()));
        return rt;
        }
    }
    
    BinaryNode<Key,E>* getmin(BinaryNode<Key, E>* rt) {
      if (rt->left() == nullptr)
        return rt;
      else return getmin(rt->left());
    }
    

public:
    BinarySearchTree() {
        root = nullptr;
        nodecount = 0;
        
    }
    ~BinarySearchTree() {
      clearhelp(root);
        root = nullptr;
        nodecount = 0;
        
    }
  void clear(){
      clearhelp(root);
      root = nullptr;
      nodecount = 0;
      
  }
  void insert(const Key& k, const E& e) {
    root = inserthelp(root, k, e);
    nodecount++;
  }
  bool find(const Key& k) const {
      return findhelps(root, k);
      
  }
    
  E getValue(const Key& k) const {
        return findhelp(root, k);
        
  }


  E remove(const Key& k) {
  E temp = findhelp(root, k);
  if (temp.description() != E().description()) {
    root = removehelp(root, k);
    nodecount--;
  }
  return temp;
  }
    
    E printInorder(BinaryNode<Key, E> *node){
        E data;
        if (node == nullptr)return E();
        
        /* first recur on left subtree */
        data = printInorder(node->left());

     
        /* then print data of node */
        data = node->element();
        cout<<"-> "<<data.description()<<" <-"<<endl;
     
     
        /* now recur on right subtree */
        data = printInorder(node->right());
        
        return data;
    }
    
    
    BinaryNode<Key, E>* getRoot(){
        return this->root;
    }
    
    int getLength(){return nodecount;}

};
#endif
