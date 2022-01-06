#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> measurements;
	int repeat;
	int increases = 0;
	while (cin >> repeat)
	{
		measurements.push_back(repeat);
	}

	for (int i = 0; i < measurements.size()-3; ++i)
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int j = i; j < i+3; ++j)
		{
			sum1 += measurements[j];
			sum2 += measurements[j + 1];
		}

		if (sum1 < sum2)
			++increases;
		else
			continue;
	}
	printf("%d", increases);
	return 0;
}
