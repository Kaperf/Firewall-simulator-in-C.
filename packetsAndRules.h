#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>
// Just basic information about traffic
typedef struct {
char ip_address[16];
int port;
char protocol[8];
}Packet;
// Designed for blocking for example certain port eg. ssh
typedef struct{
char name[16]; //Name for blocking eg. Block SSH
char ip_source[16];
int port;  // -1 for everyone
char protocol[8];
char reason[100]; // if yes just ignore
char isAllowed[10];// Block/Allowed
}Rule;

typedef struct{
Packet packet;
char isAllowed[10]; // IsAllowed
char matched_rule[16]; // What caused the obstruction
char reason[100]; //
}EvaluationResult;

//Two structures to dynamically alocate everyting rather than static
// Functions has to bee implemented such as init_x add_x free
typedef struct{
Packet* data;
int capacity;
int count;
}PacketArray;

typedef struct{
Rule* data;
int capacity;
int count;
}RuleArray;
