
class Solution {
public:
    vector<long long> sum;
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            if(i==0){
                sum.push_back(w[i]);
            }
            else{
                sum.push_back(sum[i-1]+w[i]);
            }
        }        
    }
    int pickIndex() {
        long num=rand()%sum[sum.size()-1];
        auto it=upper_bound(sum.begin(),sum.end(),num);
        return it-sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
