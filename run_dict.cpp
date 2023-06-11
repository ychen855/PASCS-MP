/*
	Stochastic Coordinate Coding  version 1.0
	Learn representation from given dictionary
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstring>
#include "DictionaryGeneration.h"
#include "SampleNormalization.h"
#include "LR.h"
#include "SCC.h"

int main(int argc, char* argv[])
{
	/*
	double **Wd;
	double **feature;
	double **sample;
	char SampleFileName[100] = "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\sparse\\Input.txt";
	char FeatureFileName[100] = "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\sparse\\sparse.txt";
	//char initializedDictionaryName[100] = "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\Sparsecoding\\test\\RandomPatchDictionary.txt";
	char savedDictionaryName[100] = "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\sparse\\Dictionary.txt";
	int featureDim = 1000;
	int sampleDim = 128;
	int layers = 5;
	int epochNumber = 10;
	double lambda = 0.13;
	bool NonNegative = false;
	int sampleNumber = dpl::getSampleNumber(SampleFileName);
	std::cout << sampleNumber << std::endl;

	Wd = dpl::readDictionary(savedDictionaryName, featureDim, sampleDim);
	std::cout << Wd[0][0] << " " << Wd[sampleDim - 1][featureDim - 1] << std::endl;

	feature = dpl::Readsparse(FeatureFileName, sampleNumber, featureDim);
	std::cout << feature[0][0] << " " << feature[sampleNumber - 1][featureDim - 1] << std::endl;
	sample = dpl::ReadSample(SampleFileName, sampleNumber, sampleDim);


	dpl::SampleNormalization(sample, sampleNumber, sampleDim, NonNegative);

	dpl::calculateError(Wd, sample, feature, 0.13, sampleNumber, sampleDim, featureDim);
	*/
/******************************************************************************************************************/

	char SampleFileName[100];
	strcpy(SampleFileName, argv[1]);//"D:\\Dropbox (ASU)\\Project\\MICCAI2019\\Sparsecoding\\test\\Input.txt";
	char FeatureFileName[100];// "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\Sparsecoding\\test\\sparse.txt";
	strcpy(FeatureFileName, argv[2]);
	char initializedDictionaryName[100]; // "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\Sparsecoding\\test\\RandomPatchDictionary.txt";
	strcpy(initializedDictionaryName, argv[3]);
	char savedDictionaryName[100]; // "D:\\Dropbox (ASU)\\Project\\MICCAI2019\\Sparsecoding\\dict.txt";
	strcpy(savedDictionaryName, argv[4]);
	int featureDim = atoi(argv[7]); //2000;
	int sampleDim = 400;
	int layers = 5;
	int epochNumber = 10;
	double lambda = atof(argv[5]); //0.13;
	double sigma = atof(argv[6]); // 2
	bool DictionaryGenerationState = false;
	bool NonNegative = false;

	double **Wd;
	double **feature;
	double **sample;
	int sampleNumber = dpl::getSampleNumber( SampleFileName );
	int iterationNumber = sampleNumber*epochNumber;

	std::cout<<"The number of samples is "<<sampleNumber<<std::endl;
	std::cout<<"The dimension of each sample is "<<sampleDim<<std::endl;
	std::cout<<"The dimension of each sparse code is "<<featureDim<<std::endl;
	std::cout<<"Total number of iterations is "<<iterationNumber<<std::endl;
	std::cout<<"lambda is "<<lambda<<std::endl;
	std::cout<<"sigma is " <<sigma << std::endl;
	std::cout<<"Begin to read sample."<<std::endl;
	sample = dpl::ReadSample( SampleFileName, sampleNumber, sampleDim );
	dpl::SampleNormalization( sample, sampleNumber, sampleDim, NonNegative );

	std::cout<<"Begin to initialize dictionary."<<std::endl;

	if( DictionaryGenerationState ) {
        Wd = dpl::GenerateRandomPatchDictionary(featureDim, sampleDim, sampleNumber, sample);
    }
	else
	{
		Wd = dpl::readDictionary( initializedDictionaryName, featureDim, sampleDim );
		std::cout << "Finish read dictionary " << initializedDictionaryName << std::endl;
	}
	// dpl::DictionaryNormalization( featureDim, sampleDim, Wd );

	if( DictionaryGenerationState )
		dpl::saveDictionary( featureDim, sampleDim, Wd, initializedDictionaryName );

 	feature = dpl::FeatureInitialization( featureDim, sampleNumber);
	std::cout<<"Start training "<<std::endl;

	if( DictionaryGenerationState ) {
		dpl::trainDecoder( Wd, feature, sample, lambda, layers, featureDim, sampleNumber,  sampleDim, iterationNumber, NonNegative, sigma);
	}
	else
	{
		dpl::trainDecoderFixedDict( Wd, feature, sample, lambda, layers, featureDim, sampleNumber,  sampleDim, iterationNumber, NonNegative, sigma);
	}
	
	std::cout<<"Finish training "<<std::endl;

	// dpl::saveDictionary( featureDim, sampleDim, Wd, savedDictionaryName );
	dpl::saveFeature( feature, FeatureFileName, featureDim, sampleNumber );

	dpl::clearSample( sampleNumber, sample );
	dpl::clearFeature( sampleNumber, feature );
	dpl::clearDictionary( featureDim, Wd );

	return 0;
}
