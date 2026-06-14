//Problem: Best Time to Buy and Sell Stock
//You are given an array prices where prices[i] is the price of a stock on the i-th day.
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0)
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        int profit = prices[i] - minPrice;

        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}