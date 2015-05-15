/*********************************************************************
* DjereHash: a simple hashing program.                               *
**********************************************************************
* Author: Rex Djere                                                  *                                             *
* Revision: 0.23, 05/14/2015 (see revisions.txt)                     *
* License: GNU GPL v.3 (see license.txt)                             *
* Copyright (Origial): Rex Djere, 12/06/2013                         *
* Copyright: Rex Djere, 2013 - Present                               *
*********************************************************************/

// DjereHash take a string (maximum of 256 characters), and converts it to a 256 character hash.
// The final hash is reduced to 37 characters by sampling the full hash.

#include <iostream>
#include <cmath>
#include <string>

int main ()
{
    unsigned int ipSum = 0; // proportional to ASCII sum of all characters input by user
    char input[256]={}; // stores user's input
    bool pContinue = true; // stores user's choice to continue or quit program
    std::string hashString; // stores hash in string instead of array

    hashString.clear(); // clear intialized string values

    // hashModulus samples full 256 character hash and returns 37 characters (256/7 is approximately 37).
    // If a collision is found in future, lengthen hash by lowering value of hashModulus.
    const unsigned int hashModulus = 7;

    // Hash can consist of any character stored in charSet array.
    // For example, DjereHash of "Linux" is DX2UBtq6jZBqLGf5KFZNduDRti3z6yKxiT5th
    const unsigned char charSet[62] = {'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    while (pContinue)
    {
        std::cout << "Enter the string that you would like to hash:" << std::endl;
        std::cin.getline(input,256);

        for(int i=0;i<256;i++)
        {
            for(int j=0; j< 256; j++)
            {
                // You can generate different hashes for same input by changing functions below.
                ipSum = ipSum + (input[j]+1)*pow(j+1,2); // default: ipSum = ipSum + (input[j]+1)*pow(j+1,2);
                ipSum = (ipSum + 1) * log(j+1000); // default: ipSum = (ipSum + 1) * log(j+1000);
            }

            if(i%hashModulus==0) // Default value of hashModulus is 7.
            {
                //std::cout << charSet[ipSum%62]; // generates 1 of the hash characters at a time until full hash is complete
                hashString += charSet[ipSum%62];
            }
        }

        std::cout << hashString << std::endl;
        hashString.clear(); // if you don't clear hash after each round, it will print the current and previous hashes
        std::cout << std::endl << "Please enter 1 to hash another string, or 0 to quit:" << " ";
        std::cin >> pContinue; // to do: add detection for erroneous input.
        std::cin.ignore(pContinue); // clear cin to avoid error in cin getline

        // resets input array to zero to prevent inconsistent hashes
        for(int k = 0; k < 256; k++) input[k]=0;
        ipSum = 0;
    }
    return 0;
}

