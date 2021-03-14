#ifndef HIBERTCURSE_H
#define HIBERTCURSE_H

/*
��ȡϣ���������߱���˳�򲢱�����������
*/

#include <iostream>
#include <vector>
#include "base.h"
using namespace std;


//����һ������ƶ�����
enum
{
	UP, LEFT, DOWN, RIGHT
};

//class hilbertcurve
class hilbertcurve
{
public:
	int N;//N��
	int n;//n��n��
	int total;
	int tmp = 0;//�ƶ�����
	vector<POINT> table;
	POINT temp_table;
	hilbertcurve(int N);
	void createtable();
	void move(int direction);
	void make_hilbertcurve(int level, int direction = UP);
	void run();
};

#endif //HIBERTCURSE_H
