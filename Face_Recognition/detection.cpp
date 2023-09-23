#include "detection.h"

Detection::Detection()
{
    this->mFrameColor = Scalar(0, 255, 0);
}


Detection::Detection(Scalar Color)
{
    this->mFrameColor = Color;
}

Detection::~Detection()
{
}

cv::Mat& Detection::detectOnImages(cv::Mat& image, cv::CascadeClassifier& cascadeClassifier ,double scale)
{
    /*
    * 1. Convert the current frame to grayscale.
    * 2. Resize the current frame to 1/4 to speed up the Detection process.
    * 3. Equalize the histogram of the resized frame.
    * 4. Detect faces of different sizes using cascade classifier.
    * 5. Draw rectangles around the faces.
    * Return the current frame with rectangles drawn around the faces.
    */
    std::vector<cv::Rect> faces, faces2;
    cv::Mat gray, smallImg;
    // To convert the frames to gray mFrameColor
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    double fx = 1 / scale;
    // To resize the frames
    resize(gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR);
    equalizeHist(smallImg, smallImg);
    // To detect faces of different sizes using cascade classifier
    cascadeClassifier.detectMultiScale(smallImg, faces, 1.1, 5, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    // Draw rectangles around the faces
    for (auto& face : faces)
    {
        double aspect_ratio = (double)face.width / face.height;
        rectangle(image, Point(cvRound(face.x * scale), cvRound(face.y * scale)), Point(cvRound((face.x + face.width - 1) * scale), cvRound((face.y + face.height - 1) * scale)), this->mFrameColor, 3, 8, 0);
    }
    return image;
}

void Detection::run(cv::CascadeClassifier& cascadeClassifier)
{
    /*
    * 1. Get the current frame from the camera.
    * 2. Detect faces on the current frame.
    * 3. Render the current frame with rectangles drawn around the faces.
    * 4. Press q to exit from the window.
    * 5. Stop the camera.
    */
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
        camera.renderFrame(this->detectOnImages(frame, cascadeClassifier ,2));
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
