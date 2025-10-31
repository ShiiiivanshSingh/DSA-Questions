class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream alpha(title);
        string word;
        string war;

        while(alpha>> word){
            for(auto &c : word) c = tolower(c);
            if(word.size()>2) word[0] = toupper(word[0]);
            war += word + ' ';

            cout << " " << word  << " -> " << war  << " " << "\n"; 
        }
        war.pop_back();
        return war;
    }
};

// class Solution {
// public:
//     string capitalizeTitle(string title) {
//         stringstream ss(title); string word; string res;
//         while(ss>>word){
//             for(auto &c:word)c=tolower(c);
//             if(word.size()>2)word[0]=toupper(word[0]);
//             res+=word+' ';
//         }
//         res.pop_back(); 
//         return res;
//     }
// };
