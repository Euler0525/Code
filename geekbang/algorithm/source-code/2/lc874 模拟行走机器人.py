class Solution:
    def calcHash(self, obstacle):
        return (obstacle[0] + 30000) * 60001 + (obstacle[1] + 30000)

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = {}
        for obstacle in obstacles:
            obs[self.calcHash(obstacle)] = True

        x, y = 0, 0
        dir = 0 # N=0, E=1, S=2, W=3
        # 网格中行走题目，技巧：方向数组
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        ans = 0
        for command in commands:
            if command == -1:
                dir = (dir + 1) % 4
            elif command == -2:
                dir = (dir + 3) % 4
            else:
                for i in range(0, command):
                    nx = x + dx[dir]
                    ny = y + dy[dir]
                    # 如果obs.contains(...)，是障碍物
                    if self.calcHash([nx, ny]) in obs:
                        break
                    x, y = nx, ny
                    ans = max(ans, x * x + y * y)
        return ans