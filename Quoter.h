#pragma once

#include <string>
#include <ctime>
#include <fstream>

class Quoter
{
public:
	Quoter();
	std::string getRandomQuote();
	std::string getSpecificQuote(unsigned int quoteNumber);

private:
	const std::string fileWithQuotes = "quotes.txt";
	unsigned int numOfAvailableQuotes = 0;

	unsigned int countNumOfAvailableQuotes(std::ifstream& file);
	unsigned int chooseRandomQuoteNumber();
};

