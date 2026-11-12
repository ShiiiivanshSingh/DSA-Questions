class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        if (nums1.size() > nums2.size())  swap(nums1, nums2);
        

        int n = nums1.size();
        int m = nums2.size();

        int l = 0, r = n;


        while (l <= r) {

            int l1, r1, l2, r2;
            int cut1 = (l + r) / 2, cut2 = (n + m + 1) / 2 - cut1;


            if (cut1 == 0) l1 = INT_MIN;
            else l1 = nums1[cut1 - 1];

            if (cut1 == n) r1 = INT_MAX;
            else r1 = nums1[cut1];

            if (cut2 == 0) l2 = INT_MIN;
            else l2 = nums2[cut2 - 1];

            if (cut2 == m) r2 = INT_MAX;
            else r2 = nums2[cut2];


            if (l1 <= r2 && l2 <= r1) {

                if ((n + m) % 2)  return max(l1, l2); // medi
                


                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2)   r = cut1 - 1;
            
            else l = cut1 + 1;
            
        }

        return 0;
    }
};