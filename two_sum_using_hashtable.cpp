class Solution {
 public:
     vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> id;
        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if(id[compliment]) {  //checking if compliment is present in hash tables
                return {id[compliment]-1, i};
            }
            id[nums[i]] = i+1;  //if not add element to hash table with index +1 to check
                                //above condition (only true if exp value is >=1 )
        }
        return {-1, -1};  //not found
    }
};
