#include<iostream>
#include<detect_lights.h>
#define SOUREC_PATH "../video/RED.mp4"
int main(){
    cv::VideoCapture cap(SOUREC_PATH);
    cv::Mat read_img;
    AllInformation all_information;
    all_information.color = RED;
    all_information.color_image_thresold = 100;// 单彩色通道图像的二值化阈值
    all_information.gray_image_thresold = 60;// 灰度图的二值化阈值
    all_information.min_area_light = 30;// 最小的灯条面积
    all_information.max_angle_light = 50;// 最大的灯条角度
    all_information.max_angelediff = 5;// 最大的左右灯条角度差
    all_information.max_tangent = 45;// 左右灯条中心线与水平的最大tan
    all_information.max_boxlenthdivwidth = 0.6;// 最大的装甲板长宽比
    all_information.min_boxlenthdivwidth =0.35;// 最小的装甲板长宽比
    ArmorDetect armor_detect(all_information);
    while(1){
        cap.read(read_img);
        if(read_img.empty()){
            fmt::print("{}读取失败",SOUREC_PATH);
        }
        armor_detect.CaputureImage(read_img);
        armor_detect.Run();
    }
    return 0;
}