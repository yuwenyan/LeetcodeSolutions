/* 
 * Hard
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int temp;
    int *ptemp;
    if (nums1Size<nums2Size) {
        temp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = temp;
        ptemp = nums1;
        nums1 = nums2;
        nums2 = ptemp;
    }
    if (nums2Size == 0) {
        if (nums1Size%2) {
            return (double) *(nums1+ nums1Size/2);
        } else {
            return (double) (*(nums1+ nums1Size/2)+*(nums1+ nums1Size/2-1))/2.0;
        }
    }
    
    if (nums2Size == 1) {
        if (nums1Size == 1) {
            return (double) (*nums1+*nums2)/2.0;
        }
        if (nums1Size%2) {
            if ( *nums2 > *(nums1+nums1Size/2+1) ) {
                return (double) (*(nums1+nums1Size/2)+*(nums1+nums1Size/2+1))/2.0;
            } else if ( *nums2 < *(nums1+nums1Size/2-1) ) {
                return (double) (*(nums1+nums1Size/2)+*(nums1+nums1Size/2-1))/2.0;
            } else {
                return (double) (*nums2+*(nums1+nums1Size/2))/2.0;
            }
        } else {
            if ( *nums2 > *(nums1+nums1Size/2) ) {
                return (double) *(nums1+nums1Size/2);
            } else if ( *nums2 < *(nums1+nums1Size/2-1) ) {
                return (double) *(nums1+nums1Size/2-1);
            } else {
                return (double) *nums2;
            }
        }
    }
    
    if (nums1Size==nums2Size) {
        if ( *nums1>=*(nums2+nums2Size-1) ) {
            return (double) ( *nums1+*(nums2+nums2Size-1) )/2.0;
        }
        if ( *nums2>=*(nums1+nums1Size-1) ) {
            return (double) ( *nums2+*(nums1+nums1Size-1) )/2.0;
        } 
    }
    
    int f1 = 0, f2 =0;
    int l1 = nums1Size-1, l2 = nums2Size-1;
    int shift = 0;
    
    if ( (nums1Size+nums2Size)%2 ) {
        int m1 = (f1+l1)/2;
        int m2 = (f2+l2)/2;
        if (nums1Size!=nums2Size)
        {
            if ( *nums2>=*(nums1+(nums1Size+nums2Size)/2) ) {
                return (double) *(nums1+(nums1Size+nums2Size)/2);
            }
            if ( *(nums2+nums2Size-1)<=*(nums1+nums1Size-1-(nums1Size+nums2Size)/2) ) {
                return (double) ( *(nums1+nums1Size-1-(nums1Size+nums2Size)/2) );
            }
        }
        if ( *(nums1+m1)<*(nums2+m2) )  {
            f1 = m1+1;
            l2 = m2; // make the new two arries same length
            l1 = l2-f2+f1; //  l2-f2 = l1-f1
        } else {
            l1 = m1;
            f2 = m2+1;
            f1 = l1-l2+f2;
        }
        while ( (l2-f2)>1 || (l1-f1)>1 ) {
            m1 = (f1+l1+1)/2;
            m2 = (f2+l2)/2;
            if ( *(nums1+m1)<*(nums2+m2) ) {
                f1 = m1;
                l2 = m2;
            } else if ( *(nums1+m1)>*(nums2+m2) ) {
                l1 = m1;
                f2 = m2;
            } else {
                return (double) *(nums1+m1);
            }
        }
        if ( *(nums1+f1)>*(nums2+f2) ) {
            f1 = *(nums1+f1);
        } else {
            f1 = *(nums2+f2);
        }
        if ( *(nums1+l1)<*(nums2+l2) ) {
            l1 = *(nums1+l1);
        } else {
            l1 = *(nums2+l2);
        }
        if (f1<l1) {
            return (double) f1;
        } else {
            return (double) l1;
        }
    } else {
        int m1 = (f1+l1+1)/2;
        int m2 = (f2+l2)/2;
        if (nums1Size!=nums2Size)
        {
            if ( *nums2>=*(nums1+(nums1Size+nums2Size)/2) ) {
                return (double) ( *(nums1+(nums1Size+nums2Size)/2)+*(nums1+(nums1Size+nums2Size)/2-1) )/2.0;
            }
            if ( *(nums2+nums2Size-1)<=*(nums1+nums1Size-1-(nums1Size+nums2Size)/2) ) {
                return (double) ( *(nums1+nums1Size-1-(nums1Size+nums2Size)/2)+*(nums1+nums1Size-1-(nums1Size+nums2Size)/2+1) )/2.0;
            }
        }
        if ( *(nums1+m1)<*(nums2+m2) ) {
            f1 = m1;
            l2 = m2;
            l1 = l2-f2+f1;
        } else if ( *(nums1+m1)>*(nums2+m2) ) {
            l1 = m1;
            f2 = m2;
            f1 = l1-l2+f2;
        }
        while ( (l2-f2)>1 || (l1-f1)>1 ) {
            m1 = (f1+l1+1)/2;
            m2 = (f2+l2)/2;
            if ( *(nums1+m1)<*(nums2+m2) ) {
                f1 = m1;
                l2 = m2;
            } else if ( *(nums1+m1)>*(nums2+m2) ) {
                l1 = m1;
                f2 = m2;
            } else {
                return (double) *(nums1+m1);
            }
        }
        if ( *(nums1+f1)>*(nums2+f2) ) {
            f1 = *(nums1+f1);
        } else {
            f1 = *(nums2+f2);
        }
        if ( *(nums1+l1)<*(nums2+l2) ) {
            l1 = *(nums1+l1);
        } else {
            l1 = *(nums2+l2);
        }
        return (double) (f1+l1)/2.0;
    }
}