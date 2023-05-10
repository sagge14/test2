#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ranges>
#include <vector>

std::vector <std::vector <int>> ipAdress;
std::string inFile = "ip_filter.tsv";
std::string line;
std::string stringData;
char check = '.';
int point = 0;
int count = 0;

// function string -> int
int typereplacement(std::string data)
{
	int intData = 0;
	std::stringstream str;
	str << data;
	str >> intData;
	return intData;
}

//function output of the234423333333333333333444444444444444444444444342345343434 result
void outRes(int i)
{
	std::cout << ipAdress[i][0] << "." << ipAdress[i][1] << "." 
		<< ipAdress[i][2] << "." << ipAdress[i][3] << std::endl;
}


int main()
{
    std::ifstream in;
    in.open(inFile);
    std::streambuf* cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    if (in.is_open())
    {
        while (std::getline(std::cin, line))
        {
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == check)
				{
					point++;
				}
			}

			if (point == 3)
			{
				line += ":";
				std::vector<int> vectIp;

				for (int i = 0; i < line.size(); i++)
				{
					if (line[i] != check)
					{
						if (line[i] == ':')
						{
							line.clear();
							int addressBlock = typereplacement(stringData);
							vectIp.push_back(addressBlock);
							stringData.clear();
							break;
						}
						stringData += line[i];
					}
					else
					{
						int addressBlock = typereplacement(stringData);
						vectIp.push_back(addressBlock);
						stringData.clear();
					}
				}

				ipAdress.push_back(vectIp);
				point = 0;
			}
			else
			{
				line.clear();
			}
            count++;
        }
		
		std::ranges::sort(ipAdress, std::ranges::greater());

		for (int i = 0; i < ipAdress.size(); i++)
		{
			outRes(i);
		}

		for (int i = 0; i < ipAdress.size(); i++)
		{
			if (ipAdress[i][0] == 1)
				outRes(i);
		}

		for (int i = 0; i < ipAdress.size(); i++)
		{
			if ((ipAdress[i][0] == 46) && (ipAdress[i][1] == 70))
				outRes(i);
		}

		for (int i = 0; i < ipAdress.size(); i++)
		{
			if ((ipAdress[i][0] == 46) || (ipAdress[i][1] == 46) || (ipAdress[i][2] == 46) || (ipAdress[i][3] == 46))
				outRes(i);
		}
    }
    in.close();
}

