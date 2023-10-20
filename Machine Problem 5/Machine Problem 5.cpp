#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
// stock.hpp
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

// Stock.cpp
Stock::Stock()
{
	symbol = "";
	openPrice = 0;
	closePrice = 0;
	highPrice = 0;
	lowPrice = 0;
	prevPrice = 0;
	percentGainOrLoss = 0;
	numOfShares = 0;
};
Stock::Stock(string symbol,
	double openPrice,
	double closePrice,
	double highPrice,
	double lowPrice,
	double prevPrice,
	double percentGainOrLoss,
	int numOfShares)
{
	this->symbol = symbol;
	this->openPrice = openPrice;
	this->closePrice = closePrice;
	this->highPrice = highPrice;
	this->lowPrice = lowPrice;
	this->prevPrice = prevPrice;
	this->percentGainOrLoss = percentGainOrLoss;
	this->numOfShares = numOfShares;
};

void Stock::setSymbol(string symbol) { this->symbol = symbol; };
void Stock::setOpenPrice(double openPrice) { this->openPrice = openPrice; };
void Stock::setClosePrice(double closePrice) { this->closePrice = closePrice; };
void Stock::setHighPrice(double highPrice) { this->highPrice = highPrice; };
void Stock::setLowPrice(double lowPrice) { this->lowPrice = lowPrice; };
void Stock::setPrevPrice(double prevPrice) { this->prevPrice = prevPrice; };
void Stock::setPercent(double percentGainOrLoss) { this->percentGainOrLoss = percentGainOrLoss; };
void Stock::setNumOfShares(int numOfShares) { this->numOfShares = numOfShares; };

string Stock::getSymbol() { return symbol; };
double Stock::getPercentGainOrLoss() { return percentGainOrLoss; };
int Stock::getNumberOfShares() { return numOfShares; };

void Stock::ShowPrices(ostream& prices) const
{
	prices << left << setw(9) << setfill(' ') << openPrice;
	prices << left << setw(9) << setfill(' ') << closePrice;
	prices << left << setw(9) << setfill(' ') << highPrice;
	prices << left << setw(9) << setfill(' ') << lowPrice;
	prices << left << setw(9) << setfill(' ') << prevPrice;
};
double Stock::CalculateGainLoss()
{
	percentGainOrLoss = (((openPrice - closePrice) / openPrice) * 100);
	return percentGainOrLoss;
};
bool Stock::operator<(const Stock& s) const
{
	return symbol < s.symbol;
};

ostream& operator<<(ostream& out, const Stock& stock)
{
	out << left << setw(6) << setfill(' ') << stock.symbol;
	stock.ShowPrices(out);
	out << left << setw(11) << setfill(' ') << stock.numOfShares;
	out << left << setw(10) << setfill(' ') << stock.percentGainOrLoss << "%";
	return out;
};

//StockList.hpp

class StockList
{
public:
	StockList(string file);
	void outputStock();
};

// StockList.cpp

string line;
char* lineToCharPtr;
char* tokenPtr;
vector <Stock> vectorStocks;

StockList::StockList(string fileName)
{
	ifstream file;
	file.open(fileName);
	Stock stock;
	while (!file.eof()) {
		getline(file, line);
		int i = 0;
		lineToCharPtr = (char*)line.c_str();
		tokenPtr = strtok(lineToCharPtr, "\t");
		while (tokenPtr != NULL)
		{
			switch (i++)
			{
			case 0:
				stock = Stock();
				stock.setSymbol(tokenPtr);
				break;
			case 1:
				stock.setOpenPrice(stod(tokenPtr));
				break;
			case 2:
				stock.setClosePrice(stod(tokenPtr));
				break;
			case 3:
				stock.setHighPrice(stod(tokenPtr));
				break;
			case 4:
				stock.setLowPrice(stod(tokenPtr));
				break;
			case 5:
				stock.setPrevPrice(stod(tokenPtr));
				break;
			case 6:
				stock.setNumOfShares(stoi(tokenPtr));
				vectorStocks.emplace_back(stock);
				break;
			};
			tokenPtr = strtok(NULL, "\t");
			stock.CalculateGainLoss();
		};
	};
	sort(vectorStocks.begin(), vectorStocks.end());
};

void StockList::outputStock()
{
	cout << setw(19) << setfill(' ') << "Today" << setw(23) << setfill(' ') << " ";
	cout << "Yesterday" << setw(11) << setfill(' ') << " ";
	cout << "Percent" << setw(10) << setfill(' ') << endl;
	cout << left << setw(6) << setfill(' ') << "Sym";
	cout << left << setw(9) << setfill(' ') << "Open";
	cout << left << setw(9) << setfill(' ') << "Close";
	cout << left << setw(9) << setfill(' ') << "High";
	cout << left << setw(9) << setfill(' ') << "Low";
	cout << left << setw(9) << setfill(' ') << "Close";
	cout << left << setw(11) << setfill(' ') << "Shares";
	cout << left << setw(10) << setfill(' ') << "G/L" << endl;
	for (int i = 0; i < vectorStocks.size(); i++)
		cout << vectorStocks[i] << endl;
};



using namespace std;

int main()
{
	StockList list("Stocks.txt");
	list.outputStock();


};