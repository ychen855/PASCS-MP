input=/mnt/d/Projects/plasma/data/patches/MMS_patches_198_np_252.txt
outdir=/mnt/d/Projects/plasma/data/198_np/mms/random_252
patchsize=252
lambda=0.2
sigma=4.0
feat_dim=1800

./run_random ${input} ${outdir}/MMS_sparse_${feat_dim}.txt ${outdir}/MMS_initdict_${feat_dim}.txt ${outdir}/MMS_dict_${feat_dim}.txt ${lambda} ${sigma} ${feat_dim}
python maxpooling.py --input ${outdir}/MMS_sparse_1800.txt --output ${outdir}/MMS_features_1800.txt --dim ${patchsize}
# ./MaxPooling ${feat_dim} 252 ${outdir}/MMS_sparse_${feat_dim}.txt ${outdir}/MMS_features_${feat_dim}.txt
