#include<detect_lights.h>
ArmorDetect::ArmorDetect(AllInformation information):information(information) {}
void ArmorDetect::CaputureImage(const cv::Mat &imgae) {
    imgae.copyTo(no_trackle_image);
}
void ArmorDetect::DrawArmor() {
    for(const auto &armor : end_armor) {
        cv::Rect rect(armor.left_on_point.x,armor.left_on_point.y,armor.armor_width,armor.armor_lenth);
        cv::rectangle(no_trackle_image,rect,cv::Scalar(0,255,0),2,8);
    }
    imshow("展示",no_trackle_image);
    cv::waitKey(0);
}

void ArmorDetect::Run() {
    cv::Mat copy_image;
    no_trackle_image.copyTo(copy_image);
    ImageTrackle trackle_image(information.color,
                               information.color_image_thresold,
                               information.gray_image_thresold);
    LightDetect light_detect(information.min_area_light,
                             information.max_angle_light);
    this->trackled_image = trackle_image.TrackleImageSubtract(no_trackle_image);
    light_detect.DetectEnemyLight(trackled_image);
    light_detect.MatchPreArmor();
    CreateRelArmor rel_armor(light_detect.pre_armor,
                                information.max_angelediff,
                                information.max_tangent,
                                information.max_boxlenthdivwidth,
                                information.min_boxlenthdivwidth);
    rel_armor.MatchRelArmor();
    end_armor = rel_armor.rel_armors;
    DrawArmor();
}
    
