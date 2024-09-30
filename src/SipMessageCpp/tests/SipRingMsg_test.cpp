#include <doctest/doctest.h>
#include "SipRingMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipRingMsg baseMsg;
    std::string strSipMessageBase = R"(SIP/2.0 180 Ringing
Via: SIP/2.0/UDP 192.168.31.109;rport=5060;received=192.168.31.109;branch=z9hG4bKmSymF8rmr1cvm
Call-ID: 81a36a1e-f284-123d-5799-f111227aced7
From: "Extension 1002" <sip:1002@192.168.31.109>;tag=58Ze4tm8QeagB
To: <sip:1009@192.168.31.109;ob>;tag=d4e3674ca23d4b22bebd2e39245254d5
CSeq: 88896036 INVITE
Contact: "1009" <sip:1009@192.168.31.109:60119;ob>
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strResult = baseMsg.dump();
    CHECK(strResult== strSipMessageBase);
    //std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipMessageBase, strResult);
    //std::cout << "COMMON: " << strCommon << std::_Get_asan_aligned_first_end;
}