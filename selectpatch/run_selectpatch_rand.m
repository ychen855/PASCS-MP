clc
clear

addpath /home/jianfen6/PASCS/selectpatch
folder1 = '/scratch/jianfen6/18vs20/MMS/Conv';
folder2 = '/scratch/jianfen6/18vs20/MMS/NonConv';
outdir = '/scratch/jianfen6/18vs20/MMS/sparse/cscc_random/patch/';


[n1, leftMMS1] = get_MMS([folder1, '/l/']);
[n1, rightMMS1] = get_MMS([folder1, '/r/']);

[n2, leftMMS2] = get_MMS([folder2, '/l/']);
[n2, rightMMS2] = get_MMS([folder2, '/r/']);

leftMMS = cat(4,leftMMS1,leftMMS2);
rightMMS = cat(4,rightMMS1,rightMMS2);
 
for i = 1:2
	[patchSamples, patchNum_MMS] = select_patches_random([outdir,int2str(i),'/MMS_patches.txt'], n1+n2, leftMMS,rightMMS, 4,10);

end

