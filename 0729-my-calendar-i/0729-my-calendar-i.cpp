class MyCalendar {
private:
    vector<pair<int,int>> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int> &time:times){
            if(max(time.first, start) < min(time.second, end)) return false;
        }
        times.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */