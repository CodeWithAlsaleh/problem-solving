/*
  This is my sol, TC => O(log(N) + K), SC => O(K)
  N = number of elements in the array
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        deque<int> dq;
        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        int L = ind - 1, R = ind;

        while(k--) {
            if(L < 0) {
                dq.push_back(arr[R++]);
                continue;
            }
            if(R >= n) {
                dq.push_front(arr[L--]);
                continue;
            }

            x - arr[L] <= arr[R] - x ? dq.push_front(arr[L--]) : dq.push_back(arr[R++]);
        }

        return vector<int>(dq.begin(), dq.end());
    }
};

/*
  This is a better sol (i didn't solve it like this):

  This is my sol, TC => O(log(N - K) + K), SC => O(K)
  N = number of elements in the array
*/
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findClosestElements(const std::vector<int>& arr, int k, int x) {
        int n = (int)arr.size();
        if (k == n) return arr;                 // trivial case
        int low = 0, high = n - k;              // possible left indices for window

        // find smallest `low` such that window [low, low+k) is best
        while (low < high) {
            int mid = low + (high - low) / 2;
            // compare distance of arr[mid] and arr[mid + k] to x
            // if arr[mid] is farther from x than arr[mid+k], move right
            if (x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else
                high = mid;
        }

        return std::vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
