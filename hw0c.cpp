#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countDownRuns(int* arrayPtr, int arrayCt){
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
            isGreaterOrEqual = false;
        }

    }


    return runCt;
}
int countUpRuns(int* arrayPtr, int arrayCt){
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
            isGreaterOrEqual = false;
        }

    }


    return runCt;
}
int* returnsArrayPointer(){
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

    for (int i = 0; i <= 100; i++ ){
        if (arrayPoint[i] == 0 && arrayPoint[i+1]==0 && arrayPoint[i+2]==0) {
            arrayCt = i - 1;
            break;
        }
    }


    cout << "Elements loaded: " << arrayCt <<endl;
    upRunCt = countUpRuns(arrayPoint, arrayCt);
    dwnRunCt = countDownRuns(arrayPoint, arrayCt);
    cout << "Up Runs Found: " << upRunCt <<endl;
    cout << "Down Runs Found: " << dwnRunCt;

    return EXIT_SUCCESS;
}


