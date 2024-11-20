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
From: "1002" <sip:1009@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
To: "1002" <sip:1009@192.168.31.109>
Call-ID: 7dacdb3605c94e659e588faa5e70af86
CSeq: 28959 REGISTER
User-Agent: DtSipClient/3.21.4
Contact: "1002" <sip:1009@192.168.31.109:64998;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Content-Length:  0)";
        regMsg.parse(strSipReg);
        regMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        //regMsg.set_username_password(strUser)
        regMsg.set_net_type("UDP");
    }

    std::string strFirstRegRsp;
    {    
        std::string strRegMsg = regMsg.dump();
        int nSendResult = client.send_message(strRegMsg);
        std::cout << "Send Result: " << nSendResult << std::endl;
        std::cout << "CLIENT SEND: " << std::endl << strRegMsg << std::endl;
        {
            std::cout << "LocalAddr: " << client.get_local_ip() << ":" << client.get_local_port() << std::endl;;
        }
        if (client.recv_message(strFirstRegRsp) > 0)
        {
            std::cout << "RSP: " << strFirstRegRsp << std::endl;
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
Contact: "1002" <sip:1009@192.168.31.109:64998;ob>
Expires: 300
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Authorization: Digest username="1002", realm="192.168.31.109", nonce="36fb7893-0612-4527-8d25-af2c14afeaec", uri="sip:192.168.31.109:5060", response="eb9d64a7b947554c160f9b5393cf2697", algorithm=MD5, cnonce="fc2d3c0e12fd4932873b5011bace6897", qop=auth, nc=00000001
Content-Length:  0)";
        secondRegMsg.parse(strDump);

        secondRegMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        secondRegMsg.set_net_type("UDP");
        {
            {
                DtSipMessageCpp::CSipRegisterServerRsp rspMsg;
                if (rspMsg.parse(strFirstRegRsp))
                {
                    std::cout << "WWW-AUTH:  " << rspMsg.get_www_auth() << std::endl;
                }

                //Parse WWW-AUTH
                {
                    WWW_AUTH wwwAuth;
                    if (wwwAuth.from_string(rspMsg.get_www_auth()))
                    {
                        std::cout << "REALM: " << wwwAuth.get_realm() << std::endl;
                        std::cout << "NONCE: " << wwwAuth.get_nonce() << std::endl;
                        std::cout << "ALGORITHM: " << wwwAuth.get_algorithm() << std::endl;
                        std::cout << "" << std::endl;
                    }
                    //https://www.cnblogs.com/yjmyzz/p/sip-register-authorization-algorithm.html
                    //HA1
                    std::string strHA1;
                    {
                        std::string strUser = "1002";
                        std::string strPass = "1234";
                        if ("MD5" == wwwAuth.get_algorithm())
                        {
                            std::string strHA1Source = strUser + ":" + wwwAuth.get_realm() + ":" + strPass;
                            strHA1 = MD5(strHA1Source).toStr();
                        }
                    }

                    //HA2
                    std::string strHA2;
                    {
                        std::string strMethod = "REGISTER";
                        std::string strDigest = "sip:192.168.31.109:5060;transport=udp";
                        if ("auth" == wwwAuth.get_qop())
                        {
                            std::string strHA2Source = strMethod + ":" + strDigest;
                            strHA2 = MD5(strHA2Source).toStr();
                        }
                    }

                    //Response
                    std::string strResponse;
                    {
                        if ("auth" == wwwAuth.get_qop())
                        {
                            std::string strCnonce = "c3606b3f70544096a7e17fcdb4670795";
                            //HA1:nonce:nonceCount:cnonce:qop:HA2
                            std::string strNonceCount = "00000002";
                            std::string strResponseSource = strHA1 + ":"
                                + wwwAuth.get_nonce() + ":"
                                + strNonceCount + ":"
                                + strCnonce + ":"
                                + wwwAuth.get_qop() + ":"
                                + strHA2;
                            strResponse = MD5(strResponseSource).toStr();
                        }
                    }
                    std::cout << "Response: " << strResponse << std::endl;

                    //Re-Register
                    {
                        Authorization auth;
                        {
                            auth.set_user_name(m_str_user_name);
                            auth.set_realm(wwwAuth.get_realm());
                            auth.set_nonce(wwwAuth.get_nonce());
                            auth.set_uri("sip:192.168.31.109:5060");//SipDigest?
                            auth.set_response(strResponse);
                            auth.set_cnonce("c3606b3f70544096a7e17fcdb4670795");
                            auth.set_nc("00000001");
                            auth.set_algorithm(wwwAuth.get_algorithm());
                            auth.set_qop(wwwAuth.get_qop());
                        }
                        std::string strNewAuth = auth.to_string();
                        std::cout << "NewAuth: " << strNewAuth << std::endl;
                        secondRegMsg.set_authorization(strNewAuth);
                    }
                }
            }
        }
    }

    std::string strRspMsg;
    {
        std::string strRegMsg = secondRegMsg.dump();
        int nSendResult = client.send_message(strRegMsg);
        std::cout << "Send Result: " << nSendResult << std::endl;
        std::cout << "CLIENT SEND: " << std::endl << strRegMsg << std::endl;
        {
            std::cout << "LocalAddr: " << client.get_local_ip() << ":" << client.get_local_port() << std::endl;;
        }
       

        if (client.recv_message(strRspMsg) > 0)
        {
            std::cout << "RSP: " << strRspMsg << std::endl;
        }
    }
}