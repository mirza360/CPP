//
// Created by Mirza on 5/31/2017.
//

#ifndef DATE_DATEOP_H
#define DATE_DATEOP_H


class dateOp {
/*private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
    int mSec;
    bool dst;*/
public:
    dateOp();
    void setDay(int n);
    int getDay();
    void setMonth(int n);
    int getMonth();
    void setYear(int n);
    int getYear();
    void setHour(int n);
    int getHour();
    void setMinute(int n);
    int getMinute();
    void setSecond(int n);
    int getSecond();
    void setMSec(int n);
    int getMSec();
    void setDst(bool n);
    bool getDST();
};


#endif //DATE_DATEOP_H
