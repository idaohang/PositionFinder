#include <iostream>
#include <bitset>

using namespace std;

int main()
{
   bitset<10> g1_gen(0x3ff);
   bitset<10> g2_gen(0x3ff);
   for(int i=0; i<1023; ++i)
   {
      cout << g1_gen[9] << endl;
      int tmp1 = g1_gen[9]^g1_gen[2];
      g1_gen = g1_gen << 1;
      g1_gen[0] = tmp1;



      cout << g2_gen[9] << endl;
      int tmp2 = g2_gen[9]^g2_gen[2]^g2_gen[1];
      g2_gen = g2_gen << 1;
      g2_gen[0] = tmp2;
   }
   return 0;
}
