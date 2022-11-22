# Default argument value is mutable
class Player(object):
    def __init__(self, name: str, assets=None):
        if assets is None:
            assets = []
        self.name = name
        self.assets = assets


# class Player(object):
#     def __init__(self, name: str, assets=[]):
#         self.name = name
#         self.assets = assets
