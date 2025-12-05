class Solution {
public:
    string decodedString(string &s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                string temp = "";
                
                // extract substring
                while(!st.empty() && st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // pop '['

                // extract full number (can be multi-digit)
                string numStr = "";
                while(!st.empty() && isdigit(st.top())){
                    numStr = st.top() + numStr;
                    st.pop();
                }
                
                int n = stoi(numStr);

                // repeat temp and push back
                string repeatStr = "";
                while(n--){
                    repeatStr += temp;
                }
                
                for(char c : repeatStr) st.push(c);
            }
            else{
                st.push(s[i]);
            }
        }

        // build final result from stack
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
