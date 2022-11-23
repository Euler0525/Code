/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    a = []
    for (let ch of s) {
        if (ch == '(' || ch == '[' || ch == '{') a.push(ch);
        else {
            if (a.length == 0) return false;
            if (ch == ')' && a[a.length - 1] != '(') return false;
            if (ch == ']' && a[a.length - 1] != '[') return false;
            if (ch == '}' && a[a.length - 1] != '{') return false;
            a.pop();
        }
    }
    return a.length == 0;
};