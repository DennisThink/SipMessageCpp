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
        CHECK("8120b595-5981-4216-bfa2-70b17f64d255" == authMsg.get_nonce());
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
    {
        Authorization authMsg;
        std::string strSipMessageBase = R"(Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5)";
        CHECK(authMsg.from_string(strSipMessageBase));
        {
            CHECK("192.168.31.109" == authMsg.get_realm());
            CHECK(R"(fffe2121-d01f-4c89-ab62-12a030a1c10d)" == authMsg.get_nonce());
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

    {
        Authorization authMsg;
        std::string strSipMessageBase = R"(Authorization: Digest username="1002",realm="192.168.31.109",nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",uri="sip:192.168.31.109:5060;transport=UDP",response="b4418b2b96e05ec2a0beb3c522edbcc9",cnonce="b3468b9ac6827d7c51e85ef96618190f",nc=00000002,qop=auth,algorithm=MD5)";
        CHECK(authMsg.from_string(strSipMessageBase));
        {
            CHECK("1002" == authMsg.get_user_name());
            CHECK("192.168.31.109" == authMsg.get_realm());
            CHECK(R"(fffe2121-d01f-4c89-ab62-12a030a1c10d)" == authMsg.get_nonce());
            CHECK("sip:192.168.31.109:5060;transport=UDP" == authMsg.get_uri());
            CHECK("b4418b2b96e05ec2a0beb3c522edbcc9" == authMsg.get_response());
            CHECK("b3468b9ac6827d7c51e85ef96618190f" == authMsg.get_cnonce());
            CHECK("00000002" == authMsg.get_nc());
            CHECK("MD5" == authMsg.get_algorithm());
            CHECK("auth" == authMsg.get_qop());
        }
        Authorization authMsgCopy;
        {
            CHECK(authMsgCopy.set_user_name(authMsg.get_user_name()));
            CHECK(authMsgCopy.set_realm(authMsg.get_realm()));
            CHECK(authMsgCopy.set_nonce(authMsg.get_nonce()));
            CHECK(authMsgCopy.set_uri(authMsg.get_uri()));
            CHECK(authMsgCopy.set_response(authMsg.get_response()));
            CHECK(authMsgCopy.set_cnonce(authMsg.get_cnonce()));
            CHECK(authMsgCopy.set_nc(authMsg.get_nc()));
            CHECK(authMsgCopy.set_algorithm(authMsg.get_algorithm()));
            CHECK(authMsgCopy.set_qop(authMsg.get_qop()));
        }
        {
            std::string strAuthMsg = authMsg.to_string();
            std::string strAuthMsgCopy = authMsgCopy.to_string();
            CHECK(strAuthMsg == strAuthMsgCopy);
            if (strAuthMsg != strAuthMsgCopy)
            {
                std::string strCommon = DtSipMessageCpp::CProtoUtil::GetCommonPartOfTwoString(strAuthMsg, strAuthMsgCopy);
                std::cout << "COMMON: " << strCommon << std::endl;
            }
        }
    }

}