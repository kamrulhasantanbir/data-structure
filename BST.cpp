#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert1(Node *&root, int v) {
    if (root == NULL) {
        root = new Node(v);
        return;
    }
    
    if (v < root->val) {
        if (root->left == NULL) {
            root->left = new Node(v);
        } else {
            insert1(root->left, v);
        }
    } else {
        if (root->right == NULL) {
            root->right = new Node(v);
        } else {
            insert1(root->right, v);
        }
    }
}

bool search1(Node *root, int x) {
    if (root == NULL) {
        return false;
    } else if (root->val == x) {
        return true;
    } else if (x < root->val) {
        return search1(root->left, x);
    } else {
        return search1(root->right, x);
    }
}


Node* array_to_bst(int arr[], int l, int r) {
    if (l > r) {
        return NULL;
    }
    
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    
    Node *left1 = array_to_bst(arr, l, mid - 1);
    Node *right1 = array_to_bst(arr, mid + 1, r);
    
    root->left = left1;
    root->right = right1;
    return root;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter values into the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    Node *root = array_to_bst(arr, 0, n - 1);
    cout << "BST initialized successfully from the array." << endl;

    cout << "1. Insert 2. Search 3. End" << endl;
    
    while (true) {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int v;
                cout << "Enter value to insert: ";
                cin >> v;
                insert1(root, v);  
                cout << "Inserted " << v << " into the BST." << endl;
            }
            break;
            
            case 2: {
                int v;
                cout << "Enter value to search: ";
                cin >> v;
                bool found = search1(root, v);  
                found ? cout << "Found" << endl : cout << "Not found" << endl;
            }
            break;

            case 3:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
