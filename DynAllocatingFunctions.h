#include "comparisionFunctions.h"

//Dynamically functions for Rules
void init_rules(RuleArray *arr){
arr->count =0;
arr->capacity =100;
arr->data = malloc(sizeof(Rule)*arr->capacity);
}

void add_rule(RuleArray *arr, Rule rule){
if(arr->capacity == arr->count){
arr->capacity*=2;
arr->data= realloc(arr->data,sizeof(Rule) * arr->capacity);
}
arr->data[arr->count] = rule;
arr->count++;
}

void free_rules(RuleArray *arr){
free(arr->data);
arr->data = NULL;
arr->count = 0;
arr->capacity = 0;
}
//Dynamically functions for packets
void init_packets(PacketArray *arr){
arr->count =0;
arr->capacity =100;
arr->data = malloc(sizeof(Packet)*arr->capacity);
}

void add_packet(PacketArray *arr, Packet packet){ 
if(arr->capacity == arr->count){ 
arr->capacity*=2;
arr->data = realloc(arr->data, sizeof(Packet) * arr->capacity);
}
arr->data[arr->count] = packet;
arr->count++;
}

void free_packets(PacketArray *arr){
free(arr->data);
arr->data = NULL;
arr->count = 0;
arr->capacity = 0;
}
