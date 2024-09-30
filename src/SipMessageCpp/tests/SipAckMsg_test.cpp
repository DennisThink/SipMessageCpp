#include <doctest/doctest.h>
#include <iostream>
#include "SipAckMsg.hpp"
#include "SipMessageUtil.h"

TEST_CASE("SipAckMsg"){
    DtSipMessageCpp::CSipAckMsg baseMsg;
    std::string strSipMessageBase = R"(ACK sip:1009@192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---78626c9dcaefb665;rport
Max-Forwards: 70
To: <sip:1009@192.168.31.109:5060>;tag=3pDX04j1XvXam
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=0e837329
Call-ID: cqBcUqknj-sTLjz_cI-GKw..
CSeq: 1 ACK
Content-Length: 0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strResult = baseMsg.dump();
    CHECK(strResult== strSipMessageBase);
    {
        //std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strResult, strSipMessageBase);
        //std::cout << "COMMON BEGIN" << std::endl<< strCommon<<std::endl<<"COMMEND END"<<std::endl;
    }
}