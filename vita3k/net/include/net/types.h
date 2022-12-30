// Vita3K emulator project
// Copyright (C) 2021 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <mem/ptr.h>

enum SceNetProtocol {
    SCE_NET_IPPROTO_IP = 0,
    SCE_NET_IPPROTO_ICMP = 1,
    SCE_NET_IPPROTO_IGMP = 2,
    SCE_NET_IPPROTO_TCP = 6,
    SCE_NET_IPPROTO_UDP = 17,
    SCE_NET_SOL_SOCKET = 0xFFFF
};

enum SceNetSocketType {
    SCE_NET_SOCK_STREAM = 1,
    SCE_NET_SOCK_DGRAM = 2,
    SCE_NET_SOCK_RAW = 3,
    SCE_NET_SOCK_DGRAM_P2P = 6,
    SCE_NET_SOCK_STREAM_P2P = 10
};

enum SceNetSocketOption {
    /* IP */
    SCE_NET_IP_HDRINCL = 2,
    SCE_NET_IP_TOS = 3,
    SCE_NET_IP_TTL = 4,
    SCE_NET_IP_MULTICAST_IF = 9,
    SCE_NET_IP_MULTICAST_TTL = 10,
    SCE_NET_IP_MULTICAST_LOOP = 11,
    SCE_NET_IP_ADD_MEMBERSHIP = 12,
    SCE_NET_IP_DROP_MEMBERSHIP = 13,
    SCE_NET_IP_TTLCHK = 23,
    SCE_NET_IP_MAXTTL = 24,
    /* TCP */
    SCE_NET_TCP_NODELAY = 1,
    SCE_NET_TCP_MAXSEG = 2,
    SCE_NET_TCP_MSS_TO_ADVERTISE = 3,
    /* SOCKET */
    SCE_NET_SO_REUSEADDR = 0x00000004,
    SCE_NET_SO_KEEPALIVE = 0x00000008,
    SCE_NET_SO_BROADCAST = 0x00000020,
    SCE_NET_SO_LINGER = 0x00000080,
    SCE_NET_SO_OOBINLINE = 0x00000100,
    SCE_NET_SO_REUSEPORT = 0x00000200,
    SCE_NET_SO_ONESBCAST = 0x00000800,
    SCE_NET_SO_USECRYPTO = 0x00001000,
    SCE_NET_SO_USESIGNATURE = 0x00002000,
    SCE_NET_SO_SNDBUF = 0x1001,
    SCE_NET_SO_RCVBUF = 0x1002,
    SCE_NET_SO_SNDLOWAT = 0x1003,
    SCE_NET_SO_RCVLOWAT = 0x1004,
    SCE_NET_SO_SNDTIMEO = 0x1005,
    SCE_NET_SO_RCVTIMEO = 0x1006,
    SCE_NET_SO_ERROR = 0x1007,
    SCE_NET_SO_TYPE = 0x1008,
    SCE_NET_SO_NBIO = 0x1100,
    SCE_NET_SO_TPPOLICY = 0x1101,
    SCE_NET_SO_NAME = 0x1102
};

