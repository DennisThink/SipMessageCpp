#include <doctest/doctest.h>
#include "SipOkMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipOkMsg baseMsg;
    std::string strSipMessageBase = R"(SIP/2.0 200 OK
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---974f0e190ebbfd0d;rport=55747
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=0e837329
To: <sip:1009@192.168.31.109:5060>;tag=4Z6N2Z34t5KXF
Call-ID: cqBcUqknj-sTLjz_cI-GKw..
CSeq: 2 INVITE
Contact: <sip:1009@192.168.31.109:5060;transport=udp>
User-Agent: FreeSWITCH-mod_sofia/1.10.12-release~a88d069d6f~64bit
Allow: INVITE, ACK, BYE, CANCEL, OPTIONS, MESSAGE, INFO, UPDATE, REGISTER, REFER, NOTIFY, PUBLISH, SUBSCRIBE
Supported: timer, path, replaces
Allow-Events: talk, hold, conference, presence, as-feature-event, dialog, line-seize, call-info, sla, include-session-description, presence.winfo, message-summary, refer
Content-Type: application/sdp
Content-Disposition: session
Content-Length: 272
Remote-Party-ID: "Outbound Call" <sip:1009@192.168.31.109>;party=calling;privacy=off;screen=no

v=0
o=FreeSWITCH 1726881924 1726881925 IN IP4 192.168.31.109
s=FreeSWITCH
c=IN IP4 192.168.31.109
t=0 0
m=audio 17734 RTP/AVP 8 101
a=rtpmap:8 PCMA/8000
a=rtpmap:101 telephone-event/8000
a=fmtp:101 0-15
a=ptime:20
a=rtcp-mux
a=rtcp:17734 IN IP4 192.168.31.109)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strResult = baseMsg.dump();
    CHECK(strResult== strSipMessageBase);
    if (strResult != strSipMessageBase)
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strResult, strSipMessageBase);
        std::cout << "COMMON BEGIN: " << std::endl << strCommon << std::endl << "COMMEN END" << std::endl;
    }
}