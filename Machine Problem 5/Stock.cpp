#include <string>
#include <iomanip>
#include "Stock.hpp"

using namespace std;

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