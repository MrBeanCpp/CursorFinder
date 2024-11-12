#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QCursor>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QDir>
#include <QApplication>
#include <QTime>
#include <settingdialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    double distance(const QPoint& lhs, const QPoint& rhs);
    double includeAngle(const QPoint& A, const QPoint& B, const QPoint& C);
    void setCursorPix(const QPixmap& pix);
    void initSysTray(void);
    void setAutoRun(bool isAuto);
    bool isAutoRun(void);
    void writeIni(void);
    void readIni(void);
    bool isCursorHide(void);
    bool isForeFullScreen(void);
    HWND topWinFromPoint(const QPoint& pos);
    QPoint screenCursorPos(void);

signals:
    void cornerDetected(QPoint pos, QTime time);
    void slowSpeedDetected(void);

private:
    Ui::Widget* ui;

    QPixmap cursorPix;

    const QString iniPath = QApplication::applicationDirPath() + "/settings.ini";
    const QString Reg_AutoRun = "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"; //HKEY_CURRENT_USER仅仅对当前用户有效，但不需要管理员权限
    const QString AppName = "CursorFinder";
    const QString AppPath = QDir::toNativeSeparators(QApplication::applicationFilePath());
    QSystemTrayIcon* sysTray = nullptr;

    int Gap = 120; //ms
    int Dist = 150; //px

    bool isStopWhileFullScreen = true;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent* event) override;

    // QWidget interface
protected:
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
};
#endif // WIDGET_H
