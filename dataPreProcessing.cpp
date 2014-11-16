#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;
int main()
{
   ifstream inFile("GPS_fs16_3676E6-if4_1304E6_8bit_Real.bin");
   ofstream outFile("GPS_raw_data2.txt");

   if(!inFile)
   {
      cerr << "can not find the input file.\n";
      return -1;
   }
   if(!outFile)
   {
      cerr << "can not find the output file.\n";
      return -1;
   }

   istream_iterator<char> in_iter(inFile);
   istream_iterator<char> eof;

   ostream_iterator<double> out_iter(outFile,"\n");
   while(in_iter!=eof)
      *out_iter++ = double(*in_iter++);

   inFile.close();
   outFile.close();
   return 0;
}
