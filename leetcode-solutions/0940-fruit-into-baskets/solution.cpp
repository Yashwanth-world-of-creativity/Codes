// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         unordered_map<int,int>basket;
//         int n=fruits.size();
//         int l=0,maxPicked=0;
//         for(int r=0;r<n;r++){
//             basket[fruits[r]]++;
//             while(basket.size()>2){
//                     basket[fruits[l]]--;
//                     if(basket[fruits[l]]==0)
//                     basket.erase(fruits[l]);
//                     l++;
//             }
//             maxPicked=max(maxPicked,r-l+1);
//         }
//         return maxPicked;
//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& nums) {

        int lastFruit = -1;
        int secondLastFruit = -1;

        int lastFruitCount = 0;   // consecutive count of lastFruit
        int currentWindow = 0;
        int ans = 0;

        for (int fruit : nums) {

            // extend window if fruit matches existing baskets
            if (fruit == lastFruit || fruit == secondLastFruit) {
                currentWindow++;
            } 
            else {
                // new third fruit appears
                currentWindow = lastFruitCount + 1;
            }

            // update consecutive count
            if (fruit == lastFruit) {
                lastFruitCount++;
            } else {
                lastFruitCount = 1;
            }

            // shift fruit types
            if (fruit != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            ans = max(ans, currentWindow);
        }

        return ans;
    }
};
