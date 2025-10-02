class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum = numBottles;
        int empty = numBottles;
        int newb = 0;
        while(empty>=numExchange){
           sum += 1;
           empty = empty - numExchange+1;
           numExchange++;
        }
        return sum;
    }
};
