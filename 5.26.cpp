#define _CRT_SECURE_NO_WARNINGS 1、

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "common/eigen_types.h"
#include "common/math_utils.h"
#include "tools/ui/pangolin_windows.h"

///本节程序用来演示做圆周运动的车辆
///车辆的角速度与线速度可以在GFlags中设置

DEFINE_double(angular_velocity, 10.0, "角速度，角度制");
DEFINE_double(linear_velocity, 5.0, "车辆前进的速度的 m/s");
DEFINE_bool(use_quaternion, false, "是否使用四元数计算");

int main(int argc, char** argv) {
	goole::InitGooleLogging(argv[0]);
	FLAGS_stderrthreshold = goole::INFO;
	FLAGS_colorlogtostderr = true;
	google::ParseCommandLineFlags(&argc, &argv, true);
}

///可视化
sad::ui::PangoWindow ui;
if (ui.Init() == false) {
	return -1;
}

double angular_velocity_rad = FLAGS_angular_velocity * sad::math::kDEG2RAD;   //弧度制角速度
SE3 pose;																	  //TWB表示位姿
Vec3d omega(0, 0, angular_celocity_rad);									  //角速度向量	
Vec3d v_body(FLAGS_linear_velocity, 0, 0);									  //本体系速度
const double dt = 0.05;													      //每次更新的时间

while (ui.ShouldQuit() == false) {
	//更新自身的位置
	Vec3d v_word = pose.so3() * v_body;
	pose.translation() += v_word * dt;

	//更新自身旋转
	if (FLAGS_use_quaternion) {
		Quatd q = pose.unit_quaternion() * Quatd(1, 0.5 * omega[0] * dt, 0.5 * omega[1] * dt, 0.5 * omega[2] * dt);
		q.normalize();
		pose.so3() = SO3(q);
	}
	else {
		pose.so3() = pose.sO3() * S03::exp(omega * dt);
	}

	LOG(INFO) << "pose: " << pose.translation().transpose();
	ui.UpdateNavStated(sad::NavStated(0, pose, v_word));


	usleep(dt * 1e6);
}

ui.Quit();
return 0;
}





