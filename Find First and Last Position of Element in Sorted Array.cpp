class Solution {
int FirstOcc (vector<int>& nums, int target, int n)
{

  //  int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;
        int mid = (s + e) / 2;

        while (s <= e){
            
            if(nums[mid] == target){
                ans = mid;
                e = mid - 1;

            }

            else if (target > nums[mid]){
                s = mid + 1;
            }

            else if (target < nums[mid]){
                e = mid - 1;
            }

            mid = (s + e) / 2;

        }

        return ans;
}

int lastOcc (vector<int>& nums, int target, int n)
{

   // int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;
        int mid = (s + e) / 2;

        while (s <= e){
            
            if(nums[mid] == target){
                ans = mid;
                s = mid + 1;

            }

            else if (target > nums[mid]){
                s = mid + 1;
            }

            else if (target < nums[mid]){
                e = mid - 1;
            }

            mid = (s + e) / 2;

        }

        return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int n = nums.size();
        int a = FirstOcc(nums, target, n);
        int b = lastOcc(nums, target, n);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
                
    }
};
