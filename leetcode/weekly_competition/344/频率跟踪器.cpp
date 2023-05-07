#include <vector>
#include <unordered_map>

using namespace std;

class FrequencyTracker {
public:
    const int N = 100010;

    vector<int> store;
    unordered_map<int, int> freq;
    vector<int> bit;
    
    FrequencyTracker() {
        bit = vector<int>(N, 0);
    }   
    
    void add(int number) {
        store.push_back(number);
        bit[freq[number]] --;
        freq[number] ++;
        bit[freq[number]] ++;
    }
    
    void deleteOne(int number) {
        if (freq[number]) {
            bit[freq[number]] --;
            freq[number] --;
            bit[freq[number]] ++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if (bit[frequency]) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */