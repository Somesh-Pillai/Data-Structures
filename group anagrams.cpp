class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty() and strs.size()==1)
            return {strs};
        unordered_map<string, vector<string>> mymap;   // no need for ordering so runtime less for unordered
        int n = strs.size();
        string temp;
        for(int i = 0; i<n; i++)
        {
            temp=strs[i];
            sort(strs[i].begin(), strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        vector<vector<string>> result;
        for(auto itr=mymap.begin(); itr!=mymap.end();itr++)
            result.push_back(itr->second);
        return result;
        }
    
};


//if sorted strings of two strings are equal then they are anagrams(nklogk)
//map has key as sorted strings, values as list of anagrams