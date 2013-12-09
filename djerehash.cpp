/********************************************************************
* DjereHash: a simple hashing program.                              *
*********************************************************************
* Author: Rex Djere                                                 *
* Contact rdjere gmail                                              *
* Revision 0.11, 12/08/2013 (see revisions.txt and peerReview.txt)  *
* License: GNU GPL v.3 (see license.txt)                            *
* copyright: Rex Djere, 12/06/2013                                  *
********************************************************************/
// This program take a string (maximum of 256 characters), and coverts it to a 36 character hash.

#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;


int main ()
{
    int i, j, k; // counters
    unsigned int hashBins[256] = {}; // stores user input in bins (bin 1 => 0-256, bin 2 => 257-513 etc. etc.)
    unsigned int binSum = 0;
    char input[256]={};
    const unsigned char charSet[62] =     {'D','y','6','Q','s','1','A','r','P','5','n','C',
                                     'M','2','b','l','f','U','9','t','J','o','w','d',
                                     'Z','k','4','g','O','H','p','X','S','0','c','m',
                                     'B','Y','3','N','e','W','i','8','v','E','L','V',
                                     'G','7','T','x','K','u','R','I','a','z','q','h','F','j'};
    bool Pcontinue = true; // user chooses to continue or quit program

    while (Pcontinue)
    {
        cout << "Enter the string that you would like to hash:" << endl;
        cin.getline(input,256);

        for(i=0;i<256;i++)
        {
            for(j=0; j< 256; j++)
            {
                binSum = binSum + input[j];
            }

            // the main hash function
            hashBins[i] = hashBins[i] + (input[i] * 27) + input[i]%7 + (i+1)%11 + (i+2)%104729 + (i * 256);
            binSum = binSum + hashBins[i];

            if(i%7==0 && i<252)
            {
                cout << charSet[binSum%36]; // 36 character hash output
            }
        }
        cout << endl << "Please enter 1 to hash another string, or 0 to quit:" << " ";
        cin >> Pcontinue; // to do: add detection for erroneous input.
        cin.ignore(Pcontinue); // clear cin to avoid error in cin getline around line 35

        // reset all arrays to zero
        for(k = 0; k < 256; k++)
        {
            input[k]=0;
            hashBins[k]=0;
        }
            binSum = 0; // reset binSum to zero
    }
}
