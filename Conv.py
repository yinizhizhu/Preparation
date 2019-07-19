import numpy as np

input_data=[
              [[1,0,1,2,1],
               [0,2,1,0,1],
               [1,1,0,2,0],
               [2,2,1,1,0],
               [2,0,1,2,0]],
 
               [[2,0,2,1,1],
                [0,1,0,0,2],
                [1,0,0,2,1],
                [1,1,2,1,0],
                [1,0,1,1,1]] 
            ]

weights_data=[ 
               [[ 1, 0, 1],
                [-1, 1, 0],
                [ 0,-1, 0]],
               [[-1, 0, 1],
                [ 0, 0, 1],
                [ 1, 1, 1]] 
            ]

#print(input_data)

#print(weights_data)
 

def conv(fm, kernel):
    [h,w] = fm.shape
    [k, _] = kernel.shape
    r = k>>1
    padding_fm = np.zeros([h+2*r, w+2*r], np.float32)
    
    print('Initial:')
    print(padding_fm)

    rs = np.zeros([h, w], np.float32)
    padding_fm[r:h+r, r:w+r] = fm

    print('After assignment:')
    print(padding_fm)
    
    for i in range(r, h+r):
        for j in range(r, w+r):
            roi = padding_fm[i-r:i+r+1, j-r:j+r+1]

            print('\nROI:')
            print(roi)
            print('\n')
            print(kernel)
            print('\n')
            print(roi*kernel)
            print (np.sum(roi*kernel))

            rs[i-1][j-1] = np.sum(roi*kernel)
    return rs

def lee_conv2d(input, weights):
    [c,h,w] = input.shape
    [_,k,_] = weights.shape
    outputs = np.zeros([h, w], np.float32)

    for i in range(c):
        f_map = input[i]
        w = weights[i]
        rs = conv(f_map, w)
        outputs = outputs+rs
    return outputs

input = np.asarray(input_data, np.float32)
weights = np.asarray(weights_data, np.float32)
rs = lee_conv2d(input, weights)
print(rs)

#[[ 2.  0.  2.  4.  0.]
# [ 1.  4.  4.  3.  5.]
# [ 4.  3.  5.  9. -1.]
# [ 3.  4.  6.  2.  1.]
# [ 5.  3.  5.  1. -2.]]