#include <doctest/doctest.h>
#include "SipTryingMsg.hpp"

TEST_CASE("SipTryingMsg"){
    DtSipMessageCpp::CSipTryingMsg baseMsg;
    std::string strSipMessageBase = R"(SIP/2.0 100 Trying
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---974f0e190ebbfd0d;rport=55747
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=0e837329
To: <sip:1009@192.168.31.109:5060>
Call-ID: cqBcUqknj-sTLjz_cI-GKw..
CSeq: 2 INVITE
User-Agent: FreeSWITCH-mod_sofia/1.10.12-release~a88d069d6f~64bit
Content-Length: 0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strResult = baseMsg.dump();
    CHECK(strResult== strSipMessageBase);
}