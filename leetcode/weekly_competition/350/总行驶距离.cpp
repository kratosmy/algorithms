#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;

        if (mainTank < 5) return mainTank * 10;
        else {
        	while (mainTank >= 5) {
        		mainTank -= 5;
        		res += 50;
        		if (additionalTank >= 1)  {
        			additionalTank -= 1;
        			mainTank += 1;
        		}
        	}
        }
        return res + mainTank * 10;
    }
};