#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto b=tempfun(nums,0,nums.size()-1,target);
        return b;
    }

private:
    vector<int> tempfun(vector<int> &nums,int left,int right,int target)
    {
        if(left>right)
            return {-1,-1};
        auto base=(left+right+1)/2;
        if(nums[base]>target)
            return tempfun(nums,left,base-1,target);
        else if(nums[base]<target)
            return tempfun(nums,base+1,right,target);
        else
        {
            int l=base;
            int r=base;
            while (l+1>=0&&nums[l-1]==target)
                l--;
            while (r+1<=nums.size()-1&&nums[r+1]==target)
                r++;
            return {l,r};
        }

    }
};

int main() {
    vector<int> a={2,2};
    Solution s;
    auto b=s.searchRange(a,2);
    cout<<b[0]<<" "<<b[1]<<endl;
    cout<<"end"<<endl;
    return 0;

}