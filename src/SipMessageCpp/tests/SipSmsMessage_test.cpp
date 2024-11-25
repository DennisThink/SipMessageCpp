#include <doctest/doctest.h>
#include "SipSmsMessage.hpp"
#include "SipMessageUtil.h"
#include <iostream>

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipSmsMessage baseMsg;
    std::string strSipMessageBase = R"(MESSAGE sip:1009@192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:50757;branch=z9hG4bK-524287-1---924a4031843731a9;rport
Max-Forwards: 70
To: <sip:1009@192.168.31.109:5060;transport=UDP>
From: "1003"<sip:1003@192.168.31.109:5060;transport=UDP>;tag=f39ef304
Call-ID: EVT_xLB_dIPYDUi2URkpgQ
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
        CHECK(R"(Call-ID: EVT_xLB_dIPYDUi2URkpgQ)" == baseMsg.get_call_id_line());
        CHECK(R"(Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE)"==baseMsg.get_allow_line());
        CHECK(R"(User-Agent: Zoiper v2.10.20.4_1)" == baseMsg.get_user_agent_line());
        CHECK(R"(Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE)" == baseMsg.get_allow_line());
        CHECK(R"(Allow-Events: presence, kpml, talk, as-feature-event)" == baseMsg.get_allow_events_line());
    }
    DtSipMessageCpp::CSipSmsMessage createSmsMsg;
    {

        //variables 
        
        //SET 
        {
            std::string strSender = "1003";
            std::string strReciver = "1009";
            std::string strPassword = "1234";
            std::string strServerIp = "192.168.31.109";
            int serverPort = 5060;
            std::string strLocalIp = "192.168.31.109";
            int localPort = 64998;

            std::string strViaIp = "192.168.31.142";
            int viaPort = 50757;

            std::string strNetType = "UDP";
            std::string strAllowOptions = "Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE";
            std::string strAllowEvents = "Allow-Events: presence, kpml, talk, as-feature-event";
            std::string strCallId = "Call-ID: EVT_xLB_dIPYDUi2URkpgQ";
            std::string strBranch = "z9hG4bK-524287-1---924a4031843731a9";
            std::string strMaxForwards = "Max-Forwards: 70";
            std::string strFromTag = "f39ef304";
            std::string strCSeq = "CSeq: 2 MESSAGE";
            std::string strUserAgent = "User-Agent: Zoiper v2.10.20.4_1";
            std::string strContent = "1234";
            std::string strContentLength = "Content-Length: 4";
            std::string strContentType = "Content-Type: text/plain";
            //SET variable
            {
                createSmsMsg.set_sip_server_ip_port(strServerIp, serverPort);
                createSmsMsg.set_sip_local_ip_port(strLocalIp, localPort);
                createSmsMsg.add_via_ip_port(strViaIp, viaPort);
                createSmsMsg.set_net_type(strNetType);
                createSmsMsg.set_allow_options(strAllowOptions);
                createSmsMsg.set_call_id(strCallId);
                createSmsMsg.set_content_length(strContentLength);
                createSmsMsg.set_branch(strBranch);
                createSmsMsg.set_max_forwards(strMaxForwards);
                createSmsMsg.set_from_tag(strFromTag);
                createSmsMsg.set_sender(strSender);
                createSmsMsg.set_reciver(strReciver);
                createSmsMsg.set_c_seq(strCSeq);
                createSmsMsg.set_user_agent(strUserAgent);
                createSmsMsg.set_allow_events(strAllowEvents);
                createSmsMsg.set_content(strContent);
                createSmsMsg.set_content_type(strContentType);
                //createSmsMsg.set_con
                createSmsMsg.set_content_length(strContentLength);
            }

            //create
            {
                createSmsMsg.create_header_line();
                createSmsMsg.create_via_line();
                createSmsMsg.create_from_line();
                createSmsMsg.create_to_line();
            }
        }
        //CHECK
        {
            CHECK(createSmsMsg.get_header_line() == baseMsg.get_header_line());
            CHECK(createSmsMsg.get_via_line() == baseMsg.get_via_line());
            CHECK(createSmsMsg.get_max_forwards_line() == baseMsg.get_max_forwards_line());
            CHECK(createSmsMsg.get_to_line() == baseMsg.get_to_line());
            CHECK(createSmsMsg.get_from_line() == baseMsg.get_from_line());
            CHECK(createSmsMsg.get_call_id_line() == baseMsg.get_call_id_line());
            CHECK(createSmsMsg.get_allow_line() == baseMsg.get_allow_line());
            CHECK(createSmsMsg.get_user_agent_line() == baseMsg.get_user_agent_line());
            CHECK(createSmsMsg.get_allow_line() == baseMsg.get_allow_line());
            CHECK(createSmsMsg.get_allow_events_line() == baseMsg.get_allow_events_line());
            CHECK(createSmsMsg.get_content_length_line() == baseMsg.get_content_length_line());
        }
    }

    baseMsg.create_header_line();
    baseMsg.create_via_line();
    baseMsg.create_from_line();
    {
        std::string strDump = baseMsg.dump();
        CHECK(strSipMessageBase == strDump);
        if (strSipMessageBase != strDump)
        {
            std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strDump, strSipMessageBase);
            std::cout << "COMMON BEGIN: " << std::endl << strCommon << std::endl << "COMMEN END" << std::endl;
        }
    }
    {
        std::string strDump = createSmsMsg.dump();
        CHECK(strSipMessageBase == strDump);
        if (strSipMessageBase != strDump)
        {
            std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strDump, strSipMessageBase);
            std::cout << "COMMON BEGIN: " << std::endl << strCommon << std::endl << "COMMEN END" << std::endl;
        }
    }
}