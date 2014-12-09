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

	void train()
	{
	
	}



	void run()
	{


		if (inputlayer_.holdball == 1)
		{
			nextballpositionx = outlayer_.balldestinationx;
			nextballpositiony = outlayer_.balldestinationy;
			nextmethod = outlayer_.method;
			switch (inputlayer_.selfposition)
			{
			case 1:
				{
				PGnextx = outlayer_.peopledestinationx;
				PGnexty = outlayer_.peopledestinationy;
				break;
				}
			case 2:
				{
				SGnextx = outlayer_.peopledestinationx;
				SGnexty = outlayer_.peopledestinationy;
				break;
				}
			case 3:
				{
				SFnextx = outlayer_.peopledestinationx;
				SFnexty = outlayer_.peopledestinationy;
				break;
				}
			case 4:
				{
				PFnextx = outlayer_.peopledestinationx;
				PFnexty = outlayer_.peopledestinationy;
				break;
				}
			case 5:
				{
				Cnextx = outlayer_.peopledestinationx;
				Cnexty = outlayer_.peopledestinationy;
				break;
				}
			default:
				break;
			}
		}
	}

};




//程序的全局变量
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
neuronsnetwork PGmind;
neuronsnetwork SGmind;
neuronsnetwork SFmind;
neuronsnetwork PFmind;
neuronsnetwork Cmind;

int PGnextx;
int PGnexty;
int SGnextx;
int SGnexty;
int SFnextx;
int SFnexty;
int PFnextx;
int PFnexty;
int Cnextx;
int Cnexty;

int nextmethod;

int nextballpositionx;
int nextballpositiony;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////