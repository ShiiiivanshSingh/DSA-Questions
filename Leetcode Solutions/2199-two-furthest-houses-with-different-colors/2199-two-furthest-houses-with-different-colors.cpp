class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n =colors.size() -1;
        int right  = n ; int left =0;
        while(right!= 0 && colors[0] == colors[right] ) right--;
        while(left<n && colors[0] == colors[left] ) left++;

        return max(n -left , right);
    }
};