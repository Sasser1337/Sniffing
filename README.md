<h2 align="center">Sniffing</h2>

<p align="center">
  <a href="https://github.com/Sasser1337/Sniffing/stargazers">
    <img src="https://img.shields.io/github/stars/Sasser1337/Sniffing" alt="Stars Badge"/>
  </a>
  <a href="https://github.com/Sasser1337/awesome-github-profile-readme/network/members">
    <img src="https://img.shields.io/github/forks/Sasser1337/Sniffing" alt="Forks Badge"/>
  </a>
  <a href="https://github.com/Sasser1337/Sniffing/blob/master/LICENSE">
    <img src="https://img.shields.io/github/license/Sasser1337/Sniffing?color=2b9348" alt="License Badge"/>
  </a>
  <a href="https://hits.seeyoufarm.com">
    <img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FSasser1337%2FSniffing%2F&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false"/>
  </a>
</p>



# Network Sniffer

## Overview
This is a simple network sniffer program written in C. It uses a RAW socket to capture and analyze network traffic, providing insights into the types of packets (ICMP, TCP, UDP) being transmitted on the network.

## How it Works
1. **RAW Socket Initialization**: The program initializes a RAW socket to capture network packets.
2. **Infinite Loop**: It enters an infinite loop to continuously receive and analyze incoming packets.
3. **Packet Reception**: Using `recvfrom`, the program captures incoming packets and stores them in a buffer.
4. **Protocol Analysis**: It identifies the packet's protocol by inspecting the IP header.
5. **Print Header Information**: Depending on the protocol (ICMP, TCP, UDP), it prints relevant header information, such as source and destination IP addresses and ports.
6. **Handling Unknown Protocols**: If an unknown protocol is encountered, it prints "Unknown Protocol."
7. **Closing RAW Socket**: After packet analysis, the RAW socket is closed.
8. **Exiting the Program**: The program can be manually stopped to exit.

## Usage
1. Ensure you have the necessary permissions to run this program, as it requires administrative access.
2. Compile the program using a C compiler (e.g., `gcc sniffer.c -o sniffer`).
3. Run the program (e.g., `sudo ./sniffer`).
4. The program will continuously display information about incoming network packets.

## Important Notes
- Use this program responsibly and only for legitimate purposes. Unauthorized network monitoring may be illegal.
- Ensure you have the necessary knowledge of networking and permissions before running this program.
