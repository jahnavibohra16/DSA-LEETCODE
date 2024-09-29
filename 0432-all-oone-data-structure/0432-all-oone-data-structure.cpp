#include <unordered_map>
#include <unordered_set>
#include <string>

class Node {
public:
    int freq;
    std::unordered_set<std::string> keys;  // Set of keys with this frequency
    Node* prev;
    Node* next;

    Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    std::unordered_map<std::string, Node*> map;  // Map from key to node
    Node* head;  // Dummy head node
    Node* tail;  // Dummy tail node

public:
    // Constructor to initialize the data structure
    AllOne() {
        head = new Node(0);  // Dummy head node
        tail = new Node(0);  // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // Increment the count of a key
    void inc(std::string key) {
        Node* cur = head;
        int newFreq = 1;

        // If the key already exists, get its current frequency and node
        if (map.count(key)) {
            cur = map[key];
            newFreq = cur->freq + 1;
            cur->keys.erase(key);  // Remove the key from the current node
        }

        // Check if the next node has the same new frequency
        if (cur->next->freq == newFreq) {
            cur->next->keys.insert(key);
        } else {  // Create a new node for the new frequency
            Node* node = new Node(newFreq);
            node->keys.insert(key);
            Node* nextNode = cur->next;
            cur->next = node;
            node->prev = cur;
            node->next = nextNode;
            nextNode->prev = node;
        }

        map[key] = cur->next;  // Update the key's node in the map

        // If the current node is empty and not the dummy head, remove it
        if (cur->keys.empty() && cur != head) {
            removeNode(cur);
        }
    }

    // Decrement the count of a key
    void dec(std::string key) {
        Node* cur = map[key];
        int newFreq = cur->freq - 1;
        cur->keys.erase(key);  // Remove the key from the current node

        if (newFreq == 0) {
            // If the new frequency is 0, remove the key from the map
            if (cur->keys.empty()) {
                removeNode(cur);
            }
            map.erase(key);
            return;
        }

        // Check if the previous node has the same new frequency
        if (cur->prev->freq == newFreq) {
            cur->prev->keys.insert(key);
        } else {  // Create a new node for the new frequency
            Node* node = new Node(newFreq);
            node->keys.insert(key);
            Node* prevNode = cur->prev;
            node->prev = prevNode;
            node->next = cur;
            prevNode->next = node;
            cur->prev = node;
        }

        map[key] = cur->prev;  // Update the key's node in the map

        // If the current node is empty and not the dummy head, remove it
        if (cur->keys.empty() && cur != head) {
            removeNode(cur);
        }
    }

    // Get the key with the maximum frequency
    std::string getMaxKey() {
        if (tail->prev == head) {
            return "";  // If no keys exist, return an empty string
        }
        return *(tail->prev->keys.begin());  // Return any key from the last node
    }

    // Get the key with the minimum frequency
    std::string getMinKey() {
        if (head->next == tail) {
            return "";  // If no keys exist, return an empty string
        }
        return *(head->next->keys.begin());  // Return any key from the first node
    }

private:
    // Helper function to remove a node from the doubly linked list
    void removeNode(Node* cur) {
        Node* prevNode = cur->prev;
        Node* nextNode = cur->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete cur;
    }
};
