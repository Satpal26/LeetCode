class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int,vector<int>,greater<int>> minHeap;

        int n = events.size();
        int i = 0;
        int day = 0;
        int count = 0;

        while (i < n || !minHeap.empty()) {
            // If no event is available, jump to next event start day
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // Add all events that start on or before current day
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event which ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
                day++;
            }
        }

        return count;
    }
};