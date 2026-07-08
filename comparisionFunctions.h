#include "packetsAndRules.h"
#include <string.h>
// Checking if Ip of the packet is eq to  Ip of the rule.
int match_ip(char packet_ip[], char rule_ip[]){
if (strcmp(packet_ip, rule_ip) == 0) return 1; //  simplest thing ip_address == rule_ip 
if (strcmp(rule_ip, "*") == 0) return 1; //   * is just broadcasting meainng every ipaddress is good 
else return 0; // Nothing is compatable
}

// As above checking is packet port is eq to rule port
int match_port(int packet_port, int  rule_port){
if (packet_port == rule_port) return 1; // as above 
else if (rule_port == -1) return 1; // to everyport
else return 0;
}

int match_protocol(char packet_protocol[], char rule_protocol[]){
if (strcmp(packet_protocol, rule_protocol) == 0) return 1;
else if (strcmp(rule_protocol, "*") == 0) return 1;
else return 0;
}

int match_rule(Packet packet, Rule rule){
if (match_ip(packet.ip_address, rule.ip_source) == 0) return 0;
if (match_port(packet.port, rule.port) == 0) return 0;
if (match_protocol(packet.protocol, rule.protocol) == 0) return 0;
return 1;
}