enum SceNetKernelErrorCode {
    SCE_NET_EPERM = 1,
    SCE_NET_ENOENT = 2,
    SCE_NET_ESRCH = 3,
    SCE_NET_EINTR = 4,
    SCE_NET_EIO = 5,
    SCE_NET_ENXIO = 6,
    SCE_NET_E2BIG = 7,
    SCE_NET_ENOEXEC = 8,
    SCE_NET_EBADF = 9,
    SCE_NET_ECHILD = 10,
    SCE_NET_EDEADLK = 11,
    SCE_NET_ENOMEM = 12,
    SCE_NET_EACCES = 13,
    SCE_NET_EFAULT = 14,
    SCE_NET_ENOTBLK = 15,
    SCE_NET_EBUSY = 16,
    SCE_NET_EEXIST = 17,
    SCE_NET_EXDEV = 18,
    SCE_NET_ENODEV = 19,
    SCE_NET_ENOTDIR = 20,
    SCE_NET_EISDIR = 21,
    SCE_NET_EINVAL = 22,
    SCE_NET_ENFILE = 23,
    SCE_NET_EMFILE = 24,
    SCE_NET_ENOTTY = 25,
    SCE_NET_ETXTBSY = 26,
    SCE_NET_EFBIG = 27,
    SCE_NET_ENOSPC = 28,
    SCE_NET_ESPIPE = 29,
    SCE_NET_EROFS = 30,
    SCE_NET_EMLINK = 31,
    SCE_NET_EPIPE = 32,
    SCE_NET_EDOM = 33,
    SCE_NET_ERANGE = 34,
    SCE_NET_EAGAIN = 35,
    SCE_NET_EWOULDBLOCK = 35,
    SCE_NET_EINPROGRESS = 36,
    SCE_NET_EALREADY = 37,
    SCE_NET_ENOTSOCK = 38,
    SCE_NET_EDESTADDRREQ = 39,
    SCE_NET_EMSGSIZE = 40,
    SCE_NET_EPROTOTYPE = 41,
    SCE_NET_ENOPROTOOPT = 42,
    SCE_NET_EPROTONOSUPPORT = 43,
    SCE_NET_ESOCKTNOSUPPORT = 44,
    SCE_NET_EOPNOTSUPP = 45,
    SCE_NET_EPFNOSUPPORT = 46,
    SCE_NET_EAFNOSUPPORT = 47,
    SCE_NET_EADDRINUSE = 48,
    SCE_NET_EADDRNOTAVAIL = 49,
    SCE_NET_ENETDOWN = 50,
    SCE_NET_ENETUNREACH = 51,
    SCE_NET_ENETRESET = 52,
    SCE_NET_ECONNABORTED = 53,
    SCE_NET_ECONNRESET = 54,
    SCE_NET_ENOBUFS = 55,
    SCE_NET_EISCONN = 56,
    SCE_NET_ENOTCONN = 57,
    SCE_NET_ESHUTDOWN = 58,
    SCE_NET_ETOOMANYREFS = 59,
    SCE_NET_ETIMEDOUT = 60,
    SCE_NET_ECONNREFUSED = 61,
    SCE_NET_ELOOP = 62,
    SCE_NET_ENAMETOOLONG = 63,
    SCE_NET_EHOSTDOWN = 64,
    SCE_NET_EHOSTUNREACH = 65,
    SCE_NET_ENOTEMPTY = 66,
    SCE_NET_EPROCLIM = 67,
    SCE_NET_EUSERS = 68,
    SCE_NET_EDQUOT = 69,
    SCE_NET_ESTALE = 70,
    SCE_NET_EREMOTE = 71,
    SCE_NET_EBADRPC = 72,
    SCE_NET_ERPCMISMATCH = 73,
    SCE_NET_EPROGUNAVAIL = 74,
    SCE_NET_EPROGMISMATCH = 75,
    SCE_NET_EPROCUNAVAIL = 76,
    SCE_NET_ENOLCK = 77,
    SCE_NET_ENOSYS = 78,
    SCE_NET_EFTYPE = 79,
    SCE_NET_EAUTH = 80,
    SCE_NET_ENEEDAUTH = 81,
    SCE_NET_EIDRM = 82,
    SCE_NET_ENOMSG = 83,
    SCE_NET_EOVERFLOW = 84,
    SCE_NET_EILSEQ = 85,
    SCE_NET_ENOTSUP = 86,
    SCE_NET_ECANCELED = 87,
    SCE_NET_EBADMSG = 88,
    SCE_NET_ENODATA = 89,
    SCE_NET_ENOSR = 90,
    SCE_NET_ENOSTR = 91,
    SCE_NET_ETIME = 92,
    SCE_NET_EADHOC = 160,
    SCE_NET_EDISABLEDIF = 161,
    SCE_NET_ERESUME = 162
};

