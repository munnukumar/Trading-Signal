#include"technical_Analysis.h"

double TechnicalAnalysis::calculateFiftyMA()
{

	std::ifstream myFile;
	std::string line;
	std::vector<double> closeingPrice;

	myFile.open("data.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << "\n";
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closeingPrice.push_back(stod(val));
	}
	myFile.close();

	double MA = 0;
	for (auto& val : closeingPrice)
	{
		MA = val + MA;
	}
	return MA / 50;
}

//Calculate 20 Moving Average for Day Entry

double TechnicalAnalysis::calculateTwentyMA()
{

	std::ifstream myFile;
	std::string line;
	std::vector<double> closeingPrice;

	myFile.open("Data3.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closeingPrice.push_back(stoi(val));
	}
	myFile.close();

	double MA = 0;
	for (int i = 0; i < 21; i++)
	{
		MA = MA + closeingPrice[i];
	}

	return MA / 21;

}


//calculate Twenty Moving Average for Investing

double TechnicalAnalysis::calculateTwohundredMA()
{
	std::ifstream myFile;
	std::string line;
	std::vector<double> closeingPrice;

	myFile.open("Data3.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closeingPrice.push_back(stoi(val));
	}
	myFile.close();

	double MA = 0;
	for (auto& val : closeingPrice)
	{
		MA = val + MA;
	}
	return MA / 200;
}


//Calculating RSI of DR Reddy

double TechnicalAnalysis::calculateRSIOfDrReddy()
{
	double sumGain = 0;
	double sumLoss = 0;


	std::ifstream myFile;
	std::string line;
	std::vector<double> closingPrice;

	myFile.open("DR_Reddy.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice.push_back(stof(val));
	}
	myFile.close();


	for (int i = 7; i < 14; i++)
	{
		double difference = closingPrice[i] - closingPrice[i-1];
		if (difference >= 0)
		{
			sumGain += difference;
		}
		else
		{
			sumLoss -= difference;
		}
	}
	double avgGain = sumGain / 9;
	double avgLoss = sumLoss / 9;
	double RS = avgGain / avgLoss;
	int RSI;
	RSI = 100.0 - (100.0 / (1 + RS));
	double res = closingPrice[20];

	return res;
}

//Calculating RSI of Nifty

double TechnicalAnalysis::calculateRSIOfNifty()
{
	double sumGain = 0;
	double sumLoss = 0;


	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_Nifty;

	myFile.open("Nifty.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Nifty.push_back(stof(val));
	}
	myFile.close();


	for (int i = 7; i < 14; i++)
	{
		double difference_of_Nifty = closingPrice_of_Nifty[i] - closingPrice_of_Nifty[i - 1];
		if (difference_of_Nifty >= 0)
		{
			sumGain += difference_of_Nifty;
		}
		else
		{
			sumLoss -= difference_of_Nifty;
		}
	}
	double avgGain_of_Nifty = sumGain / 9;
	double avgLoss_of_Nifty = sumLoss / 9;
	double RS_of_Nifty = avgGain_of_Nifty / avgLoss_of_Nifty;
	int RSI_of_Nifty;
	RSI_of_Nifty = 100.0 - (100.0 / (1 + RS_of_Nifty));
	double rsi_of_Nifty = closingPrice_of_Nifty[20];

	return rsi_of_Nifty;
}

//Calculating RSI of Relience

double TechnicalAnalysis::calculateRSIOfRel()
{
	double sumGain = 0;
	double sumLoss = 0;

	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_Relience;

	myFile.open("Relience.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Relience.push_back(stof(val));
	}
	myFile.close();


	for (int i = 7; i < 14; i++)
	{
		double difference_of_Relience = closingPrice_of_Relience[i] - closingPrice_of_Relience[i - 1];
		if (difference_of_Relience >= 0)
		{
			sumGain += difference_of_Relience;
		}
		else
		{
			sumLoss -= difference_of_Relience;
		}
	}
	double avgGain_of_Relience = sumGain / 9;
	double avgLoss_of_Relience = sumLoss / 9;
	double RS_of_Relience = avgGain_of_Relience / avgLoss_of_Relience;
	int RSI_of_Relience;
	RSI_of_Relience = 100.0 - (100.0 / (1 + RS_of_Relience));
	double rsi_of_Relience = closingPrice_of_Relience[21];

	return rsi_of_Relience;
}

