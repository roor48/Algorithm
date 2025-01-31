from sys import stdin

def FEN2board(fen):
    board = [['' for _ in range(8)] for _ in range(8)]
    for col_idx, col in enumerate(fen):
        row_idx = 0
        for ele in col:
            if ele.isdecimal():
                row_idx += int(ele)
                continue
            board[col_idx][row_idx] = ele
            row_idx += 1    

    return board

# y, x 순
piece_dir = {
    'p': [[1, 1], [1, -1]],
    'P': [[-1, -1], [1, -1]],
    'N': [[2, 1, -1, -2, -2, -1, 1, 2], [1, 2, 2, 1, -1, -2, -2, -1]],
    'B': [[1, -1, -1, 1], [1, 1, -1, -1]],
    'R': [[1, 0, -1, 0], [0, 1, 0, -1]],
    'Q': [[1, 1, 0, -1, -1, -1, 0, 1], [0, 1, 1, 1, 0, -1, -1, -1]],
    'K': [[1, 1, 0, -1, -1, -1, 0, 1], [0, 1, 1, 1, 0, -1, -1, -1]]
}

def counter(board):
    atk_board = [[False] * 8 for _ in range(8)]

    for i in range(8):
        for j in range(8):
            if not board[i][j]:
                continue
            
            if board[i][j] not in 'pP':
                board[i][j] = board[i][j].upper()

            atk_board[i][j] = True
            dir = piece_dir[board[i][j]]
            if board[i][j] in 'pPNK': # 한번밖에 못 움직임
                for dir_idx in range(len(dir[0])):
                    next_y = i + dir[0][dir_idx]
                    next_x = j + dir[1][dir_idx]

                    if next_x < 0 or next_x >= 8 or next_y < 0 or next_y >= 8:
                        continue

                    atk_board[next_y][next_x] = True
            else:
                for dir_y, dir_x in zip(dir[0], dir[1]):
                    next_y = i + dir_y
                    next_x = j + dir_x
                    while True:
                        if next_x < 0 or next_x >= 8 or next_y < 0 or next_y >= 8 or board[next_y][next_x]:
                            break

                        atk_board[next_y][next_x] = True
                        next_y += dir_y
                        next_x += dir_x

    return sum(row.count(False) for row in atk_board)

while True:
    fen = stdin.readline().strip().split('/')

    if not fen[0]:
        break
    
    print(counter(FEN2board(fen)))
    