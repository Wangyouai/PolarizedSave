# 偏振相机制作数据集

[TOC]

## Environment used to develop:

- Blackfly S BFS-U3-51S5P偏振相机
- Ubuntu 20.04

## Dependencies

### Spinnaker SDK

[Spinnaker SDK下载](https://meta.box.lenovo.com/v/link/view/a1995795ffba47dbbe45771477319cc3)

[百度网盘下载](https://pan.baidu.com/s/1un45FTvpFJ_WwlLL3dJ3Yw)   提取码：ndlu

解压后查看README文件，避免与以下操作有误

无误则运行：

```shell
 sudo apt-get install libavcodec58 libavformat58 \
libswscale5 libswresample3 libavutil56 libusb-1.0-0 \
libpcre2-16-0 libdouble-conversion3 libxcb-xinput0 \
libxcb-xinerama0

sudo sh install_spinnaker.sh

```

配置USB驱动：（相机为USB3.0接口，若是GIGE接口则运行相关.sh）

```shell
sudo sh configure_usbfs.sh
```

一路yes即可

命令行直接运行 `SpinView`测试相机是否正常运行

### Boost 1.7

```shell
sudo apt-get install libboost-all-dev
```



