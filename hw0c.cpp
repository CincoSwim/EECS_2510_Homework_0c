//Name: Christopher Pucko
//Course: EECS 2510 - Non-Linear Data Structures
//Assignment - Homework 0, Part C

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countDownRuns(int* arrayPtr, int arrayCt){
    //Counts Number of Down Runs in the array passed.
    bool isGreaterOrEqual = false;
    int runCt = 0;
    int i = 0;

    while (i < arrayCt){
        if (arrayPtr[i]>= arrayPtr[i+1] & isGreaterOrEqual == false){
            i++;
            runCt++;
            isGreaterOrEqual = true;
        }
        else if (arrayPtr[i]>= arrayPtr[i+1] & isGreaterOrEqual == true){
            i++;
            isGreaterOrEqual = true;
        }
        else if (arrayPtr[i]< arrayPtr[i+1]){
            i++;
            isGreaterOrEqual = false; //Up run hit, so toggle flag & check next
        }

    }


    return runCt;
}
int countUpRuns(int* arrayPtr, int arrayCt){
    //Counts number of Up runs in the array passed.
    bool isGreaterOrEqual = false;
    int runCt = 0;
    int i = 0;

    while (i < arrayCt){
        if (arrayPtr[i]<= arrayPtr[i+1] & isGreaterOrEqual == false){
            i++;
            runCt++;
            isGreaterOrEqual = true;
        }
        else if (arrayPtr[i]<= arrayPtr[i+1] & isGreaterOrEqual == true){
            i++;
            isGreaterOrEqual = true;
        }
        else if (arrayPtr[i]> arrayPtr[i+1]){
            i++;
            isGreaterOrEqual = false; //Down Run hit, so toggle flag & check next.
        }

    }


    return runCt;
}
int* returnsArrayPointer(){
    //Reads values from .txt file to array, then returns pointer location of array
    static int readArray[100], rdNum;
    string line;
    ifstream numFile;

    numFile.open("testdata.txt");

    if (numFile.is_open()){
        cout << "File opened!" << endl;
        int i = 0;
        while ( getline(numFile, line)){
           rdNum = stoi(line);
           readArray[i] = rdNum;
           i++;
           }
    }
    else cout << "File failed to open." <<endl;

    return readArray;
}

int main() {
    int* arrayPoint;
    int upRunCt, dwnRunCt, arrayCt;
    arrayPoint = returnsArrayPointer();
    arrayCt = 0;

    //Counts elements in array to find "end" of practical array.
    //
    //This accounts for the number of 0 values appended to the end of the large array, preventing miscount
    //of runs.
    //
    //Assumes end of array is at index before a run of three 0 values.
    for (int i = 0; i <= 100; i++ ){
        if (arrayPoint[i] == 0 && arrayPoint[i+1]==0 && arrayPoint[i+2]==0) {    //ArrayList<> will be missed...
            arrayCt = i - 1;
            break;
        }
    }


    cout << "Numbers loaded: " << arrayCt <<endl;
    upRunCt = countUpRuns(arrayPoint, arrayCt);
    dwnRunCt = countDownRuns(arrayPoint, arrayCt);
    cout << "Up Runs Found: " << upRunCt <<endl;
    cout << "Down Runs Found: " << dwnRunCt;

    return EXIT_SUCCESS;
}


