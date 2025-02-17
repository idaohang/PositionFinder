#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include "channel.h"


const double channel::fs = 16.3676e6;
const double channel::fo = 4.1304e6;

std::vector<double> channel::raw_data{};


std::vector<double> channel::ifData()
{
   return raw_data;
}

void channel::dataShown() 
{
   for(auto it = raw_data.begin(); it!=raw_data.end(); ++it)
      std::cout << (*it) << " "; 
   std::cout << std::endl;
}


void channel::readData(std::istream& in, size_t n)
{
   raw_data.clear();
   double x;
   while(n!=0)
   {
      in >> x;
      raw_data.push_back(x);
      --n;
   }
}


void channel::prnGen(int sat_num)
{
   std::bitset<10> g1_reg(0x3ff);
   std::bitset<10> g2_reg(0x3ff);
   for(int i = 0; i < 1023; ++i)
   {
      switch(sat_num)
      {
         case 1: prn.push_back(g1_reg[9]^g2_reg[5]^g2_reg[1]); break;
         case 2: prn.push_back(g1_reg[9]^g2_reg[6]^g2_reg[2]); break;
         case 3: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[3]); break;
         case 4: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[4]); break;
         case 5: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[0]); break;
         case 6: prn.push_back(g1_reg[9]^g2_reg[9]^g2_reg[1]); break;
         case 7: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[0]); break;
         case 8: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[1]); break;
         case 9: prn.push_back(g1_reg[9]^g2_reg[9]^g2_reg[2]); break;
         case 10: prn.push_back(g1_reg[9]^g2_reg[2]^g2_reg[1]); break;
         case 11: prn.push_back(g1_reg[9]^g2_reg[3]^g2_reg[2]); break;
         case 12: prn.push_back(g1_reg[9]^g2_reg[5]^g2_reg[4]); break;
         case 13: prn.push_back(g1_reg[9]^g2_reg[6]^g2_reg[5]); break;
         case 14: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[6]); break;
         case 15: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[7]); break;
         case 16: prn.push_back(g1_reg[9]^g2_reg[9]^g2_reg[8]); break;
         case 17: prn.push_back(g1_reg[9]^g2_reg[3]^g2_reg[0]); break;
         case 18: prn.push_back(g1_reg[9]^g2_reg[4]^g2_reg[1]); break;
         case 19: prn.push_back(g1_reg[9]^g2_reg[5]^g2_reg[2]); break;
         case 20: prn.push_back(g1_reg[9]^g2_reg[6]^g2_reg[3]); break;
         case 21: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[4]); break;
         case 22: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[5]); break;
         case 23: prn.push_back(g1_reg[9]^g2_reg[2]^g2_reg[0]); break;
         case 24: prn.push_back(g1_reg[9]^g2_reg[5]^g2_reg[3]); break;
         case 25: prn.push_back(g1_reg[9]^g2_reg[6]^g2_reg[4]); break;
         case 26: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[5]); break;
         case 27: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[6]); break;
         case 28: prn.push_back(g1_reg[9]^g2_reg[9]^g2_reg[7]); break;
         case 29: prn.push_back(g1_reg[9]^g2_reg[5]^g2_reg[0]); break;
         case 30: prn.push_back(g1_reg[9]^g2_reg[6]^g2_reg[1]); break;
         case 31: prn.push_back(g1_reg[9]^g2_reg[7]^g2_reg[2]); break;
         case 32: prn.push_back(g1_reg[9]^g2_reg[8]^g2_reg[3]); break;
         default: break;
      }

      int tmp1 = g1_reg[9]^g1_reg[2];
      int tmp2 = g2_reg[9]^g2_reg[8]^g2_reg[7]^g2_reg[5]^g2_reg[2]^g2_reg[1];
      g1_reg = g1_reg << 1;
      g2_reg = g2_reg << 1;
      g1_reg[0] = tmp1;
      g2_reg[0] = tmp2;
   }
}

