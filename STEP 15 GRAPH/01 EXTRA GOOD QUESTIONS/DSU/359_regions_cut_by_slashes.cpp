
class DisjointSet {
public:
vector<int> rank, parent, size;
   DisjointSet(int n)
{
       rank.resize(n+1, 0);
       parent.resize(n+1);
       size.resize(n+1);
       for(int i = 0;i<=n;i++) {
           parent[i] = i;
           size[i] = 1;
       }
   }
 
   int findUPar(int node)
  {
       if(node == parent[node])
           return node;
       return parent[node] = findUPar(parent[node]);
   }
 
   void unionBySize(int u, int v)
 {
       int ulp_u = findUPar(u);
       int ulp_v = findUPar(v);
       if(ulp_u == ulp_v) return;
       if(size[ulp_u] < size[ulp_v]) {
           parent[ulp_u] = ulp_v;
           size[ulp_v] += size[ulp_u];
       }
       else {
           parent[ulp_v] = ulp_u;
           size[ulp_u] += size[ulp_v];
       }
   }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) 
    {
        
        int rows=grid.size();
        int cols=grid[0].size();

        int tdots=(rows+1)*(cols+1);
        DisjointSet ds(tdots);

        //Connecting the border dots
        for(int r=0;r<=rows;r++)
        {
            for(int c=0;c<=cols;c++)
            {
                if(r==0 || r==rows || c==0 || c==cols)
                {
                    int dot=(r*(cols+1))+c;
                    // print(dot);
                    ds.unionBySize(0,dot);
                }
            }
        }
        int comp=1;
        //Travering the grid and connecting
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]=='/')
                {
                    int dot1=((r+1)*(cols+1))+c;
                    int dot2=((r)*(cols+1))+c+1;
                    if(ds.findUPar(dot1)==ds.findUPar(dot2))
                    {
                        // cout<<dot1<<" / "<<dot2<<endl;
                        comp+=1;
                    }
                        
                    ds.unionBySize(dot1,dot2);
                }
                else if(grid[r][c]=='\\')
                {
                    int dot1=((r)*(cols+1))+c;
                    int dot2=((r+1)*(cols+1))+c+1;
                    if(ds.findUPar(dot1)==ds.findUPar(dot2))
                    {
                        // cout<<dot1<<" \\ "<<dot2<<endl;
                        comp+=1;
                    }
                    ds.unionBySize(dot1,dot2);
                }
            }
        }

        return comp;
    }
};