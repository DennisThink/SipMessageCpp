#include <doctest/doctest.h>
#include "SipByeMsg.hpp"

TEST_CASE("SipByeMsg"){
    DtSipMessageCpp::CSipByeMsg baseMsg;
    std::string strSipMessageBase = R"(BYE sip:mod_sofia@192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:60119;rport;branch=z9hG4bKPjf3b1d22a5602462d8ca11d6db5fad320
Max-Forwards: 70
From: <sip:1009@192.168.31.109;ob>;tag=d4e3674ca23d4b22bebd2e39245254d5
To: "Extension 1002" <sip:1002@192.168.31.109>;tag=58Ze4tm8QeagB
Call-ID: 81a36a1e-f284-123d-5799-f111227aced7
CSeq: 30422 BYE
User-Agent: MicroSIP/3.21.4
Content-Length:  0)";
    CHECK(baseMsg.parse(strSipMessageBase));
    std::string strDump = baseMsg.dump();
    CHECK(strSipMessageBase == strDump);
}