#include <detect_lights.h>
LightBar::LightBar() {
    light_rect = cv::RotatedRect();
    light_angle = 0;
    light_lenth = 0;
    lingt_center = cv::Point2f();
}
LightBar::LightBar(const cv::RotatedRect rotated_rect) {
    light_rect = rotated_rect;
    
    light_lenth = std::max(rotated_rect.size.height,rotated_rect.size.width);
    lingt_center = rotated_rect.center;
    if (rotated_rect.angle>90) {
        light_angle=rotated_rect.angle-180;
    }else {
        light_angle = rotated_rect.angle;
    }
}
LightBar::~LightBar() {}
