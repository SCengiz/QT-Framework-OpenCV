#include <QCoreApplication>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cv::Mat img = cv::imread("/home/htr/Downloads/lena.png");
    cv::imshow("Window", img);
    cv::waitKey(0);

    return a.exec();
}
