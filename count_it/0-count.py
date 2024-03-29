#!/usr/bin/python3
"""
0-count.py
"""
import requests
import sys


def count_words(subreddit, word_list, after=None, word_count=None):
    if word_count is None:
        word_count = {word.lower(): 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    params = {'limit': 100, 'after': after}
    headers = {'User-Agent': 'wordcount-bot'}

    response = requests.get(url, headers=headers, params=params)

    if response.status_code != 200:
        return

    data = response.json()

    for post in data['data']['children']:
        title = post['data']['title'].lower()
        for word in word_count:
            word_count[word] += title.split().count(word)

    next_page = data['data']['after']
    if next_page:
        count_words(subreddit, word_list, after=next_page,
                    word_count=word_count)
    else:
        def sort_key(item):
            return -item[1], item[0]

        sorted_word_counts = sorted(word_count.items(), key=sort_key)

        for word, count in sorted_word_counts:
            if count > 0:
                print(f"{word}: {count}")


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(
            sys.argv[0]))
    else:
        count_words(sys.argv[1], sys.argv[2].split())
