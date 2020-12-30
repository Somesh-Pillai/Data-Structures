//backtracking algo
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        backtrack(v, "", n);
        return v;
    }
    void backtrack(vector<string> &v, string s,int n, int open=0, int close=0){  //open ->opening bracket
     if (open == n && close == n) //checking for equal number of opening and closing brackets
            v.push_back(s);
         else
        {
            if (open < n)
                backtrack(v, s + '(', n, open + 1, close);
            if (close < open)
                backtrack(v, s + ')', n, open, close + 1);
   }
    }
};
