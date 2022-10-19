import cv2
import numpy

img=cv2.imread("beauty.png")
dst = cv2.flip(img, -1)
cv2.imshow("dst1.png", dst)
r = cv2.imwrite("dst1.png", dst)

if r==True:
    print("图像保存成功！")

cv2.waitKey(0)
cv2.destroyAllWindows()