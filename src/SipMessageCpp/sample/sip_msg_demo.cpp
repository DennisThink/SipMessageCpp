#include <iostream>
#include "simple_cpp_sockets.h"

#include "CSipMsgCpp.hpp"
#include "SipMsgBaseStruct.hpp"
#include "md5/md5.h"
int main(int argc,char * argv[])
{
    UDPClient client(5060, "192.168.31.109");
    //UDPClient client(7080, "192.168.31.106");
    //TCPClient client(7080, "192.168.31.109");
    //if (client.make_connection())
    {

    }
    std::string strRegMsg;
    {
        DtSipMessageCpp::CSipRegisterMsg regMsg;

        std::string strDump = R"(REGISTER sip:192.168.31.109:5060;transport=UDP SIP/2.0
Via: SIP/2.0/UDP 192.168.31.142:55747;branch=z9hG4bK-524287-1---86aa6dd38424cee1;rport
Max-Forwards: 70
Contact: <sip:1002@192.168.31.142:55747;rinstance=59defe5c8b2788ae;transport=UDP>
To: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>
From: "1002"<sip:1002@192.168.31.109:5060;transport=UDP>;tag=88741f1c
Call-ID: gzK0vdfGjqqhSuekwhNwmg
CSeq: 3 REGISTER
Expires: 60
Allow: INVITE, ACK, CANCEL, BYE, NOTIFY, REFER, MESSAGE, OPTIONS, INFO, SUBSCRIBE
Supported: replaces, norefersub, extended-refer, timer, sec-agree, outbound, path, X-cisco-serviceuri
User-Agent: Zoiper v2.10.20.4_1
Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5
Allow-Events: presence, kpml, talk, as-feature-event
Content-Length: 0)";
        regMsg.parse(strDump);

        regMsg.set_sip_server_ip_port("192.168.31.109", 5060);
        regMsg.set_net_type("UDP");
        strRegMsg = regMsg.dump();
    }
    int nSendResult = client.send_message(strRegMsg);
    std::cout << "Send Result: " << nSendResult << std::endl;
    {
        std::cout << "LocalAddr: " << client.get_local_ip() << ":" << client.get_local_port() << std::endl;;
    }
    std::string strRspMsg;

    if (client.recv_message(strRspMsg) > 0)
    {
        std::cout << "RSP: " << strRspMsg << std::endl;
    }
    {
        DtSipMessageCpp::CSipRegisterServerRsp rspMsg;
        if (rspMsg.parse(strRspMsg))
        {
            std::cout << "WWW-AUTH:  " << rspMsg.get_www_auth() << std::endl;
        }

        //Parse WWW-AUTH
        {
            WWW_AUTH wwwAuth;
            if (wwwAuth.from_string(rspMsg.get_www_auth()))
            {
                std::cout << "REALM: "<<wwwAuth.get_realm()<< std::endl;
                std::cout << "NONCE: "<<wwwAuth.get_nonce() << std::endl;
                std::cout << "ALGORITHM: "<<wwwAuth.get_algorithm()<< std::endl;
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
                    std::string strNonceCount = "00000001";
                    std::string strResponseSource = strHA1 + ":" 
                        + wwwAuth.get_nonce()+":"
                        + strNonceCount + ":" 
                        + strCnonce+":"
                        + wwwAuth.get_qop()+":"
                        + strHA2;
                    strResponse = MD5(strResponseSource).toStr();
                }
            }

            std::cout << "Response: " << strResponse << std::endl;
        }
    }


    std::cout<<"sip_msg_demo"<<std::endl;
    return 0;
}