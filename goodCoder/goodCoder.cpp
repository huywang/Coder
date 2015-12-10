// goodCoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileParser.h"


int _tmain(int argc, _TCHAR* argv[])
{
  Coder::FileParser file_parser(L"data.txt");
  file_parser.Parse();
	return 0;
}

