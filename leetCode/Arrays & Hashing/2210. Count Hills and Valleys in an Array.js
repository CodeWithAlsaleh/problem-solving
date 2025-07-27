/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
    let ans = 0;

    for(let i = 1 ; i < nums.length - 1 ; ++i) {

        // Using this to avoid re‑scanning which can lead to o(n²)
        if(nums[i] === nums[i-1])
         continue;

        let L = i - 1 , R = i + 1;

        while(L >= 0 && nums[L] === nums[i])
         L--;
        
        while(R < nums.length && nums[R] === nums[i])
         R++;

        if(L >= 0 && R < nums.length) {
            const check1 = nums[L] < nums[i] && nums[R] < nums[i];
            const check2 = nums[L] > nums[i] && nums[R] > nums[i];
        
            if(check1 || check2)
             ans++;
        }

    }

    return ans;
};
