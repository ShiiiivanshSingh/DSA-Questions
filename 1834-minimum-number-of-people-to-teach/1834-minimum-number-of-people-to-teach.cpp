class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> users;
        for(auto &people: friendships){
            int i= people[0]-1;
            int j= people[1] -1;
            unordered_set<int> total_lang(begin(languages[i]),end(languages[i]));
            bool talk =false;
            for(int q = 0;q<languages[j].size();q++){
                if(total_lang.count(languages[j][q])){
                    talk = true;
                    break;
                }
            }
            if(!talk){
                users.insert(i);
                users.insert(j);
                }
            }
            vector<int> major(n+1,0);
          int popular_lang = 0;
            for(int u : users){
                for(int lang : languages[u]){
                major[lang]++;
                popular_lang = max(popular_lang, major[lang]);
            }
        }
            // int popular_lang = 0;
            // for(int p=0;p<users;p++){
            //     for(z=0;z<languages[users];z++){
            //         languages[z]++;
            //         popular_lang = max(popular_lang,languages[z]);
            //     }
            // }
            return users.size() - popular_lang;
        }

};