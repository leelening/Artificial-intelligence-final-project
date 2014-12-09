#include "stdafx.h"

class inputlayer
{
	

public:
	inputlayer();							// 标准构造函数
	virtual ~inputlayer();


protected:

public:

	int ballx;
	int bally;

	int selfposition;
	int defenseposititon;					// PG = 1
											// SG = 2
											// SF = 3
											// PF = 4
											// C  = 5

	int PGx;
	int PGy;

	int SGx;
	int SGy;

	int SFx;
	int SFy;

	int PFx;
	int PFy;

	int Cx;
	int Cy;


	int holdball;						//  0 not hold the ball
										//	1 hold the ball

	int time;

	int socreattack;

	int scoredefense;

	int tactics;						//	tactics

};


class outlayer
{
public:
	outlayer();
	virtual ~outlayer();

protected:
	

public:
	int peopledestinationx;
	int peopledestinationy;
	int method;
	int balldestinationx;
	int balldestinationy;
};

class neuronsnetwork
{
public:
	inputlayer inputlayer_;
	float weight[10];
	outlayer outlayer_;

protected:


public:
	neuronsnetwork()
	{
		for (int j = 0;j<10;j = j+1)
		{
			weight[j] = 0;
		}
	}						// 构造函数
	virtual ~neuronsnetwork();

	void hidenlayeraddnode(float newweight)
	{
		int index = 0;
		for (int i=0;i<10;i=i+1)
			if (weight[i]!=0)
			{
				index = index + 1;
			}
		if( index < 9)
		{
			weight[index] = newweight;
		}
		else
		{
			MessageBox(NULL,TEXT("erro! the number of hidenlayer should not be more than 10!"),NULL,MB_OK);
			//MessageBox("erro! the number of hidenlayer should not be more than 10");
		}

	}

	void changeweight(float changedweight, int i)
	{
		weight[i] = changedweight;
	}
};


