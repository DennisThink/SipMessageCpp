#include <doctest/doctest.h>
#include "SipRegisterMsg.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("SipRegisterMsg_Case1"){
    DtSipMessageCpp::CSipRegisterMsg baseMsg;
    std::string strSipRegister =
        R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64565;rport;branch=z9hG4bKPj9c79bce7877f493a949a0442ef6a78c3
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1009" <sip:1009@192.168.31.109>;tag=b1a5cb34bf4443ee9d2aba31f7414e78
To: "1009" <sip:1009@192.168.31.109>
Call-ID: da72dbf2beb54974a12db2a38ad2aa3e
CSeq: 39245 REGISTER
User-Agent: MicroSIP/3.21.4
Contact: "1009" <sip:1009@192.168.31.109:64565;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0)";
    //CHECK_PARSE
    {
        CHECK(baseMsg.parse(strSipRegister));
        {
            {
                std::string strMsgType = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0)";
                CHECK_EQ(baseMsg.get_header_line(), strMsgType);
            }

            {
                std::string strVia = R"(Via: SIP/2.0/UDP 192.168.31.109:64565;rport;branch=z9hG4bKPj9c79bce7877f493a949a0442ef6a78c3)";
                CHECK_EQ(baseMsg.get_via_line(), strVia);
            }
            {
                std::string strMaxForwards = R"(Max-Forwards: 70)";
                CHECK_EQ(baseMsg.get_max_forwards_line(), strMaxForwards);
            }
            {
                std::string strTo = R"(To: "1009" <sip:1009@192.168.31.109>)";
                CHECK_EQ(baseMsg.get_to_line(), strTo);
            }
            {
                std::string strFrom = R"(From: "1009" <sip:1009@192.168.31.109>;tag=b1a5cb34bf4443ee9d2aba31f7414e78)";
                CHECK_EQ(baseMsg.get_from_line(), strFrom);
            }
            {
                std::string strCallId = R"(Call-ID: da72dbf2beb54974a12db2a38ad2aa3e)";
                CHECK_EQ(baseMsg.get_call_id_line(), strCallId);
            }

            {
                std::string strCSeq = R"(CSeq: 39245 REGISTER)";
                CHECK_EQ(baseMsg.get_c_seq_line(), strCSeq);
            }
            {
                std::string strExpires = R"(Expires: 300)";
                CHECK_EQ(baseMsg.get_expires_line(), strExpires);
            }
            {
                std::string strAllow = R"(Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS)";
                CHECK_EQ(baseMsg.get_allow_line(), strAllow);
            }
            /* {
                std::string strSupported = R"(Supported: replaces, norefersub, extended-refer, timer, sec-agree, outbound, path, X-cisco-serviceuri)";
                CHECK_EQ(baseMsg.get_supported_line(), strSupported);
            }*/
            {
                std::string strUserAgent = R"(User-Agent: MicroSIP/3.21.4)";
                CHECK_EQ(baseMsg.get_user_agent_line(), strUserAgent);
            }
            {
                std::string strContentLength = R"(Content-Length:  0)";
                CHECK_EQ(baseMsg.get_content_length_line(), strContentLength);
            }
        }
        /*std::string strSipRegDump = baseMsg.dump();
        CHECK(strSipRegister == strSipRegDump);
        if (strSipRegister != strSipRegDump)
        {
            std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipRegister, strSipRegDump);
            std::cout << "COMMON BEGIN" << std::endl << strCommon << std::endl << "COMMEND END" << std::endl;
        }*/
    }
    //CHECK_CREATE
    {

    }
    

}

TEST_CASE("TEST2") {
    if (0)
    {
        std::string strSipReg = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64565;rport;branch=z9hG4bKPj9c79bce7877f493a949a0442ef6a78c3
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1009" <sip:1009@192.168.31.109>;tag=b1a5cb34bf4443ee9d2aba31f7414e78
To: "1009" <sip:1009@192.168.31.109>
Call-ID: da72dbf2beb54974a12db2a38ad2aa3e
CSeq: 39245 REGISTER
User-Agent: MicroSIP/3.21.4
Contact: "1009" <sip:1009@192.168.31.109:64565;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0)";
        DtSipMessageCpp::CSipRegisterMsg baseMsg;
        CHECK(baseMsg.parse(strSipReg));
        std::string strSipRegDump = baseMsg.dump();
        DtSipMessageCpp::CSipRegisterMsg baseMsgDump;
        CHECK(baseMsgDump.parse(strSipRegDump));
        std::string strSipDump2 = baseMsgDump.dump();
        CHECK_EQ(strSipRegDump, strSipDump2);
        if (strSipRegDump != strSipDump2)
        {
            std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipRegDump, strSipDump2);
            std::cout << "COMMON BEGIN" << std::endl << strCommon << std::endl << "COMMEND END" << std::endl;
        }
    }
}


TEST_CASE("SipRegisterNext") {
    if (0)
    {
        std::string strSipReg = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1009" <sip:1009@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
To: "1009" <sip:1009@192.168.31.109>
Call-ID: 7dacdb3605c94e659e588faa5e70af86
CSeq: 28959 REGISTER
User-Agent: MicroSIP/3.21.4
Contact: "1009" <sip:1009@192.168.31.109:64998;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0
)";
        DtSipMessageCpp::CSipRegisterMsg regMsg;
        regMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        regMsg.set_sip_local_ip_port("192.168.31.109", 64998);
        regMsg.set_net_type("UDP");
        std::string strBranch = "z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69";
        regMsg.set_branch(strBranch);
        {
            std::string strDump = regMsg.dump();
            CHECK(strDump == strSipReg);
            if (strDump != strSipReg)
            {
                std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strDump, strSipReg);
                std::cout << "COMMON BEGIN: " << strCommon << std::endl << " COMMON END " << std::endl;
            }
        }
    }
}