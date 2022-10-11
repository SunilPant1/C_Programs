int maxProfit(int* prices, int pricesSize){
    
    int max_profit = 0, min = 0, max = 0;
    
    min = prices[0];
    
    // Iterate over the elements of the prices one by one
    for (int i = 1; i < pricesSize; ++i) {
        
        // If the current element of prices is less than min I compare the max_profit
        // And if it is greater than the previous than the previous value, overwrite the max_profit
        if (prices[i] > min) {
            
            max = prices[i];
            max_profit = max - min >= max_profit ? max - min : max_profit;
            
        } else {
            
            min = prices[i];
            
        }
        
    }
    
    return max_profit;
}