
//#include<iostream>
//#include<fstream>
//using namespace std;


struct hiddennode//声明一个结构体类型Student
{
	float weight1;
	float weight2;
	float outputweight;
};  //最后有一个分号

class inputlayer
{
public:
	inputlayer();							// 标准构造函数
	~inputlayer(){}
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
	int ownx[1000];
	int owny[1000];


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
	virtual ~outlayer(){}

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
	outlayer outlayer_;
	//int numnodes;
	int inputsize;
	int datasize;
	//float weight[numnodes][inputsize];
	//float outputweight[numnodes];
	hiddennode node[1024];

protected:
	FILE *fp;

public:
	neuronsnetwork();

	virtual ~neuronsnetwork(){}

	char *ReadData(FILE *fp, char *buf);

	void readfile(char *filename);


	void hidenlayeraddnode(float newweight);


	void changeweight(float changedweight, int i);

	void train();

	void scaleinputsize();

	void run();
	


};




//程序的全局变量
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////