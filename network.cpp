#include "stdafx.h"
#include "network.h"
#include <iostream>
#include <fstream>
using namespace std;

#define LINE 1024
#define alpha 1


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





inputlayer::inputlayer()
{
}

outlayer::outlayer()
{
}



neuronsnetwork::neuronsnetwork()
{
}


char *neuronsnetwork::ReadData(FILE *fp, char *buf)
{
	return fgets(buf, LINE, fp);
}

void neuronsnetwork::readfile(char *filename)
{
	char buffer[256];  
	fstream outFile;  
	string data[LINE];
	int i = 0;
	outFile.open(filename,ios::in);

	//cout<<"inFile.txt"<<"--- all file is as follows:---"<<endl;  
	while(!outFile.eof())  
	{  
		outFile.getline(buffer,256,'\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束  
		if (buffer[0]!='#')
		{
			data[i] = buffer;
			i = i + 1;
		}
	}
	datasize = i - 1;
	
	
	for (int n= 0;n<datasize;n++)
	{
		int m =0;
		int temp[256];
		for(int j = 0; j<24; j++)
			if(isdigit(data[0][j]))
			{
				temp[m] = int(data[n][j])-48;
				m++;
			}
		inputsize = i -1;
		inputlayer_.ownx[n] = temp[2];
		inputlayer_.owny[n] = temp[3];
	}
	outFile.close();

	

	//char *buf,*p;
	//char *data[LINE];
	//int i = 0;
 //   if ((fp=fopen("SGdataset","r"))==NULL)
 //   {
	//	MessageBox(NULL,TEXT("erro!"),NULL,MB_OK);
 //       exit(0);
 //   }
	//buf = (char *)malloc(LINE*sizeof(char));
	//p = ReadData(fp, buf);
	//while (p)
	//{
	//	if (buf[0]!='#')
	//	{
	//		data[i] = buf;
	//		i = i + 1;
	//	}
	//	p = ReadData(fp, buf);
	//}
	//fclose(fp);
}

void neuronsnetwork::hidenlayeraddnode(float newweight)
{
	//int index = 0;
	//for (int i=0;i<numnodes;i=i+1)
	//	if (weight[i]!=0)
	//	{
	//		index = index + 1;
	//	}
	//if( index < numnodes-1)
	//{
	//	weight[index] = newweight;
	//}
	//else
	//{
	//	MessageBox(NULL,TEXT("erro! the number of hidenlayer should not be more than 10!"),NULL,MB_OK);
	//	MessageBox("erro! the number of hidenlayer should not be more than 10");
	//}

}

void neuronsnetwork::changeweight(float changedweight, int i)
{
	//weight[i] = changedweight;
}

void neuronsnetwork::scaleinputsize()
{

}


float g(float x)
{
	return 0;
}

float gprime(float x)
{
	return 0;
}


void neuronsnetwork::train()
{
	for (int i = 0;i<3;i = i + 1)
	{
		node[i].weight1 = rand()%6;
		node[i].weight2 = rand()%6;
		node[i].outputweight = rand()%6;
	}
	float in_ [3];//the size of the hiddenlayer
	float a[2];

	for (int m = 0;m<datasize;m=m+1)       //# Propagate the inputs forward to compute the outputs
	{
		a[0] = exmaple[m].input1;
		a[1] = example[m].input2;
		float b[3];		
		float suma = 0;
		float deltai[3];
		for(int j = 0;j<3;j=j+1)// # for the layer 2
		{
			in_[j] = node[j].weight1 * a[0] + node[j].weight2 * a[1];
			b[j]=in_[j];
		}
		for (int p = 0;p<3;p=p+1)
		{
			suma = suma + b[p] * node[p].outputweight;
		}
		float newa = g(suma);
		float deltaj = gprime(suma) * (examples[m].value - newa);
		for (int k=0;k<3;k=k+1)
			deltai[k]=gprime(in_[k])*(node[k].outputweight * deltaj);

		for (int c = 0;c<3;c = c + 1)
		{
			node[c].weight1 = node[c].weight1 + alpha * a[0] * deltai[c];
			node[c].weight2 = node[c].weight2 + alpha *	a[1] * deltai[c];
			node[c].outputweight = node[c].outputweight + b[c] * deltaj;
		}
	}
}

int neuronsnetwork::judge(float number)
{
	if (number < 0.5)
		return 0 ;
	else
	{
		return 1;
	}
}


void neuronsnetwork::run()
{
	float a[2];
	float in_[3];
	float b[3];

	for(int i=0;i<len(testdata);i++)
	{
		float suma = 0;
		a[0] = float(testdata[i].x);
		a[1] = float(testdata[i].y);
		float label = float(testdata[i].value);

		for(int j = 0;j < 3;j++)						//# for the layer 2
		{
			in_[j] = a[0] * node[j].weight1 + a[1] * node[j].weight2;
			b[j] = g(in_[j]);
		}
		for(int m;m<3;m++)
		{
			suma = suma + b[m] * node[m].outputweight;
		}
		float newa = g(suma);
		int newlabel = judge (newa);
		switch(newlabel)
		{
		case 0:
			// output pass
			break;
		case 1:
			// output shoot
			break;
		default:
			// no action
			break;
		}
	}
/*
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
	}*/
}
