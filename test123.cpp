// test123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "A.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int *map11;
	map11 = new int[56];
	int map[56] = {1, 1, 1, 1, 1, 1, 1, 1, 
				   1, 0, 0, 0, 0, 1, 0, 1,
				   1, 0, 0, 0, 0, 1, 0, 1,
				   1, 0, 0, 0, 0, 1, 0, 1,
				   1, 0, 1, 1, 1, 1, 0, 1,
				   1, 0, 0, 0, 0, 0, 0, 1,         
				   1, 1, 1, 1, 1, 1, 1, 1};
	memcpy(map11, map, 56*sizeof(int));

	cout << "��ͼ���£�����Χ������ߣ�" << endl;
	for (int i = 0; i <= 8; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	int k = 1;
	for (int i = 0; i < 7; i++)
	{
		cout << k << ' ';
		for (int j = 0; j < 8; j++)
		{
			cout << map11[i*8+j] << ' ';
		}
		cout << endl;
		k++;
	}
	k = 1;


	cout << "�������������յ����꣬��ʽ���£�" << endl;
	cout << "2 4 7 3" << endl;
	cout << "���������յ����£����Ϊ5���յ�Ϊ3��" << endl;
	map11[(4-1)*8+2-1] = 5;
	map11[(3-1)*8+7-1] = 3;
	for (int i = 0; i <= 8; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << k << ' ';
		for (int j = 0; j < 8; j++)
		{
			cout << map11[i*8+j] << ' ';
		}
		cout << endl;
		k++;
	}
	map11[(4-1)*8+2-1] = 0;
	map11[(3-1)*8+7-1] = 0;
	cout << "�������˾��������������յ�����ɣ�" << endl;

	int sx, sy, ex, ey;
	AStart *astart;
	list<Rect>::iterator iter;

	while (1)
	{
		cin >> sx >> sy >> ex >> ey;

		if ((sx < 1) || (sx > 8) || 
			(sy < 1) || (sy > 7) ||
			(ex < 1) || (ex > 8) ||
			(ey < 1) || (ey > 8))
		{
			cout << "��������겻�ڵ�ͼ�ڣ����������룺" << endl;
			continue;
		}
		if ((map11[(sy-1)*8+sx-1] == 1) || (map11[(ey-1)*8+ex-1] == 1))
		{
			cout << "����������յ�����Ϊ1�����ɴ���������룺" << endl;
			continue;
		}
		astart = new AStart(map11, 8, 7, (sy-1)*8+sx-1, (ey-1)*8+ex-1);
		if (true == astart->Find())
		{
			astart->getResultPath();
			iter = astart->result.begin();
			while (iter != astart->result.end())
			{
				map11[iter->y*8+iter->x] = 7;
				iter++;
			}
			k = 1;
			for (int i = 0; i <= 8; i++)
			{
				cout << i << ' ';
			}
			cout << endl;
			for (int i = 0; i < 7; i++)
			{
				cout << k << ' ';
				for (int j = 0; j < 8; j++)
				{
					cout << map11[i*8+j] << ' ';
				}
				cout << endl;
				k++;
			}
			iter = astart->result.begin();
			while (iter != astart->result.end())
			{
				map11[iter->y*8+iter->x] = 0;
				iter++;
			}
		}
		else
		{
			cout << "No path!" << endl;
		}
	}
	return 0;
}

