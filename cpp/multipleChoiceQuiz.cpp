#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int randnum( const int t )
{   return rand() % t + 1;
}

void separator()
{   cout << "\n-------------------------------------\n";
}

void quiz( const int t, const char k[], bool a[], int &c, int &n )
{   char input;

	while( a[n - 1] == true )
       n = randnum( t );

    switch( n )
    {   case 1:
           cout << "\nWhich of the following is not greater than 7/16 ?\n"
              << "\tA.  27/62\n"
              << "\tB.  37/71\n"
              << "\tC.  12/27\n"
              << "\tD.  3/4\n";

           cin >> input;
           if( input == k[0] or input == k[0] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[0] << ".";
           a[0] = true;
           break;

        case 2:
           cout << "\nWhen simplified, | 39 - (17 + 9) - 118 | has a vule of ?\n"
              << "\tA.  -95\n"
              << "\tB.  105\n"
              << "\tC.  -98\n"
              << "\tD.  90\n";

           cin >> input;
           if( input == k[1] or input == k[1] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[1] << ".";
           a[1] = true;
           break;

        case 3:
           cout << "\nIf 2[ 3(x^2 -5) + 5y] = 486 when x = 9, find the value of y\n"
              << "\tA.  -5/2\n"
              << "\tB.  21/8\n"
              << "\tC.  3\n"
              << "\tD.  -9\n";

           cin >> input;
           if( input == k[2] or input == k[2] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[2] << ".";
           a[2] = true;
           break;

        case 4:
           cout << "\nIf the sum of the first two of five consecutive odd integers is 52, "
              << "what is the sum of the last two ?\n"
              << "\tA.  64\n"
              << "\tB.  58\n"
              << "\tC.  62\n"
              << "\tD.  66\n";

           cin >> input;
           if( input == k[3] or input == k[3] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[3] << ".";
           a[3] = true;
           break;

        case 5:
           cout << "\nFreight charges of a certain courier company is as follows:\n"
              << "\n$14.49 for the first 3 pounds"
              << "\n$1.15 for each succeeding quarter pound weight of parcels\n"
              << "\nAt this rate, what is the exact amount charged on a package which weighs 38.7 pounds ?\n"
              << "\tA.  $164.22\n"
              << "\tB.  $183.71\n"
              << "\tC.  $178.71\n"
              << "\tD.  $176.61\n";

           cin >> input;
           if( input == k[4] or input == k[4] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[4] << ".";
           a[4] = true;
           break;

        case 6:
           cout << "\nIf 63/79 < x and 37/42 > x, which of the following could be the value of x ?\n"
              << "\tA.  81/97\n"
              << "\tB.  69/91\n"
              << "\tC.  5/7\n"
              << "\tD.  93/105\n";

           cin >> input;
           if( input == k[5] or input == k[5] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[5] << ".";
           a[5] = true;
           break;

        case 7:
           cout << "\nIf each side of a proportional hexagon is increased by 8/3x units, "
              << "then its perimeter is increased by how many units ?\n"
              << "\tA.  16\n"
              << "\tB.  18\n"
              << "\tC.  44/3\n"
              << "\tD.  50/3\n";

           cin >> input;
           if( input == k[6] or input == k[6] + 32 )
           {   cout << "\nCorrect!";
               c++;
           }
           else
              cout << "\nIncorrect! The correct answer is " << k[6] << ".";
           a[6] = true;
           break;
    }
}

int grade( int c, int q )
{   double g = static_cast<double>( c ) / static_cast<double>( q );
    return g * 100;
}

int main()
{
    cout << "Multiple Choice Quiz!\n" << endl;

    const int total = 7;
    const char key[10] = { 'A', 'B', 'C', 'A', 'C', 'A', 'A' };
    bool answered[6] = {false};

    int correct = 0;
    srand( time(NULL) );
    int number = randnum( total );

	int questions;
    cout << "How many questions would you like to answer? ";
    cin >> questions;
    while( questions < 1 or questions > 7 )
    {   cout << "\nEnter a positive number between 1 and 7: ";
        cin >> questions;
    }

    int i;
    for( i = 1; i <= questions; i++ )
    {   quiz( total, key, answered, correct, number );
        separator();
    }

    cout << "\nYou have completed the quiz. Your grade is " << grade( correct, questions )
       << "%\n" << endl;
    return 0;
}
