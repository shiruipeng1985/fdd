#ifndef DM_GLOBAL_H
#define DM_GLOBAL_H

#include<string>
#include<iostream>
#include<libconfig.h++>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

extern std::string projectHome;
//model root folder
extern std::string re_modelHome;
//front face detection model
extern std::string fccModelName;
//profile face detection model
extern std::string pfccModelName;
extern std::string rightEyeStatusSVMModelName;
extern std::string mouthChinStatusSVMModelName;
extern std::string featurePointsRegressorModelName;
extern std::string regName;
extern std::string mediaHome;
extern std::string rightEyeFatigueAudio;
extern std::string mouthFatigueAudio;
extern std::string outputDataHome;
extern std::string videoFolder;
extern std::string eyesEvidenceFolder;
extern std::string mouthEvidenceFolder;
extern std::string rightEyeDNNModelFile;
extern std::string rightEyeDNNWeightsFile;
extern std::string rightEyeDNNMeanFile;
extern std::string mouthChinDNNModelFile;
extern std::string mouthChinDNNWeightsFile;
extern std::string mouthChinDNNMeanFile;
extern std::string leftEyeDNNModelFile;
extern std::string leftEyeDNNWeightsFile;
extern std::string leftEyeDNNMeanFile;
extern std::string faceComponentLabelFile;
extern std::string headposeDNNModelFile;
extern std::string headposeDNNWeightsFile;
extern std::string headposeDNNMeanFile;
extern std::string headposeLabelFile;

void configGlobalVariables(const std::string &configFile);

//check if folder exists,if not ,make the folder
inline void checkFolder(const std::string &folderName){
    //determine if the folder exists
    if(-1==access(folderName.c_str(),F_OK)){
        //folder doesn't exists
        if(-1==mkdir(folderName.c_str(),S_IRWXU)){
            //fail to mkdir folder
                std::cout<<"fail to mkdir "<<folderName.c_str()<<std::endl;
                exit(-1);
        }
    }
}

#endif