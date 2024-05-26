#define _CRT_SECURE_NO_WARNINGS 1��

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "common/eigen_types.h"
#include "common/math_utils.h"
#include "tools/ui/pangolin_windows.h"

///���ڳ���������ʾ��Բ���˶��ĳ���
///�����Ľ��ٶ������ٶȿ�����GFlags������

DEFINE_double(angular_velocity, 10.0, "���ٶȣ��Ƕ���");
DEFINE_double(linear_velocity, 5.0, "����ǰ�����ٶȵ� m/s");
DEFINE_bool(use_quaternion, false, "�Ƿ�ʹ����Ԫ������");

int main(int argc, char** argv) {
	goole::InitGooleLogging(argv[0]);
	FLAGS_stderrthreshold = goole::INFO;
	FLAGS_colorlogtostderr = true;
	google::ParseCommandLineFlags(&argc, &argv, true);
}

///���ӻ�
sad::ui::PangoWindow ui;
if (ui.Init() == false) {
	return -1;
}

double angular_velocity_rad = FLAGS_angular_velocity * sad::math::kDEG2RAD;   //�����ƽ��ٶ�
SE3 pose;																	  //TWB��ʾλ��
Vec3d omega(0, 0, angular_celocity_rad);									  //���ٶ�����	
Vec3d v_body(FLAGS_linear_velocity, 0, 0);									  //����ϵ�ٶ�
const double dt = 0.05;													      //ÿ�θ��µ�ʱ��

while (ui.ShouldQuit() == false) {
	//���������λ��
	Vec3d v_word = pose.so3() * v_body;
	pose.translation() += v_word * dt;

	//����������ת
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





