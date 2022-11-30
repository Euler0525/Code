class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        '''
        {
            "aet": ["eat", "tea", "ate"],
            "ant": ["tan", "nat"],
            "abt": ["bat"]
        }
        '''
        groups = {}
        for s in strs:
            copy = ''.join(sorted(s))
            if copy not in groups:
                groups[copy] = []
            groups[copy].append(s)
        ans = []
        for group in groups.values():
            ans.append(group)
        return ans