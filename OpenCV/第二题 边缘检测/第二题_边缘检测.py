import cv2
import numpy

img = cv2.imread("lab_logo.jpg", 0)

# 阈值处理
retval, img = cv2.threshold(img, 80, 255, cv2.THRESH_BINARY)
cv2.imwrite("result_1.png", img)

# 轮廓提取
contours, hierarchy = cv2.findContours(img, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
dst = numpy.zeros(img.shape, numpy.uint8)
dst = cv2.drawContours(dst, contours, -1, 255)

b = numpy.zeros(img.shape, numpy.uint8)
g = numpy.zeros(img.shape, numpy.uint8)
result_2 = cv2.merge([b, g, dst])
cv2.imwrite("result_2.png", result_2)


