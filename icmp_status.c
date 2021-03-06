/*
+--------------------------------------------------+
| @file: icmp_status.c                             |
| @brief: Program for icmp status testing          |
| @author: YoungJoo.Kim <vozlt@vozlt.com>          |
| @version:                                        |
| @date: 20080515                                  |
+--------------------------------------------------+
 
+-----------------------------------------------------------------------------+
shell> gcc -o icmp_status icmp_status.c
shell> ./icmp_status kr.yahoo.com
reply to   : 211.115.101.150
icmp_type  : 0x8
icmp_code  : 0x0
icmp_cksum : 0xb235
icmp_id    : 0x4db3
icmp_seq   : 0xf
send packet: 08 00 35 b2 b3 4d 0f 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00
 
reply from : 211.115.101.150
icmp_type  : 0x0
icmp_code  : 0x0
icmp_cksum : 0xb23d
icmp_id    : 0x4db3
icmp_seq   : 0xf
icmp_data  : 
icmp packet: 00 00 3d b2 b3 4d 0f 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 
recv packet: 45 00 00 30 72 0a 00 00 3c 01 47 6c d3 73 65 96 cb d7 c0
75 00 00 3d b2 b3 4d 0f 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 
 
ICMP SERVER STATUS : OK
+-----------------------------------------------------------------------------+
 
 
        http://www.faqs.org/rfcs/rfc791.html
        http://www.faqs.org/rfcs/rfc792.html
        http://www.faqs.org/rfcs/rfc1071.html
 
        0                   1                   2                   3   
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |Version|  IHL  |Type of Service|          Total Length         |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |         Identification        |Flags|      Fragment Offset    |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |  Time to Live |    Protocol   |         Header Checksum       |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                       Source Address                          |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                    Destination Address                        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                    Options                    |    Padding    |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Internet Header Format
        ICMP messages are sent using the basic IP header.
        Version = 4
        Type of Service = 0
        Protocol = 1
        .
        .
        ICMP : IP Header size 160 bit(20byte) + ICMP Packet(ICMP Header(8byte) + ICMP Data)
        +----------------------------------------------------------
        |IP Header| ICMP Packet 
        +----------------------------------------------------------
        |IP Header| ICMP Header                           |  
        +----------------------------------------------------------
        |IP Header|Type|Code|Checksum|Optional prarameters|Data ...
        +----------------------------------------------------------
        | 20      | 1  | 1  |  2     |     4              |    
        +----------------------------------------------------------
        Figure: ICMP datagram structure
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |           Identifier          |        Sequence Number        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Data ...
        +-+-+-+-+-
        Figure: Icmp Echo or Echo Reply Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                             unused                            |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |      Internet Header + 64 bits of Original Data Datagram      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Destination Unreachable Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                             unused                            |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |      Internet Header + 64 bits of Original Data Datagram      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Time Exceeded Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |    Pointer    |                   unused                      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |      Internet Header + 64 bits of Original Data Datagram      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Parameter Problem Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                             unused                            |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |      Internet Header + 64 bits of Original Data Datagram      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Source Quench Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |     Code      |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                 Gateway Internet Address                      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |      Internet Header + 64 bits of Original Data Datagram      |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Redirect Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |      Code     |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |           Identifier          |        Sequence Number        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Originate Timestamp                                       |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Receive Timestamp                                         |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Transmit Timestamp                                        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Timestamp or Timestamp Reply Message
 
        0                   1                   2                   3
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |     Type      |      Code     |          Checksum             |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |           Identifier          |        Sequence Number        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Figure: Information Request or Information Reply Message
 
        Summary of Message Types
        0   Echo Reply
        3   Destination Unreachable
        4   Source Quench
        5   Redirect
        8   Echo
        11  Time Exceeded
        12  Parameter Problem
        13  Timestamp
        14  Timestamp Reply
        15  Information Request
        16  Information Reply
 
        Flow Diagram
    ------------------------------------------------------
    Client              Internet       Server
    ICMP_ECHO --->
                        ICMP_ECHO --->
                                       ICMP_ECHO
                                       <--- ICMP_ECHOREPLY
                   <--- ICMP_ECHOREPLY
    ICMP_ECHOREPLY
    ------------------------------------------------------
        * 참고
                Traceroute는 IPv4의 TTL 필드를 사용하거나 IPv6의 홉 제한 필드와 두개의 ICMP
                메시지들을 사용한다.
                traceroute는 TTL을 1로 설정한 UDP 패킷을 목적지에 보내는것으로 시작한다.
                이 패킷은 첫번째 hop 라우터가 ICMP 'time exceeded in transit' 오류를 반환하도록 한다.
                이후 TTL을 1 증가 시켜 다시 목적지에 보낸다.
                그리고 두분째 hop 라우터가 ICMP 'time exceeded in transit' 오류를 반환하도록 한다.
                목적지까지 반복된 과정이후에 마지막 목적지에 도착했을때 목적지는 ICMP 'port unreachable'
                오류를 반환하는 호스트가 있다면 목적지에 도착한 것이다.
                이것은 목적지의 사용하지 않는 임의의 포트로 패킷을 보냄으로써 이루어진다.
                ( traceroute 에 -f 옵션으로 초기 TTL 시작 값을 변경 할 수 있다.
                  늘어난 값만큼의 hop은 건너뛰고 시작하게 된다. )
*/
 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#define BUFSIZE		1024	
