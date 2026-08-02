class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto i: wordList){
            words.insert(i);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(words.find(word) != words.end()){
                        q.push({word, steps + 1});
                        words.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};