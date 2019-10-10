#pragma once

#include <string>
#include <fstream>
#include <random>

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
	unsigned int generateRandomNumber(const unsigned int first, const unsigned int last);
};

