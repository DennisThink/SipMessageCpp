#include <iostream>
#include "sip_client.h"
int main(int argc,char * argv[])
{
    SipClient sipPhone;
    std::string strUserName = "1002";
    std::string strPassword = "1234";
    std::string strServerIp = "192.168.31.109";
    int nServerPort = 5060;
    sipPhone.set_user_name(strUserName);
    sipPhone.set_pass_word(strPassword);
    sipPhone.set_sip_server_addr(strServerIp,nServerPort);
    sipPhone.init_protocal();
    sipPhone.do_register();
    //sipPhone.send_sms("1009", "Hello From 1002");
    std::cout<<"sip_msg_demo"<<std::endl;
    return 0;
}