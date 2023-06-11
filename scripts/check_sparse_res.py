import numpy as np

mtx = np.loadtxt('/mnt/d/Projects/plasma/data/198_np/mms/252/MMS_initdict_1800.txt')
mtx_dict = np.loadtxt('/mnt/d/Projects/plasma/data/198_np/mms/252/MMS_dict_1800.txt')

print(np.max(mtx))
print(np.max(mtx_dict))
# res = np.zeros(mtx.shape[0], dtype=int)
# for i in range(mtx.shape[0]):
#     res[i] = np.count_nonzero(mtx[i])

# np.savetxt('/mnt/d/Projects/plasma/data/198_np/mms/720/MMS_sparse_nonzero.txt', res, fmt='%d')