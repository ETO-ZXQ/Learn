import cv2
import numpy

img1 = cv2.imread("road1.jpg")
img2 = cv2.imread("road2.jpg")

# ------------img1------------
imgg1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)

# 阈值处理
retval, imgg1 = cv2.threshold(imgg1, 140, 255, cv2.THRESH_BINARY)
# Canny
edges = cv2.Canny(imgg1, 216, 168)
# 霍夫变换
lines = cv2.HoughLinesP(edges, 1, numpy.pi/180, 68, minLineLength=216, maxLineGap=32)
for line in lines:
    x1, y1, x2, y2 = line[0]
    img1 = cv2.line(img1, (x1,y1), (x2,y2), (0,0,255), 2, cv2.LINE_AA) # 绘制

cv2.imshow("img1", img1)
cv2.imwrite("result1.png", img1)


# ------------img2------------
imgg2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
mask = numpy.zeros(imgg2.shape, numpy.uint8)
# 阈值处理
retval, imgg2 = cv2.threshold(imgg2, 128, 255, cv2.THRESH_BINARY)

# 闭 开
K = numpy.ones((5,5), numpy.uint8)
imgg2 = cv2.morphologyEx(imgg2, cv2.MORPH_CLOSE, K) # 膨胀 腐蚀
imgg2 = cv2.morphologyEx(imgg2, cv2.MORPH_OPEN, K)  # 腐蚀 膨胀

# 霍夫变换
lines2 = cv2.HoughLinesP(imgg2, 1, numpy.pi/180, 256, minLineLength=316, maxLineGap=4)
for line in lines2:
    x1, y1, x2, y2 = line[0]
    mask = cv2.line(mask, (x1,y1), (x2,y2), 255, 10, cv2.LINE_AA) # 绘制

# 膨胀
K = numpy.ones((45,45), numpy.uint8)
mask = cv2.dilate(mask, K)

mask_dst = cv2.bitwise_and(mask, imgg2)

b, g, r = cv2.split(img2)

retval, mask_dst_f = cv2.threshold(mask_dst, 127, 255, cv2.THRESH_BINARY_INV)
b = cv2.bitwise_and(b, mask_dst_f)
g = cv2.bitwise_and(g, mask_dst_f)
r = cv2.bitwise_or(r, mask_dst)

bgr = cv2.merge([b,g,r])

cv2.imshow("bgr", bgr)
cv2.imwrite("result2.png", bgr)


cv2.waitKey(0)
cv2.destroyAllWindows()
