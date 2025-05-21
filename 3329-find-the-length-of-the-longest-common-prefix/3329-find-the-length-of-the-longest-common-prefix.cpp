struct Node {
     // Array to store
     // links to child nodes
    Node* links[10];
     // Counter for number of
     // words that end at this node
    int cntEndWith = 0;
    // Counter for number of words
    // that have this node as a prefix
    int cntPrefix = 0; 

    // Function to check if the
    // node contains a specific key
    bool containsKey(char ch) {
        // Check if the link corresponding
        // to the character exists
        return (links[ch - '0'] != NULL); 
    }

    // Function to get the child
    // node corresponding to a key
    Node* get(char ch) {
        // Return the link
        // corresponding to the character
        return links[ch - '0']; 
    }

    // Function to insert a child
    // node with a specific key
    void put(char ch, Node* node) {
         // Set the link corresponding to
         // the character to the provided node
        links[ch - '0'] = node;
    }

    // Function to increment the
    // count of words that end at this node
    void increaseEnd() {
        // Increment the counter
        cntEndWith++; 
    }

    // Function to increment the count of
    // words that have this node as a prefix
    void increasePrefix() {
         // Increment the counter
        cntPrefix++;
    }

    // Function to decrement the count
    // of words that end at this node
    void deleteEnd() {
        // Decrement the counter
        cntEndWith--; 
    }

    // Function to decrement the count of
    // words that have this node as a prefix
    void reducePrefix() {
        // Decrement the counter
        cntPrefix--; 
    }
};

// Define a class for the
// trie data structure
class Trie {
private:
    // Pointer to the
    // root node of the trie
    Node* root; 

public:
    // Constructor to initialize
    // the trie with an empty root node
    Trie() {
        // Create a new root node
        root = new Node(); 
    }

    // Function to insert
    // a word into the trie
    void insert(string word) {
        // Start from the root node
        Node* node = root; 
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
             // If the character is
             // not already in the trie
            if (!node->containsKey(word[i])) {
                // Create a new node
                // for the character
                node->put(word[i], new Node()); 
            }
             // Move to the child node
             // corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix
            // count for the node
            node->increasePrefix(); 
        }
        // Increment the end count
        // for the last node of the word
        node->increaseEnd(); 
    }

    // Function to count the number
    // of words equal to a given word
    int countWordsEqualTo(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        int len = 0;
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
                len++;
            } else {
                 // Return 0 if the
                 // character is not found
                return len;
            }
        }
        // Return the count of
        // words ending at the node
        return len; 
    }

    // Function to count the number of
    // words starting with a given prefix
    int countWordsStartingWith(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                // Return 0 if the
                // character is not found
                return 0; 
            }
        }
        // Return the count of
        // words with the prefix
        return node->cntPrefix; 
    }

    // Function to erase a
    // word from the trie
    void erase(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is
            // found in the trie
            if (node->containsKey(word[i])) { 
                 // Move to the child node
                 // corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix
                // count for the node
                node->reducePrefix(); 
            } else {
                // Return if the
                // character is not found
                return; 
            }
        }
        // Decrement the end count
        // for the last node of the word
        node->deleteEnd(); 
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin() , arr1.end());
        sort(arr2.begin() , arr2.end());

        arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        Trie t;

        for(auto & x : arr2){
            t.insert(to_string(x));
        }

        int ans = 0;
        for(auto & x : arr1){
            int i = t.countWordsEqualTo(to_string(x));
            ans = max(ans , i);
        }
        return ans;
    }
};