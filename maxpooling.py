import numpy as np
import skimage.measure
import argparse

def maxpooling(f, dst, size):
    mtx = np.loadtxt(f)
    res = skimage.measure.block_reduce(mtx, (1, size), np.max)
    np.savetxt(dst, res, fmt='%.15f')

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', dest='input', type=str)
    parser.add_argument('--output', dest='output', type=str)
    parser.add_argument('--dim', dest='dim', type=int)
    args = parser.parse_args()

    maxpooling(args.input, args.output, args.dim)