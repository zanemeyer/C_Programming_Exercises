#include "mapper.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

/**
 * Returns the amount of digits in x (includes possible negative signs)
 */
int intSize(int x) {
    int count = 10;
    int size = 1;
    int absX = (x < 0) ? x * -1 : x;
    while (x < count) {
        count *= 10;
        size++;
    }
    return (x < 0) ? size + 1 : size;
}

/**
 * Write word count that is stored in a intermediate data structure to files.
 * The file should be in a corresponding folder in output/IntermediateData/
 */
void writeInterDSToFiles(void) {

    for (int i = 1; i <= MaxWordLength; i++) {
        //concatenate the file name to the file directory
        int iSize = (i < 9) ? 1 : 2;
        char numFile[maxFileNameLength];
        snprintf(numFile, maxFileNameLength, "%s/%d/m%d.txt", intermediateDir, i, mapperID);

        //convert index and value to string
        //credit to Stack Overflow for advice on how to convert int to string
        int vSize = (int)(intSize(interDS[i-1]));
        char amountValue[iSize + 1 + vSize];
        sprintf(amountValue, "%d %d", i, interDS[i-1]);

        int fd = open(numFile, O_RDWR | O_CREAT | O_APPEND, 0644);
        ssize_t writeResult = write(fd, amountValue, strlen(amountValue));
        if (writeResult != strlen(amountValue)) { printf("Writing error!\n"); }
        int closeResult = close(fd);
        if (closeResult == -1) { printf("File closing error!\n"); }
    }

}

/**
 * Read lines from files, and count words by word length
 */
void map(char * inputFileName) {
    int fd = open(inputFileName, O_RDWR);
    ssize_t bytesRead;

    //code works by reading 20 characters at a time, determining if the
    //starting bunch of characters form a word, and if it does, increasing
    //the corresponding word length counter by 1 and moving the offset.

    do {
    off_t temp = lseek(fd, 0, SEEK_CUR);
    char buf[MaxWordLength] = "";
    bytesRead = read(fd, buf, MaxWordLength);
    for (int i = 0; i <= bytesRead; i++) {
    int isWhiteSpace = buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t';
        if (isWhiteSpace || i == bytesRead) {
            if (i != 0) {
                interDS[i-1] += 1;
            }
            lseek(fd, temp + i+1, SEEK_SET);
            break;
        }
    }
  } while (bytesRead != 0);

    close(fd);
}

int main(int argc, char *argv[]) {

    mapperID = strtol(argv[1], NULL, 10);
    int nMappers = strtol(argv[2], NULL, 10);
    inputFileDir = argv[3];

    //getMapperTasks function returns a list of input file names that this mapper should process
    char *myTasks[MaxNumInputFiles] = {NULL};
    int nTasks = getMapperTasks(nMappers, mapperID, inputFileDir, &myTasks[0]);

    int tIdx;
    for (tIdx = 0; tIdx < nTasks; tIdx++) {
        printf("mapper[%d] - %s\n", mapperID, myTasks[tIdx]);
        map(myTasks[tIdx]);
        free(myTasks[tIdx]);
    }

    writeInterDSToFiles();

    return EXIT_SUCCESS;
}
