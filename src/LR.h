#ifndef LEARNING_RATE_H
#define LEARNING_RATE_H

namespace dpl{

/* adaptive learning rate */
double learningRate( double*A, int index ){
	//std::cout << index << " " << A[index] << std::endl;
	return 0.00001/A[index];
	// return 0.0001;
}


}

#endif /*  learning rate */
