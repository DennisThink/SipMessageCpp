#include "sip_client.h"
#include "simple_cpp_sockets.h"
#include "SipMsgBaseStruct.hpp"
#include "CSipMsgCpp.hpp"
#include "md5/md5.h"
#include "SipMessageUtil.h"
SipClient::SipClient()
{

}
SipClient::~SipClient()
{

}

void SipClient::set_user_name(const std::string str_user_name)
{
	m_str_user_name = str_user_name;
}
void SipClient::set_pass_word(const std::string str_pass_word)
{
	m_str_pass_word = str_pass_word;
}
void SipClient::set_sip_server_addr(const std::string serverIp, const int port)
{
	m_str_sip_server_ip = serverIp;
	m_sip_server_port = port;
}
void SipClient::send_sms(const std::string strReciver, const std::string strSms)
{
    register_to_server();
}
std::string SipClient::recv_sms()
{
	return "";
}


static std::string get_authorization_from_www_auth_for_client(const std::string& strWwwAuth, const std::string strUser, const std::string strPass, const std::string strCnonce, const std::string strUri)
{
    WWW_AUTH wwwAuth;
    std::string strMethod = "REGISTER";
    std::string strNonceCount = "00000001";
    std::string strResponse;
    if (wwwAuth.from_string(strWwwAuth))
    {
        //HA1
        std::string strHA1;
        {
            std::string strRealm = wwwAuth.get_realm();

            std::string strHA1Source = strUser + ":" + strRealm + ":" + strPass;
            strHA1 = MD5(strHA1Source).toStr();
        }

        //HA2
        std::string strHA2;
        {

            std::string strDigest = strUri;
            std::string strHA2Source = strMethod + ":" + strDigest;
            strHA2 = MD5(strHA2Source).toStr();
        }

        //Response

        {

            std::string strNonce = wwwAuth.get_nonce();// "36fb7893-0612-4527-8d25-af2c14afeaec";
            //HA1:nonce:nonceCount:cnonce:qop:HA2

            std::string strQop = wwwAuth.get_qop();
            std::string strResponseSource = strHA1 + ":"
                + strNonce + ":"
                + strNonceCount + ":"
                + strCnonce + ":"
                + strQop + ":"
                + strHA2;
            std::cout << "ResponseSource:" << strResponseSource << std::endl;
            strResponse = MD5(strResponseSource).toStr();
            //std::string strStdResponse = "eb9d64a7b947554c160f9b5393cf2697";
            //CHECK(strResponse == strStdResponse);
        }
    }
    return strResponse;
}

void SipClient::register_to_server()
{
    UDPClient client(5060, "192.168.31.109");
    //First Time Register
    DtSipMessageCpp::CSipRegisterMsg regMsg;
    {
        std::string strSipReg = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1002" <sip:1002@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
To: "1002" <sip:1002@192.168.31.109>
Call-ID: 7dacdb3605c94e659e588faa5e70af86
CSeq: 28959 REGISTER
User-Agent: DtSipClient/3.21.4
Contact: "1002" <sip:1002@192.168.31.109:64998;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0)";
        regMsg.parse(strSipReg);
        regMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        regMsg.set_sip_local_ip_port(client.get_local_ip(), client.get_local_port());
        //regMsg.set_username_password(strUser)
        regMsg.set_net_type("UDP");
    }

    DtSipMessageCpp::CSipRegisterServerRsp firstRegRspMsg;
    {    
        std::string strRegMsg = regMsg.dump();
        int nSendResult = client.send_message(strRegMsg);
        std::cout << "Send Result: " << nSendResult << std::endl;
        std::cout << "CLIENT SEND: " << std::endl << strRegMsg << std::endl;
        {
            std::cout << "LocalAddr: " << client.get_local_ip() << ":" << client.get_local_port() << std::endl;;
        }
        std::string strFirstRegRsp;
        if (client.recv_message(strFirstRegRsp) > 0)
        {
            std::cout << "RSP: " << strFirstRegRsp << std::endl;
        }
        if (firstRegRspMsg.parse(strFirstRegRsp))
        {
            std::cout << "Send First Reg succeed" << std::endl;
        }
    }

    DtSipMessageCpp::CSipRegisterMsg secondRegMsg;
    {
        std::string strDump = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPja4bf5bc9a06b4a9f9413f9c143242321
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1002" <sip:1002@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
To: "1002" <sip:1002@192.168.31.109>
Call-ID: 7dacdb3605c94e659e588faa5e70af86
CSeq: 28960 REGISTER
User-Agent: DtSipClient/3.21.4
Contact: "1002" <sip:1002@192.168.31.109:64998;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Authorization: Digest username="1002", realm="192.168.31.109", nonce="36fb7893-0612-4527-8d25-af2c14afeaec", uri="sip:192.168.31.109:5060", response="eb9d64a7b947554c160f9b5393cf2697", algorithm=MD5, cnonce="fc2d3c0e12fd4932873b5011bace6897", qop=auth, nc=00000001
Content-Length:  0)";
        secondRegMsg.parse(strDump);

        secondRegMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        secondRegMsg.set_net_type("UDP");
    }
    
    {
        WWW_AUTH wwwAuth;
        wwwAuth.from_string(firstRegRspMsg.get_www_auth());
        std::string strCnonce = "c3606b3f70544096a7e17fcdb4670795";
        Authorization auth;
        {
            auth.set_user_name(m_str_user_name);
            auth.set_realm(wwwAuth.get_realm());
            auth.set_nonce(wwwAuth.get_nonce());
            auth.set_uri("sip:192.168.31.109:5060");//SipDigest?
            std::string strResponse = get_authorization_from_www_auth_for_client(
                firstRegRspMsg.get_www_auth(),
                m_str_user_name,
                m_str_pass_word,
                strCnonce,
                "sip:192.168.31.109:5060");
            auth.set_response(strResponse);
            auth.set_cnonce(strCnonce);
            auth.set_nc("00000001");
            auth.set_algorithm(wwwAuth.get_algorithm());
            auth.set_qop(wwwAuth.get_qop());
        }
        secondRegMsg.set_authorization(auth.to_string());
    }
    {
        std::string strRegMsg = secondRegMsg.dump();
        int nSendResult = client.send_message(strRegMsg);
        std::cout << "Send Result: " << nSendResult << std::endl;
        std::cout << "CLIENT SEND: " << std::endl << strRegMsg << std::endl;
        {
            std::cout << "LocalAddr: " << client.get_local_ip() << ":" << client.get_local_port() << std::endl;;
        }
        std::string strFirstRegRsp;
        if (client.recv_message(strFirstRegRsp) > 0)
        {
            std::cout << "RSP: " << strFirstRegRsp << std::endl;
        }
    }

}