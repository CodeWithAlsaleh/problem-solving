/**
 * @param {number[]} fruits
 * @param {number[]} baskets
 * @return {number}
 */
var numOfUnplacedFruits = function(fruits, baskets) {
    const n = fruits.length;

    let ans = 0;
    const vis = Array.from({length: n} , () => 1);

    fruits.forEach(item => {
        let flag = false , L = 0;

        while(L < n) {
            if(vis[L] && baskets[L] >= item) {
             flag = true;
             vis[L] = 0;
             break;
            }

            L++;
        }

        if(!flag)
         ans++;
    });

    return ans;
};
