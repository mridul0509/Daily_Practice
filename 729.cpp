class MyCalendar {
public:
     unordered_map<int,int> bookings;
    MyCalendar() {
        
    }
    
    bool book(int s1, int e1) {
        for(auto& [s2, e2] : bookings) 
            if( !(s1 >= e2 || s2 >= e1) )
			    return false; 
        bookings[s1] = e1;
        return true;
    }
};
