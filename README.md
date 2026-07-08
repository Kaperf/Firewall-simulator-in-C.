# Firewall-simulator-in-C.
# Description
Firewall Simulator is a simple rule-based traffic filtering program written in C. The program simulates how a firewall decides whether incoming traffic should be allowed or blocked. Each packet is checked against a list of firewall rules. The decision is based on:
- source IP address,
- port number,
- protocol,
- rule action: Allow or Block.
The program also shows which rule matched the packet and why the packet was allowed or blocked.
# Main idea
The simulator uses the first match wins approach. This means that rules are checked from top to bottom meaning first rule that matches the packet decides the final action. If no rule matches, the packet is blocked by the default policy.
# Features
- rule-based packet filtering,
- filtering by source IP, port and protocol,
- wildcard support:
- * for any IP address,
- -1 for any port,
- * for any protocol,
- default firewall rules,
- random packet generation,
- user-defined rules,
- dynamic arrays using malloc and realloc,
- logging to file,
- summary of allowed and blocked packets,
- console table showing filtering results.
# Example default rules
Rule name	Source IP	Port	Protocol	Action
Block SSH	*	22	TCP	Block
Allow HTTP	*	80	TCP	Allow
Allow HTTPS	*	443	TCP	Allow
Block MySQL	*	3306	TCP	Block
Block all UDP	*	-1	UDP	Block
# Example packets
Source IP	Port	Protocol
192.168.1.10	22	TCP
8.8.8.8	80	TCP
10.0.0.5	53	UDP
1.1.1.1	443	TCP
# Example output
"+-----------------+----------+-------+----------+------------------+------------------------------------------+
| Source IP       | Protocol | Port  | Action   | Rule             | Reason                                   |
+-----------------+----------+-------+----------+------------------+------------------------------------------+
| 192.168.1.10    | TCP      | 22    | Block    | Block SSH        | SSH traffic is blocked                   |
| 8.8.8.8         | TCP      | 80    | Allow    | Allow HTTP       | HTTP traffic is allowed                  |
| 10.0.0.5        | UDP      | 53    | Block    | Block all UDP    | UDP traffic is blocked                   |
| 1.1.1.1         | TCP      | 443   | Allow    | Allow HTTPS      | HTTPS traffic is allowed                 |
+-----------------+----------+-------+----------+------------------+------------------------------------------+"
# Program menu
1. Show rules
2. Show count of allowed packets
3. Show count of blocked packets
4. Show summary of packets
5. Generate one packet
6. Generate multiple packets
7. Generate your own rule
8. Evaluate packets
9. Show packets
0. Exit
# How to compile
- Using GCC: gcc main.c -o firewall_simulator
- How to run
- On Linux/macOS: ./firewall_simulator
- On Windows: firewall_simulator.exe
# Project structure
- main.c
- packetsAndRules.h
- comparisionFunctions.h
- DynAllocatingFunctions.h
- loggingFunctions.h
- printingFunctions.h
- dataGenerator.h
- Firewall.h
- countingFunctions.c
- logs.txt
- rules.txt
# What I learned
This project helped me understand:
- how firewall rules work,
- how packets can be filtered by IP, port and protocol,
- how first-match rule evaluation works,
- how to use structures in C,
- how to use dynamic memory allocation,
- how to log program results to a file,
- how to present results in a readable console table.
# Possible future improvements:
- support for CIDR notation, for example 192.168.1.0/24,
- support for port ranges, for example 20-25,
- loading rules from a text file,
- saving results in CSV format.
