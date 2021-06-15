/*
 * Daniel Alemu G00884794
 * CS 262, Lab Section 207
 * Lab 7 AsciiToBinary
*/
#include<stdio.h>
#include<stdlib.h>

#define LINE_SIZE 40

/* read data from an ASCII file and save the data to a new file in a binary format
   obtain the filenames to be read and written from command line */
int main( int argc, char *argv[])
{

        FILE *inFile;
        FILE *outFile;
	
        char AsciiToBinery[LINE_SIZE];
	double floatNumber;
	int intNumber;

        inFile = fopen(argv[1], "r");  // get afile name from comandline then open a file  in read mode


        if (inFile == NULL)   // check the given infile name if it is open properly/exist
         {

                 printf("Error opening file\n");    // if not give error message and exit
                exit(1);
         }

        outFile = fopen(argv[2], "wb+");  // get a file name from comandline then Open a file in writing binary mode  for writing

        if (outFile == NULL)     // Check the given outfile name if it  open correctly/existed
         {
       		  printf("Error opening file\n");    // if not give error message and exit
    		  exit(1);
         }	
	
	// read and write line by line
	for(int i=0;i<30;i++){

		// read 10 floating point numbers from Ascii file then created and wrote to Binary file
		if(i<10){
			
			fgets(AsciiToBinery,LINE_SIZE,inFile);
			sscanf(AsciiToBinery,"%lf",&floatNumber);
			fwrite(&floatNumber,sizeof(double),1,outFile);
              	}

		//read 10 lines of text from Ascii file then  created and wrote to Binary file
		if((i>9)&&(i<20)){
			fgets(AsciiToBinery,LINE_SIZE,inFile);
			fwrite(AsciiToBinery,sizeof(AsciiToBinery),1,outFile);	
		}
		
		// read 10 integer  numbers from Ascii file then created and wrote to Binary  file
		if(i>19){
				
			fgets(AsciiToBinery,LINE_SIZE,inFile);
                        sscanf(AsciiToBinery,"%d",&intNumber);
                        fwrite(&intNumber,sizeof(int),1,outFile);
                }

	}
 
	fclose(inFile);		//close inFile
     	fclose(outFile);	//close outFile
     return 0;
 }

