class Solution {
public:
    bool allowed(vector<int>& position, int m, int distance){
        //check if yeh allowed hai?
        int count  = 1;
        int last = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - last >= distance){
                count++;
                last = position[i];
            }
            if(count >= m) return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); 
        // b r a t  b i n a r y s e a r c h
        int low = 1, high = position.back() - position.front();
        int rnm = 0;
        while(low<=high) {
        int mid = low + (high - low)/2;
            if(allowed(position, m , mid)){
                rnm = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return rnm;
    }
};