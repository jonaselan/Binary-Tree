#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root){
    if (root != NULL) {
        inorder(root->left);
        //printf("%d \n", root->key);
        cout << root->key << "\n";
        inorder(root->right);
    }
}

void posorder(struct node* node){
  if (node != NULL) {
    posorder(node->left);
    posorder(node->right);

    cout << node->key;
  }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

bool isEmpty(struct node* node){
  if (node == NULL)
    return true;
  else
    return false;
}

bool search(struct node* node, int key) {
  if (node == NULL)
    return false;
  else if (node->key == key)
    return true;

  if (node->key > key)
    search(node->right, key);
  else
    search(node->left, key);

}

// Driver Program to test above functions
int main() {
    /* Let us create following BST
                5
             /    \
           3       7
          /  \   /  \
         2   4  6   8 */
    struct node *root = NULL;
    root = insert(root, 5);

    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    /*  */

    /* verify if tree it is empty
      cout << isEmpty(root);
    */

    /* print inoder traversal of the BST */
     inorder(root);

    /* print posoderdem traversal of the BST */
    posorder(root);

    /* search value in tree
      cout << search(root, 8)
     */

    return 0;
}
