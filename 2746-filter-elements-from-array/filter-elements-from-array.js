/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans =[];

    arr.forEach((a,idx)=>{
       let cur_ele = fn(a,idx);
       if(cur_ele) ans.push(a);
    });

    return ans;
};