### （二）3D空间物体距离计算器

**题目要求**：在VR场景中，经常需要计算物体之间的距离。设计一个3D空间物体类（`VRObject`），用于管理物体位置和计算距离。


#### 1. 私有成员：
- 物体名称（`name`，`string`类型）
- 3D坐标：`x`、`y`、`z`（`double`类型）


#### 2. 公有成员函数：
- `init(string n, double x0, double y0, double z0)`：初始化物体名称和坐标
- `setPosition(double x, double y, double z)`：设置物体位置
- `distanceTo(VRObject &other)`：计算到另一个物体的距离
- `displayPosition()`：显示物体坐标


#### 3. 封装性要求：
- 类声明与成员函数定义分离
- 在`main`函数中创建多个物体，计算它们之间的距离


#### 4. 测试要求：
创建玩家位置、目标物体、障碍物三个对象，计算它们之间的距离，使用三种访问方式调用函数。