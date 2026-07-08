#include "countingFunctions.c"
	
void menu(RuleArray* rulearr, PacketArray* packetarr){
int looping = 1;
int option = -5;
int output = 0, output2 = 0;
char choice[4];
do{
printf("\nHello in FireWall simulator!\n Choose an option!\n");
printf("1. Show rules.\n");
printf("2. Show count of allowed packets\n");
printf("3. Show count of blocked packets\n");
printf("4. Show summary of packets\n");
printf("5. Generate one packet\n");
printf("6. Generate multiple packets\n");
printf("7. Generate Your own Rule\n");
printf("8. Evaluate packets\n");
printf("9. Show packets\n");
printf("0. Exiting\n");
scanf("%d",&option);
switch(option){
case 0:
looping = 0;
printf("Do you want to erase logs?");
scanf("%s",choice);
to_upper_string(choice);
if(strcmp(choice,"YES") == 0) reset_logs();
break;
case 1:
printRules(rulearr->data,rulearr->count);
break;
case 2:
output =  count_allowed(Logs_FILE);
printf("Number of allowed packets: %d",output);
break;
case 3:
output =  count_blocked(Logs_FILE);
printf("Number of blocked packets: %d",output);
break;
case 4:
output =  count_allowed(Logs_FILE);
output2 =  count_blocked(Logs_FILE);
printf("Number of every packets: %d\n Allowed: %d\n Blocked: %d",output+output2,output,output2);
break;
case 5:
generate_multiple_packets(packetarr, 1);
break;
case 6:
printf("How many?");
scanf("%d", &output2);
generate_multiple_packets(packetarr, output2);
break;
case 7:
generateYourOwnRule(rulearr);
break;
case 8:
process_packets(packetarr->data,packetarr->count,rulearr->data, rulearr->count);
break;
case 9:
for (int i = 0; i < packetarr->count; i++) {
    printPacket(packetarr->data[i]);
}
print_result_separator();
break;
default: 
printf("Wrong option");
break;
}
}while(looping);
}

int main(void){
init_random();
RuleArray rule_arr;
PacketArray packet_arr;
init_rules(&rule_arr);
init_packets(&packet_arr);
add_default_rules(&rule_arr);
add_default_packets(&packet_arr);
menu(&rule_arr,&packet_arr);
free_rules(&rule_arr);
free_packets(&packet_arr);
return 0;
}

