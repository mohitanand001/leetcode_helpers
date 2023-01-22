//https://leetcode.com/contest/weekly-contest-329/problems/sort-the-students-by-their-kth-score/
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](vector<int>& a, vector<int> &b)
             {
                 return a[k] > b[k];
             });
            
        return score;
    }
};
