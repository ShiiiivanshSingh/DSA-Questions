class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n, j = n;
        i--; i--;  j--;
        
        while (i >= 0 && arr[i] <= arr[i + 1]) i--;
        if (i < 0)   return arr;
        
        
        while (arr[j] >=arr[i]||arr[j] ==arr[j-1]) 
                j--;
        
        
        swap(arr[i], arr[j]);
        return arr;
    }
};