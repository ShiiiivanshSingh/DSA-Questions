class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int arr[] = {a, b, c}; 
        sort(arr, arr + 3);
        a = arr[0]; b = arr[1]; c = arr[2];

        int gap1 = b - a, gap2 = c-b;
        int qwerty =c-a - 2, wasd;

        if(gap1 == 1 && gap2 == 1) wasd =0;
        else if (gap1 <= 2 || gap2 <= 2) wasd = 1;
        else wasd = 2;
        
        return {wasd, qwerty};
    }
};