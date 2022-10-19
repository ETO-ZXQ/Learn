import requests
from lxml import html
etree = html.etree

# 爬取58同城二手房的房源信息
if __name__ == "__main__":
    # UA伪装
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 爬取页面源码数据
    url = 'https://luzhou.58.com/ershoufang/'
    page_text = requests.get(url=url, headers=headers).text

    # 数据解析
    tree = etree.HTML(page_text)
    info_list = tree.xpath('//section[@class="list"]/div//div[@class="property-content-title"]/h3/text()')

    for info in info_list:
        print(info)

    # 完成
    print('===========================================')
    print('over!!!')
