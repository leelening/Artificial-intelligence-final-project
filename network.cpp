#include "stdafx.h"
#include "network.h"
#include <iostream>
#include <fstream>

#include <cmath>
#include <string.h>
using namespace std;

#define LINE 1024
#define alpha 0.5


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

//
//char *neuronsnetwork::ReadData(FILE *fp, char *buf)
//{
//	return fgets(buf, LINE, fp);
//}

void neuronsnetwork::readfile(char *filename)
{
//	char buffer[256];  
	fstream outFile;  
	//char *data[][256];
	int i = 0;
	outFile.open(filename,ios::in);
	char a;
	char b;
	char c;
	char d;

	while(!outFile.eof())  
	{  
		outFile>>inputlayer_.examples[i].input1>>a>>inputlayer_.examples[i].input2>>b>>inputlayer_.examples[i].input3>>c>>inputlayer_.examples[i].input4>>d>>inputlayer_.examples[i].output;
		//inputlayer_.examples[i].input1 = inputlayer_.examples[i].input1;
		//inputlayer_.examples[i].input2 = inputlayer_.examples[i].input2;
		i = i + 1;
	}
	datasize = i - 1;

	outFile.close();






	////char *buf,*p;
	////char *data[LINE];
	////int i = 0;
////   if ((fp=fopen("SGdataset","r"))==NULL)
 ////   {
	////	MessageBox(NULL,TEXT("erro!"),NULL,MB_OK);
 ////       exit(0);
 ////   }
	////buf = (char *)malloc(LINE*sizeof(char));
	////p = ReadData(fp, buf);
	////while (p)
	////{
	////	if (buf[0]!='#')
	////	{
	////		data[i] = buf;
	////		i = i + 1;
	////	}
	////	p = ReadData(fp, buf);
	////}
	////fclose(fp);

	//char buffer[256];  
	//fstream outFile;  
	//string data[LINE];
	//int i = 0;
	//outFile.open(filename,ios::in);

	//char buffer[256];  
	//fstream outFile;  
	//CString data[1024];
	//int i = 0;
	//outFile.open(filename,ios::in);
	//while(!outFile.eof())  
	//{  
	//	outFile.getline(buffer,256,'\n');
	//	data[i] = buffer;
	//	i = i + 1;
	//	getchar();
	//}
	//data[0].splitstring();
	////datasize = i - 1;
	//for(int n = 0;n<datasize;n++)
	//{
	//	inputlayer_.examples[n].input1 = data[n][0]-48;
	//	inputlayer_.examples[n].input2 = int(data[n][2])-48;
	//	inputlayer_.examples[n].output = int(data[n][4])-48;
	//}

	////for (int n= 0;n<datasize;n++)
	////{

	////}
	//outFile.close();


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

int neuronsnetwork::lendata(char *filename)
{
	fstream outFile;  
	int i = 0;
	outFile.open(filename,ios::in);

	while(!outFile.eof())  
	{  
		i = i + 1;
	}
	datasize = i - 1;
	return (i - 1);
}


float g(float x)
{
	return (1 / (1 + (exp(-(x)))));
}

float gprime(float x)
{
	return (1 / (2 + (exp(-(x))) + (exp((x)))));
}


void neuronsnetwork::train()
{
	for (int i = 0;i<3;i = i + 1)
	{
		node[i].weight1 = rand()/(RAND_MAX+1.0);
		node[i].weight2 = rand()/(RAND_MAX+1.0);
		node[i].weight3 = rand()/(RAND_MAX+1.0);
		node[i].weight4 = rand()/(RAND_MAX+1.0);

		node[i].outputweight = rand()/(RAND_MAX+1.0);
	}
	float in_ [3];//the size of the hiddenlayer
	float a[4];

	for (int m = 0;m < datasize;m = m + 1)       //# Propagate the inputs forward to compute the outputs
	{
		a[0] = inputlayer_.examples[m].input1;
		a[1] = inputlayer_.examples[m].input2;
		a[2] = inputlayer_.examples[m].input3;
		a[3] = inputlayer_.examples[m].input4;
		float b[3];		
		float suma = 0;
		float deltai[3];
		for(int j = 0;j < 3;j =j + 1)// # for the layer 2
		{
			in_[j] = node[j].weight1 * a[0] + node[j].weight2 * a[1]+ node[j].weight3 * a[2]+ node[j].weight4 * a[3];
			b[j]=in_[j];
		}
		for (int p = 0;p < 3;p = p + 1)
		{
			suma = suma + b[p] * node[p].outputweight;
		}
		float newa = g(suma);
		float deltaj = gprime(suma) * (inputlayer_.examples[m].output - newa);
		for (int k = 0;k < 3;k = k + 1)
			deltai[k]=gprime(in_[k])*(node[k].outputweight * deltaj);
		for (int c = 0;c < 3;c = c + 1)
		{
			node[c].weight1 = node[c].weight1 + alpha * a[0] * deltai[c];	
			node[c].weight2 = node[c].weight2 + alpha *	a[1] * deltai[c];
			node[c].weight3 = node[c].weight3 + alpha *	a[2] * deltai[c];
			node[c].weight4 = node[c].weight4 + alpha *	a[3] * deltai[c];

			node[c].outputweight = node[c].outputweight + b[c] * deltaj;
		}
	}
}

int neuronsnetwork::judge(float number)
{
	if (number <= 0.85)
		return 0 ;
	else
		return 1;

}


int neuronsnetwork::run(int i1,int i2, int i3,int i4)
{
	float a[4];
	float in_[3];
	float b[3];


	float suma = 0;
	a[0] = float(i1);
	a[1] = float(i2);
	a[2] = float(i3);
	a[3] = float(i4);
	//float label = float(inputlayer_.examples[i].output);
	for(int j = 0;j < 3;j++)						//# for the layer 2
	{
		in_[j] = a[0] * node[j].weight1 + a[1] * node[j].weight2 + a[2] * node[j].weight3 + a[3] * node[j].weight4;
		b[j] = g(in_[j]);
	}
	for(int m = 0;m < 3;m++)
	{
		suma = suma + b[m] * node[m].outputweight;
	}
	float newa = g(suma);
	int newlabel = judge (newa);

	for(int i = 0;i<datasize;i++)
	{
		int daf = inputlayer_.examples[i].output;
		if((float(i1) == inputlayer_.examples[i].input1)&&(float(i2) == inputlayer_.examples[i].input2)&&(float( newlabel) != float(inputlayer_.examples[i].output) ))
		{
				error = error + 1;
		}
	}
		

	//switch(newlabel)
	//{
	//case 0:
	//	return 0;// output pass
	//	break;
	//case 1:
	//	return 1;// output shoot
	//	break;
	//default:
	//	return 2;// no action
	//	break;
	return newlabel;
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

