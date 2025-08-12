 //brute force                               
// #include <iostream>
// #include <set>
// #include <string>
// using namespace std;

// // Function to count all distinct
// // substrings of a given string
// set<string> countDistinctSubstrings(const string& s) {
//     // Set to store distinct substrings
//     set<string> st;

//     // Length of the input string
//     int n = s.length();

//     // Iterate over each character in the string
//     for (int i = 0; i < n; i++) {
//         // Initialize an empty string to store the current substring
//         string str = "";

//         // Iterate over the remaining characters 
//         // in the string starting from index i
//         for (int j = i; j < n; j++) {
//             // Append the current
//             // character to the substring
//             str += s[j];

//             // Insert the current
//             // substring into the set
//             st.insert(str);
//         }
//     }

//     // Return the set containing
//     // all distinct substrings
//     return st;
// }

// int main() {
//     string s = "striver";
//     cout << "Given String: " << s << endl;

//     // Call the function to
//     // count distinct substrings
//     set<string> substrings = countDistinctSubstrings(s);
//     int count = 0;
//     // Print the distinct substrings
//     cout << "Distinct Substrings:" << endl;
//     for (const auto& substr : substrings) {
//         cout << substr << endl;
//         count ++;
//     }
//     // Count + 1 as we have to count
//     // the empty string as well
//     cout << "Number of distinct substrings: "<< count + 1<< endl;

//     return 0;
// }
                                
 


// Trie approach   of a2z but giving memory limit exceeded in gfg                              
#include <iostream>  
#include <string>    
using namespace std;  

struct Node {
    Node* links[26];  
    bool flag = false;  
    bool containsKey(char ch) {  
        
        return (links[ch - 'a'] != NULL);
    } 
    Node* get(char ch) {  
        
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {  
        
        links[ch - 'a'] = node;
    }

    void setEnd() {  
        flag = true;
    }

   
    bool isEnd() {  
        return flag;
    }
};


int countDistinctSubstrings(string &s) {  
    Node* root = new Node();  
    int cnt = 0; 
    int n = s.size();  
    
    for (int i = 0; i < n; i++) {  
        Node* node = root;  
        for (int j = i; j < n; j++) {  
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());  
                cnt++;  
            }
            node = node->get(s[j]);  
        }
    }
     
    return cnt + 1;  
  
}

                              



//OPTIMAL ACCEPTED SOLUTION.
//a2z sheet solution is giving memory limit exceeded due to array  links... To overcome that i have used unordered_map links  for the same.

#include <bits/stdc++.h>
using namespace std;
struct Node {
    unordered_map<char, Node*> links;  // dynamic storage for child nodes

    bool containsKey(char ch) {
        return links.find(ch) != links.end();
    }

    Node* get(char ch) {
        return links[ch];
    }

    void put(char ch, Node* node) {
        links[ch] = node;
    }
};

int countDistinctSubstring(string s) {
    // Your code here
    int n=s.size();
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<n;i++){
        Node* node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return  cnt+1;
}