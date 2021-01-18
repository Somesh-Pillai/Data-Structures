class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());
    // remove duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
   //1223221 --> 12321
        vector <vector <int>> res;
        vector <int> ele;
        backtrack(candidates, 0, target, ele, res);
        return res;
    }
   void backtrack(vector<int>& candidates, int i, int target, vector<int>& ele, vector<vector <int>>& res)
   {
       if(target<0)  //breaking condition
           return;
       if(target==0)   //base condition
       {res.push_back(ele);
        return;}
       while (i < candidates.size() && target - candidates[i] >= 0)
       {
           ele.push_back(candidates[i]);
           backtrack(candidates, i, target-candidates[i], ele, res);
           i++;
           ele.pop_back();  //removes the last added element which made target<0
       }
   }

};
