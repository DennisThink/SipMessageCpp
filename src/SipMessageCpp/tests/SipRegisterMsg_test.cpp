#include <doctest/doctest.h>
#include "SipRegisterMsg.hpp"

TEST_CASE("SipRegisterMsg_Case1"){
    DtSipMessageCpp::CSipRegisterMsg baseMsg;
    std::string strSipRegister =
        R"(REGISTER sip:192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---86aa6dd38424cee1;rport
Max-Forwards: 70
Contact: <sip:1002@192.168.31.142:55747;rinstance=59defe5c8b2788ae;transport=UDP>
To: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=88741f1c
Call-ID: gzK0vdfGjqqhSuekwhNwmg..
CSeq: 3 REGISTER
Expires: 60
Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE
Supported: replaces, norefersub, extended-refer, timer, sec-agree, outbound, path, X-cisco-serviceuri
User-Agent: Zoiper v2.10.20.4_1
Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5
Allow-Events: presence, kpml, talk, as-feature-event
Content-Length: 0)";
    CHECK(baseMsg.parse(strSipRegister));
    {
        {
            std::string strMsgType = R"(REGISTER sip:192.168.31.109:5060;transport=UDP SIP/2.0)";
            CHECK_EQ(baseMsg.m_strMsgType, strMsgType);
        }

        {
            std::string strVia = R"(Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---86aa6dd38424cee1;rport)";
            CHECK_EQ(baseMsg.m_strVia, strVia);
        }
        {
            std::string strMaxForwards = R"(Max-Forwards: 70)";
            CHECK_EQ(baseMsg.m_strMaxForwards, strMaxForwards);
        }
        {
            std::string strMaxForwards = R"(Max-Forwards: 70)";
            CHECK_EQ(baseMsg.m_strMaxForwards, strMaxForwards);
        }
        {
            std::string strTo = R"(To: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>)";
            CHECK_EQ(baseMsg.m_strTo, strTo);
        }
        {
            std::string strFrom = R"(From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=88741f1c)";
            CHECK_EQ(baseMsg.m_strFrom, strFrom);
        }
        {
            std::string strCallId = R"(Call-ID: gzK0vdfGjqqhSuekwhNwmg..)";
            CHECK_EQ(baseMsg.m_strCallId, strCallId);
        }

        {
            std::string strCSeq = R"(CSeq: 3 REGISTER)";
            CHECK_EQ(baseMsg.m_strCSeq, strCSeq);
        }
        {
            std::string strExpires = R"(Expires: 60)";
            CHECK_EQ(baseMsg.m_strExpires, strExpires);
        }
        {
            std::string strAllow = R"(Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE)";
            CHECK_EQ(baseMsg.m_strAllow, strAllow);
        }
        {
            std::string strSupported = R"(Supported: replaces, norefersub, extended-refer, timer, sec-agree, outbound, path, X-cisco-serviceuri)";
            CHECK_EQ(baseMsg.m_strSupported, strSupported);
        }
        {
            std::string strUserAgent = R"(User-Agent: Zoiper v2.10.20.4_1)";
            CHECK_EQ(baseMsg.m_strUserAgent, strUserAgent);
        }
        {
            std::string strAuthorization = R"(Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5)";
            CHECK_EQ(baseMsg.m_strAuthorization, strAuthorization);
        }
        {
            std::string strAllowEvents = R"(Allow-Events: presence, kpml, talk, as-feature-event)";
            CHECK_EQ(baseMsg.m_strAllowEvents, strAllowEvents);
        }
        {
            std::string strContentLength = R"(Content-Length: 0)";
            CHECK_EQ(baseMsg.m_strContentLength, strContentLength);
        }
    }
    CHECK(strSipRegister ==baseMsg.dump());
}