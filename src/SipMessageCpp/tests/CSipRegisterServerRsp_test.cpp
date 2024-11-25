#include <doctest/doctest.h>
#include <iostream>
#include "CSipRegisterServerRsp.hpp"
#include "SipMessageUtil.h"
TEST_CASE("CSipRegisterServerRsp"){
    DtSipMessageCpp::CSipRegisterServerRsp baseMsg;
    std::string strSipMessageBase = R"(SIP/2.0 401 Unauthorized
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---86aa6dd38424cee1;rport=58888;received=192.168.31.109
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=88741f1c
To: "1002" <sip:1002@192.168.31.109:5060;transport=UDP>;tag=Qt4vrUUp8BymB
Call-ID: gzK0vdfGjqqhSuekwhNwmg
CSeq: 3 REGISTER
User-Agent: FreeSWITCH-mod_sofia/1.10.12-release~a88d069d6f~64bit
Allow: INVITE, ACK, BYE, CANCEL, OPTIONS, MESSAGE, INFO, UPDATE, REGISTER, REFER, NOTIFY, PUBLISH, SUBSCRIBE
Supported: timer, path, replaces
WWW-Authenticate: Digest realm="192.168.31.109", nonce="12e57fcc-cde4-4626-8d17-b7c104153d1c", stale=true, algorithm=MD5, qop="auth"
Content-Length: 0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    CHECK(401 == baseMsg.get_rsp_code());
    CHECK("Unauthorized" == baseMsg.get_rsp_code_msg());
    std::string strResult = baseMsg.dump();
    CHECK(strResult == strSipMessageBase);
    if(strResult != strSipMessageBase)
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strResult, strSipMessageBase);
        std::cout << "COMMON BEGIN: " << std::endl << strCommon << std::endl << "COMMEN END" << std::endl;
    }
}