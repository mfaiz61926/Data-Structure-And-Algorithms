class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;
        for(auto &ch : s){
            if(isalpha(ch)) n++; // append;
            else if(ch == '#') n *= 2; //duplicate
            else if(ch == '*' && n) n--; // remove
        }

        if(k >= n) return '.';

        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];
            if(isalpha(c)){
                n--; 
                if(n == k) return c; // got the char
            }
            else if(c == '#'){ //undo dup : dedup
                n /= 2;
                if(k >= n) k -= n;  // cut the first half
            }
            else if(c == '%') k = n - k - 1; //undo reverse: mirror k
            else if(c == '*' && n) n++; // undo remove
        }

        return '.';
    }
};