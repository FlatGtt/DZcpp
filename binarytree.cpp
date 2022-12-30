#include <iostream>
using namespace std;
 
template <class T>
class Tree{
private:
    class Item{
        friend Tree;
        Item* parent;
        Item* left;
        Item* right;
        T value;
        Item(T value, Item* parent, Item* left = nullptr, Item* right = nullptr) : value(value), parent(parent), left(left), right(right) {}
    };
 
    Item* root;
 
    void Add(T& value, Item* ptr){
        if (ptr->value > value){
            if (ptr->left){
                Add(value, ptr);
            }
            else{
                ptr->left = new Item(value, ptr);
            }
        }
        else{
            if (ptr->right){
                Add(value, ptr->right);
            }
            else{
                ptr->right = new Item(value, ptr);
            }
        }
    }
    void Print(Item* ptr){
        
        if (ptr->left)Print(ptr->left);
        cout << ptr->value << "; ";
        if (ptr->right)Print(ptr->right);
    }
 
    void Destroy(Item* ptr){
        if (ptr->left)Destroy(ptr->left);
        if (ptr->right)Destroy(ptr->right);
        delete ptr;
    }
 
public:
    Tree() :root(nullptr){
 
    }
 
    void Add(T value){
        if (root){
            Add(value, root);
        }
        else
            root = new Item(value, nullptr);
    }
 
    void Print(){
        if (!root){
            cout << "Tree is empty" << endl;
        }
        else
            Print(root);
    }
 
    ~Tree(){
        if (root)Destroy(root);
    }
};


int main(){
    Tree <int> BTree;
    BTree.Add(50);
    BTree.Print();
    cout << endl;
}