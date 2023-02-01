//Statement: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    vector<struct node*> children = vector<struct node*>(26, nullptr);
    char ch;
    bool isEnd = false;
} node;

class Trie {
public:
    node* root;

    Trie() {
        root = new node;
    }
    
    void insertWord(node* currnode, string word, int pos){
        if (pos == word.length()){
            currnode->isEnd = true;
            return;
        }
        if (currnode->children[word[pos]-'a'] == nullptr){
            node* newnode = new node;
            newnode->ch = word[pos];
            currnode->children[word[pos]-'a'] = newnode;
        }
        insertWord(currnode->children[word[pos]-'a'], word, pos+1);
    }

    node* searchPrefix(node* currnode, string prefix, int pos){
        if (pos==prefix.length()) return currnode;
        if (currnode->children[prefix[pos]-'a'] == nullptr) return nullptr;
        return searchPrefix(currnode->children[prefix[pos]-'a'], prefix, pos+1);
    }

    void insert(string word) {
        insertWord(root, word, 0);
    }
    
    bool search(string word) {
        node* endnode = searchPrefix(root, word, 0);
        if (endnode == nullptr) return false;
        else return endnode->isEnd;
    }
    
    bool startsWith(string prefix) {
        if (searchPrefix(root, prefix, 0) == nullptr) return false;
        return true;
    }
};

/**
 * Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */