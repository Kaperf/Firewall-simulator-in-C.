#include "dataGenerator.h"
//counting allowed packets
int count_allowed(const char* filename){
FILE*outfile;
outfile = fopen(filename,"r");
char line[512];
int count = 0;
while(fgets(line,sizeof(line), outfile) != NULL)
{
if(strstr(line, "Result") != NULL && strstr(line,"Allow") !=NULL) count++;
}// strstr is comparing every line of a word packet and allowed  if match then  counting
fclose(outfile);
return count;
}
int count_blocked(const char*filename){
FILE*outfile;
outfile = fopen(filename, "r");
char line[512];
int count = 0;
while (fgets(line,sizeof(line), outfile) !=NULL)
{
if(strstr(line,"Result") != NULL && strstr(line, "Block") != NULL) count++;
}
fclose(outfile);
logMessage(Logs_FILE,"Counting of blocked packets has been done");
return count;
}
void summary(const char* filename){
int allowed = count_allowed(filename);
int blocked = count_blocked(filename);
printf("Number of allowed packets: %d.\n Number of blocked packets: %d.\n",allowed,blocked);
}
