#ifndef SPARSE_COORDINATE_CODING_H
#define SPARSE_COORDINATE_CODING_H

namespace dpl{

static unsigned int myseed;

double getAbs( double value ){
	if( value < 0 )
		return -1*value;
	else
		return value;
}

double **FeatureInitialization( int featureDim, int sampleNumber ){

	double **feature = (double**)malloc(sampleNumber*sizeof(double*));
        for( unsigned int i=0; i<sampleNumber; i++ ){
		feature[i] = (double*)malloc(featureDim*sizeof(double));
		for( unsigned int j=0; j<featureDim; j++ )
			feature[i][j] = 0;
	}
	return feature;
}

std::vector<int> *NonZeroIndexInitialization( int sampleNumber ){
	std::vector<int> *nonZeroIndex = new std::vector<int> [sampleNumber];
	return nonZeroIndex;
}

double ShrinkageFunction( double value, double theta ){

	if( value < -theta )
		return value+theta;
	else if( value > theta )
		return value-theta;
	else
		return 0;
}

double *Initialize_A_Copy( int featureDim ){

	double *A_Copy = (double*)malloc(featureDim*sizeof(double));
	for( unsigned int i=0; i<featureDim; i++ )
		A_Copy[i]=0;
	return A_Copy;
}

double *Initialize_A( int featureDim ){

	double *A = (double*)malloc(featureDim*sizeof(double));
	for( unsigned int i=0; i<featureDim; i++ )
		A[i]=0;
	return A;
}

void Initialize_A( double *A, double *A_Copy, int featureDim ){
	for( unsigned int i=0; i<featureDim; i++ ){
		A[i]=A_Copy[i];
		A_Copy[i]=0;
    	}
}

void Update_A( double *A, double *A_Copy, double *feature, std::vector<int> &nonZeroIndex ){
	for( unsigned int i=0; i<nonZeroIndex.size(); i++ ){
		A[nonZeroIndex[i]] += feature[nonZeroIndex[i]]*feature[nonZeroIndex[i]];
		A_Copy[nonZeroIndex[i]] += feature[nonZeroIndex[i]]*feature[nonZeroIndex[i]];
	}
}

double getNonNegativeFeature( double featureElement, double optimalT ){
	if( featureElement+optimalT>=0 )
		return optimalT;
	else
		return -1*featureElement;
}

int *getRandomIndex( int size ){

	std::vector<int> index (size);
	int *data=(int*)malloc(size*sizeof(int));
	for( unsigned int i=0; i<size; i++ )
	        index[i] = i;

	for( unsigned int i=0; i<size; i++ ){
    		int randomIndex = rand_r(&myseed)%index.size();
        	data[i] = index[randomIndex];
        	index.erase(index.begin()+randomIndex);
    	}
    	return data;
}

void UpdateFeature( double **Wd, double *sample, double *residuals, double *feature, std::vector<int> &nonZeroIndex, double lambda, int layers, int featureDim, int sampleDim, bool NonNegative, double p_i, double sigma ){

    for( unsigned int i = 0; i<sampleDim; i++ ){
  		residuals[i] = -sample[i];
        for( unsigned int j = 0; j<nonZeroIndex.size(); j++ )
            residuals[i] += Wd[nonZeroIndex[j]][i]*feature[nonZeroIndex[j]];
    }

	nonZeroIndex.resize(0);
	int *randomIndex = getRandomIndex(featureDim );

	for ( unsigned int i = 0; i < featureDim; i++ ){

		double optimalT;
		double derivative = 0;

		for (unsigned int j = 0;j < sampleDim; j++)
				derivative += (residuals[j]*Wd[i][j]);

		optimalT = ShrinkageFunction( feature[i]-derivative, lambda ) / p_i-feature[i];

		if( NonNegative )
			optimalT = getNonNegativeFeature( feature[i], optimalT );

		feature[i] += optimalT;

		if ( optimalT!=0 ){

			for (unsigned int j = 0; j < sampleDim; j++) {
				residuals[j] += optimalT * Wd[i][j];
			}

		}

		if( feature[i]!=0 )
			nonZeroIndex.push_back(i);

	}
	// double sum_res = 0;
	// for (unsigned int j = 0; j < sampleDim; j++) {
	// 	sum_res += residuals[j] * residuals[j];
	// }
	// p_i = exp(-sum_res / sigma / sigma);

	for ( unsigned int k = 1; k < layers; k++ ){
		for ( unsigned int i = 0; i < nonZeroIndex.size(); i++ ){
        		double optimalT;
        		double derivative = 0;
        		for (unsigned int j = 0;j < sampleDim; j++)
                		derivative += (residuals[j]*Wd[nonZeroIndex[i]][j]);
			optimalT = ShrinkageFunction( feature[nonZeroIndex[i]]-derivative, lambda ) / p_i-feature[nonZeroIndex[i]];

			if( NonNegative )
				optimalT = getNonNegativeFeature( feature[nonZeroIndex[i]], optimalT );

			feature[nonZeroIndex[i]] += optimalT;

			if ( optimalT!=0 ){
				// double sum_res = 0;
				for (unsigned int j = 0; j < sampleDim; j++) {
					residuals[j] += optimalT * Wd[nonZeroIndex[i]][j];
					// sum_res += residuals[j] * residuals[j];
				}
				// p_i = exp(-sum_res / sigma / sigma);
        	}
		}
		// double sum_res = 0;
		// for (unsigned int j = 0; j < sampleDim; j++) {
		// 	sum_res += residuals[j] * residuals[j];
		// }
		// p_i = exp(-sum_res / sigma / sigma);
	}

	nonZeroIndex.resize(0);
	for ( unsigned int i = 0; i < featureDim; i++ ){
		if( feature[i]!=0 )
			nonZeroIndex.push_back(i);
	}
	free(randomIndex);
}


void UpdateWd( double **Wd, double *residuals, double *feature, double *A, std::vector<int> &nonZeroIndex, int sampleDim, bool NonNegative, double p_i ){

    	for ( unsigned int i = 0; i < sampleDim; i++ ){
        	for ( unsigned int j = 0; j < nonZeroIndex.size(); j++ ){
                // std::cout << dpl::learningRate(A,nonZeroIndex[j]) << std::endl;
				if( NonNegative && Wd[nonZeroIndex[j]][i] - feature[nonZeroIndex[j]]*residuals[i]*p_i*dpl::learningRate(A,nonZeroIndex[j])<0 )
				    Wd[nonZeroIndex[j]][i] = 0;
                else
                    Wd[nonZeroIndex[j]][i] = Wd[nonZeroIndex[j]][i] - feature[nonZeroIndex[j]]*residuals[i]*p_i*dpl::learningRate(A,nonZeroIndex[j]);
            }
    	}
}

void NormalizeWd( double **Wd, std::vector<int> &nonZeroIndex, int sampleDim ){
	for( unsigned int i=0; i<nonZeroIndex.size(); i++ ){
		double sum = 0;
		for( unsigned int j=0; j<sampleDim; j++ )
			sum += Wd[nonZeroIndex[i]][j]*Wd[nonZeroIndex[i]][j];
		sum = sqrt(sum);

		if( sum!=0 ){
			for( unsigned int j=0; j<sampleDim; j++ )
				Wd[nonZeroIndex[i]][j] = Wd[nonZeroIndex[i]][j]/sum;
		}
	}
}

void saveFeature( double **feature, char *FeatureFileName, int featureDim, int sampleNumber ){

	printf("Save Features in %s\n", FeatureFileName);

	FILE *fp;
    fp = fopen( FeatureFileName, "w");
    if( fp == NULL ){
		printf("could not find feature file %s\n", FeatureFileName);
        exit(0);
	}

	for( unsigned int i=0; i<featureDim; i++ ){
		for( unsigned int j=0; j<sampleNumber; j++)
	        	fprintf(fp, "%.15lf ", feature[j][i]);
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void saveNonZeroIndex( std::vector<int> *nonZeroIndex, char *IndexFileName, int featureDim, int sampleNumber ){

	printf("Save nonZero index in %s\n", IndexFileName);

	FILE *fp;
    fp = fopen( IndexFileName, "w");
    if( fp == NULL ){
		printf("could not find index file %s\n", IndexFileName);
        exit(0);
	}

	for( unsigned int i=0; i<sampleNumber; i++ ){
		for( unsigned int j=0; j<nonZeroIndex[i].size(); j++)
	        	fprintf(fp, "%d ", nonZeroIndex[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void clearFeature( int sampleNumber, double **feature ){

	for( unsigned int i=0; i<sampleNumber; i++ )
		free(feature[i]);
	free(feature);
}

double computeLassoResult( double **Wd, double *sample, double *feature, double lambda, int sampleDim, int featureDim ){

	double LassoResult = 0;
	double residuals;
	for( unsigned int i=0; i<sampleDim; i++ ){
		residuals = -sample[i];
		for( unsigned int j=0; j<featureDim; j++ )
			residuals += Wd[j][i]*feature[j];

		LassoResult += residuals*residuals;
	}

	double sum_feature = 0;
	for( unsigned int j=0; j<featureDim; j++ )
		sum_feature += getAbs(feature[j]);

    	return 0.5*LassoResult+lambda*sum_feature;
}


void calculateError(  double **Wd,  double **sample, double **feature, double lambda, int sampleNumber, int sampleDim, int featureDim ) {

	double TotalDecError = 0;
	for( unsigned int t=0; t<sampleNumber; t++ ){
		TotalDecError += computeLassoResult( Wd, sample[t], feature[t], lambda, sampleDim, featureDim);
	}
	TotalDecError /= sampleNumber;
	std::cout<<"Total Decode Error is "<<TotalDecError<<std::endl;
}

void UpdateP( double **Wd, double* residuals, int sampleDim, double *p, int index, int sigma){
	double sum_res = 0;
	for (unsigned int j = 0; j < sampleDim; j++) {
		sum_res += residuals[j] * residuals[j];
	}
	p[index] = exp(-sum_res / sigma / sigma);
}

void trainDecoder( double **Wd, double **feature, double **sample, double lambda, int layers, int featureDim, int sampleNumber, int sampleDim, int iterationNumber, bool NonNegative, double sigma ){
	
	double *residuals = (double*)malloc(sampleDim*sizeof(double));
	double *A = Initialize_A( featureDim );
	double *A_Copy = Initialize_A_Copy( featureDim );
	std::vector<int> *nonZeroIndex = NonZeroIndexInitialization( sampleNumber );
	double *p = (double*)malloc(sampleNumber * sizeof(double));

	for (unsigned int i = 0; i < sampleNumber; i++)
	{
		p[i] = 0.0;
		for (unsigned int j = 0; j < sampleDim; j++)
		{
			p[i] += sample[i][j] * sample[i][j];
		}
		p[i] = exp(-p[i] / sigma / sigma);
		// std::cout << p[i] << " ";
	}

	// exit(0);

	srand((unsigned)time(0));
	myseed = (unsigned int) RAND_MAX * rand();
	// myseed = (unsigned int) 1;

	std::cout<<"Train decoder"<<std::endl;
	double ComputionalTime = 0;
	clock_t BeginTime = clock();
	clock_t epochBegin = clock();

	// int epochNumber = iterationNumber / sampleNumber;

	// for( unsigned int it = 0; it < 10; it++ ){
	for( unsigned int it = 0; it < iterationNumber; it++ ){
		int cur_id = it%sampleNumber;
		int index = cur_id;
		if( cur_id == 0)
			Initialize_A( A, A_Copy, featureDim );

		UpdateFeature( Wd, sample[index], residuals, feature[index], nonZeroIndex[index], lambda, layers, featureDim, sampleDim, NonNegative, p[index], sigma);
		Update_A( A, A_Copy, feature[index], nonZeroIndex[index] );
		UpdateWd( Wd, residuals, feature[index], A, nonZeroIndex[index], sampleDim, NonNegative, p[index] );
		NormalizeWd( Wd, nonZeroIndex[index], sampleDim );
		UpdateP( Wd, residuals, sampleDim, p, index, sigma);

		// for(int i = 0; i < 10; i++){
		// 	std::cout << p[i] << std::endl;
		// }
		
		if( it%sampleNumber==sampleNumber-1 ){
					std::cout<<it/sampleNumber + 1<<" epochs finished"<<std::endl;
					clock_t epochTime = clock();
					std::cout<<"epochs time: " << (double)(epochTime - epochBegin)/CLOCKS_PER_SEC <<std::endl;
					epochBegin = epochTime;
			// calculateError(Wd, sample, feature, lambda, sampleNumber, sampleDim, featureDim);
		}
	}

	clock_t EndTime = clock();
	ComputionalTime = (double)(EndTime-BeginTime)/CLOCKS_PER_SEC;
   	std::cout<<"Finish decoding process:"<<std::endl;
	std::cout<<"Train Decode Time is "<<ComputionalTime<<" seconds."<<std::endl;
	calculateError( Wd, sample, feature, lambda, sampleNumber, sampleDim, featureDim );
	free(A_Copy);
	free(A);
	free(residuals);
	delete [] nonZeroIndex;
}

void trainDecoderRandom( double **Wd, double **feature, double **sample, double lambda, int layers, int featureDim, int sampleNumber, int sampleDim, int iterationNumber, bool NonNegative, double sigma, int patchSize ){
	
	double *residuals = (double*)malloc(sampleDim*sizeof(double));
	double *A = Initialize_A( featureDim );
	double *A_Copy = Initialize_A_Copy( featureDim );
	std::vector<int> *nonZeroIndex = NonZeroIndexInitialization( sampleNumber );
	double *p = (double*)malloc(sampleNumber * sizeof(double));

	for (unsigned int i = 0; i < sampleNumber; i++)
	{
		p[i] = 0.0;
		for (unsigned int j = 0; j < sampleDim; j++)
		{
			p[i] += sample[i][j] * sample[i][j];
		}
		p[i] = exp(-p[i] / sigma / sigma);
	}

	srand((unsigned)time(0));
	myseed = (unsigned int) RAND_MAX * rand();

	std::cout<<"Train decoder"<<std::endl;
	double ComputionalTime = 0;
	clock_t BeginTime = clock();
	clock_t epochBegin = clock();

	int epochNumber = iterationNumber / sampleNumber;

	int* rIndex = getRandomIndex(sampleNumber/patchSize);

	for( unsigned int epoch = 0; epoch < epochNumber; epoch++){
		Initialize_A( A, A_Copy, featureDim );
		for( unsigned int patch = 0; patch < sampleNumber/patchSize; patch++){
			int cur_patch = rIndex[patch];
			for( unsigned int i = 0; i < patchSize; i++){
				int index = cur_patch * patchSize + i;
				UpdateFeature( Wd, sample[index], residuals, feature[index], nonZeroIndex[index], lambda, layers, featureDim, sampleDim, NonNegative, p[index], sigma);
				Update_A( A, A_Copy, feature[index], nonZeroIndex[index] );
				UpdateWd( Wd, residuals, feature[index], A, nonZeroIndex[index], sampleDim, NonNegative, p[index] );
				NormalizeWd( Wd, nonZeroIndex[index], sampleDim );
				UpdateP( Wd, residuals, sampleDim, p, index, sigma);
			}
		}
		std::cout<< epoch + 1<<" epochs finished"<<std::endl;
		clock_t epochTime = clock();
		std::cout<<"epochs time: " << (double)(epochTime - epochBegin)/CLOCKS_PER_SEC <<std::endl;
		epochBegin = epochTime;
	}
	
	clock_t EndTime = clock();
	ComputionalTime = (double)(EndTime-BeginTime)/CLOCKS_PER_SEC;
   	std::cout<<"Finish decoding process:"<<std::endl;
	std::cout<<"Train Decode Time is "<<ComputionalTime<<" seconds."<<std::endl;
	calculateError( Wd, sample, feature, lambda, sampleNumber, sampleDim, featureDim );
	free(A_Copy);
	free(A);
	free(residuals);
	delete [] nonZeroIndex;
}




}
#endif /* Sparse Coordinate Coding */