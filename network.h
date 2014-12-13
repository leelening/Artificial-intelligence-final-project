
//#include<iostream>
//#include<fstream>
//using namespace std;


struct hiddennode//����һ���ṹ������Student
{
	float weight1;
	float weight2;
	float weight3;
	float weight4;
	float outputweight;
};  //�����һ���ֺ�

struct example
{
	float input1;
	float input2;
	float input3;
	float input4;
	int output;
};


class inputlayer
{
	

public:
	inputlayer();							// ��׼���캯��
	~inputlayer(){}


protected:

public:


	example examples[1024];

	int ballx;
	int bally;
	int selfposition;
	int defenseposititon;					// PG = 1
											// SG = 2
											// SF = 3
											// PF = 4
											// C  = 5
	int ownx;
	int owny;


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
	//int inputsize;
	int datasize;
	//float weight[numnodes][inputsize];
	//float outputweight[numnodes];
	hiddennode node[3];

protected:
	//FILE *fp;

public:
	neuronsnetwork();

	virtual ~neuronsnetwork(){}

	//char *ReadData(FILE *fp, char *buf);

	void readfile(char *filename);


	void hidenlayeraddnode(float newweight);

	int judge(float number);


	void changeweight(float changedweight, int i);

	void train();

	int lendata(char *filename);

	int run(int i1,int i2, int i3, int i4);
	


};




//�����ȫ�ֱ���
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////