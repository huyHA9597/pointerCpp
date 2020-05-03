// Pointer tutorial
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// function prototype
double getAverage(int *, int);
void sortArray(int *, int);
int getMode(int*, int);
double getMedian(int*, int);

int main(int argc, char* argv[])
{
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    // validate input using while loop
    while (numStudents <= 0)
    {
        cout << "Please enter a number greater than 0: ";
        cin >> numStudents;
    }

    int *movies = new int[numStudents];

    cout << "Number of movies for\n";
    for (int i =0; i < numStudents; i++)
    {
        cout << "Student " << i+1 << ": ";
        cin >> *(movies + 1);

        // validate
        while (*(movies+1) < 0)
        {
            cout << "Please enter a nonnegative number: ";
            cin >> *(movies+1);
        }
    }

    // sort array
    sortArray(movies, numStudents);

    // display mode
    cout << "\n\n The mode: " << getMode(movies, numStudents);
    cout << "\n\n The median: " << getMedian(movies, numStudents);
    cout << "\n\n The average: " << getAverage(movies, numStudents);

    // delete the dynamically allocated memory
    delete [] movies;

    return 0;
}

void sortArray(int *arr, int SIZE)
{
    int startScan, minIndex;
    int minElem;

    for (startScan = 0; startScan < (SIZE-1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < SIZE; index++)
        {
            if (arr[index] < minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

double getAverage(int *ptr, int arraySize)
{
    // accumulator variable
    int total = 0;

    // loop on all values of array, except from
    // first one
    for (int counter = 0; counter < arraySize; counter++)
    {
        total += *(ptr + counter);
    }

    return (double)total/arraySize;
}

int getMode(int *arr, int numElements)
{
    // keep track of highest number of apperances
    // the index, and the mode
    int maxAppearances = 0, appearances;
    int *mode;

    for (int i =0; i < numElements; i++)
    {
        // first reset number of appearances to 0
        appearances = 0;

        // loop on all elements, to count all appearances
        // of i-th element from its index until end
        for (int j = i; j < numElements; j++)
        {
            if(*(arr+i) == *(arr+j))
                appearances++;
        }

        // after counting total number of appearances for 
        // the i-th elemnet, update mode if necessary
        if (appearances > maxAppearances)
        {
            maxAppearances = appearances;
            mode = arr + i;
        }
    }

    // if maximum numer of appearances is 1
    // there is no mode, return -1
    if (maxAppearances == 1)
        return -1;

    // otherwise, return the mode
    return *mode;
}

double getMedian(int *arr, int numELements)
{
    // first check if odd number of elements
    // then index of middle element number
    // of elements divided by 2
    if (numELements % 2 == 1)
    {
        return *(arr + (numELements/2));
    }
    else
    {
        int mid = numELements / 2;
        double median = (*(arr+mid) + *(arr+mid-1))/2.0;
        return median;
    }
}