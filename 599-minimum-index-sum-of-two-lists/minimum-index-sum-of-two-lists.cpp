#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mapList1;
        vector<string> result;
        int minSum = INT_MAX; 

        for (int i = 0; i < list1.size(); i++) {
            mapList1[list1[i]] = i;
        }

        for (int j = 0; j < list2.size(); j++) {
            string currentWord = list2[j];

            if (mapList1.find(currentWord) != mapList1.end()) {
                int i = mapList1[currentWord];
                int currentSum = i + j;

                if (currentSum < minSum) {
                    minSum = currentSum;
                    result.clear();
                    result.push_back(currentWord);
                } 
                else if (currentSum == minSum) {
                    result.push_back(currentWord);
                }
            }
        }

        return result;
    }
};