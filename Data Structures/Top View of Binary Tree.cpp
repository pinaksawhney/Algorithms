#include <iostream>
#include<queue>
#include<map>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node *insert(Node *root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node *cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void topView(Node* root) {
        if (root != nullptr) {
            queue<pair<int,Node *>> q;
            map<int, Node *> m;
            q.push(make_pair(0,root));
            m.insert(pair<int, Node *>(0, root));
            while (!q.empty()) {
                pair<int, Node*> p = q.front();
                int val = p.first;
                Node* parent = p.second;
                if (parent->left != nullptr) {
                    q.push(make_pair(val-1,parent->left));
                    if (m.find(val-1) == m.end()) {
                        m.insert(pair<int, Node*>(val-1, parent->left));
                    }
                }
                if (parent->right != nullptr) {
                    q.push(make_pair(val+1,parent->right));
                    if (m.find(val+1) == m.end()) {
                        m.insert(pair<int, Node *>(val+1, parent->right));
                    }
                }
                q.pop();
            }
            for(auto it:m){
                cout<<it.second->data<<" ";
            }
        }
    }
};



int main() {
    Solution myTree;
    Node* root = nullptr;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);

    return 0;
}
