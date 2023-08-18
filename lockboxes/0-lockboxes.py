#!/usr/bin/python3
"""testing boxes all by one to see if they can be unlocked"""


def canUnlockAll(boxes):
    queue = [0]
    unlocked_boxes = set([0])
    while queue:
        current_box = queue.pop(0)
        for key in boxes[current_box]:
            if key not in unlocked_boxes and key < len(boxes):
                unlocked_boxes.add(key)
                queue.append(key)

    return len(unlocked_boxes) == len(boxes)
