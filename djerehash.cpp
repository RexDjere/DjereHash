// DjereHash: a simple 256 bit hashing program.
//  © 2013-Present Rex Djere.
// License: GNU GPL version 3 or later.

#include <iostream>
#include <cmath>
#include <string>

int main ()
{
   unsigned int inputSum = 0;
   unsigned long int variant = 699425794;
   bool userChoosesContinue = true;
   std::string hashInput;
   std::string hashOutput;

   hashInput.clear();
   hashOutput.clear();

   const unsigned int hashModulus = 4; // sets output length to 64 Hex characters (256 bits)
   const unsigned char hashCharacterSet[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

   while (userChoosesContinue)
   {
      std::cout << "Enter the string that you would like to hash:" << std::endl;
      std::getline(std::cin,hashInput);
      for(int i=0;i<256;i++)
      {
         for(unsigned int j=0; j<hashInput.size(); j++)
         {
            // You can generate different hashes for same hashInput by changing functions below.
            // default: inputSum = inputSum + (hashInput[j]+1)*pow(j+1,2);
            inputSum = inputSum + (hashInput[j]+1)*pow(j+1,2);
            inputSum = (inputSum + 1) * log(j+variant); // default: inputSum = (inputSum + 1) * log(j+1000);
         }
         if(i%hashModulus==0)
         {
            hashOutput += hashCharacterSet[inputSum%16];
         }
      }

   std::cout << hashOutput << std::endl;

   hashInput.clear();
   hashOutput.clear();

   std::cout << std::endl << "Please enter 1 to hash another string, or 0 to quit:" << " ";
   std::cin >>    userChoosesContinue;
   std::cin.ignore(userChoosesContinue);

    // resets everything to zero to prevent inconsistent hashes
   for(unsigned int k = 0; k < hashInput.size(); k++) hashInput[k]=0;
   for(unsigned int l = 0; l < hashOutput.size(); l++) hashOutput[l]=0;
   inputSum = 0;
   }
   return 0;
}



