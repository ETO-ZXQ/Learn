import cv2
import numpy

img = cv2.imread("identify_code.png", 0)

# 阈值处理
retval, img = cv2.threshold(img, 168, 255, cv2.THRESH_BINARY_INV)
# 开运算
K1 = numpy.ones((5,5), numpy.uint8)
img = cv2.morphologyEx(img, cv2.MORPH_OPEN, K1)
# 闭运算
K2 = numpy.ones((2,2), numpy.uint8)
img = cv2.morphologyEx(img, cv2.MORPH_CLOSE, K2)
# 腐蚀
img = cv2.erode(img, K2)

# 滤波
img1 = cv2.GaussianBlur(img,(11,11), 0, 0)
img2 = cv2.GaussianBlur(img1,(11,11), 0, 0)

# 阈值处理
retval, dst = cv2.threshold(img2, 64, 255, cv2.THRESH_BINARY_INV)

cv2.imshow("identify_code.png", dst)
cv2.imwrite("clear_identify_code.png", dst)

cv2.waitKey(0)
cv2.destroyAllWindows()
