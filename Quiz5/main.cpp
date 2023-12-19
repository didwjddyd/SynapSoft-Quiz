/*
* Quiz 5: ���� ����� �̿��� ���� �� �ڿ��� ���� �ּڰ�
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
* ���� ��� ���͸� ��Ģ�� ���� ���� 3���� ����
* 
* ������ ��Ģ
* 1. 0�� zeros ���ͷ� �̵�
* 2. 0�� �ƴ� ���
*	2-1. a�� b�� ���� ������ �ٸ� ���: �� �� ���� ������ ���� ���ͷ� �̵�
*	2-2. a�� b�� ���� ������ ���� ���: �� �� ���� ������ ���� ���ͷ� �̵�
*/
void DivideVector(const vector<int>& original, vector<int>& a, vector<int>& b, vector<int>& zeros)
{
	int sum_a = 0, sum_b = 0;

	for (vector<int>::const_iterator iter = original.begin(); iter != original.end(); ++iter)
	{
		if (*iter == 0) zeros.push_back(*iter); // 0�� zeros ���ͷ� �̵�
		else
		{
			// a�� b�� ���� ������ ���� ���: �� �� ���� ������ ���� ���ͷ� �̵�
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
			else // a�� b�� ���� ������ �ٸ� ���: �� �� ���� ������ ���� ���ͷ� �̵�
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
* �� ���͸� ��Ģ�� ���� ���� 2���� ����
* 
* original ���ʹ� 0�� ���ҷ� ������ ����
* 
* ������ ��Ģ
* 1. a�� b�� ���� ������ �ٸ� ���: �� �� ���� ������ ���� ���ͷ� �̵�
* 2. a�� b�� ���� ������ ���� ���: �� �� ���� ������ ���� ���ͷ� �̵�
*/
void DivideVector(const vector<int>& original, vector<int>& a, vector<int>& b)
{
	int sum_a = 0, sum_b = 0;

	for (vector<int>::const_iterator iter = original.begin(); iter != original.end(); ++iter)
	{
		// a�� b�� ���� ������ ���� ���: �� �� ���� ������ ���� ���ͷ� �̵�
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
		else // a�� b�� ���� ������ �ٸ� ���: �� �� ���� ������ ���� ���ͷ� �̵�
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

// ������ ���� ������ �����ϸ� ������ ��ȯ
int GetNumber(const vector<int>& numbers)
{
	int result = 0;
	int count = 1;

	// ���͸� �������� Ž���Ͽ� �� �ڸ��� �ش��ϴ� 10�� �ŵ������� ���ϰ� ���� ������ ��ȯ
	for (vector<int>::const_reverse_iterator iter = numbers.rbegin(); iter != numbers.rend(); ++iter)
	{
		result += *iter * count;
		count *= 10;
	}

	return result;
}


// ������ ù��° ���Ұ� 0�� ��� ���� �տ� �ִ� 0�� �ƴ� ���ҿ� swap
void MoveZero(vector<int>& numbers)
{
	vector<int>::iterator iter1 = numbers.begin();

	if (*iter1 == 0)
	{
		vector<int>::iterator iter2 = iter1;

		// 0�� �ƴ� �κб��� �ݺ��� �̵�
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

		DivideVector(numbers, a, b, zeros); // ���� ��� ���͸� ��Ģ�� ���� ���� 3���� ����
		DivideVector(zeros, a, b); // ���� ��� ���͸� ��Ģ�� ���� ���� 2���� ����

		// ���� ����
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		// ������ ù��° ���Ұ� 0�� ��� ���� �տ� �ִ� 0�� �ƴ� ���ҿ� swap
		MoveZero(a);
		MoveZero(b);


		// ������ ���� ������ �����ϸ� ������ ��ȯ
		if (GetNumber(a) == 0 || GetNumber(b) == 0)
		{
			// ������ ���Ұ� 0���̶� �ڿ����� ��Ÿ�� �� ���� ��� -1 ���
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