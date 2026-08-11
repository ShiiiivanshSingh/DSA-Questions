class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int steps = 0;
        queue<pair<string, int>> q;
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene)) return -1;
        set<string> visited;

        // if (gene == endGene) return mutations;
        q.push({startGene, 0});
        visited.insert(startGene);

        while (!q.empty()) {
            pair<string, int> cur = q.front();
            q.pop();

            string gene = cur.first;
            int steps = cur.second;
            if (gene == endGene)  return steps;
            for (int i = 0; i < 8; i++) {
                for (char c : {'A', 'C', 'G', 'T'}) {
                    string next = gene;
                    if(c == gene[i]) continue;
                    next[i] = c;
                    if(st.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};