#define CKSUMLEN	32*32
 
#define IS_SOCKET(sock) (sock > 0)
 
#define SUCCESS 0
#define FAILURE 1
 
int status = 0;
 
int socket_set_option (int sock, int level, int optname, const void *optval);
unsigned short in_cksum(const u_short *addr, int len);
char *inet_ntoa64(struct in_addr ina);
 
int main(int argc, char **argv)
{
	char *host = (argv[1]) ? argv[1] : "localhost";
 
	struct timeval timeval_v;
	int sock = 0, i = 0, timeout = 1;
	int ret;
	struct icmp *p, *rp;
	struct sockaddr_in to, from;
	struct ip *ip;
	char ackbuf[BUFSIZE];
	char buf[BUFSIZE];
	socklen_t fromlen;
	int hlen;
	struct hostent *domain;
	char *ipchar;
	unsigned int vozlt_seq=0xf;
 
	if ((domain=gethostbyname(host)) == NULL) {  /* get the host info */
		herror("gethostbyname");
		goto try_return;
	}
 
	ipchar = inet_ntoa64(*((struct in_addr *)domain->h_addr));
 
	if( (sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1 ) {
		perror("socket");
		goto try_return;
	}
 
	/* recvfrom 으로부터의 blocking 시간의 설정 */
	if (timeout > 0) {
		timeval_v.tv_sec = timeout;
		timeval_v.tv_usec = 0;
		socket_set_option(sock, SOL_SOCKET, SO_SNDTIMEO, &timeval_v);
		socket_set_option(sock, SOL_SOCKET, SO_RCVTIMEO, &timeval_v);
	}
 
 
	memset(buf, 0x0, sizeof(buf));
 
	p = (struct icmp *)buf;
	p->icmp_type=ICMP_ECHO;
	p->icmp_code=0;
	p->icmp_cksum=0;
	p->icmp_seq=vozlt_seq++;
	p->icmp_id=getpid();
	p->icmp_cksum = in_cksum((u_short *)p, CKSUMLEN);
 
	inet_aton (ipchar, &to.sin_addr);
	to.sin_family = AF_INET;
 
	if ( (ret = sendto(sock, p, sizeof(*p), MSG_DONTWAIT, (struct sockaddr *)&to, sizeof(to))) == -1) {
		perror("sendto");
		goto try_return;
	}
 
	printf("reply to   : %s\n", inet_ntoa64(to.sin_addr));
	printf("icmp_type  : 0x%x\n", p->icmp_type);
	printf("icmp_code  : 0x%x\n", p->icmp_code);
	printf("icmp_cksum : 0x%x\n", p->icmp_cksum);
	printf("icmp_id    : 0x%x\n", p->icmp_id);
	printf("icmp_seq   : 0x%x\n", p->icmp_seq);
 
	printf("send packet: ");
	/* 보낸 내용을 한자씩 읽어서 보여준다. */
	for(i=0;i < ret; i++) {
		printf("%02x ", (unsigned char)buf[i]);
	}
	printf("\n\n");
 
 
	fromlen = sizeof(from);
 
	if ( (ret = recvfrom(sock, ackbuf, sizeof(ackbuf), 0, (struct sockaddr *)&from, &fromlen)) == -1) {
		perror("recvfrom");
		goto try_return;
	}
 
	/* IP 헤더까지 같이 받았기 때문에
	 * IP 헤더 길이(20byte) 만큼 포인터를 이동 시켜 버린후
	 * ICMP 구조체로 처리해 버린다.
	 */ 
	ip = (struct ip *)ackbuf;
	hlen = ip->ip_hl*4;
	rp = (struct icmp *)(ackbuf+hlen);
 
	/* Defined Message Types (/usr/include/netinet/ip_icmp.h)
	 *
	 * ICMP_ECHOREPLY      0
	 * ICMP_DEST_UNREACH   3
	 * ICMP_SOURCE_QUENCH  4
	 * ICMP_REDIRECT       5
	 * ICMP_ECHO           8
	 * ICMP_TIME_EXCEEDED  11
	 * ICMP_PARAMETERPROB  12
	 * ICMP_TIMESTAMP      13
	 * ICMP_TIMESTAMPREPLY 14
	 * ICMP_INFO_REQUEST   15
	 * ICMP_INFO_REPLY     16
	 *
	 * Flow
	 * -----------------------------------------------------
	 * Client              Internet       Server
	 * ICMP_ECHO ---> 
	 *                     ICMP_ECHO --->
	 *                                    ICMP_ECHO
	 *                                    <--- ICMP_ECHOREPLY
	 *                <--- ICMP_ECHOREPLY          
	 * ICMP_ECHOREPLY
	 * -----------------------------------------------------
	 *
	 * */
	//if(rp->icmp_type == ICMP_ECHOREPLY && p->icmp_id == rp->icmp_id) {
	if(p->icmp_id == rp->icmp_id) {
		printf("reply from : %s\n", inet_ntoa64(from.sin_addr));
		printf("icmp_type  : 0x%x\n", rp->icmp_type);
		printf("icmp_code  : 0x%x\n", rp->icmp_code);
		printf("icmp_cksum : 0x%x\n", rp->icmp_cksum);
		printf("icmp_id    : 0x%x\n", rp->icmp_id);
		printf("icmp_seq   : 0x%x\n", rp->icmp_seq);
		printf("icmp_data  : %s\n", rp->icmp_data);
 
		printf("icmp packet: ");
		/* 받은 내용을 한자씩 읽어서 보여준다.
		 * ip 헤더는 제외한 부분부터 보여준다.
		 * ret = IP header + ICMP
		 * hlen = 20(IP header size)
		 */ 
		for(i=0;i < ret - hlen; i++) {
			printf("%02x ", (unsigned char)(ackbuf+hlen)[i]);
		}
		printf("\n");
		printf("recv packet: ");
		for(i=0;i < ret; i++) {
			printf("%02x ", (unsigned char)ackbuf[i]);
		}	
		printf("\n\n");
 
 
		status = 1;
	}
 
try_return:
	if (status == 1)
		printf("\nICMP SERVER STATUS : OK\n");
	else 
		printf("\nICMP SERVER STATUS : FAIL\n");
 
	if (IS_SOCKET(sock)) close(sock);
 
	return 0;
 
}
 
/*
 *************************************************
 *
 *       socket_set_option()
 *
 * 설명
 *       socket option에 대한 현재 값을 설정 또는 변경한다.
 *
 * 인자
 *       1. socket descriptor
 *       2. SOL_SOCKET
 *          IPPROTO_IP
 *          IPPROTO_ICMPV6
 *          IPPROTO_IPV6
 *          IPPROTO_TCP
 *       3. 각 level 에 속한 optname
 *       4. 변경할 값을 저장한 변수
 *
 * 반환값
 *       성공 = SUCCESS 
 *       실패 = FAILURE
 *
 *************************************************
 */
int socket_set_option (int sock, int level, int optname, const void *optval)
{
	socklen_t optlen;
 
	switch(optname) {
		case SO_LINGER:
			optlen = sizeof(struct linger);
			if (setsockopt(sock, level, optname, optval, optlen) != 0) {
				perror("unable to retrieve socket option");
				return FAILURE;
			}
			break;
 
		case SO_RCVTIMEO:
		case SO_SNDTIMEO:
			optlen = sizeof(struct timeval);
			if (setsockopt(sock, level, optname, optval, optlen) != 0) {
				perror("unable to retrieve socket option");
				return FAILURE;
			}
			break;
 
		default:
			optlen = sizeof(int);
			if (setsockopt(sock, level, optname, optval, optlen) != 0) {
				perror("unable to retrieve socket option");
				return FAILURE;;
			}
			break;
	}
	return SUCCESS;
}
 
/*
 *************************************************
 *
 *       in_cksum()
 *
 * 설명
 *       checksum 값을 만들어 준다.
 *       checksum은 checksum된 16비트 값들의 합의 1의 보수이다.
 *       만약 데이터 길이가 홀수이면, checksum 계산을 위해서 1바이트의 0이 데이터의 끝에 논리적으로 덧붙여진다.
 *       http://www.faqs.org/rfcs/rfc1071.html
 *
 * 인자
 *       1. ICMP header 에 대한 포인터(ICMP_ECHO(8) 등 첫 값을 사용하게 된다.)
 *       2. 길이(사용자 정의)
 *
 * 반환값
 *       생성된 checksum 값
 *
 *************************************************
 */
unsigned short in_cksum(const u_short *addr, int len)
{
	int nleft = len;
	const u_short *w = addr; /* *w = ICMP_ECHO(8) .... */
	u_short answer;
	int sum = 0;
 
	/* This is the inner loop */
	while (nleft > 1)  {
		sum += *w++;
		nleft -= 2;
	}
 
	/* Add left-over byte, if any */
	if (nleft == 1)
		sum += htons(*(u_char *)w << 8);
 
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}
 
/*
 *************************************************
 *
 *       inet_ntoa64()
 *
 * 설명
 *       inet_ntoa64() 함수는 네트웍 바이트 순서로 주어진 인터넷 호스트 주소 in을 표준점-수 표기의 문자열로 바꾼다.
 *       문자열은 정적으로 할당된 버퍼로 반환되며 이 함수의 연속적인 호출은 이 공간을 덮어 쓴다.
 *
 * 인자
 *       1. struct in_addr 형 구조체 
 *
 * 반환값
 *       문자열로 변환된 IP주소 값
 *
 *************************************************
 */
char *inet_ntoa64(struct in_addr ina)
{
	static char buf[4*sizeof("123")];
	unsigned char *ucp = (unsigned char *)&ina;
 
	sprintf(buf, "%d.%d.%d.%d",
			ucp[0] & 0xff,
			ucp[1] & 0xff,
			ucp[2] & 0xff,
			ucp[3] & 0xff);
	return buf;
}
