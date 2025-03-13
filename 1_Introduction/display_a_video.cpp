#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
int main()
{
    cv::namedWindow("Video display", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open("C:/Users/datng/OneDrive/OneDrive/Mecatronique/Vision par ordinateur/cv/medias/video.mp4");
    cv::Mat frame;
    for (;;)
    {
        cap >> frame;
        if (frame.empty())
            break; // Ran out of film
        cv::imshow("Video display", frame);
        if (cv::waitKey(33) >= 0)
            break;
    }
    return 0;
}