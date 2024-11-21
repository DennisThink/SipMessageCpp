#include "sip_client_protocal_handler.h"
#include "CSipMsgCpp.hpp"
#include "SipMsgBaseStruct.hpp"
#include "md5/md5.h"
#include <iostream>
enum class SIP_CLIENT_STATE
{
	UNKNOWN,
	NOT_REGISTER,
	DOING_REGISTER,
	REGISTER_FINISHED,
};
SIP_CLIENT_STATE g_sip_client_state = SIP_CLIENT_STATE::UNKNOWN;
sip_client_protocal_handler::sip_client_protocal_handler()
{

}

sip_client_protocal_handler::~sip_client_protocal_handler()
{

}



bool sip_client_protocal_handler::handle_current_message(const std::string strMsg)
{
	if (g_sip_client_state == SIP_CLIENT_STATE::DOING_REGISTER)
	{
        handle_first_register_rsp(strMsg);
        g_sip_client_state = SIP_CLIENT_STATE::REGISTER_FINISHED;
	}
	return false;
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

bool sip_client_protocal_handler::handle_first_register_rsp(const std::string strRsp)
{
    DtSipMessageCpp::CSipRegisterServerRsp rspMsg;
    rspMsg.parse(strRsp);

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
        wwwAuth.from_string(rspMsg.get_www_auth());
        std::string strCnonce = "c3606b3f70544096a7e17fcdb4670795";
        Authorization auth;
        {
            auth.set_user_name(m_str_user_name);
            auth.set_realm(wwwAuth.get_realm());
            auth.set_nonce(wwwAuth.get_nonce());
            auth.set_uri("sip:192.168.31.109:5060");//SipDigest?
            std::string strResponse = get_authorization_from_www_auth_for_client(
                rspMsg.get_www_auth(),
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

    m_strWaitForSend = secondRegMsg.dump();
    return true;
}
bool sip_client_protocal_handler::set_user_name_pass_word(const std::string strUserName, const std::string strPassWord)
{
	m_str_user_name = strUserName;
	m_str_pass_word = strPassWord;
	return true;
}
bool sip_client_protocal_handler::set_sip_server_ip_port(const std::string strIp, const int nPort)
{
	m_str_sip_server_ip = strIp;
	m_n_sip_server_port = nPort;
	return true;
}
bool sip_client_protocal_handler::set_sip_client_ip_port(const std::string strIp, const int nPort)
{
	m_str_sip_client_ip = strIp;
	m_n_sip_client_port = nPort;
	return true;
}


void sip_client_protocal_handler::do_register()
{
	g_sip_client_state = SIP_CLIENT_STATE::NOT_REGISTER;
	init_first_register();
}

std::string sip_client_protocal_handler::get_next_message()
{
	std::string strResult= m_strWaitForSend;
	m_strWaitForSend.clear();
	return strResult;
	
	return strResult;
}

void sip_client_protocal_handler::init_first_register()
{
	if (g_sip_client_state == SIP_CLIENT_STATE::NOT_REGISTER)
	{
		g_sip_client_state = SIP_CLIENT_STATE::DOING_REGISTER;
		{
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
				regMsg.set_sip_server_ip_port(m_str_sip_server_ip, m_n_sip_server_port);
				regMsg.set_sip_local_ip_port(m_str_sip_client_ip, m_n_sip_client_port);
				regMsg.set_net_type("UDP");
			}
			m_strWaitForSend = regMsg.dump();
		}
	}
}