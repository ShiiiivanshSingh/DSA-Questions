class Trie {

    struct node{
        node* child[26];
        bool end;
        node(){
            for(int i=0;i<26;i++)
                child[i]=NULL;
            end=false;
        }
    };

public:
    node* root;
    Trie() {
        root = new node();
    }

    void insert(string word) {

        node* current = root;

        for(char c:word){

            int i = c-'a';
            if(current->child[i] == NULL) current->child[i] = new node();

            current = current->child[i];
        }

        current->end = true;
    }

    bool search(string word) {

        node* cur = root;

        for(char c:word){

            int i = c-'a';

            if(cur->child[i] == NULL)
                return false;

            cur = cur->child[i];
        }

        return cur->end;
    }

    bool startsWith(string prefix) {

        node* cur = root;

        for(char c:prefix){

            int i = c-'a';

            if(cur->child[i] == NULL)
                return 0;

            cur = cur->child[i];
        }

        return 1;
    }
};