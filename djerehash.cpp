/*********************************************************************
* DjereHash: a simple hashing program.                               *
**********************************************************************
* Author: Rex Djere                                                  *
* Contact: rdjere gmail                                              *
* Revision: 0.18, 12/14/2013 (see revisions.txt)                     *
* License: GNU GPL v.3 (see license.txt)                             *
* Copyright: Rex Djere, 12/06/2013                                   *
*********************************************************************/
// This program take a string (maximum of 256 characters), and coverts it to a 37 character hash.

#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;


int main ()
{
    unsigned int ipSum = 0; // stores value proportional to sum of user input
    char input[256]={}; // stores the user input
    const unsigned char charSet[62] = {'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    bool Pcontinue = true; // user chooses to continue or quit program

    while (Pcontinue)
    {
        cout << "Enter the string that you would like to hash:" << endl;
        cin.getline(input,256);

        for(int i=0;i<256;i++)
        {
            for(int j=0; j< 256; j++)
            {
                // hash function is exponential/logarithmic to provide maximum randomness of hash output in O( N^2 ) time.
                ipSum = ipSum + (input[j]+1)*pow(j+1,2);
                ipSum = (ipSum + 1) * log(j+1000);
            }

            if(i%7==0)
            {
                cout << charSet[ipSum%62]; // 36 character hash output
            }
        }
        cout << endl << "Please enter 1 to hash another string, or 0 to quit:" << " ";
        cin >> Pcontinue; // to do: add detection for erroneous input.
        cin.ignore(Pcontinue); // clear cin to avoid error in cin getline around line 35

        // reset input array to zero
        for(int k = 0; k < 256; k++) input[k]=0;
        ipSum = 0;
    }
    return 0;
}

