// because there must be a bad version, so i return in while(1) loop
// although binary search is O(log_2(n)), here it is 2*O(log_2(n))
// I can't make mysefl understand how to do it without check the fisrt version and return at last instead of within loop
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        long left = 2, right = n;   // long here because mid = (left+right) is potential to be overflow
        while (1){
            int mid = (left+right)/2;    // it is okay to use mid = left + (right-left)/2 to avoid to use long
            if (isBadVersion(mid)){
                if (!isBadVersion(mid-1))   return mid;
                else right = mid - 1;
            }else{
                if (isBadVersion(mid+1)) return mid+1;
                else left = mid + 1;
            }
        }
    }
};

// Forward declaration of isBadVersion API.
// because there must be a bad version, so when left is greater than or equal to right, then the right is the bad version
// but i can't convince myself about above statement
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right){
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};