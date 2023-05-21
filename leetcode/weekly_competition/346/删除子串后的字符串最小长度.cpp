#include <string>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        string sub1 = "AB";
        string sub2 = "CD";

        while (s.size()) {
            auto start1 = s.find(sub1);
            auto start2 = s.find(sub2);

            if(start1 != string::npos){
                s.erase(start1, 2);
            } else if (start2 != string::npos) {
                s.erase(start2, 2);
            } else {
                break;
            }
        }
        return s.size();
    }
};