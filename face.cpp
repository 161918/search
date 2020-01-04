#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <Robuffer.h>


void InternalDetectObjects(cv::Mat& inputImg, std::vector<cv::Rect> & objectVector, std::vector<cv::Rect> & objectVectorBodies, cv::CascadeClassifier& face_cascade, cv::CascadeClassifier& body_cascade)
{
    cv::Mat frame_gray;

    cvtColor(inputImg, frame_gray, CV_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, objectVector, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
    //detect bodies
    body_cascade.detectMultiScale(frame_gray, objectVectorBodies, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 300));
}


// run the object detection function on the image and draw rectangles around the results
int main(int argc, char **argv )
{
    cv::CascadeClassifier face_cascade;
    cv::CascadeClassifier body_cascade;

    cv::Mat frame = cv::imread(argv[1],1);

    if (frame.empty())
        return;

    std::vector<cv::Rect> faces;
    std::vector<cv::Rect> bodies;
    // run object detection
    InternalDetectObjects(frame, faces, bodies, face_cascade, body_cascade);
    // draw red rectangles around detected faces
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        cv::rectangle(_stored_image, faces[i], cv::Scalar(0, 0, 255, 255), 5);
    }
    // draw black rectangles around detected bodies
    for (unsigned int i = 0; i < bodies.size(); i++)
    {
        cv::rectangle(_stored_image, bodies[i], cv::Scalar(0, 0, 0, 255), 5);
    }
    // draw the image in the pane
    imwrite("algo_resultat.jpg", _stored_image);
    //UpdateImage(_stored_image);
    return 0;
}