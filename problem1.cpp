// Time Complexity : O(H*W)Cn * (H*W)
// Space Complexity : O(H*W)
// Did this code successfully run on Leetcode : yes ( leetcode playground for smaple test cases)
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach

// Backtracking:

// we need to place n buildings at all possible options and check for which placement, are we getting a min answer.

//  we use bactracking for placing n buildings, and use BFS for find the distance of farthest cell.

//  imp :
//  whenever we need to use BFS, think of independent and dependent values and proceed for clarity


class BuildingPosition
{
    public:
    int W = 0,H = 0,N = 0;
    int ans = INT_MAX;
    vector<vector<int>>grid;
    BuildingPosition(int w,int h,int n)
    {
        this->W = w;
        this->H = h;
        this->N = n;
        grid.resize(W,vector<int>(H,0));
    }  
    void bfs()
    {
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}}; // L R U D
        queue<pair<int,int>>q;
        bool vis[W][H];
        memset(vis,false,sizeof(vis));
        for(int i = 0;i<W;i++)
        {
            for(int j = 0;j<H;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }

        int lvl = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r,c] = q.front(); q.pop();
                for(auto & dir: dirs)
                {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if(nr>=0 && nr<W && nc>=0 && nc<H && vis[nr][nc] == false)
                    {
                        q.push({nr,nc});
                        vis[nr][nc] = true;
                    }
                }
            }
            lvl++;
        }
        ans = min(ans,lvl-1);
    }
    void dfs(int r,int c,int n)
    {

        if(n == 0)
        {
            bfs();
        }
        if(c == H)
        {
            c = 0;
            r++;
        }

        for(int i = r;i<W;i++)
        {
            for(int j = c;j<H;j++)
            {
                grid[i][j] = 1;
                dfs(i,j+1,n-1);

                grid[i][j] = 0;
            }
        }
    }
    int getans()
    {
        dfs(0,0,N);
        return ans;
    }
};

int main() {
    BuildingPosition *BP = new BuildingPosition(4,4,3);
    
    cout << (BP->getans());
    return 0;
    
}

/*
Problem1: Optimal Placement of Buildings in a grid
Given a grid with w as width, h as height. Each cell of the grid represents a potential building lot and we will be adding "n" buildings inside this grid. The goal is for the furthest of all lots to be as near as possible to a building. Given an input n, which is the number of buildings to be placed in the lot, determine the building placement to minimize the distance the most distant empty lot is from the building. Movement is restricted to horizontal and vertical i.e. diagonal movement is not required.

For example, w=4, h=4 and n=3. An optimal grid placement sets any lot within two unit distance of the building. The answer for this case is 2.

"0" indicates optimal building placement and in this case the maximal value of all shortest distances to the closest building for each cell is "2".

1 0 1 2

2 1 2 1

1 0 1 0
*/
