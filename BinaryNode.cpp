//  BinaryNode.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/26.
#ifndef BINARY_NODE
#define BINARY_NODE
template <typename E> class BinNode {
public:
  virtual ~BinNode() {} // Base destructor
  // Return the node’s value
  virtual E& element() = 0;
  // Set the node’s value
  virtual void setElement(const E&) = 0;
  // Return the node’s left child
  virtual BinNode* left() const = 0;
  // Set the node’s left child
  virtual void setLeft(BinNode*) = 0;
  // Return the node’s right child
  virtual BinNode* right() const = 0;
  // Set the node’s right child
  virtual void setRight(BinNode*) = 0;
  // Return true if the node is a leaf, false otherwise
  virtual bool isLeaf() = 0;
};

template <typename Key,typename T> class BinaryNode:public BinNode<T> {
    
private:
Key key;
T data;
BinaryNode* leftChild;
BinaryNode* rightChild;

public:
    BinaryNode() {
        leftChild = rightChild = nullptr;
        
    }
    BinaryNode(Key key, T item, BinaryNode* left =nullptr, BinaryNode* right =nullptr){
        this->key = key;
        data = item;
        leftChild = left;
        rightChild = right;
        
    }
    ~BinaryNode() {}

  T& element() {
      return data;
      
  }
    
  T& elementPointer(){return &data;}
  void setElement(const T& e) {
      data = e;
      
  }
  Key& getKey() {
      return key;
      
  }
    
  T& getData(){
     return &data;
   }
  void setKey(const Key& K) {
      this->key = K;
      
  }

  inline BinaryNode* left() const {
      return leftChild;
      
  }
  void setLeft(BinNode<T>* b) {
      leftChild = (BinaryNode*)b;
      
  }
  inline BinaryNode* right() const {
      return rightChild;
      
  }
  void setRight(BinNode<T>* b) {
      rightChild = (BinaryNode*)b;
      
  }

  bool isLeaf() {
      return (leftChild == nullptr) && (rightChild == nullptr);
      
  }
};
#endif
