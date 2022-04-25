class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>myset;
        bool isPresent = false;
        for(auto word:wordList){
            if(word== endWord) isPresent = true;
            myset.insert(word);
        }
        if(isPresent == false)
            return 0;
        queue<string>q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int lsize = q.size();
            while(lsize--){
                string cur = q.front();
                q.pop();
                for(int i=0; i<cur.length(); i++){
                    string temp = cur;
                    for(char c = 'a'; c<='z'; c++){
                        temp[i]=c;
                        if(cur == temp) continue;
                        if(temp == endWord)
                            return depth + 1;
                        else if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
