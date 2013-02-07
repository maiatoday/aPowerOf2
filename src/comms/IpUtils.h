/*
 * IpUtils.h
 *
 *  Created on: Feb 7, 2013
 *      Author: maia
 */

#ifndef IPUTILS_H_
#define IPUTILS_H_

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
namespace IpUtils {
/**
 * Utility function to get my own IP. returns my IPv4 address. If eth one exists return the first one or else return the first wlan one
 */
std::string getMyIp() {
	struct ifaddrs * ifAddrStruct = NULL;
	struct ifaddrs * ifa = NULL;
	void * tmpAddrPtr = NULL;
	std::string myIp = "127.0.0.1";
	bool retValSet = false;

	getifaddrs(&ifAddrStruct);

	for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
			// is a valid IP4 Address
			tmpAddrPtr = &((struct sockaddr_in *) ifa->ifa_addr)->sin_addr;
			char addressBuffer[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
			printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
			if (!retValSet) {
				string name = ifa->ifa_name;
				string eth = "eth";
				string wlan = "wlan";
				if ((name.compare(0, eth.length(), eth) == 0) || (name.compare(0, wlan.length(), wlan) == 0)) {
					myIp = addressBuffer;
					retValSet = true;
				}
			}
		} else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6
			// is a valid IP6 Address
			tmpAddrPtr = &((struct sockaddr_in6 *) ifa->ifa_addr)->sin6_addr;
			char addressBuffer[INET6_ADDRSTRLEN];
			inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
			printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
		}
	}
	if (ifAddrStruct != NULL)
		freeifaddrs(ifAddrStruct);
	return myIp;
}
}

#endif /* IPUTILS_H_ */
