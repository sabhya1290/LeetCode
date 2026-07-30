class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        for (int j = 0; j < n; j++) {
            if (hand[j] == -1) continue;

            int start = hand[j];
            hand[j] = -1;

            int temp = j + 1;

            for (int k = 1; k < groupSize; k++) {
                while (temp < n && hand[temp] != start + k)
                    temp++;

                if (temp == n)
                    return false;

                hand[temp] = -1;
            }
        }

        return true;
    }
};