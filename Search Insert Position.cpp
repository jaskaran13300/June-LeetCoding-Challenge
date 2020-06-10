// Binary Search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target<nums[mid]){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};

// Using inbuild😁😁
// auto itr=lower_bound(nums.begin(),nums.end(),target);
// return itr-nums.begin();
