#include "DynAllocatingFunctions.h"
//To minimize declaring them in most of the functions for archiving
#define Logs_FILE "logs.txt"
#define Rules_FILE "rules.txt"
//Opening an file to write to logs or Rules

//To add timestamps on everylog
void getCurrentTime(char buffer[], int size){
time_t now = time(0);
struct tm *timeinfo = localtime(&now);
strftime(buffer,size,"%Y-%m-%d %H:%M:%S",timeinfo);
}


//Saving a rule to log
void rulesToLog(const char* filename,Rule rule){
FILE* outfile;
outfile = fopen(filename,"a");

char timeBuffer[20];
getCurrentTime(timeBuffer,sizeof(timeBuffer));

int flag = fprintf(outfile,
"[%s] Rule: Name: %s, IP: %s, Port: %d, Protocol: %s, Is allowed: %s, Reason: %s\n",
timeBuffer,rule.name,rule.ip_source, rule.port,rule.protocol,rule.isAllowed, rule.reason);

//const char* SuccessfullRuleTransfer = "Rules has been successfully written\n";
const char* UnSuccessfullRuleTransfer = "Error. Log of rules hasn't been successfully written\n";
if(!flag){
fprintf(outfile,"[%s] %s\n",timeBuffer,UnSuccessfullRuleTransfer); 
}
//else{
//fprintf(outfile,"[%s] %s\n",timeBuffer,UnSuccessfullRuleTransfer);  
//}
fclose(outfile);
}


// saving a result to a log
void resultsToLog(const char*filename, EvaluationResult result){
FILE* outfile;
outfile = fopen(filename,"a");
char timeBuffer[20];
getCurrentTime(timeBuffer,sizeof(timeBuffer));
int flag = fprintf(outfile,"[%s] Result: IP: %s, Port: %d, Protocol: %s, Is allowed: %s, Matched rule: %s, Reason: %s\n",timeBuffer,result.packet.ip_address,result.packet.port,result.packet.protocol,result.isAllowed,result.matched_rule,result.reason);
//const char* SuccessfullRuleTransfer = "Result of scanning  has been successfully written\n";
const char* UnSuccessfullRuleTransfer = "Error. Log of result of scanning hasn't been successfully written\n";
if(!flag){ 
fprintf(outfile,"[%s] %s\n",timeBuffer,UnSuccessfullRuleTransfer); 
}
//else{ 
//fprintf(outfile,"[%s] %s\n", timeBuffer,UnSuccessfullRuleTransfer);
//}
fclose(outfile);
}


//Saving a rule to dictionary
void rulesToFile(const char* filename,Rule rule){
FILE* outfile;
outfile = fopen(filename,"a");
int flag = fwrite(&rule,sizeof(rule),1,outfile);
//const char* SuccessfullRuleTransfer = "Rules has been successfully written\n";
const char* UnSuccessfullRuleTransfer = "Error. Saving a rule hasn't been successfully written\n";
if(flag != 1){
printf("%s",UnSuccessfullRuleTransfer);
}
//else{
//printf("%s",UnSuccessfullRuleTransfer);
//}
fclose(outfile);
}


//Saving packets to a log
void packetsToLog(const char*filename, Packet packet){
FILE* outfile;
outfile = fopen(filename,"a");
char timeBuffer[20];
getCurrentTime(timeBuffer,sizeof(timeBuffer));
int flag = fprintf(outfile,"[%s] Packet: IP: %s, Port: %d, Protocol: %s\n",timeBuffer,packet.ip_address,packet.port,packet.protocol);
//const char* SuccessfullRuleTransfer = "Packet has been successfully written\n";
const char* UnSuccessfullRuleTransfer = "Error. Log of packet hasn't been successfully written\n";
if(!flag){ 
fprintf(outfile,"[%s] %s\n",timeBuffer,UnSuccessfullRuleTransfer); 
}
//else{ 
//fprintf(outfile,"[%s] %s\n", timeBuffer,UnSuccessfullRuleTransfer);
//}
fclose(outfile);
}

void logMessage(const char*filename, const char* message){
FILE* outfile;
outfile = fopen(filename,"a");
char timeBuffer[20];
getCurrentTime(timeBuffer,sizeof(timeBuffer));
int flag = fprintf(outfile,"[%s] %s\n", timeBuffer, message);
const char* SuccessfullRuleTransfer = "Message has been successfully written\n";
const char* UnSuccessfullRuleTransfer = "Error. Message hasn't been successfully written\n";
if(flag){ 
fprintf(outfile,"[%s] %s\n",timeBuffer,SuccessfullRuleTransfer);
}
else{ 
fprintf(outfile,"[%s] %s\n", timeBuffer,UnSuccessfullRuleTransfer);
}
fclose(outfile);
}

void to_upper_string(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = toupper((unsigned char)text[i]);
    }
}

void clear_file(const char* filename) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error clearing file\n");
        return;
    }

    fclose(file);
}

void reset_logs() {
    clear_file(Logs_FILE);
    clear_file(Rules_FILE);
}
