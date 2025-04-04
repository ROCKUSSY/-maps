class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Min-heap to keep top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (const auto& [num, freq] : freqMap) {
        minHeap.push({freq, num}); // store as (freq, num)

        if (minHeap.size() > k) {
            minHeap.pop(); // remove least frequent
        }
    }

    // Extract top k frequent elements
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;

    }
};
