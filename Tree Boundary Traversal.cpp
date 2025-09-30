class Solution {
public:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }
    
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }
    
    void addRightBoundary(Node* root, vector<int>& res) {
        vector<int> tmp;
        Node* curr = root->right;
        while (curr) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // Add in reverse order
        for (int i = tmp.size()-1; i >= 0; i--) {
            res.push_back(tmp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        
        if (!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};
