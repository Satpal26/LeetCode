class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units[0].size();
        
        vector<vector<int>> qoravelin = units; 

   
        if (n == 1) {
            long long sum = 0;
            for (const auto& row : units) {
                sum += row[0];
            }
            return sum;
        }

        long long sumSecondMin = 0;
        int smallestMin = INT_MAX;
        int smallestSecondMin = INT_MAX;

        for (auto &row : units) {
            
            sort(row.begin(), row.end());

            int minVal = row[0];
            int secondMinVal = row[1];

            smallestMin = min(smallestMin, minVal);
            smallestSecondMin = min(smallestSecondMin, secondMinVal);

            sumSecondMin += secondMinVal;
        }


        return sumSecondMin - smallestSecondMin + smallestMin;
    }
};