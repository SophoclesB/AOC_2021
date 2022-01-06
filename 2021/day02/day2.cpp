#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

using std::string;
using std::vector;

const string dayTwoInput = "day2.txt";

vector<string> fileInput(string input)
{
	// converts the textfile into a vector of ints
	string temp;
	vector<string> deptharray = {};
	std::ifstream input_file(input);

	while (getline(input_file, temp))
	{
		deptharray.push_back((temp));
	}
	input_file.close();
	return deptharray;
}

int part1(vector<string> input1)
{
	int x = 0;
	int y = 0;
	std::regex forward("forward");
	std::regex up("up");
	std::regex down("down");
	string temp_string;

	for (int i = 0; i < input1.size(); ++i)
	{
		temp_string = input1[i];
		if(std::regex_search(temp_string, forward))
			x += std::stoi(&temp_string.back());
		else if (std::regex_search(temp_string, up))
			y -= std::stoi(&temp_string.back());
		else if (std::regex_search(temp_string, down))
			y += std::stoi(&temp_string.back());
	}

	int result1 = x * y;
	return result1;
}

int part2(vector<string> input2)
{
	int x = 0;
	int y = 0;
	int aim = 0;
	std::regex forward("forward");
	std::regex up("up");
	std::regex down("down");
	string temp_string;

	for(int i = 0; i < input2.size(); ++i)
	{
		temp_string = input2[i];
		if(std::regex_search(temp_string, up))
			aim -= std::stoi(&temp_string.back());
		else if(std::regex_search(temp_string, down))
			aim += std::stoi(&temp_string.back());
		else if(std::regex_search(temp_string, forward))
		{
			x += std::stoi(&temp_string.back());
			y += std::stoi(&temp_string.back()) * aim;
		}
	}

	int result2 = x * y;
	return result2;
}

int main()
{
	vector<string> stringFileInputDay2 = fileInput(dayTwoInput);
	int sol1 = part1(stringFileInputDay2);
	printf("%d\n", sol1);

	int sol2 = part2(stringFileInputDay2);
	printf("%d", sol2);
	return 0;
}