# CursorFinder

`Windows`平台下的 `Shake to Find Cursor` ：晃动鼠标放大光标 ，防止丢失视野

### Snapshot

![cursor](images/cursor.gif)

### 更换默认光标（Change Default Cursor Image）

Place you own `cursor` Image to the same directory of `exe`， and rename it to `cursor`， like:

- cursor.cur
- cursor.ico
- ... (.jpg jpeg png)

### 原理

鼠标轨迹夹角 < 90° 则判定为`DirectionChanged`，也就是`Corner`，检测两次`Corner`之间的时间间隔 & `distance`来判断**晃动**  

> PS：直接设置光标会卡顿，故采用透明 **Widget + Label** 完成光标动画

### 托盘图标

- 可设置开机启动  
- 可设置两个`Corner`最大时间间隔 & `Corner`最小距离间隔