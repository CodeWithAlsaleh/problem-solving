/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    const str = num + '';
    let flag = false;
    let ans = 0;
    for(let i = 0 ; i < str.length; ++i)
    {
        if(str[i] === '6' && !flag)
        {
            ans *= 10;
            ans += 9;
            flag = true;
        }
        else {
            ans *= 10;
            ans += +str[i];
        }
    }

    return ans;
};
