#ifndef CHANNEL_H
#define CHANNEL_H
#include <bitset>
#include <vector>



class channel
{
   public:
      enum Status{IDLE, ACQUISITION, PULL, TRACKING};
      channel(int chann_num):chann_id{chann_num},state{IDLE}{ prnGen(chann_num); }
      std::vector<int> prnSequence() { return prn; } 
      static void readData(std::istream&, size_t);
      static void dataShown();
      static std::vector<double> ifData();
   private:
      static const double fs;
      static const double fo;
      int chann_id;
      Status state;
      static std::vector<double> raw_data;
      std::vector<int> prn;
      void prnGen(int sat_num);
};
#endif
