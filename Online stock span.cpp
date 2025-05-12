class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {   }
    
    int next(int price) {
        int x=1;
        while(!st.empty() && st.top().first <= price) {
            x+=st.top().second;
            st.pop();
        }
        
        st.push({price, x});
        return x;
    }
};
