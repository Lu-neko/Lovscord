#include <stdio.h>
#include "Lovense.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "env.h"

class CEventCallBack: public ILovenseSDKNotify {

    public:
        /*Call when toy search start*/
        void LovenseDidSearchStart(){
            std::cout << "LovenseDidSearchStart"<< std::endl;
        }

        /*Call when toy searching toy*/
        void LovenseSearchingToys(lovense_toy_info_t *info){
            printf("Toy : %s, id : %s\n", info->toy_name, info->toy_id);
        }

        /*Call when something went wrong*/
        void LovenseErrorOutPut(int errorCode,const char *errorMsg){
            printf("Error %d : %s\n", errorCode, errorMsg);
        }


        /*Call when toy search end*/
        void LovenseDidSearchEnd(){
            std::cout << "LovenseDidSearchEnd" << std::endl;
        }

        /*Call when send cmd start*/
        void LovenseDidSendCmdStart(){
            printf("a\n");
        }

        /*Call when send cmd return*/
        void LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd,const char *result,CLovenseToy::Error errorCode){
            printf("b\n");
        }

        /*Call when send cmd end*/
        void LovenseDidSendCmdEnd(){
            printf("c\n");
        }

        /*Call when toy connected, or disconnected*/
        void LovenseToyConnectedStatus(const char *szToyID, bool isConnected){
            if(isConnected)
                std::cout << "Toy:" << szToyID << " is connected!"<<std::endl;
            else
                std::cout << "Toy:" << szToyID << " is disConnected!" << std::endl;
        }
};

int main(int argc, char** argv)
{
    printf("hello world!\n");
    CEventCallBack *callBack = new CEventCallBack();
    CLovenseToyManager *manager = GetLovenseToyManager();
    manager->SetDeveloperToken(TOKEN);
    manager->RegisterEventCallBack(callBack);
    manager->StartSearchToy();
    return 0;
}
