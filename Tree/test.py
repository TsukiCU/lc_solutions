def is_winner(board, player):
    """检查玩家是否获胜"""
    win_states = [
        [board[0], board[1], board[2]],
        [board[3], board[4], board[5]],
        [board[6], board[7], board[8]],
        [board[0], board[3], board[6]],
        [board[1], board[4], board[7]],
        [board[2], board[5], board[8]],
        [board[0], board[4], board[8]],
        [board[2], board[4], board[6]],
    ]
    return [player, player, player] in win_states

def evaluate(board):
    """评估棋盘状态，返回评分"""
    if is_winner(board, 'X'):
        return 1
    elif is_winner(board, 'O'):
        return -1
    else:
        return 0

def minimax(board, depth, is_maximizing, alpha, beta):
    """使用Alpha-Beta剪枝的极大极小值算法"""
    score = evaluate(board)
    if score != 0 or depth == 0:
        return score

    if is_maximizing:
        max_eval = float('-inf')
        for i in range(len(board)):
            if board[i] == ' ':
                board[i] = 'X'  # 假设玩家'X'的移动
                eval = minimax(board, depth - 1, False, alpha, beta)
                board[i] = ' '
                max_eval = max(max_eval, eval)
                alpha = max(alpha, eval)
                if beta <= alpha:
                    break
        return max_eval
    else:
        min_eval = float('inf')
        for i in range(len(board)):
            if board[i] == ' ':
                board[i] = 'O'  # 假设玩家'O'的移动
                eval = minimax(board, depth - 1, True, alpha, beta)
                board[i] = ' '
                min_eval = min(min_eval, eval)
                beta = min(beta, eval)
                if beta <= alpha:
                    break
        return min_eval

def find_best_move(board, player):
    """找到最佳移动位置"""
    best_val = float('-inf') if player == 'X' else float('inf')
    best_move = -1
    for i in range(len(board)):
        if board[i] == ' ':
            board[i] = player
            move_val = minimax(board, len(board), player == 'O', float('-inf'), float('inf'))
            board[i] = ' '
            if (player == 'X' and move_val > best_val) or (player == 'O' and move_val < best_val):
                best_val = move_val
                best_move = i
    return best_move

# 示例棋盘状态，空格用 ' ' 表示
board = ['X', 'O', 'X', ' ', 'O', ' ', ' ', ' ', ' ']

# 找到最佳移动
best_move = find_best_move(board, 'X' if board.count('X') <= board.count('O') else 'O')
print("最佳移动位置:", best_move)
