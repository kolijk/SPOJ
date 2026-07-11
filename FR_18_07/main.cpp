#include <iostream>
#include <string>

enum DataType{
    B = 1,
    KB = 2,
    MB = 3,
    GB = 4
};

enum DataType2 {
    b = 1,
    Kb = 2,
    Mb = 3
};

DataType DT(std::string data) {
    if (data == "B")
        return DataType::B;
    if (data == "KB")
        return DataType::KB;
    if (data == "MB")
        return DataType::MB;
    if (data == "GB")
        return DataType::GB;
}

DataType2 DT2(std::string data) {
    if (data == "b")
        return DataType2::b;
    if (data == "Kb")
        return DataType2::Kb;
    if (data == "Mb")
        return DataType2::Mb;
}

struct Data {
    int sizeDownloadingData;
    DataType sizeUnitData;

    int speedDownloading;
    DataType2 speedUnitDownload;
};

struct Time {
    int days;
    int hours;
    int minutes;
    unsigned long long int seconds;
    Time() { days = 0; hours = 0; minutes = 0; seconds = 0; };
};
//Convert size to bits
unsigned long long int getBitsDT(DataType dt, int howMuch) {

    unsigned long long int result = howMuch;

    if (dt == DataType::GB) { 
        result = howMuch * 1024ULL * 1024ULL * 1024ULL * 8ULL; }
    if (dt == DataType::MB) { 
        result = howMuch * 1024ULL * 1024ULL * 8ULL; }
    if (dt == DataType::KB) { 
        result = howMuch * 1024ULL * 8ULL; }
    if (dt == DataType::B) {
        result = howMuch * 8ULL; }

    return result;

}
//Convert size to bits
unsigned long long int getBitsDT2(DataType2 dt, int howMuch) {

    unsigned long long int result = howMuch;

    if (dt == DataType2::Mb) {
        result = howMuch * 1024ULL * 1024ULL; }
    if (dt == DataType2::Kb) {
        result = howMuch * 1024ULL; }

    return result;

}

unsigned long long int calcSeconds(Data dt) {

    unsigned long long int downloadSizeBits = getBitsDT(dt.sizeUnitData, dt.sizeDownloadingData);
    unsigned long long int downloadSpeedBits = getBitsDT2(dt.speedUnitDownload, dt.speedDownloading);

    return downloadSizeBits / downloadSpeedBits;
}
//Convert seconds to minutes, hours and days
Time calcTime(unsigned long long int seconds) {
    Time tm;
    tm.seconds = seconds;

    if (tm.seconds > 0) {
        
        for (tm.seconds; tm.seconds >= 60; tm.seconds -= 60) {
            tm.minutes += 1;
        }

        for (tm.minutes; tm.minutes >= 60; tm.minutes -= 60) {
            tm.hours += 1;
        }

        for (tm.hours; tm.hours >= 24; tm.hours -= 24) {
            tm.days += 1;
        }

    }

    return tm;
}

int main() {

    int tests;
    std::cin >>tests;
    std::cin.clear();

    for (int x=0; x<tests; x++) {
        Data dt;
        std::string data;

        std::cin >>dt.sizeDownloadingData;
        std::cin.clear();

        std::cin >>data;
        dt.sizeUnitData = DT(data);
        std::cin.clear();

        std::cin >>dt.speedDownloading;
        std::cin.clear();

        std::cin >> data;
        dt.speedUnitDownload = DT2(data);
        std::cin.clear();

        Time tm = calcTime(calcSeconds(dt));

        bool anything = false;

        if (tm.days != 0) {
            std::cout <<"dni: "<< tm.days << std::endl; anything = true;
        }
        if (tm.hours != 0) {
            std::cout <<"godziny: "<< tm.hours << std::endl; anything = true;
        }
        if (tm.minutes != 0) {
            std::cout <<"minuty: "<< tm.minutes << std::endl; anything = true;
        }
        if (tm.seconds != 0) {
            std::cout <<"sekundy: "<< tm.seconds << std::endl; anything = true;
        }

        if (anything == false) {
            std::cout <<"w mgnieniu oka" << std::endl;
        }

        std::cout <<"\n";

    }

    return 0;

}
