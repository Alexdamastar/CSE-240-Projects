#include <iostream>
using namespace std;

class BinarySearchTree
{
    public:
        BinarySearchTree() {root = NULL;}
        void insert(int);
        bool search(int);
        bool isEmpty() const { return root==NULL;}
        void print_inorder();
    private:
        struct node
        {
            int data;
            node* left;
            node* right;
        };

        node* root;
        void inorder(node*);
};

int main()
{
    BinarySearchTree b;
    b.insert(50);
    b.insert(30);
    b.insert(40);
    b.insert(70);


    if (b.search(40))
        printf("%d found\n", 40);
    else
        printf("%d not found\n", 40);
    b.print_inorder();
}