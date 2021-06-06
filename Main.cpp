#include"technical_Analysis.h"


int main()
{
	system("color 1");
	std::cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t SuperTrend : Stock Market For Naive User";
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 1; i < 212; i++)
	{
		std::cout << "**";
	}
	std::cout << std::endl;

	TechnicalAnalysis obj;

	obj.signal();
}
