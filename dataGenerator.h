#include "Firewall.h"

//Generating  default rules, returning number of added rules
int add_default_rules(RuleArray* rules){
int NumberBeforeImplementation = rules->count;
Rule rule;
//1. Block SSH - TCP 22
strcpy(rule.name,"Block SSH");
strcpy(rule.ip_source,"*");
rule.port = 22;
strcpy(rule.protocol, "TCP");
strcpy(rule.reason, "SSH traffic is blocked");
strcpy(rule.isAllowed,"Block");
add_rule(rules, rule);
//2. Allow HTTP - TCP 80
strcpy(rule.name,"Allow HTTP");
strcpy(rule.ip_source,"*");
rule.port = 80;
strcpy(rule.protocol, "TCP");
strcpy(rule.reason, "HTTP traffic is allowed");
strcpy(rule.isAllowed,"Allow");
add_rule(rules, rule);
//3. Allow HTTPS - TCP 443
strcpy(rule.name,"Allow HTTPS");
strcpy(rule.ip_source,"*");
rule.port = 443;
strcpy(rule.protocol, "TCP");
strcpy(rule.reason, "HTTPS traffic is allowed");
strcpy(rule.isAllowed,"Allow");
add_rule(rules, rule);
//4. Block MySQL - TCP 3306
strcpy(rule.name,"Block MySQL");
strcpy(rule.ip_source,"*");
rule.port = 3306;
strcpy(rule.protocol, "TCP");
strcpy(rule.reason, "MySQL traffic is blocked");
strcpy(rule.isAllowed,"Block");
add_rule(rules, rule);
//5. Block all UDP
strcpy(rule.name,"Block all UDP");
strcpy(rule.ip_source,"*");
rule.port = -1;
strcpy(rule.protocol, "UDP");
strcpy(rule.reason, "UDP traffic is blocked");
strcpy(rule.isAllowed,"Block");
add_rule(rules, rule);
for(int i=NumberBeforeImplementation; i<rules->count;i++){
rulesToLog(Logs_FILE,rules->data[i]);
rulesToFile(Rules_FILE, rules->data[i]);
}
NumberBeforeImplementation = rules->count - NumberBeforeImplementation;
return NumberBeforeImplementation;
}
// Generating default packets, returning number of them
int add_default_packets(PacketArray* packets){
//checking for duplicates
Packet packet;
int NumberBeforeImplementation = packets->count;
//
strcpy(packet.ip_address, "192.168.1.10");
packet.port = 22;
strcpy(packet.protocol,"TCP");
add_packet(packets,packet);
packetsToLog(Logs_FILE,packet);

//
strcpy(packet.ip_address, "8.8.8.8");
packet.port = 80;
strcpy(packet.protocol,"TCP");
add_packet(packets,packet);
packetsToLog(Logs_FILE,packet);

//
strcpy(packet.ip_address, "10.0.0.5");
packet.port = 53;
strcpy(packet.protocol,"UDP");
add_packet(packets,packet);
packetsToLog(Logs_FILE,packet);

//
strcpy(packet.ip_address, "172.16.0.3");
packet.port = 53;
strcpy(packet.protocol,"UDP");
add_packet(packets,packet);
packetsToLog(Logs_FILE,packet);

//
strcpy(packet.ip_address, "1.1.1.1");
packet.port = 443;
strcpy(packet.protocol,"TCP");
add_packet(packets,packet);
packetsToLog(Logs_FILE,packet);
NumberBeforeImplementation = packets->count - NumberBeforeImplementation;
return NumberBeforeImplementation;
}

//Using to  allow program works both on windows and linux
void init_random(){
srand(time(NULL));
}//Pamietaj zeby to zaimplementowac w kodzie!!
int generate_random_number(int a){
return  rand()%a;
}

// Genearting random number
Packet generate_random_packet(){
Packet packet;
//Generating random ip address
uint32_t ul_dst;
ul_dst = ((uint32_t)(rand()%256) <<24) |
	((uint32_t)(rand()%256) <<16) | 
	((uint32_t)(rand()%256) <<8) |
	((uint32_t)(rand()%256));
//Where << is just moving bits to the left so we can achive A.B.C.D
sprintf(packet.ip_address,"%u.%u.%u.%u",
	(ul_dst >> 24) & 0xFF, 
	(ul_dst >> 16) & 0xFF, 
	(ul_dst >> 8) & 0xFF,
	ul_dst & 0xFF);
// We are doing AND operation to just get one byte
//Random port
packet.port = generate_random_number(25556);
//Random Protocol
const char* Dictionary[] = {"UDP","TCP"};
int b = rand()%2;
strcpy(packet.protocol,Dictionary[b]);
packetsToLog(Logs_FILE,packet);
return packet;
}

void generate_multiple_packets(PacketArray* arr, int count){
Packet packet;
for(int i=0;i<count;i++){ 
packet = generate_random_packet();
add_packet(arr, packet);
}
}
//Generating your own rule
void generateYourOwnRule(RuleArray* arr){
Rule rule;
char namee[16]; 
char ip_adress[16];
int portt;
char prootocol[10];
char issAllowed[10];
printf("\nName of the rule: (max. 15 chars)\n");
getchar(); // deleting enter after menu option
fgets(namee, sizeof(namee), stdin);
namee[strcspn(namee, "\n")] = '\0';
//It wouldnt work otherwise with space
printf("Ip source: (In a oktet there can be a value of max 255 or -1 for everyport)\n");
scanf("%15s", ip_adress);
printf("Enter a port value (Max 25555)\n");
scanf("%9d", &portt);
printf("Enter a protocol (UDP/TCP)\n");
scanf("%s",prootocol);
printf("Enter (Allow/Block)\n");
scanf("%s",issAllowed);
//Safety measures
to_upper_string(prootocol);
to_upper_string(issAllowed);
if (strcmp(prootocol,"UDP")!= 0 && strcmp(prootocol,"TCP") != 0) {
logMessage(Logs_FILE,"Error. Wrong protocol"); 
printf("Wrong protocol");
return;
}
if ((strcmp(issAllowed,"ALLOW") != 0) && (strcmp(issAllowed,"BLOCK") != 0)) {
logMessage(Logs_FILE,"Error. Wrong value for allowance");
return;
}
if (portt<-1 || portt >25555){
logMessage(Logs_FILE,"Error. Wrong value for port");
printf("Wrong value for port");
 return;
}
//Standard procedure to adding a rule
strcpy(rule.name,namee);
strcpy(rule.ip_source, ip_adress);
rule.port = portt;
strcpy(rule.protocol,prootocol);
if(strcmp(issAllowed,"ALLOW") == 0) strcpy(rule.isAllowed,"Allow");
else strcpy(rule.isAllowed,"Block");
strcpy(rule.reason, "User generated rule");
add_rule(arr, rule);
rulesToFile(Rules_FILE, rule);
rulesToLog(Logs_FILE, rule);
}
