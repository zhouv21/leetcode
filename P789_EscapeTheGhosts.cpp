//problem 789
//You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]).
//There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).
//Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south,
//going from the previous point to a new point 1 unit of distance away.
//You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)
//If you reach any square (including the target) at the same time as a ghost, it doesn't count as an escape.
//Return True if and only if it is possible to escape.
//你在进行一个简化版的吃豆人游戏。你从 (0, 0) 点开始出发，你的目的地是 (target[0], target[1]) 。地图上有一些阻碍者，第 i 个阻碍者从 (ghosts[i][0], ghosts[i][1]) 出发。
//每一回合，你和阻碍者们*可以*同时向东，西，南，北四个方向移动，每次可以移动到距离原位置1个单位的新位置。
//如果你可以在任何阻碍者抓住你之前到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱成功。
//当且仅当你有可能成功逃脱时，输出 True。

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
  public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int mindis = __INT_MAX__;
        for (auto ghost : ghosts)
        {
            int dis = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
            if (dis < mindis)
                mindis = dis;
        }
        int dis = abs(target[0] - 0) + abs(target[1] - 0);
        if (dis < mindis)
            return true;
        else
            return false;
    }
};

int main()
{
    while (1)
    {
        printf("input ghosts:");
        int val = 0;
        vector<int> ghost;
        vector<vector<int>> ghosts;
        while (scanf("%d", &val))
        {
            ghost.push_back(val);
            if (ghost.size() == 2)
            {
                ghosts.push_back(ghost);
                ghost.clear();
            }
            if (getchar() == '\n')
                break;
        }
        printf("input target:");
        vector<int> target;
        scanf("%d", &val);
        target.push_back(val);
        scanf("%d", &val);
        target.push_back(val);

        Solution s;

        printf("\npossible to escape: %s", (s.escapeGhosts(ghosts, target) ? "true" : "false"));

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}