#include<detect_lights.h>
CreateRelArmor::CreateRelArmor(std::vector<Armor> armor,
                                 float  max_angelediff,
                                 float max_tangent,
                                 float max_boxlenthdivwidth,
                                 float min_boxlenthdivwidth):
                                 pre_armors(armor),
                                 max_angelediff(max_angelediff),
                                 max_tangent(max_tangent),
                                 max_boxlenthdivwidth(max_boxlenthdivwidth),
                                 min_boxlenthdivwidth(min_boxlenthdivwidth) {}
float CreateRelArmor::GetAnglediff(const Armor &armor) {
    float diff_angle = std::abs(armor.armor_l_bar.light_angle-armor.armor_r_bar.light_angle);
    return diff_angle;
}
float CreateRelArmor::GetTangent(const Armor &armor) {
    float change_x = std::abs(armor.armor_l_bar.lingt_center.x-armor.armor_r_bar.lingt_center.x);// x的差值
    float change_y = std::abs(armor.armor_l_bar.lingt_center.y-armor.armor_r_bar.lingt_center.y);// y的差值
    float tan = abs(atan(change_y/ change_x)) * 180 / CV_PI; //tanθ=Δy/Δx
    return tan;
}
float CreateRelArmor::GetBoxLenthDivWidth(const Armor &armor) {
    float distance_x = std::abs(armor.armor_l_bar.lingt_center.x-armor.armor_r_bar.lingt_center.x);
    float distance_y = (armor.armor_l_bar.light_lenth+armor.armor_r_bar.light_lenth)/2;
    float roation_xy = distance_y/distance_x;
    return roation_xy;
}
bool CreateRelArmor::ArmorIssuiable(const Armor &armor) {
    fmt::print("diff_angle:{}\ntan:{}\nroation_xy:{}\n",GetAnglediff(armor),GetTangent(armor),GetBoxLenthDivWidth(armor));
    return GetAnglediff(armor) < max_angelediff &&
           GetBoxLenthDivWidth(armor) < max_boxlenthdivwidth &&
           GetBoxLenthDivWidth(armor) > min_boxlenthdivwidth &&
           GetTangent(armor)  <max_tangent ;  
}
void CreateRelArmor::MatchRelArmor() {
    for(const auto &pre_armor : pre_armors) {
        if(ArmorIssuiable(pre_armor)) {
            rel_armors.push_back(pre_armor);
        }
    }
}

