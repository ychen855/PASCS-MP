# Patch Analysis-based Surface Correntropy-induced Sparse Coding and Max-Pooling (PASCS-MP)

This is the geometric feature extraction pipeline for the paper: Chen, Y., Su, Y., Wu, J., Chen, K., Atri, A., Caselli, R.J., Reiman, E.M., Wang, Y. and Alzheimer’s Disease Neuroimaging Initiative, 2023. Combining Blood-Based Biomarkers and Structural MRI Measurements to Distinguish Persons With and Without Significant Amyloid Plaques. bioRxiv, pp.2023-10.

Authors:

	Yanxi Chen, email: ychen855@asu.edu
 	Jianfeng Wu, email: Jianfeng.Wu@asu.edu

If you find this work useful, please cite:
1. Chen, Y., Su, Y., Wu, J., Chen, K., Atri, A., Caselli, R.J., Reiman, E.M., Wang, Y. and Alzheimer’s Disease Neuroimaging Initiative, 2023. Combining Blood-Based Biomarkers and Structural MRI Measurements to Distinguish Persons With and Without Significant Amyloid Plaques. bioRxiv, pp.2023-10.
2. Wu, J., Dong, Q., Gui, J., Zhang, J., Su, Y., Chen, K., Thompson, P.M., Caselli, R.J., Reiman, E.M., Ye, J. and Wang, Y., 2021. Predicting brain amyloid using multivariate morphometry statistics, sparse coding, and Correntropy: Validation in 1,101 individuals from the ADNI and OASIS databases. Frontiers in Neuroscience, 15, p.669595.

## Step 1: Hippocampus registration, segmentation, surface reconstruction and parameterization
## Step 2: Extracting MMS features

Input: Nifti images

Output: Hippocampus surface mesh with MMS features (RD and mTBM)

Steps 1 and 2 can be done by our MTSMS pipeline: https://gsl.lab.asu.edu/mtsms/.

## Step 3: Select patches on the hippocampal surface mesh

This step is to be run by matlab.
Usage: in run_select_patch.m, set the dataset name and folders containg JFeature files (assuming positive and negative in two folders). Then run run_select_patch.m using matlab.

## Step 4: Correntropy-based sparse coding

This step is implemented by C++ and compiled Linux 64-bit binary is available. Source code is in src/.
Usage: ./run [INPUT] [OUTPUT] [INITIAL_DICT] [DICT] [LAMBDA] [SIGMA] [FEAT_DIM]
Usage: ./run_correntropy MMS_patches.txt MMS_sparse.txt MMS_initialdict.txt MMS_dict.txt 2.2 3.6 2000 400

Usage: ./MaxPooling [FEAT_DIM] [PATCH_SIZE] MMS_sparse.txt MMS_features.txt

## Step 5: Max-pooling

You may also cite the previous studies:

1. Patch Analysis-based Surface Sparse-coding and Max-Pooling (PASS-MP): 

2. PASS: 

3. Stochastic Coordinate Coding: 


