#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(int x : arr1)
        {
            bool flag = true;
            for(int y: arr2)
            {
                if(abs(x-y)<=d)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};