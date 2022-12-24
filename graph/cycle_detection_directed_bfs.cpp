// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> kahn(vector<vector<int> > &g, vector<int> &ind)
    {
        queue<int> q;
        for(int i = 0; i < ind.size(); i++)
        {
            if(ind[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> order;
        while(q.size())
        {
            int f = q.front();
            q.pop();
            order.push_back(f);
            
            for(int i = 0; i < g[f].size(); i++)
            {
                ind[g[f][i]]--;
                if(ind[g[f][i]] == 0)
                    q.push(g[f][i]);
            }
        }
        
        return order;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int> > g (numCourses, vector<int> ());
        
        vector<int> ind (numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        
        vector<int> ans = kahn(g, ind);
        if(ans.size() == numCourses)
            return ans;
        return {};
        
    }
};
