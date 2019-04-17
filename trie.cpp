// LeetCode 208. Implement Trie (Prefix Tree)

class TrieNode {
    private:
        unordered_map<char, TrieNode *> tmap;
        bool word;
    public:
        TrieNode() { word=false;}
    bool isWord() { return word;}
    void setWord() { word=true;}
        bool isValid(char c) {
            return tmap.find(c) != tmap.end();
        }
        void setValid(char c) {
            tmap.insert({c, NULL});
        }
        TrieNode *getNext(char c){
            return tmap[c];
        }
        void setNext(char c, TrieNode *n) {
            tmap[c] = n;
        }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *newNode = NULL;
        int index = 0;
        TrieNode *iter = root;
        TrieNode *prev = iter;
        iter = root;
        index = 0;
        while(index < word.length()) {
            if(!iter->isValid(word[index])) {
                iter->setValid(word[index]);
                TrieNode *n = new TrieNode();
                iter->setNext(word[index], n);
                iter = n;
            } else {
                iter = iter->getNext(word[index]);
            }
                index++;
        }
        iter->setWord();
    }
    TrieNode *getPrefixNode(string prefix) {
        TrieNode *iter = root;
        int index = 0;
        while(iter && (index < prefix.length())) {
            if (!iter->isValid(prefix[index])) {
                return NULL;
            }
            iter = iter->getNext(prefix[index]);
            index++;
        }
        return iter;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = getPrefixNode(word);
        return node && (node->isWord());
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return (getPrefixNode(prefix) != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
