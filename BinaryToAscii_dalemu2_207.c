/*
 *  Daniel Alemu G00884794
 *  CS 262, Lab Section 207
 *  Lab 7  BinaryToAscii
 */

#include<stdio.h>
#include<stdlib.h>

#define LINE_SIZE 40
/* read data from a binary file and save the data to a new file in ASCII format
   obtain the filenames to be read and written from command line parameters. */
int main( int argc, char *argv[])             
{

        FILE *inFile;
        FILE *outFile;
	
        char BineryToAscii[LINE_SIZE];
	double floatNumber;
	int intNumber;
   
        
	inFile = fopen(argv[1], "rb");  // get afile name from comandline then open a file  in read binary mode

        if (inFile == NULL)   // check the given infile name if it is open properly/exist
         {

               printf("Error opening file\n");    //  give error message and exit
               exit(1);
         }

        outFile = fopen(argv[2], "w");  // get a file name from comandline then Open a file  for writing

        if (outFile == NULL)     // Check the given outfile name if it  open correctly/existed
         {
                  printf("Error opening file\n");    // if not give error message and exit
                  exit(1);
         }

 	//read Binary file and write Ascii file  line by line
	for(int i=0;i<30;i++){
         
		/* read 10 floating point numbers from binary file then created and wrote to ASCII file
		 in four decimal places */
		 if(i<10){
                	fread(&floatNumber,sizeof(double),1,inFile);
			fprintf(outFile,"%0.4lf\n",floatNumber);   // 
                }
		
		//read 10 lines of text from binary file then  created and wrote to ASCII file
		if((i>9)&&(i<20)){
			fread(BineryToAscii,sizeof(BineryToAscii),1,inFile);
			 fprintf(outFile,"%s",BineryToAscii);
    		}
		// read 10 integer  numbers from binary file then created and wrote to ASCII file
		if(i>19){
               		 fread(&intNumber,sizeof(int),1,inFile);
			 fprintf(outFile,"%d\n",intNumber);
                }

	}
        fclose(inFile);   // close inFile
        fclose(outFile);  //close outFile
     return 0;
 }


