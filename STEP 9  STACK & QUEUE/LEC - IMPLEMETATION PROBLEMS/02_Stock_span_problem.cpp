#include <bits/stdc++.h>
using namespace std;
// link -> https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    vector<pair<int,int>>arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curP = price;
        int curS = 1;
       
        while(!arr.empty() && arr.back().first <= price){
            auto [prevP, prevS] = arr.back();
            curS += prevS;
            arr.pop_back();
        }

        arr.push_back({curP, curS});
        return curS;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */