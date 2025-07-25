/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSum = function(nums) {
    const mp = new Map();
    let sum = 0;

    let mx = -101;
    nums.forEach(num => {
        mx = Math.max(mx , num);
    });

    nums.forEach(num => {
        if(num > 0 && !mp.has(num))
         sum += num;
        
        mp.set(num , 1);
    });

    if(sum === 0 && !mp.has(0))
     return mx;

    return Math.max(mx , sum);
};
