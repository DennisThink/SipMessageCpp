#include "sip_client_protocal_handler.h"
#include "CSipMsgCpp.hpp"
#include "SipReRegisterMsg.hpp"
#include "SipSmsMessage.hpp"
#include "SipMsgBaseStruct.hpp"
#include "SipMessageUtil.h"
#include "md5/md5.h"
#include <iostream>
std::string get_authorization_from_www_auth_for_client(const std::string strMethod,const std::string& strWwwAuth, const std::string strUser, const std::string strPass, const std::string strCnonce, const std::string strUri);
enum class SIP_CLIENT_STATE
{
    UNKNOWN,
    START_STATE,
    NOT_REGISTER,
    DOING_REGISTER,
    REGISTER_FINISHED,
    SENDING_SMS,
    END_END_STATE,
};
SIP_CLIENT_STATE g_sip_client_state = SIP_CLIENT_STATE::UNKNOWN;
sip_client_protocal_handler::sip_client_protocal_handler()
{
    srand(time(0));
    m_n_c_seq = rand() % 1000;
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
    if (g_sip_client_state == SIP_CLIENT_STATE::SENDING_SMS)
    {
        handle_first_send_sms(strMsg);
        g_sip_client_state = SIP_CLIENT_STATE::REGISTER_FINISHED;
    }
	return false;
}
std::string sip_client_protocal_handler::get_first_register_message()
{
    DtSipMessageCpp::CSipRegisterMsg regCreateMsg;
    {
        std::string strNetType = "UDP";
        std::string strAllowOptions = "Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS";
        //std::string strCallId = "Call-ID: 7dacdb3605c94e659e588faa5e70af86";
        std::string strCallId = "Call-ID: " + m_str_call_id;
        std::string strContentLength = "Content-Length:  0";
        std::string strBranch = "z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69";
        std::string strMaxForwards = "Max-Forwards: 70";
        std::string strFromTag = "a2c95cb6bbf84183a634b0244b09dcd9";
        std::string strCSeq = "CSeq: "+create_c_seq() + " REGISTER";
        {
            regCreateMsg.set_sip_server_ip_port(m_str_sip_server_ip,m_n_sip_server_port);
            regCreateMsg.set_sip_local_ip_port(m_str_sip_client_ip,m_n_sip_client_port);
            regCreateMsg.set_net_type(strNetType);
            regCreateMsg.set_allow_options(strAllowOptions);
            regCreateMsg.set_call_id(strCallId);
            regCreateMsg.set_content_length(strContentLength);
            regCreateMsg.set_branch(strBranch);
            regCreateMsg.set_max_forwards(strMaxForwards);
            regCreateMsg.set_from_tag(strFromTag);
            regCreateMsg.set_username_password(m_str_user_name,m_str_pass_word);
            regCreateMsg.set_c_seq(strCSeq);
        }

        {
            regCreateMsg.create_header_line();
            regCreateMsg.create_via_line();
            regCreateMsg.create_from_line();
            regCreateMsg.create_to_line();
        }
    }
    std::string strResult = regCreateMsg.dump();
    return strResult;
}


std::string sip_client_protocal_handler::get_second_register_message(const std::string& strRsp)
{
    std::string strResult;
    {
        DtSipMessageCpp::CSipReRegisterMsg reqMsg;
        {
            DtSipMessageCpp::CSipRegisterServerRsp rspMsg;
            rspMsg.parse(strRsp);
        }
        strResult = reqMsg.dump();
    }
    return strResult;
}

