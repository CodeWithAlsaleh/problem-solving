/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function(n) {
    const mp = new Map();

    for(let i = 0 ; i <= 15 ; ++i)
     mp.set(Math.pow(4 , i) , 1);

    return mp.has(n);
};
