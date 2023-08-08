#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
    cv::Mat img = cv::imread("C:/Users/Alex/Desktop/1pic.png");
    if(img.empty())
        return -1;

    cv::Mat blur_mat, gaussian_mat, treshold_mat, gray_mat, hsv_mat, canny_mat;

    cv::pyrDown(img, img, cv::Size(img.cols/2, img.rows/2));
    cv::imshow("Example1", img);

    cv::blur(img, blur_mat, cv::Size(3, 3), cv::Point(-1, -1));
    cv::imshow("Blur", blur_mat);

    cv::GaussianBlur(img, gaussian_mat, cv::Size(5, 5), 0, 0);
    cv::imshow("GaussianBlur", gaussian_mat);

    cv::threshold(img, treshold_mat, 125, 208, cv::THRESH_BINARY);
    cv::imshow("Treshold", treshold_mat);

    cv::cvtColor(img, gray_mat, cv::COLOR_BGR2GRAY, 0);
    cv::imshow("Gray", gray_mat);

    cv::cvtColor(img, hsv_mat, cv::COLOR_BGR2HSV, 0);
    cv::imshow("HSV", hsv_mat);

    cv::Canny(gray_mat, canny_mat, 100, 200);
    cv::imshow("Canny", canny_mat);

    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}
