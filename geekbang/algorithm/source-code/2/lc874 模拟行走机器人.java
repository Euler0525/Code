class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        HashSet<Long> obs = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obs.add(calcHash(obstacle));
        }
        int x = 0, y = 0;
        int dir = 0; // N=0, E=1, S=2, W=3
        // 网格中行走题目，技巧：方向数组
        int[] dx = new int[]{0, 1, 0, -1};
        int[] dy = new int[]{1, 0, -1, 0};
        int ans = 0;
        for (int command : commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    // 如果obs.contains(...)，是障碍物
                    if (obs.contains(calcHash(new int[]{nx, ny}))) break;
                    x = nx; y = ny;
                    ans = Math.max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }

    /*string calcHash(const vector<int>& obstacle) {
        return to_string(obstacle[0]) + "," + to_string(obstacle[1]);
    }*/
    long calcHash(int[] obstacle) {
        return (obstacle[0] + 30000) * 60001l + (obstacle[1] + 30000);
    }
}