//Calculating RSI of L & T

double TechnicalAnalysis::calculateRSIOfLAndT()
{
	double sumGain = 0;
	double sumLoss = 0;

	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_LAndT;

	myFile.open("L&T.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_LAndT.push_back(stof(val));
	}
	myFile.close();


	for (int i = 7; i < 14; i++)
	{
		double difference_of_LAndT = closingPrice_of_LAndT[i] - closingPrice_of_LAndT[i - 1];
		if (difference_of_LAndT >= 0)
		{
			sumGain += difference_of_LAndT;
		}
		else
		{
			sumLoss -= difference_of_LAndT;
		}
	}
	double avgGain_of_LAndT = sumGain / 9;
	double avgLoss_of_LAndT = sumLoss / 9;
	double RS_of_LAndT = avgGain_of_LAndT / avgLoss_of_LAndT;
	int RSI_of_LAndT;
	RSI_of_LAndT = 100.0 - (100.0 / (1 + RS_of_LAndT));
	double rsi_of_LAndT = closingPrice_of_LAndT[20];

	return rsi_of_LAndT;
}


//Calculating RSI of Mahindra & Mahindra

double TechnicalAnalysis::calculateRSIOfMAndM()
{
	double sumGain = 0;
	double sumLoss = 0;

	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_MAndM;

	myFile.open("M&M.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_MAndM.push_back(stof(val));
	}
	myFile.close();


	for (int i = 7; i < 14; i++)
	{
		double difference_of_MAndM = closingPrice_of_MAndM[i] - closingPrice_of_MAndM[i - 1];
		if (difference_of_MAndM >= 0)
		{
			sumGain += difference_of_MAndM;
		}
		else
		{
			sumLoss -= difference_of_MAndM;
		}
	}
	double avgGain_of_MAndM = sumGain / 9;
	double avgLoss_of_MAndM = sumLoss / 9;
	double RS_of_MAndM = avgGain_of_MAndM / avgLoss_of_MAndM;
	int RSI_of_MAndM;
	RSI_of_MAndM = 100.0 - (100.0 / (1 + RS_of_MAndM));
	double rsi_of_MAndM = closingPrice_of_MAndM[20];

	return rsi_of_MAndM;
}



//Calculating EMA of DR Reddy

double TechnicalAnalysis::calculateEMAOfDrReddy()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice;

	myFile.open("DR_Reddy.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice.push_back(stof(val));

	}
	myFile.close();

	double EMA[2] = { 0 };
	EMA[0] = closingPrice[0];
	int l = 1;
	int smoothing = 2;
	double multiplier = 0.0909;

	EMA[1] = closingPrice[2] * multiplier + EMA[1 - 1] * (1 - multiplier);
	double sum = 0;
	for (int i = 20; i >= 18; i--)
	{
		sum += closingPrice[i];
	}
	double EMA_of_DrReddy = sum / 3;

	return EMA_of_DrReddy;
}

//Calculating EMA of Nifty

double TechnicalAnalysis::calculateEMAOfNifty()
{
	std::ifstream myFile;
	std::string line;
	std::vector<double> closingPrice_of_Nifty;

	myFile.open("Nifty.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Nifty.push_back(stof(val));

	}
	myFile.close();

	double EMA_Nifty[2] = { 0 };
	EMA_Nifty[0] = closingPrice_of_Nifty[0];
	int l1 = 1;

	int smoothing1 = 2;
	double multiplier1 = 0.0909;

	EMA_Nifty[1] = closingPrice_of_Nifty[2] * multiplier1 + EMA_Nifty[1 - 1] * (1 - multiplier1);
	double sum_Nifty = 0;
	for (int i = 20; i >= 19; i--)
	{
		sum_Nifty += closingPrice_of_Nifty[i];
	}

	double EMA_of_Nifty = sum_Nifty / 3;

	return EMA_of_Nifty;
}

