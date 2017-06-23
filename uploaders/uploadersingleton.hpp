#ifndef UPLOADERSINGLETON_HPP
#define UPLOADERSINGLETON_HPP

#include "uploader.hpp"
#include <QDir>
#include <QMap>

class UploaderSingleton : public QObject {
    Q_OBJECT
public:
    static UploaderSingleton &inst() {
        static UploaderSingleton inst;
        return inst;
    }
    void registerUploader(Uploader *uploader);
    void upload(QPixmap *pixmap);
    void upload(QByteArray img, QString format);
    void upload(QFile img, QString format);
    QList<Uploader *> uploaderList();
    void set(QString uploader);
    QString selectedUploader();
    QList<std::runtime_error> errors();
    QString currentUploader();

signals:
    void newUploader(Uploader *u);

private:
    QDir saveDir;
    UploaderSingleton();
    QMap<QString, Uploader *> uploaders;
    QString uploader = "imgur";
    QList<std::runtime_error> errs;
};

#endif // UPLOADERSINGLETON_HPP
