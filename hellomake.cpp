// // C++ program to print all combinations of size
// // k of elements in set 1..n
#include <string>
#include <vector>
#include <iostream>

using namespace std;
 
// void makeCombiUtil(vector<vector<int> >& ans,
//     vector<int>& tmp, int n, int left, int k)
// {
//     // Pushing this vector to a vector of vector
//     if (k == 0) {
//         ans.push_back(tmp);
//         return;
//     }
 
//     // i iterates from left to n. First time
//     // left will be 1
//     for (int i = left; i <= n; ++i)
//     {
//         tmp.push_back(i);
//         makeCombiUtil(ans, tmp, n, i + 1, k - 1);
 
//         // Popping out last inserted element
//         // from the vector
//         tmp.pop_back();
//     }
// }
 
// // Prints all combinations of size k of numbers
// // from 1 to n.
// vector<vector<int> > makeCombi(int n, int k)
// {
//     vector<vector<int> > ans;
//     vector<int> tmp;
//     makeCombiUtil(ans, tmp, n, 1, k);
//     return ans;
// }
 
// // Driver code
// int main()
// {
//     // given number
//     int n = 30;
//     int k = 8;
//     long long int Count = 0;
//     vector<vector<int> > ans = makeCombi(n, k);
//     for (int i = 0; i < ans.size(); i++) {
//         for (int j = 0; j < ans[i].size(); j++) {
//             //cout << ans.at(i).at(j) << " ";
//             Count++;
//         }
//     }
//         cout << "Count = " << Count;
//         cout << endl;
//     return 0;
// }

// Program to print all combination of size r in an array of size n
// #include <stdio.h>
// #include <stdlib.h>
const int RealData_Elements_Size = 56;
int Real_Data[RealData_Elements_Size] = {
2622U, /* Index  0*/
2678U, /* Index  1*/
2719U, /* Index  2*/
2723U, /* Index  3*/
2593U, /* Index  4*/
2713U, /* Index  5*/
2864U, /* Index  6*/
2600U, /* Index  7*/
2673U, /* Index  8*/
2593U, /* Index  9*/
2629U, /* Index 10*/
2707U, /* Index 11*/
2736U, /* Index 12*/
2756U, /* Index 13*/
2784U, /* Index 14*/
2696U, /* Index 15*/
2655U, /* Index 16*/
2772U, /* Index 17*/
2680U, /* Index 18*/
2647U, /* Index 19*/
2675U, /* Index 20*/
2658U, /* Index 21*/
2755U, /* Index 22*/
2603U, /* Index 23*/
2632U, /* Index 24*/
2596U, /* Index 25*/
2645U, /* Index 26*/
2619U, /* Index 27*/
2693U, /* Index 28*/
2700U, /* Index 29*/
2560U, /* Index 30*/
2543U, /* Index 31*/
2695U, /* Index 32*/
2512U, /* Index 33*/
2808U, /* Index 34*/
2678U, /* Index 35*/
2749U, /* Index 36*/
2738U, /* Index 37*/
2680U, /* Index 38*/
2540U, /* Index 39*/
2693U, /* Index 40*/
2607U, /* Index 41*/
2628U, /* Index 42*/
2475U, /* Index 43*/
2689U, /* Index 44*/
2491U, /* Index 45*/
2580U, /* Index 46*/
2597U, /* Index 47*/
2613U, /* Index 48*/
2444U, /* Index 49*/
2629U, /* Index 50*/
2488U, /* Index 51*/
2688U, /* Index 52*/
2725U, /* Index 53*/
2644U, /* Index 54*/
2754U, /* Index 55*/
};  
uint32_t Combination_Index = 0;
const int Elements_Size = 20;
const int CombinationSize = 5;
int Elements[Elements_Size] = {0};



class m_Combination_Sum_Index {
public:
    m_Combination_Sum_Index()
    {
        this->CombinationSum = 0;
        this->CombinationIndex = 0;
    }
    m_Combination_Sum_Index(int CombinationSum, int CombinationIndex)
    {
        this->CombinationSum = CombinationSum;
        this->CombinationIndex = CombinationIndex;
    }
    void CopyData(int CombinationSum, int CombinationIndex)
    {
        this->CombinationSum = CombinationSum;
        this->CombinationIndex = CombinationIndex;       
    }
    uint32_t CombinationIndex;
    uint32_t CombinationSum;
};

 

m_Combination_Sum_Index SumArray[100000];
int SumArrayMaxIndex = 0;

