#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto ret=sortedArrayToBST(nums,0,nums.size()-1);
        return ret;
    }
private:
    TreeNode * sortedArrayToBST(vector<int> & nums,int l,int r)
    {
        if(l>r)
            return nullptr;
        int mid=l+(r-l)/2;
        auto root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums,l,mid-1);
        root->right=sortedArrayToBST(nums,mid+1,r);
        return root;
    }
};
void t(TreeNode *b)
{
    if (b!=NULL)
    {
        cout<<b->val<<endl;
        t(b->left);
        t(b->right);
    }
}
int main()
{
    vector<int> a={-10,-3,0,5,9};
    Solution s;
    auto b=s.sortedArrayToBST(a);
    t(b);

}
