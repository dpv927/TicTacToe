mod constants;
mod board;
mod search;

fn main() {
    let mut arr: Vec<i32> = Vec::new();
    arr.push(0);    arr.push(0);    arr.push(0);
    arr.push(0);    arr.push(0);    arr.push(0);
    arr.push(0);    arr.push(0);    arr.push(0);

    search::set_search_rules(constants::PLAYER_1, constants::PLAYER_2, 9);
    print!("{}", search::search_minimax(&mut arr));
}