class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>count(nums.size()),ans;
        if(nums.size()==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<count.size();i++){
            count[i]=1;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    count[i]=max(count[i],count[j]+1);
                }
            }
        }
        int maxIndex=0;
        for(int i=1;i<count.size();i++){
            if(count[i]>count[maxIndex]){
                maxIndex=i;
            }
        }
        int maxEle=count[maxIndex];
        int temp=nums[maxIndex];

        for(int i=maxIndex;i>=0;i--){
            if(temp%nums[i]==0 && count[i]==maxEle){
                ans.push_back(nums[i]);
                temp=nums[i];
                maxEle--;
            }  
        }
        return ans;
    }
};
