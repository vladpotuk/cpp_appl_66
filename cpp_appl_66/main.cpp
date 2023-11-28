#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    char inputPath[] = "input.txt";
    char outputPath[] = "output.txt";
    char buffer[1000];
    bool lastLineWithoutSpace = false;

    FILE* inputFile = fopen(inputPath, "r");

    if (inputFile == NULL) {
        perror("log");
        return 1;
    }
    else {
       
        while (fgets(buffer, 999, inputFile)) {
            
            if (strchr(buffer, ' ') == NULL) {
                lastLineWithoutSpace = true;
            }
            else {
                lastLineWithoutSpace = false;
            }

            
            fputs(buffer, stdout);
        }

        
        if (lastLineWithoutSpace) {
            cout << "------------" << endl;
        }
        else {
            cout << endl << "------------" << endl;
        }

        fclose(inputFile);

        
        FILE* outputFile = fopen(outputPath, "w");
        if (outputFile == NULL) {
            perror("log");
            return 1;
        }

        inputFile = fopen(inputPath, "r"); 

        while (fgets(buffer, 999, inputFile)) {
            fputs(buffer, outputFile);
        }

       
        if (lastLineWithoutSpace) {
            fputs("------------", outputFile);
        }
        else {
            fputs("\n------------", outputFile);
        }

        fclose(inputFile);
        fclose(outputFile);
    }

    cout << "Операція завершена успішно." << endl;

    return 0;
}
