# 爬取全国城市名称 https://www.aqistudy.cn/historydata/
import requests
from lxml import html
etree = html.etree

if __name__ == "__main__":
    # UA伪装
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 爬取页面源码数据
    url = 'https://www.aqistudy.cn/historydata/'
    page_text = requests.get(url=url, headers=headers).text
    tree = etree.HTML(page_text)

    # 解析热门城市名称
    hot_list = tree.xpath('/html/body/div[@class="container"]//div[@class="hot"]//ul[@class="unstyled"]/li')
    print("热门城市：")
    for li in hot_list:
        cityName_hot = li.xpath('./a/text()')[0]
        print(cityName_hot, end='\t')
    print('\n')

    # 解析全部城市名称
    all_list = tree.xpath('/html/body/div[@class="container"]//div[@class="all"]/div[@class="bottom"]/ul')
    print("全部城市：")
    for ul in all_list:
        group = ul.xpath('./div[1]/b/text()')[0]
        print(group)
        cityName_all_list = ul.xpath('./div[2]/li')
        for li in cityName_all_list:
            cityName_all = li.xpath('./a/text()')[0]
            print(cityName_all, end=' ')
        print()

    # 完成
    print('===========================================')
    print('over!!!')