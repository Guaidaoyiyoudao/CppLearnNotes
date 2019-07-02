#include <iostream>
#include <string>

class HeartRates
{

public:
    explicit HeartRates(int y,int m,int d,std::string n);
    
    int getAge();
    int getMaxiumunHeartRate() const;
    int getTargetHeartRate() const;
    void setYear(int y);
    int getYear() const;
    void setMonth(int m);
    int getMonth() const;
    void setDay(int d);
    int getDay() const;

private:
    int year,month,day;
    std::string name;

}