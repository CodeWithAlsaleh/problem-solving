/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length() - 1;
        int index = -1;

        // Finding the largest value
        int st = 1 , en = len - 1;
        while(st <= en)
        {
            int mid = st + (en - st) / 2;
            int val = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);

            if(val > next and val > prev)
            {
                index = mid;
                break;
            }

            if(val < next)
             st = mid + 1;
            else if(val < prev)
             en = mid - 1;
        }

        if(target == mountainArr.get(index))
         return index;

        // Sol
        int ans1 = 1e9 , ans2 = 1e9;
        int st1 = 0 , en1 = index - 1;
        int st2 = index + 1 , en2 = len;

        while(st1 <= en1)
        {
            int mid1 = st1 + (en1 - st1) / 2;
            int val = mountainArr.get(mid1);

            if(val >= target)
            {
                if(val == target)
                    ans1 = mid1;
                
                en1 = mid1 - 1;
            }
            else
             st1 = mid1 + 1;
        }

        while(st2 <= en2)
        {
            int mid2 = st2 + (en2 - st2) / 2;
            int val = mountainArr.get(mid2);

            if(val <= target)
            {
                if(val == target)
                    ans2 = mid2;
                
                en2 = mid2 - 1;
            }
            else
             st2 = mid2 + 1;
        }

        int mn = min(ans1 , ans2);
        return mn == 1e9 ? -1 : mn;
    }
};
