class MyCalendar {
public:
    vector<pair<int, int>> m;
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto const& pair : m) {
            int rs = pair.first;
            int re = pair.second;
            if (start < re && end > rs)
                return false;
        }
        m.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */