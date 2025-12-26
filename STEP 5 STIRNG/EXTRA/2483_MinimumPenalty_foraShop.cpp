class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>pref(n+1,0), suf(n+1,0);
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + (customers[i] == 'N');
            cout<< pref[i];

        }
        for(int i = n-1; i >=0 ; i--){
            suf[i] = suf[i+1] + (customers[i] == 'Y');
        }
        int idx = 0;
        int mn = INT_MAX;
    
        for(int i = 0; i <= n; i++){
          int ss = pref[i] + suf[i];
          if(ss < mn){
            mn = ss;
            idx = i;
          }
            
        }
        return idx;
    }
};