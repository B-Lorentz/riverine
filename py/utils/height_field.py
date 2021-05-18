import numpy as np

def cors(N):
    cor = np.linspace(0,N, N)
    x, y = np.meshgrid(cor, cor)
    return x, y, cor
def random_hf(N, K, smin, smax):
    ins = N//8
    x, y, _ = cors(N)
    xs = np.random.uniform(ins, N-ins, (K,))
    ys = np.random.uniform(ins, N-ins, (K,))
    smin, smax = N*smin, N*smax
    sx = np.random.uniform(smin, smax , (K,))
    sy= np.random.uniform(smin, smax, (K,))
    fs = np.random.uniform(0, 10, (K,))
    r = np.exp( -((x[:,:,None] - xs)/sx)**2 -((y[:,:,None] - ys)/sy)**2 )
    r =  (r*fs).sum(-1)
    return r
def sine_hf(N, L, A):
    x, y, cor = cors(N)
    mean = N/2*A*np.cos(np.pi*2*cor/L) + N/2
    r = -np.cos(2*np.pi*(mean[:,None] - x)/N)+1
    return r

def abs_hf(N, depth):
    x, y, _ = cors(N)
    return np.abs((x-N/2)/N)

def tilt_hf(N, xtilt, ytilt):
    x, y, _ = cors(N)
    return x/N*xtilt + y/N*ytilt
def basin_hf(N):
  x, y, _ = cors(N)
  return np.maximum(np.abs((x-N/2)/N), np.abs((y-N/2)/N))
def bumpy_hf(N):
    return np.random.randn(N, N )
