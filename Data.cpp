#include <iostream>
#include <ctime>

class Data
{
private:
	int Day, Month, Year;
	Data& dayChecker() {
		switch (Month)
		{
		case 1: 
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 2:
			if (Day > 28) {
				Month++;
				Day = 1;
			}
			break;
		case 3:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 4:
			if (Day > 30) {
				Month++;
				Day = 1;
			}
			break;
		case 5:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 6:
			if (Day > 30) {
				Month++;
				Day = 1;
			}
			break;
		case 7:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 8:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 9:
			if (Day > 30) {
				Month++;
				Day = 1;
			}
			break;
		case 10:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		case 11:
			if (Day > 30) {
				Month++;
				Day = 1;
			}
			break;
		case 12:
			if (Day > 31) {
				Month++;
				Day = 1;
			}
			break;
		default:
			break;
		}
		return *this;
	}
public:
	static int objectCount;
	Data()
	{
		time_t seconds = time(NULL);
		struct tm timeinfo;
		localtime_s(&timeinfo, &seconds);

		Day = timeinfo.tm_mday;
		Month = timeinfo.tm_mon + 1;
		Year = timeinfo.tm_year + 1900;
		objectCount++;
	}
	Data(int _Day, int _Month, int _Year) : Day(_Day), Month(_Month), Year(_Year) { objectCount++; }
	Data(const Data& _Data) : Day(_Data.Day), Month(_Data.Month), Year(_Data.Year) { objectCount++; }

	Data& setDay(int _Day)
	{
		if (1 <= _Day && _Day <= 31)
		{
			Day = _Day;
		}
		else {
			std::cout << "Incorrect input!" << std::endl;
		}
		return *this;
	}
	Data& setMonth(int _Month)
	{
		if (1 <= _Month && _Month <= 12)
		{
			Month = _Month;
		}
		else {
			std::cout << "Incorrect input!" << std::endl;
		}
		return *this;
	}
	Data& setYear(int _Year)
	{
		if (1 <= _Year && _Year <= 2100)
		{
			Year = _Year;
		}
		else {
			std::cout << "Incorrect input!" << std::endl;
		}
		return *this;
	}

	int getDay() const
	{
		return Day;
	}
	int getMonth() const
	{
		return Month;
	}
	int getYear() const
	{
		return Year;
	}
	Data& operator ++() {
		Day++;
		this->dayChecker();
		return *this;
	}
	friend std::ostream& operator << (std::ostream& os, const Data& cur) {
		os << cur.Day << "." << cur.Month << "." << cur.Year << std::endl;
		return os;
	}

	~Data() {}
};