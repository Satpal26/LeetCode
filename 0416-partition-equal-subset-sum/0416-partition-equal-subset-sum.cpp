class Solution {
public:

    bool subsetSum(vector<int>& arr, int target, int n)
    {
        vector<vector<bool>> t(
            n + 1,
            vector<bool>(target + 1)
        );

        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < target + 1; j++)
            {
                if(i == 0)
                    t[i][j] = false;

                if(j == 0)
                    t[i][j] = true;
            }
        }

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < target + 1; j++)
            {
                if(arr[i - 1] <= j)
                {
                    t[i][j] =
                        t[i - 1][j - arr[i - 1]]
                        ||
                        t[i - 1][j];
                }

                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][target];
    }


    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }

        if(sum % 2 != 0)
        {
            return false;
        }

        else
        {
            return subsetSum(nums, sum / 2, n);
        }
    }
};