#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <bitset>
//#include "LATCH.h"
#include "K2NN.h"

#include <vector>
#include "KORAL.h"

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/program_options.hpp>


using namespace std;
namespace po = boost::program_options;



void search() {
/*    constexpr int threshold = 5;
    constexpr int max_twiddles = 2;
    constexpr int warmups = 10;

    int start;
    int i;*/



    constexpr int threshold = 2;
    constexpr int max_twiddles = 5;




    // -------- Configuration ----------
    constexpr uint8_t KFAST_thresh = 65;
    constexpr char name[] = "test.jpg";
    constexpr float scale_factor = 1.2f;
    constexpr uint8_t scale_levels = 2;
    // --------------------------------




    // ------------- Image Read -------
    cv::Mat image = cv::imread(name, CV_LOAD_IMAGE_GRAYSCALE);
    if (!image.data) {
        std::cerr << "ERROR: failed to open image. Aborting." << std::endl;
        return;
    }

    // ------------- KORAL -----------
    KORAL koral(scale_factor, scale_levels);
    koral.go(image.data, image.cols, image.rows, KFAST_thresh);
    std::cout << "KORAL found " << koral.kps.size() << " keypoints and descriptors." << std::endl << std::endl;

    // --------------------------------


    constexpr char path[] = "./images";
    boost::filesystem::path p(path);



    int n = 0;

    if (boost::filesystem::is_directory(p)) {

        std::cout << p << " is a directory containing:\n";
        for (auto &entry : boost::make_iterator_range(boost::filesystem::directory_iterator(p), {})) {
            n++;
            std::cout << entry.path().string() << "\n";

            // ------------- Image Read ------------
            cv::Mat testimage = cv::imread(entry.path().string(), CV_LOAD_IMAGE_GRAYSCALE);
            if (!testimage.data) {
                std::cerr << "ERROR: failed to open image. Aborting." << std::endl;
                return;
            }

    	    // Resize src so that is has the same size as img
//	    cv::resize(testimage, testimage, image.size());

            // ------------- KORAL -----------
            KORAL koraltwo(scale_factor, scale_levels);
            koraltwo.go(testimage.data, testimage.cols, testimage.rows, KFAST_thresh);
            // --------------------------------


            // ------------ Output ------------
            std::cout << "KORAL two found " << koraltwo.kps.size() << " keypoints and descriptors." << std::endl;
            Matcher<false> m(koraltwo.desc.data(), koraltwo.kps.size(), koral.desc.data(), koral.kps.size(), threshold, max_twiddles);
            m.bruteMatch();
            std::cout << "matches found: " << m.matches.size() << " of " << koral.kps.size() <<   std::endl;


            //Matcher<false> mr(koral.desc.data(), koral.kps.size(), koraltwo.desc.data(), koraltwo.kps.size(), threshold, max_twiddles);
            Matcher<false> mr(koral.desc.data(), koral.kps.size(), koraltwo.desc.data(), koraltwo.kps.size(), threshold, max_twiddles);

            mr.bruteMatch();

            std::cout << "matches reverse found: " << mr.matches.size() << " of " << koral.kps.size() <<   std::endl << std::endl;

	    unsigned int m_threshold= (koral.kps.size() * 0.27);

            if( m.matches.size() >=  m_threshold && mr.matches.size() >=  m_threshold ) {
                 std::cout << "MATCHED!!! threshold is " << m_threshold << std::endl;
		cv::namedWindow( entry.path().string());// Create a window for display.
	        cv::imshow( entry.path().string(), testimage );
		cv::waitKey(0);
	    }

           std::cout << "-------------------------------------------------------" << std::endl;

        }
    }




}


int main() {

    search();

    return 0;
}