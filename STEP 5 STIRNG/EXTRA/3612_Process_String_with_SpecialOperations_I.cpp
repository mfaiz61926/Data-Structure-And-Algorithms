class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto &ch : s){
            if(ch == '*'){
                if(res.size() > 0) res.pop_back();
            }
            else if(ch == '#'){
                res += res;
            }
            else if(ch == '%'){
                reverse(res.begin(), res.end());
            }
            else{
                res += ch;
            }
        }
        return res;
    }
};