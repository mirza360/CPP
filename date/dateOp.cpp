//
// Created by Mirza on 5/31/2017.
//
#include <iostream>
#include "dateOp.h"

class dateOp{
private:
    int day=0;
    int month;
    int year;
    int hour;
    int minute;
    int second;
    int mSec;
    bool dst;
public:
    dateOp::dateOp();
    void dateOp::setDay(int n){
        day=n;
    }
    int  dateOp::getDay(){
        return day;
    }
    void dateOp::setMonth(int n){
        month=n;
    }
    int dateOp::getMonth(){
        return month;
    }
    void dateOp::setYear(int n){
        year=n;
    }
    int dateOp::getYear(){
        return year;
    }
    void dateOp::setHour(int n){
        hour=n;
    }
    int dateOp::getHour(){
        return hour;
    }
    void dateOp::setMinute(int n){
        minute=n;
    }
    int dateOp::getMinute(){
        return minute;
    }
    void dateOp::setSecond(int n){
        second=n;
    }
    int dateOp::getSecond(){
        return second;
    }
    void dateOp::setMSec(int n){
        mSec=n;
    }
    int dateOp::getMSec(){
        return mSec;
    }
    void dateOp::setDst(bool n){
        dst=n;
    }
    bool dateOp::getDST(){
        return dst;
    }

};
