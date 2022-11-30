/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {
    var calcHash = function(obstacle) {
        return (obstacle[0] + 30000) * 60001 + (obstacle[1] + 30000);
    };

    let obs = {};
    for (let obstacle of obstacles) {
        obs[calcHash(obstacle)] = true;
    }
    let x = 0, y = 0;
    let dir = 0; // N=0, E=1, S=2, W=3
    // 网格中行走题目，技巧：方向数组
    let dx = [0, 1, 0, -1];
    let dy = [1, 0, -1, 0];
    let ans = 0;
    for (let command of commands) {
        if (command == -1) {
            dir = (dir + 1) % 4;
        } else if (command == -2) {
            dir = (dir + 3) % 4;
        } else {
            for (let i = 0; i < command; i++) {
                let nx = x + dx[dir];
                let ny = y + dy[dir];
                // 如果obs.contains(...)，是障碍物
                if (calcHash([nx, ny]) in obs) break;
                x = nx; y = ny;
                ans = Math.max(ans, x * x + y * y);
            }
        }
    }
    return ans;
};