/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
    const arr = text.split(' ');
    const st = new Set(brokenLetters);

    let ans = 0;
    
    arr.forEach(word => {
        const check = new Set(word);

        if(!(st.intersection(check).size))
         ans++;
    });

    return ans;
};
