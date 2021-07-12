//
// Created by wya on 2021/7/10.
//
#include <iostream>
#include "util.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

int RemoveDirectory(const std::string & strSourceDir)
{
    bool ec= false;
    boost::filesystem::path tmpPath(strSourceDir);
    boost::filesystem::directory_iterator diter(tmpPath);
    boost::filesystem::directory_iterator diter_end;


    for (; diter != diter_end; ++diter) {
        if (!boost::filesystem::is_regular_file(diter->status())) continue;
        std::string filename = diter->path().filename().string();
        boost::filesystem::remove(diter->path());
        ec=true;
    }
    if(!ec)
    {
        std::cout << "Error! Can not remove files:\n" <<strSourceDir+"/*"<< std::endl;
        return false;
    }
    std::cout << "remove files:\n" <<strSourceDir+"/*"<< std::endl;
    return true;
}

bool CopyDirectory(const std::string &strSourceDir, const std::string &strDestDir)
{
    boost::filesystem::recursive_directory_iterator end; //设置遍历结束标志，用recursive_directory_iterator即可循环的遍历目录
    boost::system::error_code ec;
    for (boost::filesystem::recursive_directory_iterator pos(strSourceDir); pos != end; ++pos)
    {
        //过滤掉目录和子目录为空的情况
        if(boost::filesystem::is_directory(*pos))
            continue;
        std::string strAppPath = boost::filesystem::path(*pos).string();
        std::string strRestorePath;
        //replace_first_copy在algorithm/string头文件中，在strAppPath中查找strSourceDir字符串，找到则用strDestDir替换，替换后的字符串保存在一个输出迭代器中
        boost::algorithm::replace_first_copy(std::back_inserter(strRestorePath), strAppPath, strSourceDir, strDestDir);
        if(!boost::filesystem::exists(boost::filesystem::path(strRestorePath).parent_path()))
        {
            boost::filesystem::create_directories(boost::filesystem::path(strRestorePath).parent_path(), ec);
            if(ec)
            {
                std::cout<<"ERROR! Can not create the parent path: "<< boost::filesystem::path(strRestorePath).parent_path() <<std::endl;
                return false;
            }
        }
        boost::filesystem::copy_file(strAppPath, strRestorePath, boost::filesystem::copy_option::overwrite_if_exists, ec);
    }

    return true;
}
bool CopyDireWithTimestamp(const std::string &CurrentPath, const std::string &TargetPath) {

    const time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
//    boost::system::error_code ec;
    bool ec;
    std::string Time;

    Time = std::to_string(current_time->tm_mon + 1) + "-" + std::to_string(current_time->tm_mday)
           + "_" + std::to_string(current_time->tm_hour) + ":" + std::to_string(current_time->tm_min);
    std::string Target_path = TargetPath + "/" + Time;

    boost::filesystem::path Target_folder(Target_path);

    ec=CopyDirectory(CurrentPath + "/", Target_path + "/");

    if(!ec){
        std::cout<<"ERROR! Can not copy the captured images to the DataSet folder! :\n"<<Target_path<<std::endl;
        return false;
    }
    std::cout<<"DONE! Copy the captured images to the DataSet folder:\n"<<Target_path<<std::endl;
    return true;


}