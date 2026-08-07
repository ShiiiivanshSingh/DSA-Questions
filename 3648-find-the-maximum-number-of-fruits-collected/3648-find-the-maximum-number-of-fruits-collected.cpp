class Solution {
public:
    vector<vector<int>> dpDos, dpTres;
    
    int childUno(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int child1 = 0; // no pooosbile mejora
        for (int i = 0; i < n; i++) child1 += fruits[i][i];
        return child1;
    }

    int childDos(vector<vector<int>>& fruits, int i, int j) {
        int n = fruits.size();
        if (i < 0 || i >= n || j < 0 || j >= n) return INT_MIN;
        if (j <= i && !(i == n - 1 && j == n - 1)) return INT_MIN;
        if (dpDos[i][j] != -1) return dpDos[i][j];
        if (i == n - 1 && j == n - 1) return 0;

        int child = max({
            childDos(fruits, i + 1, j),
            childDos(fruits, i + 1, j - 1),
            childDos(fruits, i + 1, j + 1) });

        if (child == INT_MIN) return dpDos[i][j] = INT_MIN;
        return dpDos[i][j] = fruits[i][j] + child;
        //return dpDos[i][j] = child2;
    }

    int childTres(vector<vector<int>>& fruits, int i, int j) {
        
        int n = fruits.size();
        if (i < 0 || i >= n || j < 0 || j >= n) return INT_MIN;
        if (j >= i && !(i == n - 1 && j == n - 1)) return INT_MIN;
        int child3 = 0;
        if (dpTres[i][j] != -1) return dpTres[i][j];
        if (i == n - 1 && j == n - 1) return 0;

        int child = max({
            childTres(fruits, i - 1, j + 1),
            childTres(fruits, i,     j + 1),
            childTres(fruits, i + 1, j + 1) });

        if (child == INT_MIN) return dpTres[i][j] = INT_MIN;
        return dpTres[i][j] = fruits[i][j] + child;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int m = fruits[0].size();
        dpDos.assign(n, vector<int>(n, -1));
        dpTres.assign(n, vector<int>(n, -1));
        return childUno(fruits) + childDos(fruits, 0, n - 1) +  childTres(fruits, n - 1, 0);
    }
};
