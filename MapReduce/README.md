# MapReduce - Word counts of different lengths

date: 02/24/21
names: Zane Meyer, Kyle Luu, Nathan Kanzelman

Program Purpose:
	The Purpose of our program is to count the number of words that are of length 1 - 20. This information is output in 20 files each representing a length.

Compile Program:
	Our Program can be compiled using the make command when in the command prompt.

Program Function:
	Our program works by first taking a file or files containing various words, and then uses a master program to create a series of mappers and then reducers. The mappers are used to create an output .txt file for every provided file and for each word length. Then the reducers are used to combine the set of multiple files in each word length folder and output a single total wordlength for each.

Assumptions:
	- that no non-ASCII characters are used.
	- the computer running the program has enough memory to handle all the data
	- files aren't opened and edited during any part of the process


