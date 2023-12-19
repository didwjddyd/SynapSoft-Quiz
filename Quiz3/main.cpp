/*
* Quiz 3: Full HD ȭ����� ���簢������ �����ϰ� �ִ� �Ѹ���
*/

#include <iostream>
#include <fstream>

using namespace std;

char pixels[1081][1921] = { 0, }; // ȭ����� ���� ����ϴ� �迭

int main()
{
	int result = 0;

	ifstream boxes_txt;

	// boxes.txt �о����
	boxes_txt.open("boxes.txt", ios::in);
	
	if (!boxes_txt) cerr << "Error!" << endl;

	/*
	* boxes.txt���� ��ǥ�� �о� �迭�� �����ϱ�
	*/
	while (!boxes_txt.eof())
	{
		/*
		* ���� ��: x1, y1
		* ������ �Ʒ�: x2, y2
		*/
		int x1, y1, x2, y2;

		boxes_txt >> x1 >> y1 >> x2 >> y2; // ���� ��ǥ �о����
		
		/*
		* �迭 ����
		* 
		* ������ �ش��ϴ� element �� 1 ����
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
	* �迭 Ž��
	* element�� ���� 0�� �ƴ� ��� result 1 ������Ų��.
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