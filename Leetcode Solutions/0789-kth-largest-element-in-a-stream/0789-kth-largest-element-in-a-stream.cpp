class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> meow;
    int myau;

    KthLargest(int k, vector<int>& nums) {
        myau = k;
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(meow.size() < myau ) meow.push(val);
        else if ( val > meow.top() )  {
            meow.pop();
            meow.push(val);
        }
        return meow.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */