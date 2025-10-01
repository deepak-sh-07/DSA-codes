class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles; 
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange; 
            sum += newBottles;                   
            empty = newBottles + (empty % numExchange);
        }
        return sum;
    }
};
