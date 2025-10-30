class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> myau(k, 0);

        for (int i = 0; i < energy.size(); i++) {
            myau[i % k] = max(energy[i], myau[i % k] + energy[i]);
        }

        return *max_element(myau.begin(), myau.end());
    }
};