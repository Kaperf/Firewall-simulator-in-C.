#include "printingFunctions.h"
EvaluationResult evaluate_packet(Packet packet, Rule* rules, int rulesCount){ // 
int outcome = 5;
EvaluationResult result; // struct to return
result.packet = packet; // easier to copy whole struct

for(int i = 0;i<rulesCount;i++){
outcome = match_rule(packet, rules[i]);
//If rule is found  either allowed or blocked we can return it
if(outcome == 1){
strcpy(result.isAllowed, rules[i].isAllowed);
strcpy(result.reason, rules[i].reason);
strcpy(result.matched_rule, rules[i].name);
resultsToLog(Logs_FILE, result);
return result;
}
}
//sceneario where neither allowed or blocked reason has been found
//security measure
strcpy(result.isAllowed, "Block" );
strcpy(result.matched_rule, "Default");
strcpy(result.reason, "No rule matched (Default block)");
resultsToLog(Logs_FILE, result);
return result;
}
//Processing multiple packet at once
void process_packets(Packet packets[],int packetsCount, Rule* rules, int rulesCount){
print_result_separator();
EvaluationResult result;
for(int i=0;i<packetsCount;i++) {
result = evaluate_packet(packets[i], rules,rulesCount);
print_result_row(result);
}
print_result_separator();
}
