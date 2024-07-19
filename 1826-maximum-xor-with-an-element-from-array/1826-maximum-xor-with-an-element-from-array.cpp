#include <bits/stdc++.h>
using namespace std;

// Node class representing a node in the Trie data structure
class Node
{
private:
    Node *links[2]; // Links to child nodes, assuming binary numbers (0 and 1)

public:
    // Check if the node contains a child node for a given bit (0 or 1)
    bool ContainsKey(int bit)
    {
        return links[bit] != NULL;
    }

    // Get the child node for a given bit (0 or 1)
    Node *get(int bit)
    {
        return links[bit];
    }

    // Put a child node for a given bit (0 or 1)
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

// Trie class implementing a Trie data structure for XOR operations
class Trie
{
private:
    Node *root; // Root node of the Trie

public:
    // Constructor to initialize the Trie with an empty root node
    Trie()
    {
        root = new Node();
    }

    // Insert a number into the Trie
    void insert(int num)
    {
        Node *node = root;
        // Traverse through each bit of the number from left to right
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // Extract the i-th bit of the number
            // If the node doesn't have a child for the current bit, create one
            if (!(node->ContainsKey(bit)))
            {
                node->put(bit, new Node());
            }
            // Move to the child node corresponding to the current bit
            node = node->get(bit);
        }
    }

    // Find the maximum XOR of a number with any number present in the Trie
    int maxXor(int num)
    {
        Node *node = root;
        int maxx = 0; // Initialize the maximum XOR result
        // Traverse through each bit of the number from left to right
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // Extract the i-th bit of the number
            // If there is a different bit in the Trie for the current bit, update the maximum XOR result
            if (node->ContainsKey(1 - bit))
            {
                maxx = maxx | (1 << i);    // Update the maximum XOR result
                node = node->get(1 - bit); // Move to the child node with the different bit
            }
            else
            {
                node = node->get(bit); // Move to the child node with the same bit
            }
        }
        return maxx; // Return the maximum XOR result
    }
};

class Solution
{
public:
    // Function to maximize XOR for each query using offline processing
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        // Sort the array for proper and efficient traversal to generate the query answers
        sort(nums.begin(), nums.end());

        // Creating offline queries
        // Each query is represented as a pair of {Ai, {Xi, i}}
        // where Ai is the threshold value, Xi is the query value, and i is the query index
        vector<pair<int, pair<int, int>>> OfflineQueries;

        for (int i = 0; i < q; i++)
        {
            OfflineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        // Sorting the queries according to Ai
        sort(OfflineQueries.begin(), OfflineQueries.end());

        int index = 0;
        Trie trie;
        vector<int> ans(q);
        for (int i = 0; i < q; i++)
        {
            int Ai = OfflineQueries[i].first;
            int Xi = OfflineQueries[i].second.first;
            int Qindex = OfflineQueries[i].second.second;

            // Insert elements into the trie until the current threshold value (Ai)
            while (index < n && nums[index] <= Ai)
            {
                trie.insert(nums[index]);
                index++;
            }

            // If no element is inserted into the trie, set the answer to -1
            if (index == 0)
            {
                ans[Qindex] = -1;
            }
            // Otherwise, find the maximum XOR for the current query value (Xi)
            else
            {
                ans[Qindex] = trie.maxXor(Xi);
            }
        }
        return ans;
    }
};