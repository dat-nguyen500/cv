#include <opencv2/opencv.hpp>

int main() 
{
    cv::Mat img = cv::imread("C:/Users/datng/OneDrive/OneDrive/Mecatronique/Vision par ordinateur/cv/lena.png");
    if (img.empty()) 
    {
        std::cout << "Could not read the image: " << "1_introduction/lena.png" << std::endl;
        return 1;
    }
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", img);
    cv::waitKey(0);
    return 0;
}