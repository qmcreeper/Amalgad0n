#ifndef HIBERTCURSE_H
#define HIBERTCURSE_H

/*
获取希尔伯特曲线遍历顺序并保存至数组中
*/

#include <iostream>
#include <vector>
#include "base.h"
using namespace std;


//向下一个点的移动方向
enum
{
	UP, LEFT, DOWN, RIGHT
};

//class hilbertcurve
class hilbertcurve
{
public:
	int N;//N阶
	int n;//n行n列
	int total;
	int tmp = 0;//移动计数
	vector<POINT> table;
	POINT temp_table;
	hilbertcurve(int N);
	void createtable();
	void move(int direction);
	void make_hilbertcurve(int level, int direction = UP);
	void run();
};

#endif //HIBERTCURSE_H
