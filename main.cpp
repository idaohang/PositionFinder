#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <fstream>
#include "channel.h"
#include <fftw3.h>

using namespace std;

int main()
{
   const double fs =16.3676e6;
   const double fo = 4.1304e6; 
   const double pi = 3.14159; 
   ifstream inFile("GPS_raw_data.txt");
   if(!inFile)
   {
      cerr << "the input file does not exist.\n";
      return -1;
   }

   vector<channel> ch;
   for(int i=0; i<32; ++i)
   {
      channel cur_ch(i+1);
      ch.push_back(cur_ch);
   }

   size_t data_num = 10*16.3676e3;
   cout << "data_num: " << data_num <<endl;
   channel::readData(inFile, data_num);
   channel::dataShown();


   const int N = 163676;
   fftw_complex in[N], out[N];
   vector<double> vec = channel::ifData();
   for(int i = 0; i!=N-1; ++i)
   {
      in[i][0] = vec[i];
      in[i][0] = in[i][0]*sin(2*pi*fs*i/fo);
   }

   fftw_plan p;
   p = fftw_plan_dft_1d(N, in, out,FFTW_FORWARD, FFTW_ESTIMATE);
   fftw_execute(p);
   fftw_destroy_plan(p);

   for(int i = 0; i<N; ++i)
   {
      cout << i << ": " << out[i][0] <<", " << out[i][1] <<endl;
   }
   return 0;
}
