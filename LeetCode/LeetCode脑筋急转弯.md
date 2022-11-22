# LeetCode脑筋急转弯题目

## [292. Nim 游戏](https://leetcode.cn/problems/nim-game/)

每次拿的石头为1~3个，那么先手拿了`x`个，后手拿`4-x`个就一定能赢，所以要保证先手赢，总共的石头个数不能是4的整数倍。

```python
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0
```

## [319. 灯泡开关](https://leetcode.cn/problems/bulb-switcher/)

若`n`的因数是奇数个，那么最后第`n`个灯是亮的，否则是灭的。

> 一个数如果是完全平方数，那么它有奇数个因数。

```python
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(sqrt(n))
```

## [810. 黑板异或游戏](https://leetcode.cn/problems/chalkboard-xor-game/)

## [1025. 除数博弈](https://leetcode.cn/problems/divisor-game/)

**猜想**：`n`为奇数，先手负；`n`为偶数，先手胜。

**证明**：

1. `n=1`时，Alice负；`n=2`时，令`x=1,`，得`n=1`，Alice胜

2. 当`n > 2`时，假设当`n <= k`时猜想成立
   
   - 若`k`为偶数，`k+1`为奇数，选`n=k+1`的因数`x`（x一定为奇数），则有`n=k+1-x<=k`（n此时为偶数），Bob胜，Alice负；
   
   - 若`k`为奇数，`k+1`为偶数，选`n=k+1`的因数`x`，`n=k+1-x<=k`，为使先手Alice胜，`x`需要取奇数（n此时为奇数），Bob负，Alice胜

综合1,2，`n`为奇数，先手负；`n`为偶数，先手胜。

```python
class Solution:
    def divisorGame(self, n: int) -> bool:
        return n % 2 == 0
```

## [1033. 移动石子直到连续](https://leetcode.cn/problems/moving-stones-until-consecutive/)

```python
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> list[int]:
        x = min(min(a, b), c)
        z = max(max(a, b), c)
        y = a + b + c - x - z
        if y - x == 1 and z - y == 1:
            return [0, 0]

        if y - x <= 2 or z - y <= 2:
            return [1, z - x - 2]
        else:
            return [2, z - x - 2]
```

## [1227. 飞机座位分配概率](https://leetcode.cn/problems/airplane-seat-assignment-probability/)

- 当$n=1$时，第1位乘客一定坐在自己的座位上

- 当$n=2$时，第2位乘客有$\frac{1}{2}$的概率坐在自己的座位上

- 当$n\geq 2$时，用$f(n)$表示第$n$位乘客坐在自己座位的概率，
  
  1. 若第$1$位乘客恰好坐在自己的座位，则第$n$位乘客一定坐在自己的座位。$f_1 = \frac{1}{n}\times 1$
  2. 若第$1$位乘客恰好坐在第n个乘客的座位，则第n位乘客一定不能坐在自己的座位。$f_2=\frac{1}{n}\times 0$
  3. 若第$1$位乘客坐在第$i(1 < i< n)$位乘客的位置，则第$2$到第$i-1$位乘客可以坐在自己的座位（当$i=2$时，第$1$位乘客坐在自己的座位），还剩下$n-(i-1)$位乘客，此时问题转化为$n-i+1$位乘客选座位，其中第$i$位乘客随机选择座位，其余乘客知道自己的座位。$f_3=\dfrac{1}{n}\times\displaystyle\sum_2^{n-1}{f(n-i+1)}$

- 综上，$f(n) = f_1 + f_2 + f_3=\dfrac{1}{n}(1 + \displaystyle\sum_2^{n-1}{f(n-i+1)})$，下面求解$f(n)$，

> $$
> n\times f(n) =1+\displaystyle\sum_2^{n-1}{f(n-i+1)}\\
(n-1)\times f(n-1) = 1 + \displaystyle\sum_2^{n-2}{f(n-i)}\\
> $$
> 
> 两式相减得：
> 
> $$
> n\times f(n)-(n-1)\times f(n-1)=f(n-1)\\\
f(n)=f(n-1)
> $$

最后得到，

$$
f(n)=\left\{ \begin{aligned}  &1  & n=1 \\ & 0.5 & n\geq 2 \end{aligned} \right.
$$

```python
class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        return 1.0 if n == 1 else 0.5
```

## [1503. 所有蚂蚁掉下来前的最后一刻](https://leetcode.cn/problems/last-moment-before-all-ants-fall-out-of-a-plank/)

## [剑指 Offer 64. 求1+2+…+n](https://leetcode.cn/problems/qiu-12n-lcof/)

## [面试题 16.07. 最大数值](https://leetcode.cn/problems/maximum-lcci/)

```python
class Solution:
    def maximum(self, a: int, b: int) -> int:
        return max(a, b)
```
