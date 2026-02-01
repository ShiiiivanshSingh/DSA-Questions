class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;

        int n= letters.size();
        if(letters[n-1] <=target) return letters[0];
        int l =0, h = n-1;
        while(l<h){
            int mid = l+ (h-l)/2;
            if(letters[mid] - target <=0) l = mid + 1;
            else h = mid;
        }
        return letters[l];
    }
};