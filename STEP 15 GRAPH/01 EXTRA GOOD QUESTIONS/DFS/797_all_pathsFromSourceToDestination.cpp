class Solution {
public:
    int target;
    vector<vector<int>>res;
    vector<int>temp;

    void dfs(vector<vector<int>>&graph, int node){
        temp.push_back(node); //take it 
        // do something
        if(node == target) res.push_back(temp);
        else{
            for(auto it : graph[node]){
                dfs(graph, it);
            }
        }
        //exclude it 
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph, 0);
        return res;
    }
};