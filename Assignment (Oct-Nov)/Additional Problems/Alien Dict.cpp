


class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        for (auto &word : words) {
            for (auto &ch : word) {
                indegree[ch] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int len = min(w1.length(), w2.length());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }
            if (!found && w1.length() > w2.length()) {
                return "";
            }
        }
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        string ans = "";
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;
            for (auto &nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (ans.length() != indegree.size()) return "";
        return ans;
    }
};

