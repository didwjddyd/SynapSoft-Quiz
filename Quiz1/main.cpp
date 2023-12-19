/*
* Quiz 1: '�� ����ũ'�� ȸ�� �����ڵ����� �ູ�� �Ϸù�ȣ
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int> sadNumber; // ���� �� ����

// 1 ~ max �������� �ູ ���� ���� ������ ������ ���
void HappyNumber(int max)
{
	int count = 0; // �ູ �� ����
	int sum = 0; // �ູ �� ����

	for (int i = 0; i < max; ++i)
	{
		int num = i + 1;
		list<int> visited; // ��ȯ �������� ���İ��� �� ���

		do
		{
			visited.push_back(num); // visited ����

			/*
			* �ູ �� �Ǵ��� ���� ��ȯ ����:
			* �� �ڸ����� ���ڸ� ����ϱ� ����
			* Ư�� �ڸ����� ���� ������ ���ǹ����� �и�
			*/
			if (num < 10) // ���ڸ��� 
			{
				num = num * num;
			}
			else if (num < 100) // ���ڸ��� yx
			{
				int x = num % 10;
				int y = num / 10;

				num = x * x + y * y;
			}
			else if (num < 1000) // ���ڸ��� zyx
			{
				int x = num % 10;
				int y = (num % 100) / 10;
				int z = num / 100;

				num = x * x + y * y + z * z;
			}
			else if (num < 10000) // ���ڸ��� wzyx
			{
				int x = num % 10;
				int y = (num % 100) / 10;
				int z = (num % 1000) / 100;
				int w = num / 1000;

				num = x * x + y * y + z * z + w * w;
			}

		} while (
			/*
			* �ݺ��� Ż�� ����
			* 1. num == 1�� ���: �ູ �� ���� ����
			* 2. sadNumber�� ���� �����ϴ� ���: ��ȯ �߿� sadNumber�� ���� ���� ��� ��� �ߴ�
			* 3. visited�� ���� �ߺ��� ���: ��ȯ���� ��ȯ�� �ູ �� ������ �������� ����
			*/
			num != 1 
			&& find(sadNumber.begin(), sadNumber.end(), num) == sadNumber.end()
			&& find(visited.begin(), visited.end(), num) == visited.end()
			);

		if (num == 1) // �ູ �� ����, ���� ����
		{
			count++;
			sum += i + 1;
		}
		else // ���� �� ����Ʈ ����
		{
			sadNumber.push_back(i + 1);
		}
	}

	// count�� sum�� �������� ��� ���
	cout << "1 ~ " << max << " ������ �ູ ���� " << count << "���̰� ������ " << sum << "�Դϴ�." << endl;
}

int main()
{
	HappyNumber(9);
	HappyNumber(99);
	HappyNumber(999);
	HappyNumber(9999);

	return 0;
}