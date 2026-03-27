#include <iostream>
#include"VRObject.h"

using namespace std;



int main()
{
	VRObject player;
	VRObject target;
	VRObject obstacle;

	cout << "对象名调用：" << endl;
	player.init("玩家", 0.0, 0.0, 0.0);
	player.displayPosition();

	cout << "指针调用：" << endl;
	VRObject t;
	VRObject* pTarget = &t;
	pTarget->init("目标物体", 10.0, 5.0, 3.0);
	pTarget->displayPosition();

	cout << "引用调用：" << endl;
	VRObject obs;
	obs.init("障碍物", 2.0, 8.0, -4.0);
	VRObject& refObstacle = obs;
	refObstacle.displayPosition();

	cout << "计算距离：" << endl;
	cout << "玩家 到 目标物体 的距离: " << player.distanceTo(*pTarget) << endl;
	cout << "玩家 到 障碍物 的距离: " << player.distanceTo(refObstacle) << endl;
	cout << "目标物体 到 障碍物 的距离: " << pTarget->distanceTo(refObstacle) << endl;

	cout << "\n修改玩家位置：" << endl;
	player.setPosition(5.0, 5.0, 5.0);
	player.displayPosition();
	cout << "玩家 到 目标物体 的新距离: " << player.distanceTo(*pTarget) << endl;

	return 0;
}