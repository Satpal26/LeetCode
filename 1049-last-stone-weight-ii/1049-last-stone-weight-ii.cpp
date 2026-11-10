class Solution {
public:

    int SumofArray(vector<int>& stones) {
        int sum = 0;

        for(int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        return sum;
    }

    int lastStoneWeightII(vector<int>& stones) {

        int sum = SumofArray(stones);
        int n = stones.size();

        int target = sum / 2;

        bool t[n + 1][target + 1];
        memset(t, false, sizeof(t));

        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < target + 1; j++) {

                if(i == 0)
                    t[i][j] = false;

                if(j == 0)
                    t[i][j] = true;
            }
        }

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < target + 1; j++) {

                if(stones[i - 1] <= j) {
                    t[i][j] =
                        t[i - 1][j - stones[i - 1]]
                        ||
                        t[i - 1][j];
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        for(int j = target; j >= 0; j--) {
            if(t[n][j] == true) {
                return sum - 2 * j;
            }
        }

        return 0;
    }
};