#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: cv_demo <image>\n";
        return 1;
    }

    cv::Mat img = cv::imread(argv[1]);
    if (img.empty()) {
        std::cerr << "Nie można wczytać obrazu\n";
        return 1;
    }

    cv::Mat gray, edges;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 1.5);
    cv::Canny(gray, edges, 50, 150);

    cv::imshow("Original", img);
    cv::imshow("Edges", edges);
    cv::waitKey(0);
    return 0;
}