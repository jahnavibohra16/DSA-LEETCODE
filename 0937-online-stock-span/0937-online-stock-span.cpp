class StockSpanner {
public:
    stack <pair<int,int>> days;
    int index = -1;
    StockSpanner() {
        index = -1;
        while (!days.empty()) {
            days.pop();
        }
    }
    
    int next(int price) {
        index = index +1;
        int span;
        while(!days.empty() && days.top().first <= price){
            days.pop();
        }
        span = index - (days.empty() ? -1 : days.top().second);
        days.push({price, index});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */