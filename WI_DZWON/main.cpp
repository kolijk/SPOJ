#include <iostream>
#include <string>
#include <vector>

const int lessonTime = 45;

struct Time{
    int hours;
    int minutes;

    Time() = default;
    Time(int h, int m) : hours(h), minutes(m) {}
    Time(Time *tm) {
        hours = tm->hours;
        minutes = tm->minutes;
    }
};

//Convert std::string time to struct Time
Time prepareTime(std::string time) {
    std::string left;
    std::string right;

    bool doubleDot = false;
    for (int x = 0; x < time.size(); x++) {//iter for next positions in time string
        if (time[x] == ':') {//Separate hours and minutes
            doubleDot = !doubleDot;//Invert sign bool for change get minutes
        }
        else {
            if (doubleDot == false) {//If doubledot not reached
                left += time[x];//add next number to hours std::string
            }
            else {
                right += time[x];//add next number to minutes std::string
            }
        }
    }

    return Time(std::stoi(left), std::stoi(right));//Return object of struct Time from std::string variable

}

//Summare to object Time int timeLength
Time summ(Time firstTime, int howMuchAdd) {

    firstTime.minutes += howMuchAdd;//Summ minutes to minutes for object

    if (firstTime.minutes >= 60) {//If minutes is more than 60 (we have minimum 1 hour)
        int howMuchHours = firstTime.minutes / 60;//Calc how much i have pcs 60 minutes
        firstTime.minutes -= howMuchHours * 60;//From minutes object minus pcs (60 minutes)
        firstTime.hours += howMuchHours; //For object hours adding how much i have pcs (60 minutes)
    }

    return firstTime;

}

//Calculate next rings
std::vector <Time> calcToRing(Time firstLesson, std::vector <int> lengthFreeTime) {
    std::vector <Time> time;

    time.push_back(firstLesson);//start first lesson
    time.push_back(summ(firstLesson, lessonTime));//First free time

    for (int x = 0; x < lengthFreeTime.size(); x++) {
        time.push_back(summ(time[time.size()-1], lengthFreeTime[x]));//ring for lesson
        time.push_back(summ(time[time.size()-1], lessonTime));//ring for free time
    }

    return time;
}

//adding number 0
std::string prepareDisplay(int value) {
    std::string bufor = std::to_string(value);
    if (bufor.size() == 1) {//If minute or hour has only one digit
        bufor += bufor[0];//move first digit for second position
        bufor[0] = '0';//on first position added digit '0'
    }

    return bufor;//return result
}

//Function for display next times
void display(std::vector <Time> times) {

    for (int x = 0; x < times.size(); x++) {
        std::cout << prepareDisplay(times[x].hours) << ":" << prepareDisplay(times[x].minutes);//display hour and minute with format(HH:MM)
        if (x + 1 < times.size()) {//if next time is available
            std::cout <<",";//add sign ','
        }
    }

}

int main() {
    
    std::string timeFirstLesson;
    std::vector <int> lengthFreeTime;
    std::string lengthTime;

    std::cin >> timeFirstLesson;//Get time for start first lesson
    
    while (std::getline(std::cin, lengthTime)) {//Get while free time is available
        if (lengthTime.size() > 0)
            lengthFreeTime.push_back(std::stoi(lengthTime));//Convert to int and add value to vector
    }

    Time firstLesson = prepareTime(timeFirstLesson);//Prepare std::string time for Time struct

    display(calcToRing(firstLesson, lengthFreeTime));//calculate next rings and display result on standard out

    return 0;

}
