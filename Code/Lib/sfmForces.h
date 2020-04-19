#include <memory>
#include <vector>
#include <Eigen/Dense>
#include "sfmBasicTypes.h"
#include "sfmPedestrian.h"

namespace sfm{


class Forces : public Pedestrian {
    public:
    Forces(pos2d origin,pos2d destination, dir2d velocity,pos2d current_position,double speed,double rest_time)
    :Pedestrian(origin,destination,velocity,current_position,speed,rest_time){};
    dir2d &desired_direction(dir2d &final_position);
    dir2d &attractive_force(dir2d &force);
    double &elipse(std::shared_ptr<Forces>pedesa, std::shared_ptr<Forces>pedesb, double &elipse); // passa is the tested one, passb changes as all other pedestrians
    dir2d &repulsive_force(std::shared_ptr<Forces>pedesa, std::shared_ptr<Forces>pedesb, double &elipse, dir2d &Forces);
    //double &fov(double &fov);    
    //sfm::dir2d &border_repulsive();
    //std::vector<shared_ptr<sfm::Pedestrians> > &Resultant_force();
};
}