# 需要安装bs4 lxml
# 爬取三国演义小说所有的章节标题和内容https://www.shicimingju.com/book/sanguoyanyi.html
# 该网站有问题，所以所爬文本错误
import requests
from bs4 import BeautifulSoup

if __name__ == "__main__":
    # UA伪装：将对应的User-Agent封装到一个字典中
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }

    # 对首页的页面数据进行爬取
    url = 'https://www.shicimingju.com/book/sanguoyanyi.html'
    response1 = requests.get(url=url, headers=headers)
    response1.encoding = 'utf-8'
    page_text = response1.text
    # 在首页中解析出章节标题和详情页url
    # 1.实例化BeautifulSoup对象，将页面源码数据加载到对象中
    soup = BeautifulSoup(page_text, 'lxml')
    # 2.解析
    li_list = soup.select('.book-mulu > ul > li')
    print(li_list)
    # 打开文件
    fp = open('./三国演义.txt', 'w', encoding='utf-8')
    # 遍历
    for li in li_list:
        title = li.a.string
        detail_url = 'https://www.shicimingju.com/' + li.a['href']
        # 对详情页发请求，解析章节内容
        response2 = requests.get(url=detail_url, headers=headers)
        response2.encoding = 'utf-8'
        detail_page_text = response2.text
        # 解析详情页内容
        detail_soup = BeautifulSoup(detail_page_text, 'lxml')
        div_tag = detail_soup.find('div', class_='chapter_content')
        # 获取内容
        content = div_tag.text

        fp.write(title+'：'+content+'\n')
        print(title, '爬取成功！！！')

    # 完成
    print('===========================================')
    print('over!!!')
