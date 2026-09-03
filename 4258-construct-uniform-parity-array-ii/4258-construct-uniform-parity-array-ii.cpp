// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int n = nums1.size();
//         int odd = 0, even = 0;
//         int m_Odd = 1e9;

//         for (int x : nums1) {
//             if (x % 2) {
//                 odd++;
//                 m_Odd = min(m_Odd, x); // m_Odd -> min odd
//             } else even++;  
//         }
//         if (odd == n || even == n) return 1;
//         if (odd >= 2) return 1;
//         if (odd >= 1) {
//             for (int x : nums1) {
//                 if (x % 2 == 0 && x <= m_Odd)
//                     return 0;
//             }
//             return 1;
//         }

//         return 0;
//     }
// };

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;
        int minOdd = 1e9;

        for (int x : nums1) {
            if (x % 2) {
                odd++;
                minOdd = min(minOdd, x);
            } else  even++;
            
        }


        if (odd == 0 || even == 0)
            return 1;
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd)
                return 0;
        }

        return 1;
    }
};