class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>m;
        for(auto x:hand){
            m[x]++;
        }
        priority_queue<int>pq;
        for(auto x:m){
            pq.push(x.first);
        }
        queue<int>temp;
        while(!pq.empty()){
            int t=pq.top();
            pq.pop();
            m[t]--;
            if(m[t]>0) temp.push(t);
            int prev=t;

            for(int i=1;i<groupSize;i++){
                if(pq.empty()) return false;
                int t=pq.top();
                if(t+1!=prev) return false;
                pq.pop();
                m[t]--;
                if(m[t]>0) temp.push(t);
                prev=t;
            }

            while(!temp.empty()){
                pq.push(temp.front());
                temp.pop();
            }
        }
        return true;
        
    }
};