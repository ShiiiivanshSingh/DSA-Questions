class Solution {
public:
    TreeNode* build(unordered_map<int, vector<pair<int,int>>> &mp, int x) {
        TreeNode* root = new TreeNode(x);
        for (auto [v, f] : mp[x]) {
            if (f)
                root->left = build(mp, v);
            else
                root->right = build(mp, v);
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {

        unordered_map<int, vector<pair<int,int>>> mp;
        unordered_set<int> child, all;

     
        for (auto &x : d) {
            mp[x[0]].push_back({x[1], x[2]});
            all.insert(x[0]);
            all.insert(x[1]);
            child.insert(x[1]);
        }

        int root = 0;
        for (int x : all) {
            if (!child.count(x)) {
                root = x;
                break;
            }
        }
        return build(mp, root);
    }
};