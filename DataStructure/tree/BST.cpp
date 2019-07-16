#include <memory>
#include <iostream>

using namespace std;
template<typename T> 
struct Node{
    Node() = default;
    Node(T v):value(v){}
    T value = 0;
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;
    shared_ptr<Node<T>> parent;
};


template <typename T>
class BST{

public:
    BST() = default;
    ~BST(){
        root.reset();
    }
    void add(T value){
        if(!root)
            root = make_shared<Node<T>>(value);
        else{
            shared_ptr<Node<T>> p = root;
            while(true){
            if(value>p->value){
                if(!p->right){
                    p->right = make_shared<Node<T>>(value);
                    p->right->parent = p;
                    break;
                }else
                    p = p->right;
            }
            //put it left child    
            else{
                if(!p->left){
                    p->left = make_shared<Node<T>>(value);
                    p->left->parent = p;
                    break;
                }else
                    p = p->left;

            }
                
        }
        }
    }// end of funtion add

    bool search(T value){
        auto p = root;
        while(p!=nullptr){
            if(value>p->value){
                p = p->right;
            }else if(value < p->value)
                p = p->left;
            else
                return true;

        }
        return false;
    }// end of function search

    void balance(){

        
    }




private:

    shared_ptr<Node<T>> grandparent(shared_ptr<Node<T>> p){
        return p->parent->parent;
    }

    shared_ptr<Node<T>> root;
};


int main(){

    BST<int> tree;
    for(int i=0;i<10;i++){
        tree.add(i);
    }
    if(tree.search(11)){
        cout<<"true";
    }else
    {
        cout<<"false";
    }
    

    return 0;
}