# 爬取彼岸桌面网站的壁纸（美女分区）

import requests
import re
import os

if __name__ == "__main__":
    # UA伪装：将对应的User-Agent封装到一个字典中
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }

    # 创建一个文件夹，保存所有图片
    if not os.path.exists('./彼岸桌面壁纸（美女分区）'):
        os.mkdir('./彼岸桌面壁纸（美女分区）')

    # 爬取主体
    for page in range(1, 6): # 限制爬取页数（网站共63页）
        # 构造page url
        if page == 1:
            url = 'http://www.netbian.com/meinv/index.htm'
        else:
            url = 'http://www.netbian.com/meinv/index_' + str(page) + '.htm'

        # 使用通用爬虫对url对应的一整张页面进行爬取
        response = requests.get(url=url, headers=headers)
        response.encoding = "gbk"
        page_txt = response.text

        # 利用正则表达式，获取每一张壁纸详情的网址
        ex = '<li><a href="(.+?)".*?>.*?</a></li>'
        srcDetail_url_list = re.findall(ex, page_txt, re.S)
        srcDetail_url_list = srcDetail_url_list[3::1]              # 前三个均删掉
        # 进入每一张壁纸详情进行下载
        for srcDetail_url in srcDetail_url_list :
            srcDetail_url = 'http://www.netbian.com' + srcDetail_url  # 网址拼接一下
            # 解析一下，拿最终url
            response = requests.get(url=srcDetail_url, headers=headers)
            response.encoding = "gbk"
            page_txt = response.text

            ex2 = '<div class="pic"><p><a href=.*?><img src="(.*?)" alt=".*?" title="(.*?)"></a></p>'
            srcDetail = re.findall(ex2, page_txt, re.S)

            src_url =  srcDetail[0][0]
            src_name = srcDetail[0][1]

            # 爬取图片存储
            img_data = requests.get(url=src_url, headers=headers).content # 请求图片二进制数据
            imgPath = './彼岸桌面壁纸（美女分区）/' + src_name + '.jpg' # 图片存储路径
            with open(imgPath, 'wb') as fp:
                fp.write(img_data)
                print(src_name, '下载成功！！！')

    # 完成
    print('===========================================')
    print('over!!!')
