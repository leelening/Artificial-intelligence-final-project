#include "stdafx.h"
#include "network.h"
#include <iostream>
#include <fstream>
using namespace std;

#define LINE 1024
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
	//for (int i = 0;i<numnodes;i = i + 1)
	//	for( int q = 0;q<inputsize;q = q +1)
	//		{weight[i][q] = rand()%6;}

	//float in_ [numnodes];
	//float a[inputsize];

	//for (int m = 0;m<datasize;m=m+1)       //# Propagate the inputs forward to compute the outputs
	//{
	//	for(int z = 0;z<inputsize;z=z+1)
	//	{
	//		a[z] = input[z];
	//	}		
	//	float b[numnodes];
	//	float suma = 0;
	//	float deltai = [numnodes];
	//	for(int j = 0;j<numnodes;j=j+1)// # for the layer 2
	//	{
	//		in_[j ]= 0;
	//		for (int k = 0;k<inputsize;k=k+1)
	//			{
	//				in_[j] = in_[j] + weight[j][k] * a[k];
	//			}
	//		b[j]=in_[j];
	//		
	//	for (int p = 0;p<numnodes;p=p+1)
	//	{
	//		suma = suma + b[p] * outoutweight[p]
	//	}
	//	float newa = g(suma);
	//	float deltaj = gprime(suma) * (examples[m].value - newa);
	//	for (int k=0;k<numnodes;k=k+1)
	//		deltai[k]=gprime(in_[k])*(weight[k].weightOutput * deltaj);

	//	for (int c = 0;c<numnodes;c = c + 1)
	//	{
	//		for (int b = 0;c<inputsize;b = b+1)
	//		network.hidden[c].weightX = network.hidden[c].weightX + alpha * a[0] * deltai[c];
	//		network.hidden[c].weightY = network.hidden[c].weightY + alpha *	a[1] * deltai[c];
	//		outputweight[c] = outputweight[c] + b[c] * deltaj;
	//	}
	//}
}



void neuronsnetwork::run()
{
	//a = [None] * 2
	//in_ = [None] * (len(network.hidden))
	//b = [None] * (len(network.hidden))
	//error = 0
	//for i in range(len(testdata)):
	//	suma = 0
	//	a[0] = float(testdata[i].x)
	//	a[1] = float(testdata[i].y)
	//	label = float(testdata[i].value)
	//	for j in range(len(network.hidden)): # for the layer 2
	//		in_[j] = a[0] * network.hidden[j].weightX + a[1] * network.hidden[j].weightY
	//		b[j] = g(in_[j])
	//	for m in range(len(b)): # for the layer 3
	//		suma = suma + b[m] * network.hidden[m].weightOutput
	//	newa = g(suma)
	//	newlabel = judge (newa)
	//	if newlabel != label:
	//		error = error + 1
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
