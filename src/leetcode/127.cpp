#include "headers.h"

static int io = [](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 1;
        while(!q.empty()){
            ++depth;
            for(int sz = q.size();sz--;){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < cur.size(); ++i){
                    string temp = cur;
                    for(char j = 'a'; j <= 'z'; ++j){
                        temp[i] = j;
                        if(temp == endWord) return depth;
                        if(wordSet.count(temp)){
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