enum SceNetErrorCode {
    SCE_NET_ERROR_EPERM = 0x80410101,
    SCE_NET_ERROR_ENOENT = 0x80410102,
    SCE_NET_ERROR_ESRCH = 0x80410103,
    SCE_NET_ERROR_EINTR = 0x80410104,
    SCE_NET_ERROR_EIO = 0x80410105,
    SCE_NET_ERROR_ENXIO = 0x80410106,
    SCE_NET_ERROR_E2BIG = 0x80410107,
    SCE_NET_ERROR_ENOEXEC = 0x80410108,
    SCE_NET_ERROR_EBADF = 0x80410109,
    SCE_NET_ERROR_ECHILD = 0x8041010A,
    SCE_NET_ERROR_EDEADLK = 0x8041010B,
    SCE_NET_ERROR_ENOMEM = 0x8041010C,
    SCE_NET_ERROR_EACCES = 0x8041010D,
    SCE_NET_ERROR_EFAULT = 0x8041010E,
    SCE_NET_ERROR_ENOTBLK = 0x8041010F,
    SCE_NET_ERROR_EBUSY = 0x80410110,
    SCE_NET_ERROR_EEXIST = 0x80410111,
    SCE_NET_ERROR_EXDEV = 0x80410112,
    SCE_NET_ERROR_ENODEV = 0x80410113,
    SCE_NET_ERROR_ENOTDIR = 0x80410114,
    SCE_NET_ERROR_EISDIR = 0x80410115,
    SCE_NET_ERROR_EINVAL = 0x80410116,
    SCE_NET_ERROR_ENFILE = 0x80410117,
    SCE_NET_ERROR_EMFILE = 0x80410118,
    SCE_NET_ERROR_ENOTTY = 0x80410119,
    SCE_NET_ERROR_ETXTBSY = 0x8041011A,
    SCE_NET_ERROR_EFBIG = 0x8041011B,
    SCE_NET_ERROR_ENOSPC = 0x8041011C,
    SCE_NET_ERROR_ESPIPE = 0x8041011D,
    SCE_NET_ERROR_EROFS = 0x8041011E,
    SCE_NET_ERROR_EMLINK = 0x8041011F,
    SCE_NET_ERROR_EPIPE = 0x80410120,
    SCE_NET_ERROR_EDOM = 0x80410121,
    SCE_NET_ERROR_ERANGE = 0x80410122,
    SCE_NET_ERROR_EAGAIN = 0x80410123,
    SCE_NET_ERROR_EWOULDBLOCK = 0x80410123,
    SCE_NET_ERROR_EINPROGRESS = 0x80410124,
    SCE_NET_ERROR_EALREADY = 0x80410125,
    SCE_NET_ERROR_ENOTSOCK = 0x80410126,
    SCE_NET_ERROR_EDESTADDRREQ = 0x80410127,
    SCE_NET_ERROR_EMSGSIZE = 0x80410128,
    SCE_NET_ERROR_EPROTOTYPE = 0x80410129,
    SCE_NET_ERROR_ENOPROTOOPT = 0x8041012A,
    SCE_NET_ERROR_EPROTONOSUPPORT = 0x8041012B,
    SCE_NET_ERROR_ESOCKTNOSUPPORT = 0x8041012C,
    SCE_NET_ERROR_EOPNOTSUPP = 0x8041012D,
    SCE_NET_ERROR_EPFNOSUPPORT = 0x8041012E,
    SCE_NET_ERROR_EAFNOSUPPORT = 0x8041012F,
    SCE_NET_ERROR_EADDRINUSE = 0x80410130,
    SCE_NET_ERROR_EADDRNOTAVAIL = 0x80410131,
    SCE_NET_ERROR_ENETDOWN = 0x80410132,
    SCE_NET_ERROR_ENETUNREACH = 0x80410133,
    SCE_NET_ERROR_ENETRESET = 0x80410134,
    SCE_NET_ERROR_ECONNABORTED = 0x80410135,
    SCE_NET_ERROR_ECONNRESET = 0x80410136,
    SCE_NET_ERROR_ENOBUFS = 0x80410137,
    SCE_NET_ERROR_EISCONN = 0x80410138,
    SCE_NET_ERROR_ENOTCONN = 0x80410139,
    SCE_NET_ERROR_ESHUTDOWN = 0x8041013A,
    SCE_NET_ERROR_ETOOMANYREFS = 0x8041013B,
    SCE_NET_ERROR_ETIMEDOUT = 0x8041013C,
    SCE_NET_ERROR_ECONNREFUSED = 0x8041013D,
    SCE_NET_ERROR_ELOOP = 0x8041013E,
    SCE_NET_ERROR_ENAMETOOLONG = 0x8041013F,
    SCE_NET_ERROR_EHOSTDOWN = 0x80410140,
    SCE_NET_ERROR_EHOSTUNREACH = 0x80410141,
    SCE_NET_ERROR_ENOTEMPTY = 0x80410142,
    SCE_NET_ERROR_EPROCLIM = 0x80410143,
    SCE_NET_ERROR_EUSERS = 0x80410144,
    SCE_NET_ERROR_EDQUOT = 0x80410145,
    SCE_NET_ERROR_ESTALE = 0x80410146,
    SCE_NET_ERROR_EREMOTE = 0x80410147,
    SCE_NET_ERROR_EBADRPC = 0x80410148,
    SCE_NET_ERROR_ERPCMISMATCH = 0x80410149,
    SCE_NET_ERROR_EPROGUNAVAIL = 0x8041014A,
    SCE_NET_ERROR_EPROGMISMATCH = 0x8041014B,
    SCE_NET_ERROR_EPROCUNAVAIL = 0x8041014C,
    SCE_NET_ERROR_ENOLCK = 0x8041014D,
    SCE_NET_ERROR_ENOSYS = 0x8041014E,
    SCE_NET_ERROR_EFTYPE = 0x8041014F,
    SCE_NET_ERROR_EAUTH = 0x80410150,
    SCE_NET_ERROR_ENEEDAUTH = 0x80410151,
    SCE_NET_ERROR_EIDRM = 0x80410152,
    SCE_NET_ERROR_ENOMS = 0x80410153,
    SCE_NET_ERROR_EOVERFLOW = 0x80410154,
    SCE_NET_ERROR_EILSEQ = 0x80410155,
    SCE_NET_ERROR_ENOTSUP = 0x80410156,
    SCE_NET_ERROR_ECANCELED = 0x80410157,
    SCE_NET_ERROR_EBADMSG = 0x80410158,
    SCE_NET_ERROR_ENODATA = 0x80410159,
    SCE_NET_ERROR_ENOSR = 0x8041015A,
    SCE_NET_ERROR_ENOSTR = 0x8041015B,
    SCE_NET_ERROR_ETIME = 0x8041015C,
    SCE_NET_ERROR_EADHOC = 0x804101A0,
    SCE_NET_ERROR_EDISABLEDIF = 0x804101A1,
    SCE_NET_ERROR_ERESUME = 0x804101A2,
    SCE_NET_ERROR_ENOTINIT = 0x804101C8,
    SCE_NET_ERROR_ENOLIBMEM = 0x804101C9,
    SCE_NET_ERROR_ERESERVED202 = 0x804101CA,
    SCE_NET_ERROR_ECALLBACK = 0x804101CB,
    SCE_NET_ERROR_EINTERNAL = 0x804101CC,
    SCE_NET_ERROR_ERETURN = 0x804101CD,
    SCE_NET_ERROR_RESOLVER_EINTERNAL = 0x804101DC,
    SCE_NET_ERROR_RESOLVER_EBUSY = 0x804101DD,
    SCE_NET_ERROR_RESOLVER_ENOSPACE = 0x804101DE,
    SCE_NET_ERROR_RESOLVER_EPACKET = 0x804101DF,
    SCE_NET_ERROR_RESOLVER_ERESERVED22 = 0x804101E0,
    SCE_NET_ERROR_RESOLVER_ENODNS = 0x804101E1,
    SCE_NET_ERROR_RESOLVER_ETIMEDOUT = 0x804101E2,
    SCE_NET_ERROR_RESOLVER_ENOSUPPORT = 0x804101E3,
    SCE_NET_ERROR_RESOLVER_EFORMAT = 0x804101E4,
    SCE_NET_ERROR_RESOLVER_ESERVERFAILURE = 0x804101E5,
    SCE_NET_ERROR_RESOLVER_ENOHOST = 0x804101E6,
    SCE_NET_ERROR_RESOLVER_ENOTIMPLEMENTED = 0x804101E7,
    SCE_NET_ERROR_RESOLVER_ESERVERREFUSED = 0x804101E8,
    SCE_NET_ERROR_RESOLVER_ENORECORD = 0x804101E9,
    SCE_NET_ERROR_RESOLVER_EALIGNMENT = 0x804101EA
};

