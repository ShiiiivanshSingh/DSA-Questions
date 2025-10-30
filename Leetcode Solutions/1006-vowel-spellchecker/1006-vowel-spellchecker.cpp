class Solution {
public:

    unordered_set<string> dict; //exact set ╰(*°▽°*)╯
    unordered_map<string, string> lowercase ; 
    unordered_map<string, string> vowelmap;  


    string convert(string &s){
        string myau = s;
        for(char &c: myau){
            c = tolower(c);
        }
        return myau;
    }

    string replaceVowel(string &s){
        string result = s;
        for(char &c: result){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ){
                c = '$';
            }
        }
        return result;
    }

    string check(string &s){
        if(dict.count(s)) return s;
        string lower = convert(s);
        if(lowercase.count(lower)) return lowercase[lower];

        string vowelRep = replaceVowel(lower);
        if(vowelmap.count(vowelRep)) return vowelmap[vowelRep];
        return "";
    }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        dict.clear();
        lowercase.clear();
        vowelmap.clear();


    for(string i: wordlist){
        dict.insert(i);
        string low = convert(i);
        if(lowercase.find(low) == lowercase.end()){
            lowercase[low] = i;
        }
        string vowelcase = replaceVowel(low);
        if(vowelmap.find(vowelcase) == vowelmap.end()){
            vowelmap[vowelcase] = i;
        }
    }


    vector<string> solution;
    for(string &i: queries){
        solution.push_back(check(i));
        }

        
    return solution;
    }
};