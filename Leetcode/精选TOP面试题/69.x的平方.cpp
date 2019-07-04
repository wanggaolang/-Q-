class Solution {
public:
    int mySqrt(int x) {
       long long l=0,r=46340;
        while(l<=r)
        {
            auto mid=l+(r-l)/2;
            if(mid*mid<=x&&(mid+1)*(mid+1)>x)
                return mid;
            else if(mid*mid<x)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