//Calculating EMA of Relience

double TechnicalAnalysis::calculateEMAOfRel()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_Relience;

	myFile.open("Relience.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Relience.push_back(stof(val));

	}
	myFile.close();

	int smoothing = 2;
	double multiplier = 0.0909;

	double EMA_Relience[2] = { 0 };
	EMA_Relience[0] = closingPrice_of_Relience[0];
	int l2 = 1;

	EMA_Relience[1] = closingPrice_of_Relience[2] * multiplier + EMA_Relience[1 - 1] * (1 - multiplier);
	double sum_Relience = 0;
	for (int i = 21; i >= 19; i--)
	{
		sum_Relience += closingPrice_of_Relience[i];
	}
	// double avg = sum / 3;
	double EMA_of_Relience = sum_Relience / 3;

	return EMA_of_Relience;
}

//Calculating EMA of L&T

double TechnicalAnalysis::calculateEMAOfLAndT()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_LAndT;

	myFile.open("L&T.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_LAndT.push_back(stof(val));

	}
	myFile.close();

	int smoothing = 2;
	double multiplier = 0.0909;

	double EMA_LAndT[2] = { 0 };
	EMA_LAndT[0] = closingPrice_of_LAndT[0];
	int l2 = 1;

	EMA_LAndT[1] = closingPrice_of_LAndT[2] * multiplier + EMA_LAndT[1 - 1] * (1 - multiplier);
	double sum_LAndT = 0;
	for (int i = 20; i >= 18; i--)
	{
		sum_LAndT += closingPrice_of_LAndT[i];
	}
	// double avg = sum / 3;
	double EMA_of_LAndT = sum_LAndT / 3;

	return EMA_of_LAndT;
}


//Calculating EMA of Mahindra & Mahindra

double TechnicalAnalysis::calculateEMAOfMAndM()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_MAndM;

	myFile.open("M&M.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_MAndM.push_back(stof(val));

	}
	myFile.close();

	int smoothing = 2;
	double multiplier = 0.0909;

	double EMA_MAndM[2] = { 0 };
	EMA_MAndM[0] = closingPrice_of_MAndM[0];
	int l2 = 1;

	EMA_MAndM[1] = closingPrice_of_MAndM[2] * multiplier + EMA_MAndM[1 - 1] * (1 - multiplier);
	double sum_MAndM = 0;
	for (int i = 20; i >= 18; i--)
	{
		sum_MAndM += closingPrice_of_MAndM[i];
	}
	// double avg = sum / 3;
	double EMA_of_MAndM = sum_MAndM / 3;

	return EMA_of_MAndM;
}


// Calculating the WMA of Dr Reddy

double TechnicalAnalysis::calculateWMAOfDrReddy()
{
	std::ifstream myFile;
	std::string line;
	std::vector<double> closingPrice;

	myFile.open("DR_Reddy.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice.push_back(stof(val));
	}
	myFile.close();
	
	
	int n = 21;
	int stop = 21;
	double WMA_of_DrReddy = 0;
	double div = (n * (n + 1)) / 2;
	for (int i = stop - 1; i >= 0; i--)
	{

		WMA_of_DrReddy += closingPrice[i] * (n / div);
		n--;
	}

	return WMA_of_DrReddy;
}

// Calculating the WMA of Nifty

double TechnicalAnalysis::calculateWMAOfNifty()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_Nifty;

	myFile.open("Nifty.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Nifty.push_back(stof(val));
	}
	myFile.close();

	int n1 = 21;

	double WMA_of_Nifty = 0;
	int stop1 = 21;
	double div1 = (n1 * (n1 + 1)) / 2;
	for (int i = stop1 - 1; i >= 0; i--)
	{

		WMA_of_Nifty += closingPrice_of_Nifty[i] * (n1 / div1);
		n1--;
	}

	return WMA_of_Nifty;
}

