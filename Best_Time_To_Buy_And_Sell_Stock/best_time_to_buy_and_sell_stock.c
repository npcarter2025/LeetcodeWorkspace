int maxProfit(int* prices, int pricesSize) {

    int minPrice = prices[0];
    int maxProf = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProf) {
            maxProf = prices[i] - minPrice;
        }

    }
    return maxProf;
}


