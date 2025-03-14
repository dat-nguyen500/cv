#include "opencv2/highgui/highgui.hpp"
#include <iostream>

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *)
{
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main()
{
    cv::namedWindow("Video display", cv::WINDOW_AUTOSIZE);
    g_cap.open("C:/Users/datng/OneDrive/OneDrive/Mecatronique/Vision par ordinateur/cv/medias/video.mp4");
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has " << frames << "frames of dimensions (" <<
        tmpw << ", " << tmph << ")." << std::endl;
    cv::createTrackbar("Position", "Video display", &g_slider_position,
        frames, onTrackbarSlide);
    cv::Mat frame;
    while(true)
    {
        if (g_run != 0)
        {
            g_cap >> frame;
            if (frame.empty())
                break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            cv::setTrackbarPos("Position", "Video display", current_pos);
            cv::imshow("Video display", frame);
            g_run -= 1;
        }
        char c = (char) cv::waitKey(10);
        if (c == 's') // single step
        {
            g_run = 1;
            std::cout << "Single step, run = " << g_run << std::endl;
        }
        if (c == 'r') // run mode
        {
            g_run = -1;
            std::cout << "Run mode, run = " << g_run << std::endl;
        }
        if (c == 27)
            break;
    }
    return 0;
}