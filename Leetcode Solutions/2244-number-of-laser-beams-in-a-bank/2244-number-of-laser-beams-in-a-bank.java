class Solution {
    public int numberOfBeams(String[] bank) {
        int curr = 0;
        int last = 0;
        int ok = 0;

        for(String i:bank){
            for(char j:i.toCharArray()){
                if(j=='1'){
                    curr++;
                    ok += last;
                }
            }
            if(curr==0) continue;
            last = curr;
            curr = 0;
        }
        return ok;
    }
}