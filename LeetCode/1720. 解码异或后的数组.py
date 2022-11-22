"""
        encoded[i] = arr[i] ^ arr[i + 1]
encode[i] ^ arr[i] = arr[i + 1](0 < i < length - 1)
"""


class Solution:
    @staticmethod
    def decode(encoded: list[int], first: int) -> list[int]:
        arr = [first]
        for i in encoded:
            arr.append(arr[-1] ^ i)
        return arr
