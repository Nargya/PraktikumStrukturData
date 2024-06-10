#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    TNode (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* findNode(TNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;
    TNode* leftResult = findNode(root->left, value);
    if (leftResult != NULL) return leftResult;
    return findNode(root->right, value);
}

void displayChildren(TNode* root, int value) {
    TNode* node = findNode(root, value);
    if (node != NULL) {
        cout << "Children of " << value << ": ";
        if (node->left != NULL) cout << node->left->data << " ";
        if (node->right != NULL) cout << node->right->data << " ";
        if (node->left == NULL && node->right == NULL) cout << "No children";
        cout << endl;
    } else {
        cout << "Node " << value << " not found." << endl;
    }
}

void displayDescendants(TNode* root, int value) {
    TNode* node = findNode(root, value);
    if (node != NULL) {
        cout << "Descendants of " << value << ": ";
        queue<TNode*> q;
        q.push(node);
        bool hasDescendants = false;
        while (!q.empty()) {
            TNode* current = q.front();
            q.pop();
            if (current != node) {
                cout << current->data << " ";
                hasDescendants = true;
            }
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        if (!hasDescendants) cout << "No descendants";
        cout << endl;
    } else {
        cout << "Node " << value << " not found." << endl;
    }
}

void addNode(TNode*& root, int parentValue, int childValue, char childSide) {
    TNode* parentNode = findNode(root, parentValue);
    if (parentNode != NULL) {
        if (childSide == 'L' || childSide == 'l') {
            if (parentNode->left == NULL) {
                parentNode->left = new TNode(childValue);
            } else {
                cout << "Left child already exists for node " << parentValue << endl;
            }
        } else if (childSide == 'R' || childSide == 'r') {
            if (parentNode->right == NULL) {
                parentNode->right = new TNode(childValue);
            } else {
                cout << "Right child already exists for node " << parentValue << endl;
            }
        } else {
            cout << "Invalid child side. Use 'L' for left and 'R' for right." << endl;
        }
    } else {
        cout << "Parent node " << parentValue << " not found." << endl;
    }
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add node\n";
    cout << "2. Display children of a node\n";
    cout << "3. Display descendants of a node\n";
    cout << "4. Display Pre-Order traversal\n";
    cout << "5. Display In-Order traversal\n";
    cout << "6. Display Post-Order traversal\n";
    cout << "7. Exit\n";
}

int main() {
    TNode* root = new TNode(7); // Default root node with value 7
    int choice;
    int parentValue, childValue;
    char childSide;
    int nodeValue;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter parent node value: ";
                cin >> parentValue;
                cout << "Enter child node value: ";
                cin >> childValue;
                cout << "Enter child side (L/R): ";
                cin >> childSide;
                addNode(root, parentValue, childValue, childSide);
                break;
            case 2:
                cout << "Enter node value to display children: ";
                cin >> nodeValue;
                displayChildren(root, nodeValue);
                break;
            case 3:
                cout << "Enter node value to display descendants: ";
                cin >> nodeValue;
                displayDescendants(root, nodeValue);
                break;
            case 4:
                cout << "Pre-Order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "In-Order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Post-Order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
