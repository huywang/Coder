#include "FileParser.h"
void main() {
  Coder::FileParser file_parser(L"data.txt");
  file_parser.Parse();
  return;
}