enum SceNetEpollControlFlag : int32_t {
    SCE_NET_EPOLL_CTL_ADD = 1,
    SCE_NET_EPOLL_CTL_MOD,
    SCE_NET_EPOLL_CTL_DEL
};

enum SceNetEpollEventType {
    SCE_NET_EPOLLIN = 1,
    SCE_NET_EPOLLOUT = 2,
    SCE_NET_EPOLLERR = 8
};

struct SceNetEtherAddr {
    unsigned char data[6];
};

struct SceNetCtlCallback {
    Address pc;
    Address arg;
};

struct SceNetInAddr {
    unsigned int s_addr;
};

struct SceNetSockaddrIn {
    unsigned char sin_len;
    unsigned char sin_family;
    unsigned short int sin_port;
    SceNetInAddr sin_addr;
    unsigned short int sin_vport;
    char sin_zero[6];
};

struct SceNetSockaddr {
    unsigned char sa_len;
    unsigned char sa_family;
    char sa_data[14];
};

struct SceNetInitParam {
    Ptr<void> memory;
    int32_t size;
    int32_t flags;
};

union SceNetEpollData {
    char data[8];
};

struct SceNetEpollEvent {
    unsigned int events;
    unsigned int reserved;
    unsigned int system[4];
    SceNetEpollData data;
};
