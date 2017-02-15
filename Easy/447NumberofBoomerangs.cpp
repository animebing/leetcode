// based on the solution of StefanPochmann and discussion of ZephyrSails, https://discuss.leetcode.com/topic/66574/7-lines-1050-ms-c/4
// almost the same idea as compute adjacent matrix first, then find the boomerangs
// but here use map to simplify the process
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto &p:points) {
            unordered_map<int, int> cnt;   // unordered_map<int, int> cnt(points.size()); will use less time
            for (auto &q:points) {
                int dis = (p.first-q.first)*(p.first-q.first) + (p.second-q.second)*(p.second-q.second);
                res += 2 * cnt[dis]++; // really clever here using ++ to increase the number gradually
            }
        }
        return res;
    }
};

// based on the solution of kdtree, https://discuss.leetcode.com/topic/66554/c-clean-solution-o-n-2-fully-commented-and-explained
// compute cnt first, then compute all permutation
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto &p:points) {
            unordered_map<int, int> cnt(points.size());
            for (auto &q:points) {
                int dis = (p.first-q.first)*(p.first-q.first) + (p.second-q.second)*(p.second-q.second);
                cnt[dis]++; 
            }
            for (auto c:cnt) res += c.second*(c.second-1);
        }
        return res;
    }
};