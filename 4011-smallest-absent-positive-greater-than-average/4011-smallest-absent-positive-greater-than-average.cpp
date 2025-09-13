// 200th submission yippie !!!!!!!!!!!! （￣︶￣）↗　

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int> myau(nums.begin(), nums.end());
        
        double avg = 0;
        for(int x : nums) avg += x;
        avg /= nums.size();

        
        int meow=max(1, (int)floor(avg) + 1);
        while(myau.count(meow)) meow++;
        return meow;
    }
};