#include <iostream>
#include <bitset>
#include <vector>


using namespace std;


vector<int> prnGen(int sat_num)
{
   vector<int> prn_code;
   
   bitset<10> g1_gen(0x3ff);
   bitset<10> g2_gen(0x3ff);
   for(int i=0; i<1023; ++i)
   {
      switch(sat_num)
      {
         case 1:
            prn_code.push_back(g1_gen[9]^g2_gen[5]^g2_gen[1]);
            break;
         case 2:
            prn_code.push_back(g1_gen[9]^g2_gen[6]^g2_gen[2]);
            break;
         case 3:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[3]);
            break;
         case 4:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[4]);
            break;
         case 5:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[0]);
            break;
         case 6:
            prn_code.push_back(g1_gen[9]^g2_gen[9]^g2_gen[1]);
            break;
         case 7:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[0]);
            break;
         case 8:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[1]);
            break;
         case 9:
            prn_code.push_back(g1_gen[9]^g2_gen[9]^g2_gen[2]);
            break;
         case 10:
            prn_code.push_back(g1_gen[9]^g2_gen[2]^g2_gen[1]);
            break;
         case 11:
            prn_code.push_back(g1_gen[9]^g2_gen[3]^g2_gen[2]);
            break;
         case 12:
            prn_code.push_back(g1_gen[9]^g2_gen[5]^g2_gen[4]);
            break;
         case 13:
            prn_code.push_back(g1_gen[9]^g2_gen[6]^g2_gen[5]);
            break;
         case 14:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[6]);
            break;
         case 15:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[7]);
            break;
         case 16:
            prn_code.push_back(g1_gen[9]^g2_gen[9]^g2_gen[8]);
            break;
         case 17:
            prn_code.push_back(g1_gen[9]^g2_gen[3]^g2_gen[0]);
            break;
         case 18:
            prn_code.push_back(g1_gen[9]^g2_gen[4]^g2_gen[1]);
            break;
         case 19:
            prn_code.push_back(g1_gen[9]^g2_gen[5]^g2_gen[2]);
            break;
         case 20:
            prn_code.push_back(g1_gen[9]^g2_gen[6]^g2_gen[3]);
            break;
         case 21:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[4]);
            break;
         case 22:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[5]);
            break;
         case 23:
            prn_code.push_back(g1_gen[9]^g2_gen[2]^g2_gen[0]);
            break;
         case 24:
            prn_code.push_back(g1_gen[9]^g2_gen[5]^g2_gen[3]);
            break;
         case 25:
            prn_code.push_back(g1_gen[9]^g2_gen[6]^g2_gen[4]);
            break;
         case 26:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[5]);
            break;
         case 27:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[6]);
            break;
         case 28:
            prn_code.push_back(g1_gen[9]^g2_gen[9]^g2_gen[7]);
            break;
         case 29:
            prn_code.push_back(g1_gen[9]^g2_gen[5]^g2_gen[0]);
            break;
         case 30:
            prn_code.push_back(g1_gen[9]^g2_gen[6]^g2_gen[1]);
            break;
         case 31:
            prn_code.push_back(g1_gen[9]^g2_gen[7]^g2_gen[2]);
            break;
         case 32:
            prn_code.push_back(g1_gen[9]^g2_gen[8]^g2_gen[3]);
            break;
         default:
            break;
      }

      int tmp1 = g1_gen[9]^g1_gen[2];
      int tmp2 = g2_gen[9]^g2_gen[8]^g2_gen[7]^g2_gen[5]^g2_gen[2]^g2_gen[1];
      g1_gen = g1_gen << 1;
      g2_gen = g2_gen << 1;
      g1_gen[0] = tmp1;
      g2_gen[0] = tmp2;
   }
   return prn_code;
}


int main()
{

   for(int i=1; i<33; ++i)
   {
      cout << i << ": ";
   vector<int> prn = prnGen(i);
   for(auto i = 0; i<10; ++i)
   {
      cout << prn[i];
   }
   cout << endl;
   }
   return 0;
}
