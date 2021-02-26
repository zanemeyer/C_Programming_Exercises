#include "reducer.h"
#include <math.h>
#include <stdio.h>
#include "utils.h"


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
 * Write final word count to files.
 * The file should be in a corresponding folder in output/FinalData/
 */
void writeFinalDSToFiles(void) {
    for (int i = 1; i <= MaxWordLength; i++) {
				if (finalDS[i-1] != 0) {
		        //concatenate the file name to the file directory
		        int iSize = (i < 9) ? 1 : 2;
		        char numFile[maxFileNameLength];
		        snprintf(numFile, maxFileNameLength, "%s/%d%s", finalDir, i, ".txt");

		        //convert index and value to string
		        //credit to Stack Overflow for advice on how to convert int to string
		        int vSize = (int)(intSize(finalDS[i-1]));
		        char amountValue[iSize + 1 + vSize];
		        sprintf(amountValue, "%d %d", i, finalDS[i-1]);

		        int fd = open(numFile, O_RDWR | O_CREAT | O_APPEND, 0644);
		        ssize_t writeResult = write(fd, amountValue, strlen(amountValue));
		        if (writeResult != strlen(amountValue)) { printf("Writing error!\n"); }
		        int closeResult = close(fd);
		        if (closeResult == -1) { printf("File closing error!\n"); }
				}
    }
}



/**
 * Read lines from files, and calculate a total count for a specific word length
 */
void reduce(char * intermediateFileName) {
	char buf[8] = {0};
    ssize_t bytesRead;
    int fd = open(intermediateFileName,O_RDWR | O_CREAT, 0644);
    lseek(fd, 0, SEEK_SET);
    size_t tt = sizeof(char)*8;

    bytesRead = read(fd, buf, tt);
    close(fd);

    char * temp = strtok(buf, " "); //takes the first element before the space to find word length
    char * temp2;
    char * temp3 = temp;
    while( temp != NULL ) {
        temp2 = temp;
        temp = strtok(NULL, " "); //takes the second element after the space to find number of words
    }

    int wordlen = atoi(temp3);
    int count = atoi(temp2);
    finalDS[wordlen-1] += count;
		close(fd);
}

int main(int argc, char *argv[]) {

		// initialize
		reducerID = strtol(argv[1], NULL, 10);
		int nReducers = strtol(argv[2], NULL, 10);

    //getReducerTasks function returns a list of intermediate file names that this reducer should process
    char *myTasks[MaxNumIntermediateFiles] = {NULL};
    int nTasks = getReducerTasks(nReducers, reducerID, intermediateDir, &myTasks[0]);

    int tIdx;
    for (tIdx = 0; tIdx < nTasks; tIdx++) {
        printf("reducer[%d] - %s\n", reducerID, myTasks[tIdx]);
        reduce(myTasks[tIdx]);
        free(myTasks[tIdx]);
    }

    writeFinalDSToFiles();

	return EXIT_SUCCESS;
}
