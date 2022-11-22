class Solution:
    @staticmethod
    def defangIPaddr(address: str) -> str:
        new_address = address.split(".")
        ret = "[.]".join(new_address)

        return ret
