class Solution {
public:
    int n;
    // bool ans = false;
    unordered_map<string, vector<char>>mp;
    bool dfs(string s, int i, string temp){
        if(s.size()==1) return true;
        if(i == s.size() - 1){
            string nextRow;
            return dfs(temp, 0, nextRow);
        }

        string key = s.substr(i,2);

        for(char c : mp[key]){
            temp.push_back(c);
            if(dfs(s, i+1, temp)) return true;
            temp.pop_back();
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
         n = allowed.size();
         for(auto &i : allowed){
            mp[i.substr(0,2)].push_back(i[2]);
         }

         string temp;
         return dfs(bottom, 0 , temp);
        //  return ans;
    }
};