#include <iostream>
#include <bitset>
#include <vector>
#include <fstream>
#include "channel.h"


using namespace std;

int main()
{
   ifstream inFile("GPS_raw_data.txt");

   if(!inFile)
   {
      cerr << "the input file does not exist.\n";
      return -1;
   }

   int x;
   while(inFile>>x)
      cout << x << endl;
   /*
   char buffer[1000];

   inFile.read(buffer,1000);

   for(int i = 0; i < 1000; ++i)
   {
      cout <<int(buffer[i]) << " ";
   }
   */


   vector<channel> ch;
   for(int i=0; i<32; ++i)
   {
      channel cur_ch(i+1);
      ch.push_back(cur_ch);
   }
   for(auto i = 0; i<ch.size(); ++i)
   {
      vector<int> prnSeq = ch[i].prnSequence();
      cout << i+1 << ": ";
      for(auto it = prnSeq.begin(); it!=prnSeq.end(); ++it)
      {
         cout << *it;
      }
      cout<<endl<<endl;
   }

  // channel::readData(inFile);
   // channel::dataShown();
   return 0;
}
