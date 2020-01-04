#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables
Mat src, dst;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;


/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  src = imread( argv[1] );


 /// Default start
 Morphology_Operations( 0, 0 );

return 0;
}

 /**
  * @function Morphology_Operations
  */
void Morphology_Operations( int, void* )
{
  // Since MORPH_X : 2,3,4,5 and 6
  int operation = morph_operator + 2;

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );

  /// Apply the specified morphology operation
  morphologyEx( src, dst, operation, element );
  imwrite("algo_resultat.jpg", dst);
  }