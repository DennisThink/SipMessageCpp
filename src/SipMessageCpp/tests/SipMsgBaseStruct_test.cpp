#include <doctest/doctest.h>
#include "SipMsgBaseStruct.hpp"
#include "SipMessageUtil.h"
#include <iostream>
TEST_CASE("WWW_AUTH"){
    WWW_AUTH authMsg;
    std::string strSipMessageBase = R"( WWW-Authenticate: Digest realm="192.168.31.109", nonce="8120b595-5981-4216-bfa2-70b17f64d255", stale=true, algorithm=MD5, qop="auth")";
    CHECK(authMsg.from_string(strSipMessageBase));
    {
        CHECK("192.168.31.109" == authMsg.get_realm());
        CHECK(R"("8120b595-5981-4216-bfa2-70b17f64d255")" == authMsg.get_nonce());
        CHECK("true" == authMsg.get_stale());
        CHECK("MD5" == authMsg.get_algorithm());
        CHECK("auth" == authMsg.get_qop());
    }
    std::string strDump = authMsg.to_string();
    CHECK(strSipMessageBase == strDump);
    if (strSipMessageBase != authMsg.to_string())
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipMessageBase, strDump);
        std::cout << "COMMON: " << strCommon << std::endl;
    }
}

TEST_CASE("Authorization") {
    Authorization authMsg;
    std::string strSipMessageBase = R"(Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5)";
    CHECK(authMsg.from_string(strSipMessageBase));
    {    
        CHECK("192.168.31.109" == authMsg.get_realm());
        CHECK(R"("fffe2121-d01f-4c89-ab62-12a030a1c10d")" == authMsg.get_nonce());
        CHECK("MD5" == authMsg.get_algorithm());
        CHECK("auth" == authMsg.get_qop());
    }
    std::string strDump = authMsg.to_string();
    CHECK(strSipMessageBase == strDump);
    if (strSipMessageBase != authMsg.to_string())
    {
        std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strSipMessageBase, strDump);
        std::cout << "COMMON: " << strCommon << std::endl;
    }

}