/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const ans = [];

    arr.forEach((a, i) => {
        ans.push(fn(a, i));
    });

    return ans;
};