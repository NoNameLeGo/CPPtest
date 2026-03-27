### （一）VR游戏角色类（VRCharacter）

**题目要求**：设计一个VR游戏角色类（VRCharacter），用于管理游戏角色的基本属性。


#### 1. 私有成员：
- 角色名称（`name`，`string`类型）
- 当前血量（`health`，`int`类型，初始值100）
- 最大血量（`maxHealth`，`int`类型，初始值100）
- 攻击力（`attack`，`int`类型，初始值10）


#### 2. 公有成员函数：
- `init(string n)`：初始化角色名称
- `takeDamage(int dmg)`：受到伤害，扣除血量
- `heal(int amount)`：恢复血量
- `getHealthPercent()`：获取血量百分比（返回0-100的整数）
- `displayStatus()`：显示角色状态


#### 3. 封装性要求：
- 类声明与成员函数定义分离，分别放在`VRCharacter.h`和`VRCharacter.cpp`中
- 主函数单独放在`main.cpp`中


#### 4. 测试要求：
在`main`函数中创建角色对象，分别使用对象名、指针、引用三种方式调用成员函数，模拟角色战斗和恢复过程。