std::string sip_client_protocal_handler::get_send_sms_message(const std::string strReciver, const std::string strContent)
{
    DtSipMessageCpp::CSipSmsMessage createSmsMsg;
    {
        //SET 
        {
            //std::string strSender = "1003";
            //std::string strReciver = "1009";
            //std::string strPassword = "1234";
            //std::string strServerIp = "192.168.31.109";
            //int serverPort = 5060;
            //std::string strLocalIp = "192.168.31.109";
            //int localPort = 64998;

            std::string strViaIp = "192.168.31.109";
            int viaPort = 50757;

            std::string strNetType = "UDP";
            std::string strAllowOptions = "Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE";
            std::string strAllowEvents = "Allow-Events: presence, kpml, talk, as-feature-event";
            std::string strCallId = "Call-ID: EVT_xLB_dIPYDUi2URkpgQ";
            std::string strBranch = "z9hG4bK-524287-1---924a4031843731a9";
            std::string strMaxForwards = "Max-Forwards: 70";
            std::string strFromTag = "f39ef304";
            std::string strCSeq = "CSeq: "+create_c_seq() + " MESSAGE";
            //std::string strUserAgent = "User-Agent: Zoiper v2.10.20.4_1";
            //std::string strContent = "1234";

            std::string strContentLength = "Content-Length: " + std::to_string(strContent.length());
            std::string strContentType = "Content-Type: text/plain";
            //SET variable
            {
                createSmsMsg.set_sip_server_ip_port(m_str_sip_server_ip, m_n_sip_server_port);
                createSmsMsg.set_sip_local_ip_port(m_str_sip_client_ip, m_n_sip_client_port);
                createSmsMsg.add_via_ip_port(m_str_sip_client_ip, m_n_sip_client_port);
                createSmsMsg.set_net_type(strNetType);
                createSmsMsg.set_allow_options(strAllowOptions);
                createSmsMsg.set_call_id(strCallId);
                createSmsMsg.set_content_length(strContentLength);
                createSmsMsg.set_branch(strBranch);
                createSmsMsg.set_max_forwards(strMaxForwards);
                createSmsMsg.set_from_tag(strFromTag);
                createSmsMsg.set_sender(m_str_user_name);
                createSmsMsg.set_reciver(strReciver);
                createSmsMsg.set_c_seq(strCSeq);
                createSmsMsg.set_user_agent(m_str_client_type);
                createSmsMsg.set_allow_events(strAllowEvents);
                createSmsMsg.set_content(strContent);
                createSmsMsg.set_content_type(strContentType);
                //createSmsMsg.set_con
                createSmsMsg.set_content_length(strContentLength);
                createSmsMsg.set_user_agent(this->m_str_client_type);
            }

            //create
            {
                createSmsMsg.create_header_line();
                createSmsMsg.create_via_line();
                createSmsMsg.create_from_line();
                createSmsMsg.create_to_line();
            }
        }
    }
    return createSmsMsg.dump();
}
std::string get_authorization_from_www_auth_for_client(const std::string strMethod,const std::string& strWwwAuth, const std::string strUser, const std::string strPass, const std::string strCnonce, const std::string strUri)
{
    WWW_AUTH wwwAuth;
    //std::string strMethod = "REGISTER";
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
    std::string strNC = "00000001";
    DtSipMessageCpp::CSipReRegisterMsg secondRegMsg;
    std::string strNetType = "UDP";
    std::string strAllowOptions = "Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS";
    //std::string strCallId = "Call-ID: 7dacdb3605c94e659e588faa5e70af86";
    std::string strCallId = "Call-ID: " + m_str_call_id;
    std::string strContentLength = "Content-Length:  0";
    std::string strBranch = "z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69";
    std::string strMaxForwards = "Max-Forwards: 70";
    std::string strFromTag = "a2c95cb6bbf84183a634b0244b09dcd9";
    std::string strCSeq = "CSeq: "+create_c_seq() + " REGISTER";
    std::string strExpries = "Expires: 120";
    {
       /*std::string strDump = R"(REGISTER sip:192.168.31.109:5060 SIP/2.0
Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPja4bf5bc9a06b4a9f9413f9c143242321
Route: <sip:192.168.31.109:5060;lr>
Max-Forwards: 70
From: "1002" <sip:1002@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
To: "1002" <sip:1002@192.168.31.109>
Call-ID: 7dacdb3605c94e659e588faa5e70af86
CSeq: 28960 REGISTER
User-Agent: DtSipClient/3.21.4
Contact: "1002" <sip:1002@192.168.31.109:64998;ob>
Expires: 30
Allow: PRACK, INVITE, ACK, BYE, CANCEL, UPDATE, INFO, SUBSCRIBE, NOTIFY, REFER, MESSAGE, OPTIONS
Authorization: Digest username="1002", realm="192.168.31.109", nonce="36fb7893-0612-4527-8d25-af2c14afeaec", uri="sip:192.168.31.109:5060", response="eb9d64a7b947554c160f9b5393cf2697", algorithm=MD5, cnonce="fc2d3c0e12fd4932873b5011bace6897", qop=auth, nc=00000001
Content-Length:  0)";*/
        //secondRegMsg.parse(strDump);
        {
            {
                secondRegMsg.set_sip_server_ip_port(m_str_sip_server_ip, m_n_sip_server_port);
                secondRegMsg.set_sip_local_ip_port(m_str_sip_client_ip, m_n_sip_client_port);
                secondRegMsg.set_net_type(strNetType);
                secondRegMsg.set_allow_options(strAllowOptions);
                secondRegMsg.set_call_id(strCallId);
                secondRegMsg.set_content_length(strContentLength);
                secondRegMsg.set_branch(strBranch);
                secondRegMsg.set_max_forwards(strMaxForwards);
                secondRegMsg.set_from_tag(strFromTag);
                secondRegMsg.set_username_password(m_str_user_name, m_str_pass_word);
                secondRegMsg.set_c_seq(strCSeq);
                secondRegMsg.set_net_type(m_str_net_type);
                secondRegMsg.set_expires(strExpries);
            }

            {
                secondRegMsg.create_header_line();
                secondRegMsg.create_via_line();
                secondRegMsg.create_from_line();
                secondRegMsg.create_to_line();
                secondRegMsg.create_contact_line();
            }
        }
        //secondRegMsg.set_sip_server_ip_port(m_str_sip_server_ip, m_n_sip_server_port);
        //secondRegMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        //secondRegMsg.set_net_type("UDP");

    }

    {

        WWW_AUTH wwwAuth;
        wwwAuth.from_string(rspMsg.get_www_auth());
        std::string strCnonce = DtSipMessageCpp::CProtoUtil::get_nonce(32);// "c3606b3f70544096a7e17fcdb4670795";
        Authorization auth;
        {
            auth.set_user_name(m_str_user_name);
            auth.set_realm(wwwAuth.get_realm());
            auth.set_nonce(wwwAuth.get_nonce());
            std::string strURI = "sip:";
            {
                strURI += m_str_sip_server_ip;
                strURI += ":";
                strURI += std::to_string(m_n_sip_server_port);
            }
            auth.set_uri(strURI);//SipDigest?
            std::string strResponse = get_authorization_from_www_auth_for_client("REGISTER",
                rspMsg.get_www_auth(),
                m_str_user_name,
                m_str_pass_word,
                strCnonce,
                strURI);
            auth.set_response(strResponse);
            auth.set_cnonce(strCnonce);
            auth.set_nc(strNC);
            auth.set_algorithm(wwwAuth.get_algorithm());
            auth.set_qop(wwwAuth.get_qop());
        }
        secondRegMsg.set_authorization(auth.to_string());
    }

    m_strWaitForSend = secondRegMsg.dump();
    return true;
}

