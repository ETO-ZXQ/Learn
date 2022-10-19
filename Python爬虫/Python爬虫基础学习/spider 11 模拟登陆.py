# 模拟登陆健康打卡系统
import requests
from lxml import html
etree = html.etree

if __name__ == "__main__":
    # UA伪装
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 登陆数据
    login_url = 'https://jksb.v.zzu.edu.cn/vls6sss/zzujksb.dll/login'
    data = {
        'uid': '202102081035',
        'upw': 'ZBH1969zxq@',
        'smbtn': '进入健康状况上报平台',
        'hh28': '754'
    }

    # 创建一个session对象
    session = requests.Session()
    # 使用session对象进行模拟登陆
    login_page_text = session.post(url=login_url, data=data, headers=headers).text


    # with open('login.html', 'w', encoding='utf-8') as fp:
    #     fp.write(login_page_text)
    #
    # print('保存成功！！！')
