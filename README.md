# CursorFinder

## 介绍
原项目是MrBeanCpp/CursorFinder，项目地址为https://github.com/MrBeanCpp/CursorFinder
Windows平台下的 [Shake to Find Cursor] 晃动鼠标放大光标  
防止找不到鼠标光标

原理：鼠标轨迹夹角<90则判定为DirectionChanged，也就是Corner，检测两次Corner之间的时间间隙 & distance来判断晃动  
PS：直接设置光标会卡顿，故采用透明Widget+Label完成光标动画

托盘图标：  
可设置开机启动  
可设置两个Corner最大时间间隔 & Corner最小距离间隔
