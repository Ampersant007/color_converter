#ifndef IMAGEANALYZER_H
#define IMAGEANALYZER_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QProgressBar>
#include <QDir>
#include <QImageReader>
#include <QHeaderView>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QListWidget>
#include <QSplitter>

class ImageAnalyzer : public QMainWindow
{
    Q_OBJECT

private:
    QTableWidget *table;
    QListWidget *fileList;
    QPushButton *selectFolderButton;
    QPushButton *selectFilesButton;
    QPushButton *clearButton;
    QPushButton *analyzeButton;
    QLineEdit *folderPath;
    QLabel *statusLabel;
    QProgressBar *progressBar;
    QStringList imageFiles;

    void analyzeImage(const QString &filePath);
    QString getExtraInfo(QImageReader &reader, const QImage &image, const QString &format, qint64 fileSize);
    void addImageFile(const QString &filePath);
    QString getCompressionInfo(const QString &format);
    QString getColorDepthInfo(const QImage &image, const QString &format);

public:
    ImageAnalyzer(QWidget *parent = nullptr);
    ~ImageAnalyzer();

private slots:
    void selectFolder();
    void selectFiles();
    void clearFiles();
    void analyzeImages();

};

#endif // IMAGEANALYZER_H
