class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]]++;
        }
        priority_queue<int> maxHeap;
        for(auto& entry: freq){
            maxHeap.push(entry.second);
        }
        int time = 0;

        while(!maxHeap.empty()){
            
            vector<int> temp;
            int cycle = n + 1;
            // int i = 0;

            while(cycle && !maxHeap.empty()){
                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;
                if(cnt > 0)
                temp.push_back(cnt);
                time++;
                cycle--;
            }

            for(int val: temp){
                maxHeap.push(val);
            }

            if(maxHeap.empty()) break;

            time += cycle;

        }
        return time;

    }
};