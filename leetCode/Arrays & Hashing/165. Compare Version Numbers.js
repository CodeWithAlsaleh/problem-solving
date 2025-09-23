/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const ver1 = version1.split('.');
    const ver2 = version2.split('.');

    const size = Math.max(ver1.length,ver2.length);

    for(let i = 0 ; i < size ; ++i) {
        let num1 = 0 , num2 = 0;

        if(i < ver1.length)
         num1 = +ver1[i];

        if(i < ver2.length)
         num2 = +ver2[i];

        if(num1 > num2)
         return 1;
        
        if(num1 < num2)
         return -1;
    }

    return 0;
};
