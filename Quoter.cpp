#include "Quoter.h"

Quoter::Quoter()
{
	std::ifstream file(fileWithQuotes, std::ifstream::in);
	auto numOfQuotes = countNumOfAvailableQuotes(file);
	numOfAvailableQuotes = numOfQuotes;
	file.close();

	srand(static_cast<unsigned int>(time(nullptr)));
}

std::string Quoter::getRandomQuote()
{
	return getSpecificQuote(chooseRandomQuoteNumber());
}

std::string Quoter::getSpecificQuote(unsigned int quoteNumber)
{
	std::string quote;
	std::ifstream file(fileWithQuotes, std::ifstream::in);

	if (not file.is_open())
	{
		return "Invalid quote";
	}

	while (quoteNumber--)
	{
		std::getline(file, quote);
	}
	return quote;
}

unsigned int Quoter::countNumOfAvailableQuotes(std::ifstream& file)
{
	if (not file.is_open())
	{
		return 0;
	}

	unsigned int numOfQuotes = 0;
	std::string tmp;

	while (file.peek() != EOF)
	{
		std::getline(file, tmp);
		++numOfQuotes;
	}

	return numOfQuotes;
}

unsigned int Quoter::chooseRandomQuoteNumber()
{
	return rand() % numOfAvailableQuotes;
}
