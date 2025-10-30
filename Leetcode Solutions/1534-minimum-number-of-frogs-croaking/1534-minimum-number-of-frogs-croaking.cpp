class Solution {
public:
// i will add bunch of comments to this code so u think i use ai but mai real hu yeh shit ai nhi kar sakta 'n shoutout ghAatak for his new album aai booo
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> phase(5,0); 
// phase here refers to c->r->o->a->k id:0,1,2,3,4 which also refers to the fact that i hate mayur vihar phase 3 absolute sh#thole dotn go there m8
        int frog = 0, maxFrog = 0;
        unordered_map<char,int> pos={{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}};  //c->r->o->a->k
        for(char c : croakOfFrogs){
            int i = pos[c];
            if(i==0){    
                phase[0]++; // one start croaking
                frog++; // welcome gang
                maxFrog = max(frog, maxFrog);
            } else {
                if(phase[i-1] == 0) return -1; // is there any fogr >-< waiting before
                phase[i-1]--; //take 1 from prev phase
                phase[i]++; //put him in next phase
                if(i ==4) { 
                    phase[4]--;//  (-> k) final phase over
                    frog--; // free fogrs (p≧w≦q)
                }
            }
        }
            for(int i=0;i<4;i++){
                if(phase[i] !=0) return -1; 
// checking that if sm1 is croaking yet seee how loop is <4 i.e. last k will not be checked
            }
            return maxFrog;
    }
};