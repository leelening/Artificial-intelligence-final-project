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
	char *data[LINE];
	int i = 0;
	outFile.open(filename,ios::in);  
	//cout<<"inFile.txt"<<"--- all file is as follows:---"<<endl;  
	while(!outFile.eof())  
	{  
		outFile.getline(buffer,256,'\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束  
		if (buffer[0]!='#')
		{
			data[LINE] = buffer;
			i = i + 1;
		}
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

void neuronsnetwork::changeweight(float changedweight, int i)
{
	weight[i] = changedweight;
}

void neuronsnetwork::train()
{
	
}



void neuronsnetwork::run()
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
