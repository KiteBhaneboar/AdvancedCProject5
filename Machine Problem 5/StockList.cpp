#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "StockList.hpp"
#include "Stock.hpp"

using namespace std;

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


