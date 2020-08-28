#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void countDownRuns();
void countUpRuns();

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
           cout <<"Number Read: " << line << endl;
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


    cout << "Number of array elements: " << arrayCt <<endl;
    upRunCt = (arrayPoint, arrayCt);

    return 0;
}

int countUpRuns(int* arrayPtr, int arrayCt){
    bool isGreaterOrEqual;

    return 0;
}
