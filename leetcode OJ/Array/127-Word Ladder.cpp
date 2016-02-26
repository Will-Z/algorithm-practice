//
// Created by Will on 2/19/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

    }
};

int main() {
    queue<string> que;
    que.push("hello");

    string word = que.front();
    que.pop();
    cout<<que.size()<<endl;
}