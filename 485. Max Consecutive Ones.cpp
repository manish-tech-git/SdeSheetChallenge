class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0, counter =0;
        for (int i = 0; i < nums.size() ; i++)
        {
            if (nums[i] == 1) {
                count = max (count , ++counter);
            }
            else{
                counter = 0;
            }
        }
        
        return count;
    }
};

// Time Complexity - O(N);
// Space Complexity - O(1)
