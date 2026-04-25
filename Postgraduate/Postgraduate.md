# 题目二：学生与研究生

## 题目描述

设计一个基类 `Student`，包含：
- 保护成员：`string name`（姓名）、`int id`（学号）
- 公有成员函数：`void showBasic()`，输出姓名和学号

再设计一个派生类 `Postgraduate`（研究生），公有继承自 `Student`，新增：
- 私有成员：`string researchField`（研究方向）
- 公有成员函数：
  - 构造函数（在初始化列表中调用基类构造函数）
  - `void showAll()`：输出完整信息（调用 `showBasic()` 并额外输出研究方向）
  - `void setField(string field)`：修改研究方向（简单的 `set` 函数）

## 期望输出：

```
=== 初始信息 ===
姓名：张三，学号：2021001
研究方向：计算机视觉

=== 修改后信息 ===
姓名：张三，学号：2021001
研究方向：虚拟现实
```