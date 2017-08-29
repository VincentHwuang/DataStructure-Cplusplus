/*
 * filename:arraystring.h
 * created at:2017-08-27
 * author:VincentHwuang
 */

#ifndef ARRAYSTRING_H
#define ARRAYSTRING_H

#include<assert.h>
#include<algorithm>
#include<iostream>	//For debug purpose

using namespace std;

#define MAXSTRLEN 255

namespace ds
{
class CArrayString
{
	protected:
		char String[MAXSTRLEN+1];
		int  Length;
		bool Flag=false;	//For KMP algorithm
		int  Next[MAXSTRLEN];	//For KMP algorithm
		//Method to get 'next_value' of the string
		void GetNext() 
		{
			int i=0;
			int j=-1;
			Next[0]=-1;

			while(i<Length)
			{
				if(j == -1 || String[i] == String[j])
				{
					++i;
					++j;
					Next[i]=j;
				}
				else
				{
					j=Next[j];
				}
			}
			Flag=true;
		}
	public:
		//Constructor function
		CArrayString(const char* InitString)
		{
			//Calculate length of the string
			const char* Tempch=InitString;
			int  Counter=0;
			while(*Tempch != '\0')
			{
				Tempch++;
				Counter++;
			}
			//Check if the length is too long
			assert(Counter <= MAXSTRLEN);

			std::copy(InitString,InitString+Counter+1,String);
			Length=Counter;
		}
		CArrayString() : CArrayString("") {}
		//Destructor function
		~CArrayString() {}
		//Copy constructor function
		CArrayString(const CArrayString &Str)
		{
			CArrayString TempStr;
			TempStr.StrCopy(Str);
			
			*this=TempStr;
		}
		//Method to copy a string
		void StrCopy(const CArrayString &SourceString)
		{
			//Check if the length of source string is too long
			int Length=SourceString.GetLength();
			assert(Length <= MAXSTRLEN);

			std::copy(SourceString.String,SourceString.String+Length+1,String);
			this->Length=Length;
		}
		//Method to implement assignment operator overriding
		void operator=(const CArrayString &SourceString)
		{
			StrCopy(SourceString);
		}
		//Method to judge if the string is empty
		bool IsStrEmpty()
		{
			return (Length == 0)? true:false;
		}
		//Method to get length of the string
		int GetLength() const {return Length;}
		//Method to compare a string with another
		int StrCompare(const CArrayString &StrObj)
		{
			int i=0;
			while(String[i] == StrObj.String[i] && i < (this->Length) && i < (StrObj.Length))
			{
				i++;
			}
			if((i== (this->Length) && i != (StrObj.Length)) || String[i] < StrObj.String[i])
			{
				return -1;
			}
			else if(i == (this->Length) && i == (StrObj.Length))
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		//Method to clear the string
		void ClearStr()
		{
			String[0]='\0';
			Length=0;
		}
		//Method to concatenate two strings by plus operator overriding
		CArrayString& operator+(const CArrayString &StrObj)
		{
			//Check if the total length is too big
			int TotalLength=(this->Length)+(StrObj.Length);
			if(TotalLength > MAXSTRLEN)
			{
				std::cout<<"Sorry,the length is too big!"<<std::endl;
				exit(-1);
			}
			for(int i=0;i<(StrObj.Length+1);i++)
			{
				String[Length+i]=StrObj.String[i];
			}
			Length+=StrObj.Length;

			return *this;
		}
		//Method to obtain substring of a string
		CArrayString SubString(int Len,int Pos=0)
		{
			//Check if the Pos value is valid
			assert(Pos>=0 && Pos<(this->Length) && (Pos+Len)<=(this->Length));
			CArrayString TempStr;
			for(int i=0;i < Len;i++)
			{
				TempStr.String[i]=String[Pos+i];
			}
			TempStr.Length=Len;

			return TempStr;
		}
		//Method to index a substring after specified location
		//if we don't find a string matching the pattern string
		//then return -1.
		int IndexStr(const CArrayString &SubStr,int Pos=0)
		{
			if(SubStr.Length > Length-Pos)
			{
				return -1;
			}
			for(int i=Pos;i < Length;i++)
			{
				int j=0;
				int k=i;
				if((k+SubStr.Length) > Length)
				{
					return -1;
				}
				while(String[k] == SubStr.String[j])
				{
					k++;
					j++;
					if(j == SubStr.Length)
					{
						return i;
					}
				}
			}
			return -1;
		}
		//Method to index a substring using KMP algorithm
		int IndexStr_KMP(CArrayString &SubStr,int Pos=0)
		{
			if(SubStr.Flag == false)
			{
				SubStr.GetNext();
			}
			int i=Pos;
			int j=0;
			while(i < Length && j < SubStr.Length)
			{
				if(j == -1 || String[i] == SubStr.String[j])
				{
					++i;
					++j;
				}
				else
				{
					j=SubStr.Next[j];
				}
			}
			if(j == SubStr.Length)
			{
				return i-SubStr.Length;
			}
			else
			{
				return -1;
			}
		}
		//Method to replace all substrings 
		void ReplaceSubStr(CArrayString &SubStr,const CArrayString &NewSubStr)
		{
//			int i=IndexStr(SubStr);
			int i=IndexStr_KMP(SubStr);	//Using KMP algorithm
			int j=NewSubStr.Length-SubStr.Length;
			while(i != -1)
			{
				std::copy_backward(&String[i+SubStr.Length],&String[Length+1],&String[Length+1+j]);
				for(int k=0;k < (NewSubStr.Length);k++)
				{
					String[i+k]=NewSubStr.String[k];				
				}
				Length+=j;				
//				i=IndexStr(SubStr,i+NewSubStr.Length);				
				i=IndexStr_KMP(SubStr,i+NewSubStr.Length);	//Using KMP algorithm
			}
		}

		//Debug function
		void PrintInfo()
		{
			std::cout<<String<<std::endl<<"Length:"<<Length<<std::endl;
			std::cout<<"Next[]:"<<std::endl;
			for(int i=0;i<Length;i++)
			{
				std::cout<<Next[i]<<std::endl;
			}
		}


};

}

#endif
