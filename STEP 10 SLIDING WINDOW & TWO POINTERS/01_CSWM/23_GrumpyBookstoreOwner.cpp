class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;
        for(int i = 0; i < minutes; i++){
            unsat += customers[i] * grumpy[i];
        }

        int mxUnsat = unsat;
        int i = 0;
        int j = minutes;

        while(j < n){
            unsat += customers[j] * grumpy[j];
            unsat -= customers[i] * grumpy[i];

            mxUnsat = max(mxUnsat, unsat);
            i++;
            j++;
        }

        int mx_sat = mxUnsat;

        for(int i = 0; i < n; i++){
            mx_sat += customers[i] * (1 - grumpy[i]);
        }

        return mx_sat;


    }
};