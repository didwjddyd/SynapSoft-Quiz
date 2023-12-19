/*
* Quiz 3: Full HD 화면상의 직사각형들이 차지하고 있는 총면적
*/

#include <iostream>
#include <fstream>

using namespace std;

char pixels[1081][1921] = { 0, }; // 화면상의 면적 기록하는 배열

int main()
{
	int result = 0;

	ifstream boxes_txt;

	// boxes.txt 읽어오기
	boxes_txt.open("boxes.txt", ios::in);
	
	if (!boxes_txt) cerr << "Error!" << endl;

	/*
	* boxes.txt에서 좌표를 읽어 배열에 저장하기
	*/
	while (!boxes_txt.eof())
	{
		/*
		* 왼쪽 위: x1, y1
		* 오른쪽 아래: x2, y2
		*/
		int x1, y1, x2, y2;

		boxes_txt >> x1 >> y1 >> x2 >> y2; // 면적 좌표 읽어오기
		
		/*
		* 배열 갱신
		* 
		* 면적에 해당하는 element 값 1 증가
		*/
		for (int i = y1; i < y2; ++i)
		{
			for (int j = x1; j < x2; ++j)
			{
				pixels[i][j]++;
			}
		}
	}

	boxes_txt.close();

	/*
	* 배열 탐색
	* element의 값이 0이 아닌 경우 result 1 증가시킨다.
	*/
	for (int i = 0; i < 1081; ++i)
	{
		for (int j = 0; j < 1921; ++j)
		{
			if (pixels[i][j] > 0) result++;
		}
	}

	cout << result << endl;

	return 0;
}