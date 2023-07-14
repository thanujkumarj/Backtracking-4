// Time Complexity :  O(n*2^k) approximatley which is exponential
// lets suppose the average length is k for the letters in bracket, we have 2^k options for each bracket, and we have total of string length =n 
// so, it would be nearly n* 2^k which is exponential. sorting will take klogk.
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach

// Approach:
// we use backtracking approach. main problem lies in implementation.
// we store the characters in a map, maintaing the index order.
// while backtracking, we used the map.





class Solution {
public:
    vector<string>res;
    unordered_map<int,vector<char>>map;
    int n = 0;
    vector<string> expand(string s) {
        
        
        n = s.size();
        int i = 0;
        int idx = 0;
        
        while(i<n)
        {
            if(s[i]=='{')
            {
                i++;
                vector<char>v;
                while(s[i]!='}')
                {
                    if(s[i]!=',')
                    {
                        v.push_back(s[i]);
                    }
                    i++;
                }
                sort(v.begin(),v.end());
                map[idx++]=v;
            }
            else
            {
                map[idx++]={s[i]};
            }
            i++;
        }
        string curr;
        dfs(0,curr);
        
        return res;
    }
    void dfs(int idx,string &curr)
    {
        if(idx == map.size()){
            res.push_back(curr);
            return;
        }
        
        auto &v = map[idx];
        for(int i = 0;i<v.size();i++)
        {
            curr.push_back(v[i]);
            
            dfs(idx+1,curr);
            
            curr.pop_back();
        }
        
    }
};