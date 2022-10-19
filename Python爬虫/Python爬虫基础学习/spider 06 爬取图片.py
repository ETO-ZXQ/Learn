import requests
if __name__ == "__main__":
    # UA伪装：将对应的User-Agent封装到一个字典中
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 指定url
    url = 'https://pic2.zhimg.com/v2-379be37e0b4d372aa60046f9ce771f12_r.jpg'
    # content返回的是二进制形式的数据
    # text（字符串） content（二进制） json() （对象）

    img_data = requests.get(url=url, headers=headers).content

    with open('./小姐姐.jpg', 'wb') as fp:
        fp.write(img_data)
