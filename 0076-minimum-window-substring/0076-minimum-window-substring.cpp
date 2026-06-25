class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                targetCharsRemaining--;
            }
            charCount[ch]--;

            if (targetCharsRemaining == 0) {
                while (true) {
                    char charAtStart = s[left];
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {break;}
                    charCount[charAtStart]++;
                    left++;
                }

                if (right - left < minWindow[1] - minWindow[0]) {
                    minWindow[0] = left;
                    minWindow[1] = right;
                }

                charCount[s[left]]++;
                targetCharsRemaining++;
                left++;
            }
        }

        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);        
    }
};