# 智能交通车辆监控

## 📖项目简介

### 摘要

目前，我国车辆数目逐年增加，因此而造成的车辆违法事件也因此增多，而仅靠人力去辨别是否违章显然费时费力，所以急需一种手段解决这个问题。目前交通上的违章检测方法有人工辨别，但费时费力；还有在地下铺设感应线圈检测闯红灯和超速，但维护成本太高，不能灵活设置；另外也有通过电子眼检测的方案，但只限于超速，而且单靠雷达，准确度有待商榷。我们的方案，是将雷达和视频检测相融合，分别检测车辆状态，然后取最优结果，准确度可以很好的保证。除此之外，由于阴雨雾霾天气的影响，视频界面可能会模糊不清，为此，我们加入了去雾、去雨处理，使视频结果在异常天气也能清晰无比。本项目的目标是做一款有友好人机交互界面的软件，实现车辆检测、违章自动抓拍、车辆信息自动识别，车流量统计、视频去雾处理等，满足道路违章抓拍取证的要求。下面将会详细介绍项目的实施方案。

---
|类别|内容|
|------|------|
|目的|一款软件，实现违章抓拍、自动识别车牌、统计车流量信息、区分车道等功能|
|应用的技术|图像处理、机器学习、深度学习|  
|使用的手段|车牌识别、车辆检测、图片抓拍、违章判断、车流量统计|
|使用的工具|雷达、监控摄像头、抓拍摄像头|
|呈现形式|做成一款PC端软件，将测得的数据在界面上进行展示，并存档|
|优势|安装维护成本低|
|特色|视频和雷达的融合，准确率更高，系统稳定可靠|

## 🍉已完成
---
|已完成|可展示形式|
|-|-|
|车牌识别|可以识别图片内的车牌|
|车辆检测|可检测并追踪视频中车辆|
|雷达监测|雷达获取车辆速度、坐标、速度等信息|
|软件界面|软件界面已完成|

### 1. 车牌识别 

![](./lijie/c++版本/resyult.jpg)
#### 可识别和待支持的车牌的类型

- [x] 单行蓝牌
- [x] 单行黄牌
- [x] 新能源车牌
- [x] 白色警用车牌
- [x] 使馆/港澳车牌
- [x] 教练车牌
- [x] 武警车牌
- [ ] 民航车牌
- [ ] 双层黄牌
- [ ] 双层武警
- [ ] 双层军牌
- [ ] 双层农用车牌
- [ ] 双层个性化车牌

### 2. 车辆检测

![拍摄于西安电子商城天桥](./Res/cars.gif)

### 3. 软件界面

![初步界面](./Res/surface.png)

## 🐳还需要做的事
---
|list|content|
|-|-|
|道路检测|看了一些代码，好像也比较成熟了[示例](https://github.com/ljgithub669/CarND-Advanced-Lane-Lines)|
|代码功能的优化|目前代码主要应用别人的，自己还不会改动，后期需要多费些功夫|
|代码接口问题|对代码还不熟悉，未能灵活使用接口|
|后端和前端的统一|把后端功能在软件上进行呈现|

## 目前进度

如今已完成基本功能，测试尚可，其他信息稍后补充

**结果展示**
![](./Res/result2.gif)

## 🚀截止日期
---
2019年6月进行结题答辩