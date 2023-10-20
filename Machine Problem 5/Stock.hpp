#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stock
{
protected:

	string symbol;
	double openPrice;
	double closePrice;
	double highPrice;
	double lowPrice;
	double prevPrice;
	double percentGainOrLoss;
	int numOfShares;

	friend ostream& operator<<(ostream& out, const Stock& stock);

public:
	Stock();
	Stock(string symbol,
		double openPrice,
		double closePrice,
		double highPrice,
		double lowPrice,
		double prevPrice,
		double percentGainOrLoss,
		int numOfShares);

	void setSymbol(string symbol);
	void setOpenPrice(double openPrice);
	void setClosePrice(double closePrice);
	void setHighPrice(double highPrice);
	void setLowPrice(double lowPrice);
	void setPrevPrice(double prevPrice);
	void setPercent(double percentGainOrLoss);
	void setNumOfShares(int numOfShares);

	string getSymbol();
	double getPercentGainOrLoss();
	int getNumberOfShares();

	void ShowPrices(ostream& prices) const;
	double CalculateGainLoss();
	void OverloadStocks();
	void overloadInput();

	bool operator<(const Stock& s) const;
};