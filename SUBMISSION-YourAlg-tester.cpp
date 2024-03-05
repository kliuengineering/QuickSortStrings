#include <iostream>

// i need the string here because it is easier to compare this way
#include <string>

using namespace std;

// quick sort implementation because i used divide and conquer for partitioning
void quickSort(string arr[], int left, int right) 
{
    // lower and upper bounds
    int i = left, j = right;

    // temp variable for Swap() implementation
    string tmp;

    // at the pivot index -> 1/2 * (low + high) 
    string pivot = arr[(left + right) / 2];

    // partition is implemented below here
    while (i <= j) 
    {
        // lower partition 
        while (arr[i] < pivot)
            i++;

        // upper partition
        while (arr[j] > pivot)
            j--;

        // check if the 2 indices meet or not :)
        if (i <= j) 
        {
            // Swap() implementation
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Recursion implementation for the partitions
    if (left < j)
        quickSort(arr, left, j);

    if (i < right)
        quickSort(arr, i, right);
}

void YourAlgorithm(string array[], int size) 
{
    // abstraction -> just like an interface
    quickSort(array, 0, size - 1);
}





string testAlgorithm(string input[], string output[], int size) {
    string passed = "No";
    int noofMatches = 0;

    for (int i = 0; i < size; i++) {
        if (input[i].compare(output[i]) == 0)
            noofMatches = noofMatches;
        else
            noofMatches = noofMatches - 1;
    }

    if (noofMatches == 0)
        passed = "Yes";
    else
        passed = "No";

    return passed;
}

int main() 
{



    string testcase1_input[] = { "Papaya", "Strawberry","Jackfruit",
        "Cranberry","Apricot","Raspberry","Fig" };
    string testcase1_output[] = { "Apricot","Cranberry","Fig" ,"Jackfruit","Papaya",
        "Raspberry","Strawberry" };
    int sizeOfInput1Array = sizeof(testcase1_input) / sizeof(testcase1_input[0]);



    // Call your algorithm here
    YourAlgorithm(testcase1_input, sizeOfInput1Array);
    cout << "Test case 1 : Output" << endl;



    for (int i = 0; i < sizeOfInput1Array; i++) 
    {
        cout << "  " << testcase1_input[i];
    }
    cout << endl << "Passed test case 1: " << testAlgorithm(testcase1_input, testcase1_output, sizeOfInput1Array);



    string testcase2_input[] = { "Plum", "Loganberry","Guava","Apple","Pomegranate","Lemon","Raisin" };
    string testcase2_output[] = { "Apple","Guava", "Lemon","Loganberry","Plum","Pomegranate","Raisin" };
    int sizeOfInput2Array = sizeof(testcase2_input) / sizeof(testcase2_input[0]);



    // Call your algorithm here again
    YourAlgorithm(testcase2_input, sizeOfInput2Array);
    cout << endl << "Test case 2 : Output " << endl;



    for (int i = 0; i < sizeOfInput2Array; i++) 
    {
        cout << "  " << testcase2_input[i];
    }
    cout << endl << "Passed test case 2: " << testAlgorithm(testcase2_input, testcase2_output, sizeOfInput2Array);



    return 0;
}
