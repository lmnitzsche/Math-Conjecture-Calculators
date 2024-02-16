#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long startingNum;
    system("clear");
    cout << endl << "Enter starting number: ";
    cin >> startingNum;

    while(startingNum < 1)
    {
        cout << endl << "Enter starting number: ";
        cin >> startingNum;
        cout << endl;
    }
    cout << endl << "Path: " << startingNum << ", ";
    long currentNum = startingNum;
    int count = 0;
    int oddCount = 0;
    int evenCount = 0;

    while(currentNum != 1)
    {
        count++;
        if(currentNum % 2 == 1)
        {
            currentNum = (currentNum * 3) + 1;
            oddCount++;
        }
        else
        {
            currentNum = currentNum / 2;
            evenCount++;
        }
        if(currentNum == 1)
        {
            cout << currentNum;
        }
        else
        {
            cout << currentNum << ", ";
        }
        if(count == 1000)
        {
            break;
        }
    }
    cout << endl << endl;
    double probabilityEven = static_cast<double>(evenCount) / count;
    double probabilityOdd = static_cast<double>(oddCount) / count;
    cout << "P(even): " << probabilityEven << endl;
    cout << "P(odd): " << probabilityOdd << endl << endl;
}