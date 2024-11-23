#include <doctest/doctest.h>
#include "SipSmsMessage.hpp"

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipSmsMessage baseMsg;
    std::string strSipMessageBase = R"(MESSAGE sip:1009@192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:50757;branch=z9hG4bK-524287-1---924a4031843731a9;rport
Max-Forwards: 70
To: <sip:1009@192.168.31.109:5060;transport=UDP>
From: "1003"<sip:1003@192.168.31.109:5060;transport=UDP>;tag=f39ef304
Call-ID: EVT_xLB_dIPYDUi2URkpgQ..
CSeq: 2 MESSAGE
Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE
Content-Type: text/plain
User-Agent: Zoiper v2.10.20.4_1
Allow-Events: presence, kpml, talk, as-feature-event
Content-Length: 4

1234)";
    CHECK(baseMsg.parse(strSipMessageBase));
    {
        CHECK("MESSAGE sip:1009@192.168.31.109:5060;transport=UDP SIP/2.0"==baseMsg.get_header_line());
        CHECK("Via: SIP/2.0/UDP 192.168.31.142:50757;branch=z9hG4bK-524287-1---924a4031843731a9;rport"==baseMsg.get_via_line());
        CHECK("Max-Forwards: 70"==baseMsg.get_max_forwards_line());
        CHECK(R"(To: <sip:1009@192.168.31.109:5060;transport=UDP>)" == baseMsg.get_to_line());
        CHECK(R"(From: "1003"<sip:1003@192.168.31.109:5060;transport=UDP>;tag=f39ef304)" == baseMsg.get_from_line());
        CHECK(R"(Call-ID: EVT_xLB_dIPYDUi2URkpgQ..)" == baseMsg.get_call_id_line());
        CHECK(R"(Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE)"==baseMsg.get_allow_line());
        CHECK(R"(User-Agent: Zoiper v2.10.20.4_1)" == baseMsg.get_user_agent_line());
        CHECK(R"(Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE)" == baseMsg.get_allow_line());
        CHECK(R"(Allow-Events: presence, kpml, talk, as-feature-event)" == baseMsg.get_allow_events_line());
    }

    CHECK(strSipMessageBase ==baseMsg.dump());
}