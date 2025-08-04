/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function(fruits) {
    let ans = 0 , checkInd = 0;

    const mp = new Map();

    fruits.forEach((item , ind) => {
        if(!mp.has(item))
         mp.set(item , 1);
        else
         mp.set(item , mp.get(item) + 1);

        
        while(mp.size == 3) {
            const fruit = fruits[checkInd];
            mp.set(fruit , mp.get(fruit) - 1);

            if(!mp.get(fruit))
             mp.delete(fruit);

            checkInd++;
        }

        ans = Math.max(ans , ind - checkInd + 1);
    });

    return ans;
};
