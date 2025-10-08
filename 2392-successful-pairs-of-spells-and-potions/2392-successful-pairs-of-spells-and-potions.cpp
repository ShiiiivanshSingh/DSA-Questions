class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());
        vector<int> v;
        for(long long s : spells){
            int i = 0;
            int j = potions.size()-1;

            if(potions[i]*s >= success) {
                v.push_back(potions.size());
                continue;
            }
            if(potions[j]*s<success){
                v.push_back(0);
                continue;
            } 
            int mid;
            while(j>i){
                mid = (i+j)/2;

                 if(potions[mid]*s >= success){
                    j= mid;
                }else{
                    i = mid+1;
                    if(potions[i]*s >= success){
                        v.push_back(potions.size()-i);
                        break;
                    }
                }
            }    
        }
        return v;
        
    }
};