bool sip_client_protocal_handler::handle_first_send_sms(const std::string strRsp)
{
    DtSipMessageCpp::CSipRegisterServerRsp rspMsg;
    std::string strAuth;
    {
        rspMsg.parse(strRsp);
        std::string strNC = "00000001";
        {

            WWW_AUTH wwwAuth;
            wwwAuth.from_string(rspMsg.get_www_auth());
            std::string strCnonce = DtSipMessageCpp::CProtoUtil::get_nonce(32);// "c3606b3f70544096a7e17fcdb4670795";
            Authorization auth;
            {
                auth.set_user_name(m_str_user_name);
                auth.set_realm(wwwAuth.get_realm());
                auth.set_nonce(wwwAuth.get_nonce());
                std::string strURI = "sip:";
                {
                    strURI += m_str_sip_server_ip;
                    strURI += ":";
                    strURI += std::to_string(m_n_sip_server_port);
                }
                auth.set_uri(strURI);//SipDigest?
                std::string strResponse = get_authorization_from_www_auth_for_client("MESSAGE",
                    rspMsg.get_www_auth(),
                    m_str_user_name,
                    m_str_pass_word,
                    strCnonce,
                    strURI);
                auth.set_response(strResponse);
                auth.set_cnonce(strCnonce);
                auth.set_nc(strNC);
                auth.set_algorithm(wwwAuth.get_algorithm());
                auth.set_qop(wwwAuth.get_qop());
                auth.set_auth_type(wwwAuth.get_auth_type());
            }
            strAuth=auth.to_string();
        }
    }

    {
        DtSipMessageCpp::CSipSmsMessage createSmsMsg;
        {
            //SET 
            {
                //std::string strSender = "1003";
                //std::string strReciver = "1009";
                //std::string strPassword = "1234";
                //std::string strServerIp = "192.168.31.109";
                //int serverPort = 5060;
                //std::string strLocalIp = "192.168.31.109";
                //int localPort = 64998;

                std::string strViaIp = "192.168.31.109";
                int viaPort = 50757;

                std::string strNetType = "UDP";
                std::string strAllowOptions = "Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE";
                std::string strAllowEvents = "Allow-Events: presence, kpml, talk, as-feature-event";
                std::string strCallId = "Call-ID: EVT_xLB_dIPYDUi2URkpgQ";
                std::string strBranch = "z9hG4bK-524287-1---924a4031843731a9";
                std::string strMaxForwards = "Max-Forwards: 70";
                std::string strFromTag = "f39ef304";
                std::string strCSeq = "CSeq: " + create_c_seq() + " MESSAGE";
                //std::string strUserAgent = "User-Agent: Zoiper v2.10.20.4_1";
                //std::string strContent = "1234";

                std::string strContentLength = "Content-Length: " + std::to_string(m_strContent.length());
                std::string strContentType = "Content-Type: text/plain";
                //SET variable
                {
                    createSmsMsg.set_sip_server_ip_port(m_str_sip_server_ip, m_n_sip_server_port);
                    createSmsMsg.set_sip_local_ip_port(m_str_sip_client_ip, m_n_sip_client_port);
                    createSmsMsg.add_via_ip_port(strViaIp, viaPort);
                    createSmsMsg.set_net_type(strNetType);
                    createSmsMsg.set_allow_options(strAllowOptions);
                    createSmsMsg.set_call_id(strCallId);
                    createSmsMsg.set_content_length(strContentLength);
                    createSmsMsg.set_branch(strBranch);
                    createSmsMsg.set_max_forwards(strMaxForwards);
                    createSmsMsg.set_from_tag(strFromTag);
                    createSmsMsg.set_sender(m_str_user_name);
                    createSmsMsg.set_reciver(m_strReciver);
                    createSmsMsg.set_c_seq(strCSeq);
                    createSmsMsg.set_user_agent(m_str_client_type);
                    createSmsMsg.set_allow_events(strAllowEvents);
                    createSmsMsg.set_content(m_strContent);
                    createSmsMsg.set_content_type(strContentType);
                    //createSmsMsg.set_con
                    createSmsMsg.set_content_length(strContentLength);
                    createSmsMsg.set_authorization(strAuth);
                }

                //create
                {
                    createSmsMsg.create_header_line();
                    createSmsMsg.create_via_line();
                    createSmsMsg.create_from_line();
                    createSmsMsg.create_to_line();
                }
            }
        }
        //return createSmsMsg.dump();
        m_strWaitForSend = createSmsMsg.dump();
    }

  
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

bool sip_client_protocal_handler::set_client_type(const std::string strClientType)
{
    m_str_client_type = strClientType;
    return true;
}

bool sip_client_protocal_handler::set_net_type(const std::string strNetType)
{
    m_str_net_type = strNetType;
    return true;
}
bool sip_client_protocal_handler::init_protocal()
{
    if (m_str_call_id.empty())
    {
        m_str_call_id = DtSipMessageCpp::CProtoUtil::get_nonce(16);
    }
    return true;
}

void sip_client_protocal_handler::do_register()
{
	g_sip_client_state = SIP_CLIENT_STATE::NOT_REGISTER;
	init_first_register();
}

void sip_client_protocal_handler::do_send_sms(const std::string strReciver, const std::string strContent)
{
    m_strReciver = strReciver;
    m_strContent = strContent;
    g_sip_client_state = SIP_CLIENT_STATE::SENDING_SMS;
    m_strWaitForSend = get_send_sms_message(strReciver, strContent);
    //init_first_register();
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
            m_strWaitForSend = get_first_register_message();
		}
	}
}
void sip_client_protocal_handler::init_send_sms()
{
    //m_strWaitForSend = get_send_sms_message();
}

std::string sip_client_protocal_handler::create_c_seq()
{
    std::string strResult = std::to_string(m_n_c_seq);
    m_n_c_seq++;
    return strResult;
}