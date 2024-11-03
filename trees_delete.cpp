#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the node with the specified value
Node* findNode(Node* root, int val) {
    if (root == nullptr) return nullptr;
    if (root->data == val) return root;
    
    Node* found = findNode(root->left, val);
    if (found) return found;
    return findNode(root->right, val);
}

// Recursive function to find the deepest node and its parent
void findDeepest(Node* root, Node*& deepest, Node*& parent, int depth, int& maxDepth) {
    if (root == nullptr) return;

    // If this node is deeper than the current deepest, update deepest and maxDepth
    if (depth > maxDepth) {
        maxDepth = depth;
        deepest = root;
    }
    
    // Traverse left and right, tracking parent relationships
    if (root->left) {
        parent = root;
        findDeepest(root->left, deepest, parent, depth + 1, maxDepth);
    }
    if (root->right) {
        parent = root;
        findDeepest(root->right, deepest, parent, depth + 1, maxDepth);
    }
}

// Function to delete a node in a binary tree
Node* deleteNode(Node* root, int val) {
    if (root == nullptr) return nullptr;

    // Find the node to delete
    Node* target = findNode(root, val);
    if (target == nullptr) return root; // If node not found, return original tree

    // Initialize variables to find the deepest node and its parent
    Node* deepest = nullptr;
    Node* parent = nullptr;
    int maxDepth = -1;
    findDeepest(root, deepest, parent, 0, maxDepth); // Call to find the deepest node and its parent

    // Replace the value of the target node with the value of the deepest node
    target->data = deepest->data;

    // Now we need to remove the deepest node
    if (deepest == root) {
        // If the deepest node is the root, delete the root and return nullptr
        delete deepest;
        return nullptr;
    }

    // Disconnect the deepest node from its parent
    if (parent->left == deepest) {
        parent->left = nullptr; // If deepest is a left child, set parent's left pointer to nullptr
    } else {
        parent->right = nullptr; // If deepest is a right child, set parent's right pointer to nullptr
    }

    delete deepest; // Free the memory of the deepest node
    return root; // Return the modified tree
}

// In-order traversal to print the tree
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout << "Original tree (in-order): ";
    inorder(root);
    cout << endl;

    int valToDel = 3;
    root = deleteNode(root, valToDel);

    cout << "Tree after deleting " << valToDel << " (in-order): ";
    inorder(root);
    cout << endl;

    return 0;
}
