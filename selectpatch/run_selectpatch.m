clc
clear

addpath /scratch/ychen855/PASCS/selectpatch

dataset = '198';
neg_folder = '/scratch/ychen855/Plasma/data/198_neg/';
pos_folder = '/scratch/ychen855/Plasma/data/198_pos/';
outdir = '/scratch/ychen855/Plasma/data/patches';


[n1, leftMMS1] = get_MMS([neg_folder, '/l/']);
[n1, rightMMS1] = get_MMS([neg_folder, '/r/']);

[n2, leftMMS2] = get_MMS([pos_folder, '/l/']);
[n2, rightMMS2] = get_MMS([pos_folder, '/r/']);

leftMMS = cat(4,leftMMS1,leftMMS2);
rightMMS = cat(4,rightMMS1,rightMMS2);
 
for i = [10]
	[patchSamples, patchNum_MMS] = select_patches_new([outdir,'/MMS_patches_', dataset, '_1008.txt'], n1+n2, leftMMS,rightMMS, 4,i);
end
