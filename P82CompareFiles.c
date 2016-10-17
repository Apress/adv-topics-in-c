// Program P8.2

#include <stdio.h>
#include <string.h>
#define MaxName 20
#define MaxLine 101
int main() {
   char name1[MaxName], name2[MaxName];
   char line1[MaxLine], line2[MaxLine];
   FILE *file1, *file2, *getFileName(char *, char *);
   char *eof1, *eof2;

   int lineNum = 0;
   file1 = getFileName("First file?", name1);
   file2 = getFileName("Second file?", name2);

   while (((eof1 = fgets(line1, MaxLine, file1)) != NULL) &&
            ((eof2 = fgets(line2, MaxLine, file2)) != NULL) &&
            (strcmp (line1, line2) == 0))
      lineNum++;
   // at this stage, linenum is the number of matching lines found
   if (eof1 == NULL) //first file ended
      if (fgets(line2, MaxLine, file2) == NULL) //second also ended
         printf("\nFiles are identical\n\n");
      else    //first file ended, second file not ended
         printf("\n%s, with %d line(s), is a subset of %s\n",
                  name1, lineNum, name2);
   else if (eof2 == NULL)  //first file not ended, second file ended
         printf("\n%s, with %d line(s), is a subset of %s\n",
                  name2, lineNum, name1);
   else {  // mismatch found
      printf("\nThe files differ at line %d\n", ++lineNum);
      printf("The lines are \n%s and \n%s", line1, line2);
   }
   fclose(file1);
   fclose(file2);
} //end main

FILE * getFileName(char *prompt, char *name) {
//store the filename in 'name' and return the pointer to the file
   FILE *filePtr;
   do {
      printf("%s ", prompt); gets(name);
      if ((filePtr = fopen(name, "r")) == NULL)
         printf("File does not exist or access denied\n");
   } while (filePtr == NULL);
   return filePtr;
} //end getFileName
