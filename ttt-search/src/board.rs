use crate::constants;

pub fn board_is_full(arr: &Vec<i32>) -> bool {
    for i in (0..8).step_by(1) {
        if arr[i] != 0 {
            return false;
        }
    }
    return true;
}

pub fn evaluate_game(arr: &Vec<i32>, bias: i32) -> i32 {
    let mut result: i32 = evaluate_in_step(arr, 4, 4, bias);
    if result != constants::PLAYER_N {
        return result;
    }

    result = evaluate_in_step(arr, 4, 2, bias);
    if result != constants::PLAYER_N {
        return result;
    }

    for i in (1..7).step_by(3) {
        result = evaluate_in_step(arr, i, 1, bias);
        if result != constants::PLAYER_N {
            return result;
        }
    }

    for i in (3..5).step_by(1) {
        result = evaluate_in_step(arr, i, 3, bias);
        if result != constants::PLAYER_N {
            return result;
        }
    }
    if board_is_full(arr) {
        return constants::COND_DRAW;
    } else {
        return constants::COND_KEEP;
    }
}

fn evaluate_in_step(arr: &Vec<i32>, start: usize, step: usize, bias: i32) -> i32 {
    let mut pre_owner: i32 = 0;

    for i in (start..start + step).step_by(step) {
        pre_owner = arr[i - step];
        if pre_owner == constants::PLAYER_N || arr[i] != pre_owner {
            return 0;
        }
    }
    if pre_owner == bias {
        return i32::MAX;
    } else {
        return i32::MIN;
    }
}

pub fn print_board(arr: &Vec<i32>) {
    println!("┌───┬───┬───┐");
    
    for i in 0..constants::BOARD_LEN {
        print!("│ {} ", if arr[i] == constants::PLAYER_1 { 'x' } else if arr[i] == constants::PLAYER_2 { 'o' } else { ' ' });

        if i == 2 || i == 5 {
            println!("│\n├───┼───┼───┤");
        }
    }
    println!("│\n└───┴───┴───┘");
}