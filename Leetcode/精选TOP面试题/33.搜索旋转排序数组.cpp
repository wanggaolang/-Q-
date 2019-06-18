#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }

private:
    int search(vector<int> &nums, int low, int high, int target) {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[high]) {               //如果mid到high这段是未被旋转（升序）
            if (nums[mid] < target && target <= nums[high])             //如果目标值在右半段并且大于mid为下标的值
                return search(nums, mid + 1, high, target);
            else
                return search(nums, low, mid - 1, target);
        } else {                //如果mid到high已经被旋转
            if (nums[low] <= target && target < nums[mid])              //如果目标值在左半段（升序）
                return search(nums, low, mid - 1, target);
            else
                return search(nums, mid + 1, high, target);
        }
    }
};

int main() {
    vector<int> a={6,7,8,9,10,1,2,3,4,5};
    Solution s;
    cout<<"2: "<<s.search(a,2)<<endl;
    return 0;
}
