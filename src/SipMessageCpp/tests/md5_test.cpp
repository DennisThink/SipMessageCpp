#include <doctest/doctest.h>
#include "md5/md5.h"
#include <iostream>
TEST_CASE("SipMessageBase"){
    std::string strSource1 = R"(6a5e40ec8a6cbac75b9914b271516a47:bee3366b-cf59-476e-bc5e-334e0d65b386:00000001:c3606b3f70544096a7e17fcdb4670795:auth:c0a1637fb943febd38e69c2087d58fe9)";
    std::string strMd51 = "7a8049557b2e77602625fa9ee7d8f088";
    CHECK(MD5(strSource1).toStr() == strMd51);
}
TEST_CASE("CalcuAuthorization"){
    //"Authorization: Digest username="1000", realm="10.32.26.25", nonce="bee3366b-cf59-476e-bc5e-334e0d65b386", uri="sip:10.32.26.25:5070;transport=tcp", response="7a8049557b2e77602625fa9ee7d8f088", algorithm=MD5, cnonce="c3606b3f70544096a7e17fcdb4670795", qop=auth, nc=00000001"
    {
        //HA1
        std::string strHA1;
        {
            std::string strUser = "1000";
            std::string strPass = "1234";
            std::string strRealm = "10.32.26.25";

            std::string strHA1Source = strUser + ":" + strRealm + ":" + strPass;
            strHA1 = MD5(strHA1Source).toStr();
        }

        //HA2
        std::string strHA2;
        {
            std::string strMethod = "REGISTER";
            std::string strDigest = "sip:10.32.26.25:5070;transport=tcp";
            std::string strHA2Source = strMethod + ":" + strDigest;
            strHA2 = MD5(strHA2Source).toStr();
        }

        //Response
        std::string strResponse;
        {

            std::string strCnonce = "c3606b3f70544096a7e17fcdb4670795";
            std::string strNonce = "bee3366b-cf59-476e-bc5e-334e0d65b386";
            //HA1:nonce:nonceCount:cnonce:qop:HA2
            std::string strNonceCount = "00000001";
            std::string strQop = "auth";
            std::string strResponseSource = strHA1 + ":"
                + strNonce + ":"
                + strNonceCount + ":"
                + strCnonce + ":"
                + strQop + ":"
                + strHA2;
            strResponse = MD5(strResponseSource).toStr();
            std::string strStdResponse = "7a8049557b2e77602625fa9ee7d8f088";
            CHECK(strResponse == strStdResponse);
        }
    }
}

TEST_CASE("CalcuAuthorization2") {
    //Authorization: Digest username="1009", realm="192.168.31.109", nonce="36fb7893-0612-4527-8d25-af2c14afeaec", uri="sip:192.168.31.109:5060", response="eb9d64a7b947554c160f9b5393cf2697", algorithm=MD5, cnonce="fc2d3c0e12fd4932873b5011bace6897", qop=auth, nc=00000001
    {
        //HA1
        std::string strHA1;
        {
            std::string strUser = "1009";
            std::string strPass = "1234";
            std::string strRealm = "192.168.31.109";

            std::string strHA1Source = strUser + ":" + strRealm + ":" + strPass;
            strHA1 = MD5(strHA1Source).toStr();
        }

        //HA2
        std::string strHA2;
        {
            std::string strMethod = "REGISTER";
            std::string strDigest = "sip:192.168.31.109:5060";
            std::string strHA2Source = strMethod + ":" + strDigest;
            strHA2 = MD5(strHA2Source).toStr();
        }

        //Response
        std::string strResponse;
        {

            std::string strCnonce = "fc2d3c0e12fd4932873b5011bace6897";
            std::string strNonce = "36fb7893-0612-4527-8d25-af2c14afeaec";
            //HA1:nonce:nonceCount:cnonce:qop:HA2
            std::string strNonceCount = "00000001";
            std::string strQop = "auth";
            std::string strResponseSource = strHA1 + ":"
                + strNonce + ":"
                + strNonceCount + ":"
                + strCnonce + ":"
                + strQop + ":"
                + strHA2;
            strResponse = MD5(strResponseSource).toStr();
            std::string strStdResponse = "eb9d64a7b947554c160f9b5393cf2697";
            CHECK(strResponse == strStdResponse);
        }
    }
}