import grahamscan
import jarvismarch
import generator
import copy
import numpy as np

def main():
    P = generator.P
    C = np.array(copy.deepcopy(P))
    v1 = grahamscan.main(P=P)
    v2 = jarvismarch.main(P=C)

    with open("log.csv", "a") as log:
        log.write("\n")
        log.write(str(v1))
        log.write(", ")
        log.write(str(v2))
    print(str(v1),str(v2))

if __name__ == "__main__":
    main()
