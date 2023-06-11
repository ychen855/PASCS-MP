/*
	Stochastic Coordinate Coding  version 1.0
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
	int patchSize = 252;
	double lambda = atof(argv[5]); //0.13;
	double sigma = atof(argv[6]); // 2
	bool DictionaryGenerationState = true;
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
		Wd = dpl::readDictionary( initializedDictionaryName, featureDim, sampleDim );

	dpl::DictionaryNormalization( featureDim, sampleDim, Wd );

	if( DictionaryGenerationState )
		dpl::saveDictionary( featureDim, sampleDim, Wd, initializedDictionaryName );

 	feature = dpl::FeatureInitialization( featureDim, sampleNumber);
	std::cout<<"Start training "<<std::endl;
	dpl::trainDecoderRandom( Wd, feature, sample, lambda, layers, featureDim, sampleNumber,  sampleDim, iterationNumber, NonNegative, sigma, patchSize);
	std::cout<<"Finish training "<<std::endl;

	dpl::saveDictionary( featureDim, sampleDim, Wd, savedDictionaryName );
	dpl::saveFeature( feature, FeatureFileName, featureDim, sampleNumber );

	dpl::clearSample( sampleNumber, sample );
	dpl::clearFeature( sampleNumber, feature );
	dpl::clearDictionary( featureDim, Wd );

	return 0;
}
