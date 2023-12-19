/*
* Quiz 5: 숫자 목록을 이용해 만든 두 자연수 합의 최솟값
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 숫자 목록 벡터를 규칙에 따라 벡터 3개로 나눔
* 
* 나누는 규칙
* 1. 0은 zeros 벡터로 이동
* 2. 0이 아닌 경우
*	2-1. a와 b의 원소 갯수가 다른 경우: 둘 중 원소 갯수가 작은 벡터로 이동
*	2-2. a와 b의 원소 갯수가 같은 경우: 둘 중 원소 총합이 작은 벡터로 이동
*/
void DivideVector(const vector<int>& original, vector<int>& a, vector<int>& b, vector<int>& zeros)
{
	int sum_a = 0, sum_b = 0;

	for (vector<int>::const_iterator iter = original.begin(); iter != original.end(); ++iter)
	{
		if (*iter == 0) zeros.push_back(*iter); // 0은 zeros 벡터로 이동
		else
		{
			// a와 b의 원소 갯수가 같은 경우: 둘 중 원소 총합이 작은 벡터로 이동
			if (a.size() == b.size())
			{
				if (sum_a <= sum_b)
				{
					a.push_back(*iter);
					sum_a += *iter;
				}
				else
				{
					b.push_back(*iter);
					sum_b += *iter;
				}
			}
			else // a와 b의 원소 갯수가 다른 경우: 둘 중 원소 갯수가 작은 벡터로 이동
			{
				if (a.size() <= b.size())
				{
					a.push_back(*iter);
					sum_a += *iter;
				}
				else
				{
					b.push_back(*iter);
					sum_b += *iter;
				}
			}
		}
	}
}


/*
* 한 벡터를 규칙에 따라 벡터 2개로 나눔
* 
* original 벡터는 0을 원소로 가지지 않음
* 
* 나누는 규칙
* 1. a와 b의 원소 갯수가 다른 경우: 둘 중 원소 갯수가 작은 벡터로 이동
* 2. a와 b의 원소 갯수가 같은 경우: 둘 중 원소 총합이 작은 벡터로 이동
*/
void DivideVector(const vector<int>& original, vector<int>& a, vector<int>& b)
{
	int sum_a = 0, sum_b = 0;

	for (vector<int>::const_iterator iter = original.begin(); iter != original.end(); ++iter)
	{
		// a와 b의 원소 갯수가 같은 경우: 둘 중 원소 총합이 작은 벡터로 이동
		if (a.size() == b.size())
		{
			if (sum_a <= sum_b)
			{
				a.push_back(*iter);
				sum_a += *iter;
			}
			else
			{
				b.push_back(*iter);
				sum_b += *iter;
			}
		}
		else // a와 b의 원소 갯수가 다른 경우: 둘 중 원소 갯수가 작은 벡터로 이동
		{
			if (a.size() <= b.size())
			{
				a.push_back(*iter);
				sum_a += *iter;
			}
			else
			{
				b.push_back(*iter);
				sum_b += *iter;
			}
		}
	}
}

// 벡터의 원소 순서를 유지하며 정수로 변환
int GetNumber(const vector<int>& numbers)
{
	int result = 0;
	int count = 1;

	// 벡터를 역순으로 탐색하여 각 자리에 해당하는 10의 거듭제곱을 곱하고 더해 정수로 변환
	for (vector<int>::const_reverse_iterator iter = numbers.rbegin(); iter != numbers.rend(); ++iter)
	{
		result += *iter * count;
		count *= 10;
	}

	return result;
}


// 벡터의 첫번째 원소가 0인 경우 제일 앞에 있는 0이 아닌 원소와 swap
void MoveZero(vector<int>& numbers)
{
	vector<int>::iterator iter1 = numbers.begin();

	if (*iter1 == 0)
	{
		vector<int>::iterator iter2 = iter1;

		// 0이 아닌 부분까지 반복자 이동
		while (iter2 != numbers.end() - 1 && *iter2 == 0)
		{
			iter2++;
		}

		// swap
		*iter1 = *iter2;
		
		*iter2 = 0;
	}
}

int main()
{
	ifstream input;
	string line;
	
	input.open("input.txt", ios::in);
	if (!input) cerr << "Error!" << endl;

	while (getline(input, line))
	{
		vector<int> numbers, a, b, zeros;
		int num_a = 0, num_b = 0;

		for (string::const_iterator iter = line.begin(); iter != line.end(); ++iter)
		{
			if(*iter != ' ' && *iter != ',')
			{
				numbers.push_back(*iter - '0');
			}
		}

		sort(numbers.begin(), numbers.end());

		DivideVector(numbers, a, b, zeros); // 숫자 목록 벡터를 규칙에 따라 벡터 3개로 나눔
		DivideVector(zeros, a, b); // 숫자 목록 벡터를 규칙에 따라 벡터 2개로 나눔

		// 벡터 정렬
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		// 벡터의 첫번째 원소가 0인 경우 제일 앞에 있는 0이 아닌 원소와 swap
		MoveZero(a);
		MoveZero(b);


		// 벡터의 원소 순서를 유지하며 정수로 변환
		if (GetNumber(a) == 0 || GetNumber(b) == 0)
		{
			// 벡터의 원소가 0뿐이라 자연수로 나타낼 수 없는 경우 -1 출력
			cout << -1 << endl;
		}
		else
		{
			cout << GetNumber(a) + GetNumber(b) << endl;
		}
	}

	input.close();

	return 0;
}