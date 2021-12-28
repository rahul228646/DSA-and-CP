

    const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
    int countLeapYears(int y, int m){
        int years = y;
        if (m <= 2)
            years--;
        return years / 4 - years / 100 + years / 400;
    }
       
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        int m_1 = 0, m_2 = 0;
        for(int i = 0; i<12; i++) {
            if(i < m1-1)
                m_1 += monthDays[i];
            if(i < m2-1)
                m_2 += monthDays[i];  
        }
        
        int n1 = y1*365 + m_1 + d1 + countLeapYears(y1, m1);
        int n2 = y2*365 + m_2 + d2 + countLeapYears(y2, m2);
        
        return abs(n1-n2);
    }
