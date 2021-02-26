#include "mapreduce.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    //TODO: number of argument check
    if (argc < 4) {
        printf("Error. Not enough arguments supplied. ");
        printf("Needed 4, received %d. Exiting now.\n", argc);
        exit(EXIT_FAILURE);
    }

    int nMappers = strtol(argv[1], NULL, 10);
    int nReducers = strtol(argv[2], NULL, 10);

    inputFileDir = argv[3];
    if(!isValidDir(inputFileDir)) {
        printf("INVALID FILE, exiting now.\n");
        exit(EXIT_FAILURE);
    }

    if (nMappers < nReducers) {
        printf("Error. There should be at least as many mappers as reducers.");
        printf("Mapper amount: %d. Reducer amount: %d.", nMappers, nReducers);
        printf("Exiting now.\n");
        exit(EXIT_FAILURE);
    } else if (nMappers <= 0 || nReducers <= 0) {
        printf("Error. Must have at least 1 mapper and at least 1 reducer.");
        printf("Mapper amount: %d. Reducer amount: %d.", nMappers, nReducers);
        printf("Exiting now.\n");
        exit(EXIT_FAILURE);
    } else if (nMappers > MaxNumProcesses || nReducers > MaxNumProcesses) {
        printf("Error. Must have less than %d mappers and less than %d reducers.", MaxNumProcesses, MaxNumProcesses);
        printf("Mapper amount: %d. Reducer amount: %d.", nMappers, nReducers);
        printf("Exiting now.\n");
    }

    bookeepingCode();

    // TODO: spawn mappers
    pid_t pids[21]; //array containing all the pids
    pids[0] = getpid(); //pid of parent process
    int i;
    for (i = 1; i <= nMappers; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            //turning i into a string called iString to input as mapperID
            int iSize = (i < 10) ? 2 : 3;
            char iString[iSize];
            sprintf(iString, "%d", i);
            //calling execv
            char *args[] = {"./mapper", iString, argv[1], inputFileDir, NULL};
            execv(*args, args);
            printf("Error executing execv()\n");
            exit(0);
        }
        //printf("Mapper Spawned, id %d\n",pids[i]);
    }

    // TODO: wait for all children to complete execution
    for (i = 1; i <= nMappers; i++) {
        pid_t temp = wait(NULL);
        //printf("Mapper finished, id %d\n", temp);
        pids[i] = 0;
    }
    // TODO: spawn reducers
    for (i = 1; i <= nReducers; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            //turning i into a string called iString to input as reducerID
            int iSize = (i < 10) ? 2 : 3;
            char iString[iSize];
            sprintf(iString, "%d", i);
            //calling execv
            char *args[] = {"./reducer", iString, argv[2],
                            "output/IntermediateData", NULL};
            execv(*args, args);
            printf("Error executing execv()\n");
            exit(0);
        }
        //printf("Reducer Spawned, id %d\n",pids[i]);
    }
    // TODO: wait for all children to complete execution
    for (i = 1; i <= nReducers; i++) {
        pid_t temp = wait(NULL);
        //printf("Reducer finished, id %d\n", temp);
        pids[i] = 0;
    }
    return EXIT_SUCCESS;
}
