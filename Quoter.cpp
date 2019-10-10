#include "Quoter.h"

Quoter::Quoter()
{
	std::ifstream file(fileWithQuotes, std::ifstream::in);
	auto numOfQuotes = countNumOfAvailableQuotes(file);
	numOfAvailableQuotes = numOfQuotes;
	file.close();
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
	constexpr unsigned int numOfFirstLine = 1;
	return generateRandomNumber(numOfFirstLine, numOfAvailableQuotes);
}

unsigned int Quoter::generateRandomNumber(const unsigned int first, const unsigned int last)
{
	std::uniform_int_distribution<unsigned int> distribution(first, last);
	static std::random_device rd;
	static std::default_random_engine generator(rd());

	return distribution(generator);
}
