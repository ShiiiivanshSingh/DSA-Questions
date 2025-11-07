class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0; 
        int even =0 , odd = 0 ;
        for(int i = 0 ; i< arr.size() ; i++){
            int current_even  = odd + arr[i]*((i+1)/2); 
            int current_odd  = even + arr[i]*((i)/2 + 1);
            ans  += current_odd;

            even   = current_even;
            odd   = current_odd;
        }
        return ans;
    }
};