#include "dns.h"




int main(int argc, char *argv[]) {
 
    if (argc < 2) {
        printf("Usage:\n\tlookup hostname\n");
        printf("Example:\n\tlookup example.com\n");
        exit(0);
    }

    printf("Resolving hostname '%s'\n", argv[1]);


    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_ALL;
    struct addrinfo *peer_address;
    

    int result;
    result = getaddrinfo(argv[1],0, &hints, &peer_address);
    if (result != 0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }    
    printf("Remote address is:\n");
    struct addrinfo *address = peer_address;
    do {
        char address_buffer[100];
        getnameinfo(address->ai_addr, address->ai_addrlen,
                address_buffer, sizeof(address_buffer),
                0, 0,
                NI_NUMERICHOST);
        printf("\t%s\n", address_buffer);
    } while ((address = address->ai_next));    
    freeaddrinfo(peer_address);



    return 0;
} 