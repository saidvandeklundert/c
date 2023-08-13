#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    // getifaddrs will return a linked list of addresses
    // this will be captured in ifaddrs:
    struct ifaddrs *addresses;

    // the linked list is a struct that is defined like so:

    /**
    
           struct ifaddrs {
               struct ifaddrs  *ifa_next;    Next item in list 
               char            *ifa_name;    Name of interface
               unsigned int     ifa_flags;   Flags from SIOCGIFFLAGS
               struct sockaddr *ifa_addr;    Address of interface
               struct sockaddr *ifa_netmask; Netmask of interface
               union {
                   struct sockaddr *ifu_broadaddr;  Broadcast address of interface 
                   struct sockaddr *ifu_dstaddr;  Point-to-point destination address 
               } ifa_ifu;

           };    
    */

    // here we verify if the function fails:
    if (getifaddrs(&addresses) == -1){
        printf("getifaddrs call failed\n");
        return -1;
    }

    // we take a pointer to the linked list so we can start walking it:
    struct ifaddrs *address = addresses;
    

    while(address) {
        if (address->ifa_addr == NULL) { 
            address = address->ifa_next;
            continue;
        }        
        int family = address->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {
            printf("%s\t", address->ifa_name);
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

            char buffer_for_int_name[100];

            const int family_size = family = AF_INET ? 
                sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(address->ifa_addr,
                    family_size, buffer_for_int_name, sizeof(buffer_for_int_name), 0, 0, NI_NUMERICHOST);
            printf("\t%s\n", buffer_for_int_name);
        }
        address = address->ifa_next;


    }
    freeifaddrs(addresses);
    return 0;    
}