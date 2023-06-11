import numpy as np

mtx = np.loadtxt('/mnt/d/Projects/plasma/data/198_np/mms/720/MMS_features_1800.txt')
print(mtx.shape)
for j in range(mtx.shape[0]):
    print(np.count_nonzero(mtx[j]))
# mtx_dict = np.loadtxt('/mnt/d/Projects/plasma/data/198_np/mms/252/MMS_dict_1800.txt')
