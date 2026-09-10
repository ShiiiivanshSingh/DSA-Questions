class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, write = 0, len = chars.size();
        while (i < len) {
            int start = i;
            while (i + 1 < len && chars[i + 1] == chars[i]) {
                i++;
            }
            int count = i - start + 1;
            chars[write++] = chars[start];
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            } i = i +1;
        }
        return write;
    }
};