#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> distToNumber;
        int boo = 0;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                int dist = getDistance(points[i], points[j]);
                distToNumber[dist]++;
            }
            for (const auto& [k, v]: distToNumber) {
                boo += v*(v-1);
            }
            distToNumber.clear();
        }

        return boo;
    }

    int getDistance(const vector<int>& a, const vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};