void combinationUtil(int InputArray[], int InputArr_Size, int InputArrayIndex, int Current_Combination_Buffer[], int CombinationSize, int Combination_Buffer_Index); 
// vector<m_Combination_Sum_Index*> AllCombinations;

int Real_Data_Array_Sum(int arr[],int Len)
{
    int Sum = 0;
    for(int i = 0; i < Len; i++)
    {
        Sum += Real_Data[arr[i]];
    }

    return Sum;
}

int Find_In_Array(m_Combination_Sum_Index arr[], int arr_Size, int NumberToFind)
{
    int Index = -1;
    for(int i = 0; (i < arr_Size) && (Index == -1); i++)
        if(NumberToFind == arr[i].CombinationSum)
            Index = i;

    return Index;
}

// Needed for qsort.  See http://w...content-available-to-author-only...s.com/reference/cstdlib/qsort/
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int compare_SumArray (const void * a, const void * b)
{
    return (((m_Combination_Sum_Index*)b)->CombinationIndex - ((m_Combination_Sum_Index*)a)->CombinationIndex);
}

// The main function that prints all combinations of size Combination_Size
// in Elements[] of size Elements_Size. This function mainly uses combinationUtil()
void printCombination(int Elements[], int Elements_Size, int Combination_Size)
{
    // A temporary array to store all combination one by one
    int Current_Combination_Buffer[Combination_Size];
 
    // Sort array to handle duplicates
    // qsort (Elements, Elements_Size, sizeof(int), compare);
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(Elements, Elements_Size, 0, Current_Combination_Buffer, Combination_Size, 0);
}
 
/* InputArray[] --------------> Input Array
   InputArr_Size ------> Size of input array
   CombinationSize ----> Size of a combination to be printed
   Combination_Buffer_Index  ---------> Current index in Current_Combination_Buffer[]
   Current_Combination_Buffer[] -------------> Temporary array to store current combination
   InputArrayIndex  ---> index of current element in InputArray[]     */
void combinationUtil(int InputArray[], int InputArr_Size, int InputArrayIndex, int Current_Combination_Buffer[], int CombinationSize, int Combination_Buffer_Index)
{
    int Sum = 0;
    int Sum_Index = -1;
    // Current combination is ready
    if (Combination_Buffer_Index == CombinationSize)
    {
        // for (int j=0; j<CombinationSize; j++)
        // {
        //     printf("%d ",Current_Combination_Buffer[j]);
        // }
        // printf(" => %d\n",Real_Data_Array_Sum(Current_Combination_Buffer, CombinationSize));
        Sum = Real_Data_Array_Sum(Current_Combination_Buffer, CombinationSize);
        //AllCombinations.push_back(new m_Combination_Sum_Index(0,0));
        Sum_Index = Find_In_Array(SumArray,SumArrayMaxIndex,Sum);

        if(-1 == Sum_Index) {
            if(SumArrayMaxIndex < 100000)
            {
                SumArray[SumArrayMaxIndex].CombinationIndex = 1;
                SumArray[SumArrayMaxIndex].CombinationSum = Sum;
                SumArrayMaxIndex++;
            }
        }
        else {
            SumArray[Sum_Index].CombinationIndex++;
        }

        Combination_Index++;
        return;
    }
 
    // When no more elements are there to be put
    if (InputArrayIndex >= InputArr_Size)
        return;
 
    // current is included, put next at next location
    Current_Combination_Buffer[Combination_Buffer_Index] = InputArray[InputArrayIndex];
    combinationUtil(InputArray, InputArr_Size, InputArrayIndex+1, Current_Combination_Buffer, CombinationSize, Combination_Buffer_Index+1);
 
    // Remove duplicates
    while (InputArray[InputArrayIndex] == InputArray[InputArrayIndex+1])
        InputArrayIndex++;
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(InputArray, InputArr_Size, InputArrayIndex+1, Current_Combination_Buffer, CombinationSize, Combination_Buffer_Index);
}
// Driver program to test above functions
int main()
{
    for(int i = 0; i < Elements_Size; i++)
        Elements[i] = i;

    printCombination(Elements, Elements_Size, CombinationSize);

    printf("Number of combinations = %d\n",Combination_Index);
    printf("Sorting the List\n");

    qsort (SumArray, SumArrayMaxIndex, sizeof(SumArray[0]), compare_SumArray);

    for(int i = 0; i < SumArrayMaxIndex; i++)
    {
        printf("Element %d => CombinationSum = %d, CombinationIndex = %d \n", i, SumArray[i].CombinationSum, SumArray[i].CombinationIndex);
    }

    

    return 0;
}