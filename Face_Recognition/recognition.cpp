#include "recognition.h"

Recognition::Recognition()
{

}

Recognition::~Recognition()
{

}

void Recognition::run()
{
    std::chrono::time_point<std::chrono::high_resolution_clock>
        prev_frame_time(std::chrono::high_resolution_clock::now());
    std::chrono::time_point<std::chrono::high_resolution_clock>
        new_frame_time;

    Camera camera;
    cv::Mat frame, image;
    while (1)
    {
        camera.getCaptureDevice() >> frame;
        if (frame.empty())
            break;
        cv::Mat& frame2 = this->mDetection.detectOnImages(frame, this->mUtil.cascadeClassifier, 2);
        cout<< "Prediction: " << this->mModel.predict(frame2) << "\n";
        camera.renderFrame(frame2);
        char c = (char)cv::waitKey(10);
        // Press q to exit from the window
        if (c == 27 || c == 'q' || c == 'Q')
            break;

        new_frame_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration1(new_frame_time - prev_frame_time);
        int fps = int(1 / duration1.count());
        std::cout << "fps : " << fps << std::endl;

        prev_frame_time = new_frame_time;
    }
    camera.stop();
}
