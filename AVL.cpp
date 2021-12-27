//  AVL.cpp
//  BusReservationSystem
//  Created by admin on 2021/12/5.
#include "iostream"
#ifndef AVLTREE
#define AVLTREE
template <typename Key,typename Data> class AVL{
    public:
        class node{
            public:
                Key key;
                Data data;
                int height;
                node * left;
                node * right;
                node(Key k){
                    height = 1;
                    key = k;
                    left = nullptr;
                    right = nullptr;
                }
                node(Key k,Data data){
                height = 1;
                key = k;
                this->data = data;
                left = nullptr;
                right = nullptr;
               }
        };
        node * root = nullptr;
        int n;
        int getSize(){return this->n;}
        bool find(Key key){return this->findUtil(root, key);}
        void insert(Key x,Data data){
            root=insertUtil(root, x,data);
        }
        void remove(Key x){
            root=removeUtil(root, x);
        }
        node * search(Key x){
            return searchUtil(root,x);
        }
        void inorder(){
            inorderUtil(root);
            std::cout<<std::endl;
        }
    private:
        int height(node * head){
            if(head==nullptr) return 0;
            return head->height;
        }
        node * rightRotation(node * head){
            node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        node * leftRotation(node * head){
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        void inorderUtil(node * head){
            if(head==nullptr) return ;
            inorderUtil(head->left);
            std::cout<<head->data.description()<<" ";
            inorderUtil(head->right);
        }

        node * insertUtil(node * head, Key x,Data data){
            if(head==nullptr){
                n+=1;
                node * temp = new node(x,data);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x,data);
            else if(x > head->key) head->right = insertUtil(head->right, x,data);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x < head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                if(x > head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node * removeUtil(node * head, Key x){
            if(head==nullptr) return nullptr;
            if(x < head->key){
                head->left = removeUtil(head->left, x);
            }else if(x > head->key){
                head->right = removeUtil(head->right, x);
            }else{
                node * r = head->right;
                if(head->right==nullptr){
                    node * l = head->left;
                    delete(head);
                    head = l;
                }else if(head->left==nullptr){
                    delete(head);
                    head = r;
                }else{
                    while(r->left!=nullptr) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if(head==nullptr) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(height(head->left) >= height(head->right)){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal < -1){
                if(height(head->right) >= height(head->left)){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node * searchUtil(node * head, Key x){
            if(head == nullptr) return nullptr;
            Key k = head->key;
            if(k == x) return head;
            if(k > x) return searchUtil(head->left, x);
            if(k < x) return searchUtil(head->right, x);
            return nullptr;
        }
    
    bool findUtil(node* root,const Key& k) const {
        bool result;
      if (root == nullptr) return false;
        if (k < root->key){
           result =  findUtil(root->left, k);
        }else if (k > root->key){
           result =  findUtil(root->right, k);
        }else{
            result = true;
        }
        return result;
    }

};
#endif
