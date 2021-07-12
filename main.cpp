
#include "Polarization.h"


using namespace std;

int main(int /*argc*/, char** /*argv*/)
{

    std::string DataBase_path="/home/wya/Project/Dataset/polarized/all_sequences";
    std::string DataSave_path="/home/wya/Project/Dataset/polarized/pImgSave";

    Polarization::polarizedSave P;
    P.polarizedSave::polarized_save(DataBase_path,DataSave_path);
}