class MyCalendarTwo {
    vector<pair<int, int>> single;        // store single booking events
    vector<pair<int, int>> double_booked; // store double booking intervals

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // check for triple booking by overlapping with any double booking
        for (auto const& [s, e] : double_booked) {
            if (max(start, s) < min(end, e)) {
                return false;
            }
        }
        // add overlaping parts to double bookings
        for (auto const& [s, e] : single) {
            if (max(start, s) < min(end, e)) {
                double_booked.push_back({max(start, s), min(end, e)});
            }
        }

        // add event to single bookings
        single.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */