//
// Created by wya on 2021/7/10.
//

#ifndef POLARIZEDSAVE_UTIL_H
#define POLARIZEDSAVE_UTIL_H

int RemoveDirectory(const std::string & strSourceDir);
bool CopyDirectory(const std::string &strSourceDir, const std::string &strDestDir);
bool CopyDireWithTimestamp(const std::string &CurrentPath, const std::string &TargetPath);

#endif //POLARIZEDSAVE_UTIL_H
