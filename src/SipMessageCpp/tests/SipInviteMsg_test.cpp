#include <doctest/doctest.h>
#include "SipInviteMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("SipInviteMsg"){
    DtSipMessageCpp::CSipInviteMsg baseMsg;
    std::string strInviteSipMsg = R"(INVITE sip:1009@192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---974f0e190ebbfd0d;rport
Max-Forwards: 70
Contact: <sip:1002@192.168.31.142:55747;transport=UDP>
To: <sip:1009@192.168.31.109:5060>
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=0e837329
Call-ID: cqBcUqknj-sTLjz_cI-GKw..
CSeq: 2 INVITE
Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE
Content-Type: application/sdp
Proxy-Authorization: Digest username="1002",realm="192.168.31.109",nonce="5f046960-2eb0-484f-bf16-758576387c3f",uri="sip:1009@192.168.31.109:5060;transport=UDP",response="8bece954ef65ba0456abe71cf1243c6c",cnonce="5362af04830c3186db2b7bda9bb5585d",nc=00000001,qop=auth,algorithm=MD5
Supported: replaces, norefersub, extended-refer, timer, sec-agree, outbound, path, X-cisco-serviceuri
User-Agent: Zoiper v2.10.20.4_1
Allow-Events: presence, kpml, talk, as-feature-event
Content-Length: 264

v=0
o=Z 0 119481653 IN IP4 192.168.31.142
s=Z
c=IN IP4 192.168.31.142
t=0 0
m=audio 62715 RTP/AVP 3 101 110 97 8 0
a=rtpmap:101 telephone-event/8000
a=fmtp:101 0-16
a=rtpmap:110 speex/8000
a=rtpmap:97 iLBC/8000
a=fmtp:97 mode=20
a=sendrecv
a=rtcp-mux)";
    CHECK(baseMsg.parse(strInviteSipMsg));
    std::string strDump = baseMsg.dump();
    CHECK(strInviteSipMsg == strDump);
    //std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strInviteSipMsg, strDump);
    //std::cout << "COMMON: " << strCommon << std::_Get_asan_aligned_first_end;
}