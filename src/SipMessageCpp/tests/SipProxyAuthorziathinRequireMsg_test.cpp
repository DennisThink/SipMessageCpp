#include <doctest/doctest.h>
#include "SipProxyAuthorziathinRequireMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipProxyAuthorizationRequiresMsg baseMsg;
    std::string strSipMessageBase = R"(SIP/2.0 407 Proxy Authentication Required
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---78626c9dcaefb665;rport=55747
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=0e837329
To: <sip:1009@192.168.31.109:5060>;tag=3pDX04j1XvXam
Call-ID: cqBcUqknj-sTLjz_cI-GKw..
CSeq: 1 INVITE
User-Agent: FreeSWITCH-mod_sofia/1.10.12-release~a88d069d6f~64bit
Accept: application/sdp
Allow: INVITE, ACK, BYE, CANCEL, OPTIONS, MESSAGE, INFO, UPDATE, REGISTER, REFER, NOTIFY, PUBLISH, SUBSCRIBE
Supported: timer, path, replaces
Allow-Events: talk, hold, conference, presence, as-feature-event, dialog, line-seize, call-info, sla, include-session-description, presence.winfo, message-summary, refer
Proxy-Authenticate: Digest realm="192.168.31.109", nonce="5f046960-2eb0-484f-bf16-758576387c3f", algorithm=MD5, qop="auth"
Content-Length: 0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strResult = baseMsg.dump();
    CHECK(strResult== strSipMessageBase);

    //std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strResult, strSipMessageBase);
    //std::cout << "COMMON BEGIN: " << std::endl << strCommon << std::endl << "COMMEN END" << std::endl;



}