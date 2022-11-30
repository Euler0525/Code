/**
 * @param {string[]} strs
 * @return {string[][]}
 */
 var groupAnagrams = function(strs) {
    /*
    {
        "aet": ["eat", "tea", "ate"],
        "ant": ["tan", "nat"],
        "abt": ["bat"]
    }
    */
    let groups = {};
    for (let s of strs) {
        let copy = s.split('').sort().join('');
        if (!(copy in groups)) {
            groups[copy] = [];
        }
        groups[copy].push(s);
    }
    let ans = [];
    for (let group of Object.values(groups)) {
        ans.push(group);
    }
    return ans;
};