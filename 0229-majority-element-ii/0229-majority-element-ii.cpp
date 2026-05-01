class Solution {
public:
    
vector<int> majorityElement(vector<int>& arr) {
    int n = arr.size();
    int count1 = 0, count2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    
    for (int i = 0; i < n; i++) {
        if (count1 == 0 && ele2 != arr[i]) {
            count1 = 1;
            ele1 = arr[i];
        } else if (count2 == 0 && ele1 != arr[i]) {
            count2 = 1;
            ele2 = arr[i];
        } else if (arr[i] == ele1) {
            count1++;
        } else if (arr[i] == ele2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele1) {
            count1++;
        } 
        else if (arr[i] == ele2) {
            count2++;
        }
    }

    vector<int> ls;
    int minCount = n/3 + 1;

    if (count1 >= minCount) {
        ls.push_back(ele1);
    }
    if (count2 >= minCount) {
        ls.push_back(ele2);
    }
    
    sort(ls.begin(), ls.end());
    return ls;
}
};