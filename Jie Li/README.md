车牌识别主要分为两部分：一是车牌检测，使用深度学习，通过二值化、连通域检测、字符角点拟合、crop、sobel算子垂直分割；二是字符识别，用的是CNN神经网络，训练汉字和字母识别模型。
以上均由HyperLpr项目衍生，以下是结果展示：
结果图
![](http://ww1.sinaimg.cn/large/006YKa8tly1g4lqwky1dsj311y0kgaun.jpg)
识别结果保存
![](http://ww1.sinaimg.cn/large/006YKa8tly1g4mshx1rprj30v70g1n53.jpg)
运行GIF
![](http://ww1.sinaimg.cn/large/006YKa8tly1g4lqwkti1qg30zv0j7dtj.gif)

-------------------------------------------------------------------
以上为静态图片识别，下面为视频识别，速度比较慢，因为要将视频处理成每一帧图片进行识别，经测试，1s的视频需要大约22s才能识别完毕
![](http://ww1.sinaimg.cn/large/006YKa8tly1g4mxgxj8trg30w90e6e83.gif)