// Calculating the WMA of Relience

double TechnicalAnalysis::calculateWMAOfRel()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_Relience;

	myFile.open("Relience.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_Relience.push_back(stof(val));
	}
	myFile.close();
	int n2 = 21;



	double WMA_of_Relience = 0;
	int stop2 = 22;
	double div2 = (n2 * (n2 + 1)) / 2;
	for (int i = stop2 -1; i >= 1 ; i--)
	{

		WMA_of_Relience += closingPrice_of_Relience[i] * (n2 / div2);
		n2--;
	}

	return WMA_of_Relience;
}

// Calculating the WMA of L&T

double TechnicalAnalysis::calculateWMAOfLAndT()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_LAndT;

	myFile.open("L&T.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_LAndT.push_back(stof(val));
	}
	myFile.close();
	int n2 = 21;



	double WMA_of_LAndT = 0;
	int stop2 = 21;
	double div2 = (n2 * (n2 + 1)) / 2;
	for (int i = stop2 - 1; i >= 1; i--)
	{

		WMA_of_LAndT += closingPrice_of_LAndT[i] * (n2 / div2);
		n2--;
	}

	return WMA_of_LAndT;
}

// Calculating the WMA of Mahindra & Mahindra

double TechnicalAnalysis::calculateWMAOfMAndM()
{
	std::ifstream myFile;
	std::string line;

	std::vector<double> closingPrice_of_MAndM;

	myFile.open("M&M.csv");

	if (!myFile.is_open())
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	while (getline(myFile, line))
	{
		std::string val;
		std::stringstream s(line);

		while (getline(s, val, ','))
			closingPrice_of_MAndM.push_back(stof(val));
	}
	myFile.close();
	int n2 = 21;



	double WMA_of_MAndM = 0;
	int stop2 = 21;
	double div2 = (n2 * (n2 + 1)) / 2;
	for (int i = stop2 - 1; i >= 1; i--)
	{

		WMA_of_MAndM += closingPrice_of_MAndM[i] * (n2 / div2);
		n2--;
	}

	return WMA_of_MAndM;
}


//Generating Signal

