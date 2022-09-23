#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//        QLineSeries *series = new QLineSeries();


//        series->setName("Bubble");

//        series->append(QPointF(1024,0.004073));
//        series->append(4096,0.053277);
//        series->append(16384,0.758315);
//        series->append(65536,12.6633);
//        series->append(262144,210.895);
////        series->append(1048576,3);

//        QChart *chart = new QChart();
//                QLineSeries *series2 = new QLineSeries();
//series2->setName("OKD");
//        series2->append(0,5);
//        series2->append(QPointF(2,9));
//        series2->append(3,5);
//        series2->append(7,5);
//        series2->append(11,6);

////        chart->addSeries(series2);
//        chart->addSeries(series);
//        series->setUseOpenGL(true);
//        chart->createDefaultAxes();
//        chart->setTitle(QStringLiteral("Графік залежності часу виконання від кількості елементів"));

//        QChartView *view = new QChartView(chart);
//        //Turn on anti aliasing for better display
//        view->setRenderHint(QPainter::Antialiasing);
//        view->resize(50,50);








//        *series2 << QPointF(11,2) << QPointF(15,1) << QPointF(18,14) << QPointF(19,2);

        //Show chart


//        view->show();




    return a.exec();
}
