#include"arraystring.h"

using ds::CArrayString;

int main(void)
{
	CArrayString String0("bcdabaabcef");
	//Test for method 'StrCopy()'
	CArrayString SubStr("abaabc");
	CArrayString NewSubStr("ABCD");
	//Test for assignment operator overriding
//	String0.PrintInfo();
//	String0=String1;
//	String0.PrintInfo();
	//Test for method 'IsStrEmpty()'
//	std::cout<<String0.IsStrEmpty()<<std::endl<<String1.IsStrEmpty()<<std::endl;
	//Test for method 'StrCompare()'
//	std::cout<<String0.StrCompare(String1)<<std::endl;
	//Test for method 'ClearStr()'
//	String0.ClearStr();
//	String0.PrintInfo();
	//Test for plus operator overriding
//	(String0+String1).PrintInfo();
	//Test for method 'SubString()'
//	String0.SubString(10).PrintInfo();
	//Test for method 'IndexStr()'
//	std::cout<<String0.IndexStr(SubStr)<<std::endl<<String0.IndexStr(SubStr,10)<<std::endl;
	//Test for method 'IndexStr_KMP()'
	std::cout<<String0.IndexStr_KMP(SubStr)<<std::endl;
	SubStr.PrintInfo();
	//Test for method 'ReplaceSubStr()'
//	String0.ReplaceSubStr(SubStr,NewSubStr);
//	String0.PrintInfo();

	return 0;
}
