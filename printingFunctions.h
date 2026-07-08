#include "loggingFunctions.h"
//printing single rule
void print_result_separator() {
    printf("+-----------------+----------+-------+----------+------------------+------------------------------------------+\n");
}

void printRule(Rule rule){
print_result_separator();
printf("Name, IP, Port, Protocol, Reason, Is Allowed");
printf("%s, %s, %d, %s, %s, %s",rule.name, rule.ip_source,rule.port,rule.protocol,rule.reason,rule.isAllowed);
print_result_separator();
}
//printing whole rules
void printRules(Rule rule[], int RulesCount){
print_result_separator();
for(int i=0;i<RulesCount;i++)
printf("Number %d\n Name: %s\n IP: %s\n Port:  %d\n Protocol: %s\n Reason:  %s\n Allowance %s\n",i,rule[i].name, rule[i].ip_source,rule[i].port,rule[i].protocol,rule[i].reason,rule[i].isAllowed);
print_result_separator();
}
//printing last packet
void printPacket(Packet packet){
print_result_separator();
printf("Source IP: %s\n Port: %d\n Protocol: %s\n",packet.ip_address, packet.port, packet.protocol);
}
void print_result_header() {
    print_result_separator();

    printf("| %-15s | %-8s | %-5s | %-8s | %-16s | %-40s |\n",
           "Source IP",
           "Protocol",
           "Port",
           "Action",
           "Rule",
           "Reason");

    print_result_separator();
}

void print_result_row(EvaluationResult result) {
    printf("| %-15s | %-8s | %-5d | %-8s | %-16s | %-40.40s |\n",
           result.packet.ip_address,
           result.packet.protocol,
           result.packet.port,
           result.isAllowed,
           result.matched_rule,
           result.reason);
}

