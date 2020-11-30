class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() == 1) return "";   //empty string condition
        else {
            int min = strs[0].length();   //setting min length as that of first string
            for (int i = 1; i < strs.size(); i++) {
                if (min > strs[i].length())
                    min = strs[i].length();  //finding the smallest string length
                for (int j = 0; j < min; j++) {  //checking till the min length value
                    if (strs[i][j] != strs[i - 1][j]) {
                        min = j;
                        break;
                    }
                }
            }
            return strs[0].substr(0, min);  //excluding min
        }
    }
};
//strs[1][1]--> first element's first character
//common prefix should be presnt in the smallest string
//so finds the length of smallest string and checks characters upto that value in each string
