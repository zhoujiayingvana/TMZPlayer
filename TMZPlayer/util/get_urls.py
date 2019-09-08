import requests
import urllib
from lxml import etree
import re


def parse_2_string(in_str: str):
    pattern_str = r'"(\d+)"'
    ans = re.findall(pattern_str, in_str)[0]
    return ans


def get_ids_by_word(word):
    '''根据word查询从而获取所要的id.'''
    tempUrl = 'https://music.taihe.com/search?'
    key = {'key': word}
    key = urllib.parse.urlencode(key)
    tempUrl = tempUrl + key
    res = requests.Session().get(url=tempUrl).content.decode('utf-8')
    res_tree = etree.HTML(res)
    whats = res_tree.xpath('//span[@class="song-title"]/a/@data-songdata')
    ans_list = []
    for what in whats:
        temp = what.encode('utf-8')
        v = str(temp)
        ans_list.append(parse_2_string(v))
    return ans_list


def get_music(song_id):
    url = 'http://play.taihe.com/data/music/songlink'
    data = {'songIds': song_id, 'type': 'm4a, mp3, avi, flv, mp4'}
    res = requests.post(url, data=data)
    j = res.json()
    song_name = j.get('data').get('songList')[0].get('songName')
    song_link = j.get('data').get('songList')[0].get('songLink')
    if song_name is not None and song_link is not None:
        return song_name, song_link


def get_song_tuples(song_ids):
    ans_list = []
    for song_id in song_ids:
        temp = get_music(song_id)
        if temp is not None:
            ans_list.append(temp)
    return ans_list


def insert_2_db(db_path, song_tuple):
    import sqlite3
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    sql_string = (
        'INSERT INTO songs (song_name, song_path) VALUES ("%s", "%s")'
        % (song_tuple[0], song_tuple[1])
    )
    cursor.execute(sql_string)
    cursor.close()
    conn.commit()
    conn.close()


if __name__ == '__main__':
    import sys
    ids = get_ids_by_word(sys.argv[1])  # 第一个参数是歌名
    song_tuples = get_song_tuples(ids)
    db_path = sys.argv[2]  # 第二个参数是地址
    for song_tuple in song_tuples:
        insert_2_db(db_path, song_tuple)
