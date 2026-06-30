class Solution {
public:
    int maxDistance(string moves) {

        int U = 0;
        int D = 0;
        int L = 0;
        int R = 0;
        int wild = 0;

        for(char ch : moves) {
            if(ch == 'U') U++;
            else if(ch == 'D') D++;
            else if(ch == 'L') L++;
            else if(ch == 'R') R++;
            else wild++;
        }

        int base = abs(R - L) + abs(U - D);

        return base + wild;
    }
};