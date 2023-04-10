use crate::{board, constants};
use std::cmp;

/* Variables to define which player is used to maximize or minimize
* at the search functions. */
static mut PLAYER_TO_MAXIMIZE: i32 = 2;
static mut PLAYER_TO_MINIMIZE: i32 = 1;
static mut SELECTED_DEPTH: i32 = constants::DEF_DEPTH;

pub fn set_search_rules(p_max: i32, p_min: i32, s_depth: i32) {
    unsafe { PLAYER_TO_MAXIMIZE = p_max };
    unsafe { PLAYER_TO_MINIMIZE = p_min };
    unsafe { SELECTED_DEPTH = s_depth };
}

pub fn search_minimax(arr: &mut Vec<i32>) -> i32 {
    let mut best_score: i32 = 0;
    let mut s_move: i32 = 0;
    let mut score: i32;

    for i in 0..constants::BOARD_LEN {
        if arr[i] != constants::PLAYER_N {
            arr[i] = unsafe { PLAYER_TO_MAXIMIZE };
            score = minimax(arr, false, unsafe { SELECTED_DEPTH });
            arr[i] = constants::PLAYER_N;

            if score > best_score {
                best_score = score;
                s_move = i as i32;
            }
        }
    }
    return s_move;
}

fn minimax(arr: &mut Vec<i32>, is_maximizing: bool, depth: i32) -> i32 {

    let mut score: i32 = 0;
    let mut best_score: i32 = 0;

    score = board::evaluate_game(&arr, unsafe { PLAYER_TO_MAXIMIZE });
    if (score != constants::COND_KEEP) || (depth == 0) {
        return score;
    }

    if is_maximizing {
        best_score = i32::MIN;

        for i in 0..constants::BOARD_LEN {
            if arr[i] == constants::PLAYER_N {
                arr[i] = unsafe { PLAYER_TO_MAXIMIZE };
                score = minimax(arr, false, depth-1);
                arr[i] = constants::PLAYER_N;
                best_score = cmp::max(score, best_score);
            }
        }
    }
    else {
        best_score = i32::MAX;

        for i in 0..constants::BOARD_LEN {
            if arr[i] == constants::PLAYER_N {
                arr[i] = unsafe { PLAYER_TO_MINIMIZE };
                score = minimax(arr, true, depth-1);
                arr[i] = constants::PLAYER_N;
                best_score = cmp::min(score, best_score);
            }
        }
    }
    return best_score;
}