void TechnicalAnalysis::signal()
{


	TechnicalAnalysis res;



	int ch;
	while (1)
	{
		//Signal of Hindustanunilever

		std::cout << "1. Dr Reddy :" << std::endl;
		std::cout << "2. Nifty :" << std::endl;
		std::cout << "3. Relience :" << std::endl;
		std::cout << "4. L & T :" << std::endl;
		std::cout << "5. Mahindra & Mahindra :" << std::endl;
		std::cout << "6. Exit :" << std::endl;

		std::cout << "Enter Choise" << std::endl;
		std::cin >> ch;

		switch (ch)
		{
		case 1: double RSI_DrReddy = res.calculateRSIOfDrReddy();
			double EMA_DrReddy = res.calculateEMAOfDrReddy();
			double WMA_DrReddy = res.calculateWMAOfDrReddy();

			std::cout << "RSI OF Dr Reddy : " << RSI_DrReddy << "\n";
			std::cout << "EMA OF Dr Reddy based on RSI : " << EMA_DrReddy << "\n";
			std::cout << "WMA OF Dr Reddy based on RSI : " << WMA_DrReddy << "\n\n";

			if (RSI_DrReddy > WMA_DrReddy)
			{
				std::cout << "********Now you can BUY Share of Dr Reddy********\n\n";
			}
			else if (RSI_DrReddy == WMA_DrReddy)
			{
				std::cout << "********NO Trade, JUST WAIT AND WATCH********\n\n";
			}
			else
			{
				std::cout << "********Now you can SELL Share Dr Reddy******** " << "\n\n";
			}
			break;
		}
		switch (ch)
		{
			//Signal of Nifty

		case 2: double RSI_Nifty = res.calculateRSIOfNifty();
			double EMA_Nifty = res.calculateEMAOfNifty();
			double WMA_Nifty = res.calculateWMAOfNifty();

			std::cout << "RSI OF Nifty : " << RSI_Nifty << "\n";
			std::cout << "EMA OF Nifty based on RSI : " << EMA_Nifty << "\n";
			std::cout << "WMA OF Nifty based on RSI : " << WMA_Nifty << "\n\n";

			if (RSI_Nifty > WMA_Nifty)
			{
				std::cout << "********Now you can BUY Share of Nifty********\n\n";
			}
			else if (RSI_Nifty == WMA_Nifty )
			{
				std::cout << "********NO Trade, JUST WAIT AND WATCH********\n\n";
			}
			else
			{
				std::cout << "********Now you can SELL Share of Nifty******** " << "\n\n";
			}
			break;
		}
		switch (ch)
		{

			//Signal of Relience

		case 3: double RSI_Rel = res.calculateRSIOfRel();
				double EMA_Rel = res.calculateEMAOfRel();
				double WMA_Rel = res.calculateWMAOfRel();

				std::cout << "RSI OF Relience :" << RSI_Rel << "\n";
				std::cout << "EMA OF Relience based on RSI : " << EMA_Rel << "\n";
				std::cout << "WMA OF Relience based on RSI : " << WMA_Rel << "\n\n";

				if (RSI_Rel > WMA_Rel)
				{
					std::cout << "********Now you can BUY Share of Relience********\n\n";
				}
				else if (RSI_Rel == WMA_Rel)
				{
					std::cout << "********NO Trade, JUST WAIT AND WATCH********\n\n";
				}
				else
				{
					std::cout << "********Now you can SELL Share of Relience******** " << "\n\n";
				}
		}

		//Signal of L & T

		switch (ch)
		{

		case 4: double RSI_LAndT = res.calculateRSIOfLAndT();
			double EMA_LAndT = res.calculateEMAOfLAndT();
			double WMA_LAndT = res.calculateWMAOfLAndT();

			std::cout << "RSI OF L & T :" << RSI_LAndT << "\n";
			std::cout << "EMA OF L & T based on RSI : " << EMA_LAndT << "\n";
			std::cout << "WMA OF L & T based on RSI : " << WMA_LAndT << "\n\n";

			if (RSI_LAndT > WMA_LAndT)
			{
				std::cout << "********Now you can BUY Share of L & T********\n\n";
			}
			else if (RSI_LAndT == WMA_LAndT)
			{
				std::cout << "********NO Trade, JUST WAIT AND WATCH********\n\n";
			}
			else
			{
				std::cout << "********Now you can SELL Share of L & T******** " << "\n\n";
			}
		}

		//Signal of M & M

		switch (ch)
		{

		case 5: double RSI_MAndM = res.calculateRSIOfMAndM();
			double EMA_MAndM = res.calculateEMAOfMAndM();
			double WMA_MAndM = res.calculateWMAOfMAndM();

			std::cout << "RSI OF Mahindra & Mahindra :" << RSI_MAndM << "\n";
			std::cout << "EMA OF Mahindra & Mahindra based on RSI : " << EMA_MAndM << "\n";
			std::cout << "WMA OF Mahindra & Mahindra based on RSI : " << WMA_MAndM << "\n\n";

			if (RSI_MAndM > WMA_MAndM)
			{
				std::cout << "********Now you can BUY Share of Mahindra & Mahindra********\n\n";
			}
			else if (RSI_MAndM == WMA_MAndM)
			{
				std::cout << "********NO Trade, JUST WAIT AND WATCH********\n\n";
			}
			else
			{
				std::cout << "********Now you can SELL Share of Mahindra & Mahindra******** " << "\n\n";
			}
		}

		switch (ch)
		{
		case 6: exit(1);
			
		default: std::cout << "Enter the valid Choise :" << std::endl<<std::endl;
		}
	}
}
