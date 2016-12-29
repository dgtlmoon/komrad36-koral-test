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

unsigned int numkps = 200;


using namespace std;
namespace po = boost::program_options;



void search() {
/*    constexpr int threshold = 5;
    constexpr int max_twiddles = 2;
    constexpr int warmups = 10;

    int start;
    int i;*/



    constexpr int threshold = 10;
    constexpr int max_twiddles = 5;




    // -------- Configuration ----------
    constexpr uint8_t KFAST_thresh = 65;
    constexpr char name[] = "test.jpg";
    constexpr float scale_factor = 1.2f;
    constexpr uint8_t scale_levels = 8;
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


    constexpr char path[] = "/tmp/KORAL/images";
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



            // ------------- KORAL -----------
            KORAL koraltwo(scale_factor, scale_levels);
            koraltwo.go(testimage.data, testimage.cols, testimage.rows, KFAST_thresh);
            // --------------------------------


            // ------------ Output ------------
            std::cout << "KORAL two found " << koraltwo.kps.size() << " keypoints and descriptors." << std::endl;


            Matcher<false> m(koraltwo.desc.data(), koraltwo.kps.size(), koral.desc.data(), koral.kps.size(), threshold, max_twiddles);
            m.bruteMatch();

            std::cout << "matches found: " << m.matches.size() << std::endl;


            //Matcher<false> mr(koral.desc.data(), koral.kps.size(), koraltwo.desc.data(), koraltwo.kps.size(), threshold, max_twiddles);
            Matcher<false> mr(koral.desc.data(), koral.kps.size(), koraltwo.desc.data(), koraltwo.kps.size(), threshold, max_twiddles);

            mr.bruteMatch();

            std::cout << "matches reverse found: " << mr.matches.size() << std::endl << std::endl;
        }
    }








/*
    std::cout << "First descriptor in first set in KORAL looks like.. " << std::endl;
    for ( i = 0; i < 64; ++i) std::cout << std::bitset<8>(koral.desc[koral.kps.size()+10]);
    std::cout << std::endl;
*/

    // --------------------------------



    // Initialization of Matcher class
    // number for vector size size is /64, this is because it needs to know how many descriptors

    /*
    // -----------------------------------------------------------------------------------
    std::cout << "---- fastApproxMatch results ----" << std::endl;
    std::cout << "Warming up..." << std::endl;
    for (i = 0; i < warmups; ++i) {
        m.fastApproxMatch();
        std::cout << ".";
    }
    std::cout << std::endl;
    m.fastApproxMatch();
    i = 0;
    if(m.matches.size()) {
        start = m.matches[0].t;
        for (auto &&match : m.matches) {
            if (start == match.t) {
                i++;
            } else {
                std::cout << "Non consecutive reference found at " << match.t << " -> " << start << std::endl;
            }
            start++;
        }
        if ((unsigned) i == m.matches.size()) {
            std::cout << i << " consecutive results found" << std::endl;
        }
    } else {
        std::cout << "No matches found" << std::endl;
    }

    // -----------------------------------------------------------------------------------
    std::cout << "---- bruteMatch results ----" << std::endl;
    std::cout << "Warming up..." << std::endl;
    for (i = 0; i < warmups; ++i) {
        m.bruteMatch();
        std::cout << ".";
    }
    std::cout << std::endl;

    m.bruteMatch();

    i = 0;
    i = 0;
    if(m.matches.size()) {

        start = m.matches[0].t;
        for (auto &&match : m.matches) {
            if (start == match.t) {
                i++;
            } else {
                std::cout << "Non consecutive reference found at " << match.t << " -> " << start << std::endl;
            }
            start++;
        }
        if ((unsigned) i == m.matches.size()) {
            std::cout << i << " consecutive results found" << std::endl;
        }
    } else {
        std::cout << "No matches found" << std::endl;
    }

    // -----------------------------------------------------------------------------------
    std::cout << "---- exactMatch results ----" << std::endl;
    std::cout << "Warming up..." << std::endl;
    for (i = 0; i < warmups; ++i) {
        m.exactMatch();
        std::cout << ".";
    }
    std::cout << std::endl;
    m.exactMatch();
    i = 0;
    if(m.matches.size()) {

        start = m.matches[0].t;
        for (auto &&match : m.matches) {
            if (start == match.t) {
                i++;
            } else {
                std::cout << "Non consecutive reference found at " << match.t << " -> " << start << std::endl;
            }
            start++;
        }
        if ((unsigned) i == m.matches.size()) {
            std::cout << i << " consecutive results found" << std::endl;
        }

    } else {
        std::cout << "No matches found" << std::endl;
    }
     */
}


int main() {

    search();

    return 0;
}