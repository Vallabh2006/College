#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    else cout << val << " already exists, ignored.\n";
    return root;
}

void inorder(Node* r)   { if (r) { inorder(r->left);  cout << r->data << " "; inorder(r->right); } }
void preorder(Node* r)  { if (r) { cout << r->data << " "; preorder(r->left); preorder(r->right); } }
void postorder(Node* r) { if (r) { postorder(r->left); postorder(r->right); cout << r->data << " "; } }

int main() {
    Node* root = nullptr;
    int n, val;
    cout << "How many nodes? ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    cout << "\nInorder   : "; inorder(root);
    cout << "\nPreorder  : "; preorder(root);
    cout << "\nPostorder : "; postorder(root);
    cout << endl;
    return 0;
}
