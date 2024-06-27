// Find Center of Star Graph
// 별 그래프(하나의 노드를 센터 노드를 기준으로 다른 모든 노드들이 센터 노드와 무방향으로 연결되어 있는 그래프)의 간선 정보가 주어질 때, 센터 노드를 구하라.


// 내 답안1
#include <vector>

using namespace std;

class Solution {
public:
    int findCommon(vector<int>& a, vector<int>& b)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                if(a[i] == b[j])
                {
                    return a[i];
                }
            }        
        }
        return 0;
    }
    int findCenter(vector<vector<int>>& edges) {
        return findCommon(edges[0], edges[1]);
    }
};



// 답안 예시1 - https://leetcode.com/problems/find-center-of-star-graph/solutions/5374951/find-twice-visited-node-1-liner-o-1-97ms-beats-99-24
/*
class Solution {
public:
    static int findCenter(vector<vector<int>>& edges) {
        return edges[0][0]==edges[1][0]?edges[0][0]:(edges[0][0]==edges[1][1]?edges[0][0]:edges[0][1]);
    }
};
*/