/*
* Quiz 1: '얼른 마스크'씨 회사 전기자동차의 행복한 일련번호
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int> sadNumber; // 슬픈 수 저장

// 1 ~ max 범위에서 행복 수를 구해 갯수와 총합을 출력
void HappyNumber(int max)
{
	int count = 0; // 행복 수 갯수
	int sum = 0; // 행복 수 총합

	for (int i = 0; i < max; ++i)
	{
		int num = i + 1;
		list<int> visited; // 변환 과정에서 거쳐가는 수 기록

		do
		{
			visited.push_back(num); // visited 갱신

			/*
			* 행복 수 판단을 위한 변환 과정:
			* 각 자릿수의 숫자를 계산하기 위해
			* 특정 자릿수일 때의 연산을 조건문으로 분리
			*/
			if (num < 10) // 한자릿수 
			{
				num = num * num;
			}
			else if (num < 100) // 두자릿수 yx
			{
				int x = num % 10;
				int y = num / 10;

				num = x * x + y * y;
			}
			else if (num < 1000) // 세자릿수 zyx
			{
				int x = num % 10;
				int y = (num % 100) / 10;
				int z = num / 100;

				num = x * x + y * y + z * z;
			}
			else if (num < 10000) // 네자릿수 wzyx
			{
				int x = num % 10;
				int y = (num % 100) / 10;
				int z = (num % 1000) / 100;
				int w = num / 1000;

				num = x * x + y * y + z * z + w * w;
			}

		} while (
			/*
			* 반복문 탈출 조건
			* 1. num == 1인 경우: 행복 수 조건 충족
			* 2. sadNumber에 값이 존재하는 경우: 변환 중에 sadNumber의 수가 나올 경우 계산 중단
			* 3. visited의 값과 중복될 경우: 변환값이 순환해 행복 수 조건을 충족하지 않음
			*/
			num != 1 
			&& find(sadNumber.begin(), sadNumber.end(), num) == sadNumber.end()
			&& find(visited.begin(), visited.end(), num) == visited.end()
			);

		if (num == 1) // 행복 수 갯수, 총합 갱신
		{
			count++;
			sum += i + 1;
		}
		else // 슬픈 수 리스트 갱신
		{
			sadNumber.push_back(i + 1);
		}
	}

	// count와 sum을 바탕으로 결과 출력
	cout << "1 ~ " << max << " 범위의 행복 수는 " << count << "개이고 총합은 " << sum << "입니다." << endl;
}

int main()
{
	HappyNumber(9);
	HappyNumber(99);
	HappyNumber(999);
	HappyNumber(9999);

	return 0;
}