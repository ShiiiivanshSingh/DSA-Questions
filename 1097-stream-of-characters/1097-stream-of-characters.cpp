// class StreamChecker {
// public:
//     struct Node {
//         Node* child[26] = {};
//         bool end = 0;
//     };

//     StreamChecker(vector<string>& words) {
//         Node* root = new Node();
//         string stream;
//         int maxLen = 0;
//         for (int i = word.size() - 1; i >= 0; i--) {
//             int c = word[i] - 'a';
//             if (!cur->child[c])
//                 cur->child[c] = new Node();

//             cur = cur->child[c];
//         }
//         cur->end = true;
//     }
    
//     bool query(char letter) {
//         if (stream.size() > maxLen)  stream.erase(0, 1);
//         stream += letter;
//         int i = stream.size() - 1;
//             int len = 0;
//             while (i >= 0 && len < maxLen) {
//                 node = node->child[stream[i] - 'a'];
//                 i--;
//                 len++;
//             }

//         if (!node->child[stream[i] - 'a']) return 0;
//         node = node->child[stream[i] - 'a'];
//         if (node->end) return 1;
//         return 0;
        
//     }
// };
class StreamChecker {
public:
    struct Node {
        Node* child[26] = {};
        bool end = false;
    };

    Node* root;
    string stream;
    int maxLen = 0;

    StreamChecker(vector<string>& words) {
        root = new Node();

        for (string word : words) {
            maxLen = max(maxLen, (int)word.size());
            Node* cur = root;

            for (int i = word.size() - 1; i >= 0; i--) {
                int c = word[i] - 'a';

                if (!cur->child[c])   cur->child[c] = new Node();
                cur = cur->child[c];
            }
            cur->end = 1;
        }
    }

    bool query(char letter) {
        stream += letter;
        if (stream.size() > maxLen)  stream.erase(0, 1);
        Node* node = root;

        for (int i = stream.size() - 1; i >= 0; i--) {
            int c = stream[i] - 'a';

            if (!node->child[c])  return 0;
            node = node->child[c];
            if (node->end) return 1;
        }
        return 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */