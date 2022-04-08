为了做一个调节控制轴的上位机软件。

主要用到了QT chart， 并且大量学习内置的`example`，主要包括 QLineSeries、QSplineSeries，一个样条曲线和一个折线。

其中白色显示最为重要的RMS曲线，与黑色背景形成最鲜明对比。

还有一个QAreaSeries为了显示两个意义相同的位置信息（实际位置和设定位置），以亮蓝线表示实际位置，暗蓝色表示设定位置，中间的透明蓝表示两线围成的区域。

还有一个QStackedBarSeries，折叠柱状图，我的想法是设计红色为正误差，绿色为负误差，类似于股票的涨跌，其中柱状图包络线为实际值，并且整图来看，由于误差的累计在pid中是有所含义的，红绿色面积大小比较显眼。



还设置了多y轴，个人认为这是我设计最全的一个图了：各个颜色和图类分别表示不同的含义，我本想将左侧的红绿色y轴合二为一，但不太会且有bug，故放弃。



在图中还有点击图例的交互：实现图例闪烁和曲线现隐。

以及鼠标hover在scatter点上的显示反应。



![image-20220408194524894](https://gitee.com/tsuiwade/images/raw/master/img/image-20220408194524894.png)



接下来还需要做协议的解析、动态调整y轴的范围、计算error值。计算rms值。