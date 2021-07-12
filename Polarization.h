//
// Created by wya on 2021/7/10.
//

#ifndef POLARIZEDSAVE_POLARIZATION_H
#define POLARIZEDSAVE_POLARIZATION_H

#include "Spinnaker.h"
#include "SpinGenApi/SpinnakerGenApi.h"

namespace Polarization
{

 class polarizedSave
        {
        public:
            int polarized_save(std::string& Dataset_path, std::string& DataSave_path);
            int RunSingleCamera(Spinnaker::CameraPtr pCam, std::string& SavePath);

        private:
            int PrintDeviceInfo(Spinnaker::GenApi::INodeMap& nodeMap);
            int ConfigureStream(Spinnaker::GenApi::INodeMap& nodeMap);
            int SaveImage(const Spinnaker::ImagePtr& pImage, const std::string filename, Spinnaker::GenICam::gcstring& serialNumber);
            std::string GetQuadFileNameAppendage(const Spinnaker::ImageUtilityPolarization::PolarizationQuadrant quadrant);
            int CreateHeatmapImages(const Spinnaker::ImagePtr& mono8Image, const std::string baseFilename, Spinnaker::GenICam::gcstring& deviceSerialNumber);
            int ExtractAndSavePolarQuadImages(const Spinnaker::ImagePtr& pRawPolarizedImage, Spinnaker::GenICam::gcstring& deviceSerialNumber,std::string& path,std::string& nums);
            int CreateAndSaveGlareReducedImage(const Spinnaker::ImagePtr& pRawPolarizedImage, Spinnaker::GenICam::gcstring& deviceSerialNumber);
            int CreateNormalizedImage(const Spinnaker::ImagePtr& imageToNormalize,
                const std::string baseFilename,
                Spinnaker::GenICam::gcstring& deviceSerialNumber,
                Spinnaker::ImageUtility::SourceDataRange srcDataRange = Spinnaker::ImageUtility::IMAGE_DATA_RANGE);

            int CreateAndSaveAolpDolpImages(const Spinnaker::ImagePtr& pRawPolarizedImage, Spinnaker::GenICam::gcstring& deviceSerialNumber,std::string& path,std::string& nums);
            int CreateAndSaveStokesImages(const Spinnaker::ImagePtr& pRawPolarizedImage, Spinnaker::GenICam::gcstring& deviceSerialNumber);

            int AcquireImages(Spinnaker::CameraPtr pCam, Spinnaker::GenApi::INodeMap& nodeMapTLDevice,std::string& path,std::string& nums);

        };

}



#endif //POLARIZEDSAVE_POLARIZATION_H
