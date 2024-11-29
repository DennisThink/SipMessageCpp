#include <doctest/doctest.h>
#include "SipInviteMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("SipInviteMsg"){
    DtSipMessageCpp::CSipInviteMsg baseMsg;
    std::string strInviteSipMsg = R"(INVITE sip:1003@192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64207;rport;branch=z9hG4bKPj5d9cf2173f8748fb8eae410cca19e608
Max-Forwards: 70
From: "1009" <sip:1009@192.168.31.109>;tag=b1a2a0c71da843c18a7229f8e2bec388
To: <sip:1003@192.168.31.109>
Contact: "1009" <sip:1009@192.168.31.109:64207;ob>
Call-ID: daaef89acfb14520a2baac777cb451e0
CSeq: 24116 INVITE
Route: <sip:192.168.31.109:5060;lr>
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Supported: replaces, 100rel, timer, norefersub
Session-Expires: 1800
Min-SE: 90
User-Agent: MicroSIP/3.21.4
Content-Type: application/sdp
Content-Length:   346

v=0
o=- 3941701346 3941701346 IN IP4 192.168.31.109
s=pjmedia
b=AS:84
t=0 0
a=X-nat:0
m=audio 4004 RTP/AVP 8 0 101
c=IN IP4 192.168.31.109
b=TIAS:64000
a=rtcp:4005 IN IP4 192.168.31.109
a=sendrecv
a=rtpmap:8 PCMA/8000
a=rtpmap:0 PCMU/8000
a=rtpmap:101 telephone-event/8000
a=fmtp:101 0-16
a=ssrc:1938577929 cname:7d03491459126035)";
    CHECK(baseMsg.parse(strInviteSipMsg));
    //CHECK_ALL_LINES
    {
        {
            std::string strHeaderLine = "INVITE sip:1003@192.168.31.109:5060 SIP/2.0";
            CHECK(strHeaderLine == baseMsg.get_header_line());
        } 
        {
            std::string strViaLine = "Via: SIP/2.0/UDP 192.168.31.109:64207;rport;branch=z9hG4bKPj5d9cf2173f8748fb8eae410cca19e608";
            CHECK(strViaLine == baseMsg.get_via_line());
        }

        {
            std::string strMaxForwardsLine = "Max-Forwards: 70";
            CHECK(strMaxForwardsLine == baseMsg.get_max_forwards_line());
        }

        {
            std::string strFromLine = R"(From: "1009" <sip:1009@192.168.31.109>;tag=b1a2a0c71da843c18a7229f8e2bec388)";
            CHECK(strFromLine == baseMsg.get_from_line());
        }

        {
            std::string strToLine = "To: <sip:1003@192.168.31.109>";
            CHECK(strToLine == baseMsg.get_to_line());
        }

        {
            std::string strContactLine = R"(Contact: "1009" <sip:1009@192.168.31.109:64207;ob>)"; 
            CHECK(strContactLine == baseMsg.get_contact_line());
        }
        {
            std::string strCallId = "Call-ID: daaef89acfb14520a2baac777cb451e0";
            CHECK(strCallId == baseMsg.get_call_id_line());
        }

        {
            std::string strCSeqLine = "CSeq: 24116 INVITE";
            CHECK(strCSeqLine == baseMsg.get_c_seq_line());
        }

        {
            std::string strRouteLine = "Route: <sip:192.168.31.109:5060;lr>";
            CHECK(strRouteLine == baseMsg.get_route_line());
        }

        {
            std::string strAllowLine = "Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS";
            CHECK(strAllowLine == baseMsg.get_allow_line());
        }

        {
            std::string strSupportedLine = "Supported: replaces, 100rel, timer, norefersub";
            CHECK(strSupportedLine == baseMsg.get_supported_line());
        }

        {
            std::string strSessionExiresLine = "Session-Expires: 1800";
            CHECK(strSessionExiresLine == baseMsg.get_session_expires_line());
        }

        {
            std::string strMinSeLine = "Min-SE: 90";
            CHECK(strMinSeLine == baseMsg.get_min_se_line());
        }

        {
            std::string strUserAgentLine = "User-Agent: MicroSIP/3.21.4";
            CHECK(strUserAgentLine == baseMsg.get_user_agent_line());
        }

        {
            std::string strContentTypeLine = "Content-Type: application/sdp";
            CHECK(strContentTypeLine == baseMsg.get_content_type_line());
        }

        {
            std::string strContentLengthLine = "Content-Length:   346";
            CHECK(strContentLengthLine == baseMsg.get_content_length_line());
        }
        {

        }
    }
    //CHECK_SET
    {
        DtSipMessageCpp::CSipInviteMsg createMsg;

        {

            std::string strCalled = "1003";
            std::string strUser = "1009";
            std::string strPassword = "1234";
            std::string strServerIp = "192.168.31.109";
            int serverPort = 5060;
            std::string strLocalIp = "192.168.31.109";
            int localPort = 64207;
            std::string strNetType = "UDP";
            std::string strAllowOptions = "Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS";
            std::string strCallId = "Call-ID: daaef89acfb14520a2baac777cb451e0";
            std::string strContentLength = "Content-Length:  0";
            std::string strBranch = "z9hG4bKPj5d9cf2173f8748fb8eae410cca19e608";
            std::string strMaxForwards = "Max-Forwards: 70";
            std::string strFromTag = "b1a2a0c71da843c18a7229f8e2bec388";
            std::string strCSeq = "CSeq: 28959 REGISTER";
            std::string strSupported = "Supported: replaces, 100rel, timer, norefersub";
            {
                createMsg.set_called_number(strCalled);
                createMsg.set_username_password(strUser, strPassword);
                createMsg.set_sip_server_ip_port(strServerIp, serverPort);
                createMsg.set_sip_local_ip_port(strLocalIp, localPort);
                createMsg.set_net_type(strNetType);
                createMsg.set_allow_options(strAllowOptions);
                createMsg.set_call_id(strCallId);
                //createMsg.set_content_length(strContentLength);
                createMsg.set_branch(strBranch);
                createMsg.set_max_forwards(strMaxForwards);
                createMsg.set_from_tag(strFromTag);
                createMsg.set_username_password(strUser, strPassword);
                createMsg.set_c_seq(24116);
                createMsg.set_session_expires(1800);
                createMsg.set_min_se(90);
                createMsg.set_branch(strBranch);
                createMsg.set_route("Route: <sip:192.168.31.109:5060;lr>");
                createMsg.set_supported_line(strSupported);
                createMsg.set_user_agent("MicroSIP/3.21.4");
                createMsg.set_content_type("application/sdp");
                createMsg.set_content_length(346);
                //createMsg.
            }
        }
        //createMsg.set_c_seq();
        createMsg.create_all_lines();
        createMsg.create_contact_line();
        createMsg.create_session_expires_line();
        createMsg.create_min_se_line();
        createMsg.create_user_agent_line();
        createMsg.create_content_type_line();
        createMsg.create_content_length_line();
        {
            CHECK(createMsg.get_header_line() == baseMsg.get_header_line());
        }
        {
            std::string strViaLine = "Via: SIP/2.0/UDP 192.168.31.109:64207;rport;branch=z9hG4bKPj5d9cf2173f8748fb8eae410cca19e608";
            CHECK(createMsg.get_via_line() == baseMsg.get_via_line());
        }

        {
            std::string strMaxForwardsLine = "Max-Forwards: 70";
            CHECK(createMsg.get_max_forwards_line() == baseMsg.get_max_forwards_line());
        }

        {
            std::string strFromLine = R"(From: "1009" <sip:1009@192.168.31.109>;tag=b1a2a0c71da843c18a7229f8e2bec388)";
            CHECK(createMsg.get_from_line() == baseMsg.get_from_line());
        }

        {
            std::string strToLine = "To: <sip:1003@192.168.31.109>";
            CHECK(createMsg.get_to_line() == baseMsg.get_to_line());
        }

        {
            std::string strContactLine = R"(Contact: "1009" <sip:1009@192.168.31.109:64207;ob>)";
            CHECK(createMsg.get_contact_line() == baseMsg.get_contact_line());
        }
        {
            std::string strCallId = "Call-ID: daaef89acfb14520a2baac777cb451e0";
            CHECK(createMsg.get_call_id_line() == baseMsg.get_call_id_line());
        }

        {
            std::string strCSeqLine = "CSeq: 24116 INVITE";
            CHECK(createMsg.get_c_seq_line() == baseMsg.get_c_seq_line());
        }

        {
            std::string strRouteLine = "Route: <sip:192.168.31.109:5060;lr>";
            CHECK(createMsg.get_route_line() == baseMsg.get_route_line());
        }

        {
            std::string strAllowLine = "Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS";
            CHECK(createMsg.get_allow_line() == baseMsg.get_allow_line());
        }

        {
            std::string strSupportedLine = "Supported: replaces, 100rel, timer, norefersub";
            CHECK(createMsg.get_supported_line() == baseMsg.get_supported_line());
        }

        {
            std::string strSessionExiresLine = "Session-Expires: 1800";
            CHECK(createMsg.get_session_expires_line() == baseMsg.get_session_expires_line());
        }

        {
            std::string strMinSeLine = "Min-SE: 90";
            CHECK(createMsg.get_min_se_line() == baseMsg.get_min_se_line());
        }

        {
            std::string strUserAgentLine = "User-Agent: MicroSIP/3.21.4";
            CHECK(createMsg.get_user_agent_line() == baseMsg.get_user_agent_line());
        }

        {
            std::string strContentTypeLine = "Content-Type: application/sdp";
            CHECK(createMsg.get_content_type_line() == baseMsg.get_content_type_line());
        }

        {
            std::string strContentLengthLine = "Content-Length:   346";
            CHECK(createMsg.get_content_length_line() == baseMsg.get_content_length_line());
        }
        {

        }
    }
    std::string strDump = baseMsg.dump();
    CHECK(strInviteSipMsg == strDump);
    if (strInviteSipMsg != strDump)
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strInviteSipMsg, strDump);
        std::cout << "COMMON: " << strCommon <<std::endl<< "COMMON END" << std::endl;
    }
}