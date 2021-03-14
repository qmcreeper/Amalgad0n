#include "hilbertcurve.h"




hilbertcurve::hilbertcurve(int N)
{
	this->N = N;
	n = 1;
	int i = N;
	while (i) {
		n *= 2;
		i--;
	}
	total = n * n;
	temp_table.x = temp_table.y = 0;
}

//�������
void hilbertcurve::createtable()
{
	POINT begin;
	begin.x = 0;
	begin.y = 0;
	table.push_back(begin);
}

//�ƶ�һ��������¼��vector<POINT> table
void hilbertcurve::move(int direction)
{
	switch (direction)
	{
	case UP:         // �����ƶ�
		temp_table.x = temp_table.x - 1;
		break;
	case DOWN:       // �����ƶ�
		temp_table.x = temp_table.x + 1;
		break;
	case LEFT:       // �����ƶ�
		temp_table.y = temp_table.y - 1;
		break;
	case RIGHT:      // �����ƶ�
		temp_table.y = temp_table.y + 1;
		break;
	}
	table.push_back(temp_table);
	tmp++;
}

//�ݹ�ʵ��
void hilbertcurve::make_hilbertcurve(int level, int direction)
{
	if (level == 1)
	{
		switch (direction)
		{
		case LEFT:
			move(RIGHT);
			move(DOWN);
			move(LEFT);
			break;
		case RIGHT:
			move(LEFT);
			move(UP);
			move(RIGHT);
			break;
		case UP:
			move(DOWN);
			move(RIGHT);
			move(UP);
			break;
		case DOWN:
			move(UP);
			move(LEFT);
			move(DOWN);
			break;
		}
	}
	else
	{
		switch (direction) {
		case LEFT:
			make_hilbertcurve(level - 1, UP);
			move(RIGHT);
			make_hilbertcurve(level - 1, LEFT);
			move(DOWN);
			make_hilbertcurve(level - 1, LEFT);
			move(LEFT);
			make_hilbertcurve(level - 1, DOWN);
			break;
		case RIGHT:
			make_hilbertcurve(level - 1, DOWN);
			move(LEFT);
			make_hilbertcurve(level - 1, RIGHT);
			move(UP);
			make_hilbertcurve(level - 1, RIGHT);
			move(RIGHT);
			make_hilbertcurve(level - 1, UP);
			break;
		case UP:
			make_hilbertcurve(level - 1, LEFT);
			move(DOWN);
			make_hilbertcurve(level - 1, UP);
			move(RIGHT);
			make_hilbertcurve(level - 1, UP);
			move(UP);
			make_hilbertcurve(level - 1, RIGHT);
			break;
		case DOWN:
			make_hilbertcurve(level - 1, RIGHT);
			move(UP);
			make_hilbertcurve(level - 1, DOWN);
			move(LEFT);
			make_hilbertcurve(level - 1, DOWN);
			move(DOWN);
			make_hilbertcurve(level - 1, LEFT);
			break;
		}
	}
}

//ִ������
void hilbertcurve::run()
{
	createtable();
	make_hilbertcurve(n, UP);
	for (int i = 0; i < total; ++i){
		cout << '(' << table[i].x << ", " << table[i].y << ")\n";
	}
}
