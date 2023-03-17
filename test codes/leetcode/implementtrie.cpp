class Trie {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;

        TrieNode() {
            isEndOfWord = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
