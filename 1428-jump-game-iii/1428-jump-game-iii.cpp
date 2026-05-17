class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int x = arr[start];
        if (x == 0) return 1;
        arr[start] = -1;

        int l = start - x, r = start + x;

        if (l >= 0 && arr[l] >= 0) 
            if (canReach(arr, l)) 
                return 1;
        

        if (r < arr.size() && arr[r] >= 0) 
            if (canReach(arr, r)) 
                return 1;
    
        return 0;
    }
};