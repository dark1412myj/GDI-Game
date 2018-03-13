## 基于GDI的小游戏
+ CThing
1. CThing类是所有游戏场景的基类
2. 类内纯虚函数定义类所有场景中的物品必须的方法
3. CAnimal类定义了场景内可移动的动物类
4. CPeople类定义了场景内的玩家
+ CWorld
1. CWorld类为整个游戏世界
2. CWorld类的Add方法为游戏场景添加新物品
3. CWorld类的Notify方法通知游戏场景内所有物品进行移动
### 程序的类图如下：
![Alt text](https://github.com/dark1412myj/IMageBase/blob/master/GDI_1.jpg "Optional title")
