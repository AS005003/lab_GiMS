#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>


#include <iostream>

using namespace cv;
using namespace std;



int main(int argc, char** argv)
{
    // Загружаем исходное изображение
    Mat src = imread("photo.jpg", 1);
    //imshow("Исходное изображение", src);
    // Создаем объект для результата
    Mat dst;

    setlocale(LC_ALL, "rus");
    if (!src.data) {
        cout << "ошибка" << endl;
        return -1;
    }
    int choise;
    do {
        cout << "1: Фильтрация изображения. Медианный фильтр." << endl;
        cout << "2: Выделение краев. Фильтр Собела." << endl;
        cout << "3: Сегментация изображения. Алгоритм сегментации MeanShift." << endl;
        cout << "4: ВЫХОД." << endl;
        cout << "\nВыбрать: "; cin >> choise;

        switch (choise)
        {
        case 1:

            //Медианный фильтр
            medianBlur(src, dst, 5);

            // Отображаем исходное изображение под действием медианного фильтра
            //imshow("Медианный фильтр", dst);

            //сохранение результата
            imwrite("median_filtr.jpg", dst);

            break;

        case 2:

            // Оператор Собела
            Sobel(src, dst, -1, 1, 1);

            // Отображаем исходное изображение под действием фильтра собеля
            //imshow("Фильтр Собела", dst);
            
            //сохранение результата
            imwrite("sobel.jpg", dst);
            
        break;
    
        case 3:

            // Сегментация изображения
            pyrMeanShiftFiltering(src, dst, 25, 25);

            // Отображаем исходное изображение под действием сегментации
            //imshow("MeanShift", dst);

            //сохранение результата
            imwrite("MeanShift.jpg", dst);
            break;

        case 4:
            return 0; 
        }
    } while (1);
}