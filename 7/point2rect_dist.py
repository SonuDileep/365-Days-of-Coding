import math
import numpy as np
from numpy.linalg import norm

#Euclidean Distance formulae
def dist(p1,p2):
    distance = math.sqrt(((p1[0]-p2[0])**2)+((p1[1]-p2[1])**2))
    return distance
#Finds the perpendicular distance from one point to line    
def short_dist(p1,p2,p3): #perpendicular distance
    p1=np.array(p1)
    p2=np.array(p2)
    p3=np.array(p3)
    d=np.cross(p2-p1,p3-p1)/np.linalg.norm(p2-p1) 
    return d
    
#Return the closest distance from point to rectangle    
def find_distance(rect,point):
    p1 = [rect[0],rect[3]]
    p2 = [rect[2],rect[3]] 
    p3 = [rect[2],rect[1]]
    p4 = [rect[0],rect[1]]
    if point[1]>=rect[1]:
        if point[0]<rect[0]: 
            return dist(point, p4)
        if point[0]>rect[2]:
            return dist(point,p3)
        else:
            return short_dist(p3,p4,point)
    if point[1]<=rect[3]:
        if point[0]<rect[0]: 
            return dist(point, p1)
        if point[0]>rect[2]:
            return dist(point,p2) 
        else:
            return short_dist(p1,p2,point)
    elif point[0]>=rect[2]:
            return short_dist(p2,p3,point)  
    elif point[0]<=rect[0]:
            return short_dist(p1,p4,point)
          

#distance = find_distance([-11677631.933604991, 4865327.1966890935, -11677525.770121671, 4865247.85523969],[-11677525.770121671, 4865247.85523969])
distance = find_distance([0,3,2,0],[4,-2])
print(distance)

    