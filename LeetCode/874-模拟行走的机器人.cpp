class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int ans = 0;
        unordered_set<long long> obs;
        // 建立障碍物哈希值的无序集合
        for (vector<int> obstacle: obstacles)
        {
            obs.insert(calcHash(obstacle));
        }

        int x = 0, y = 0; // 初始坐标
        // dir: 0上,1右,2下,3左
        int dir = 0; // 初始面向北方
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        for (int command: commands)
        {
            // dir确定移动方向
            if (command == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if (command == -2)
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                // 方向数组！！！
                for (int i = 0; i < command; ++i)
                {
                    int new_x = x + dx[dir];
                    int new_y = y + dy[dir];
                    if (obs.find(calcHash({new_x, new_y})) != obs.end()) break;
                    x = new_x, y = new_y;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }

    // 生成障碍物的哈希值
    long long calcHash(vector<int> obstacle)
    {
        // 行 * 列数 + 列~唯一的HASH值
        return (obstacle[0] + 30000) * 60001ll + (obstacle[1] + 30000);  // 强制转换成long long 防止爆int;
    }
};
