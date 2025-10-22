
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int l = 0;
        int points = 0;
        int current = 0;
        int maxi = 0;
        while (1) {
            current = INT_MAX;
            if (i < n)
                current = min(current, nums[i]);
            if (j < n)
                current = min(current, nums[j] - k);
            if (l < n)
                current = min(current, nums[l] + k);
            if (current == INT_MAX)
                break;
            while ((j < n) && ((nums[j] - k) == current)) {
                points++;
                j++;
            }
            int at_point = 0;
            while ((i < n) && (nums[i] == current)) {
                at_point++;
                i++;
            }
            if (points - at_point > numOperations)
                maxi = max(maxi, numOperations + at_point);
            else
                maxi = max(maxi, points);

            while ((l < n) && (nums[l] + k == current)) {
                points--;
                l++;
            }
        }
        return maxi;
    }
};

/* Solution using map
class Solution {
    typedef struct {
        int point;
        int begin;
        int end;
    } event;

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, event> hash;
        for (auto num : nums) {
            auto it = hash.find(num - k);
            if (it != hash.end())
                it->second.begin++;
            else
                hash[num - k] = {0, 1, 0};

            it = hash.find(num);
            if (it != hash.end())
                it->second.point++;
            else
                hash[num] = {1, 0, 0};

            it = hash.find(num + k);
            if (it != hash.end())
                it->second.end++;
            else
                hash[num + k] = {0, 0, 1};
        }
        int points = 0;
        int maxi = 0;
        for(auto it = hash.begin(); it != hash.end(); it++)
        {
            points += it->second.begin;
            if(points-it->second.point>numOperations)
            maxi=max(maxi,it->second.point+numOperations);
            else
            maxi=max(maxi,points);
            points -= it->second.end;
        }
        return maxi;
    }
};*/