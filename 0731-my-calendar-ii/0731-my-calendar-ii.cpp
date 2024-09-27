class MyCalendar{
private:
    vector<pair<int,int>> overlaps;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        for (pair<int, int> &overlap : overlaps){
            if (max(overlap.first, start) < min(overlap.second, end)) return false;
        }
        overlaps.push_back({start, end});
        return true;
    }
};

class MyCalendarTwo {
    vector<pair<int,int>> times;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        MyCalendar *overlaps = new MyCalendar();
        for(pair<int,int> &time : times){
            int startTime = max(time.first, start);
            int endTime = min(time.second, end);
                
            if(startTime < endTime){ // If it's overlapped
                if(!overlaps->book(startTime, endTime)) return false;
            }
        }
        times.push_back({start, end});
        delete overlaps;
        return true;
    }
};

// /**
//  * Your MyCalendarTwo object will be instantiated and called as such:
//  * MyCalendarTwo* obj = new MyCalendarTwo();
//  * bool param_1 = obj->book(start,end);
//  */