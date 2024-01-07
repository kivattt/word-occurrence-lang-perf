fn main() {
    let args = std::env::args().skip(1).collect::<Vec<String>>();
    println!("\x1b[36m{}\x1b[0m", word_in_file(&args[0], &args[1]).unwrap().unwrap());
}

fn word_in_file(word: &str, filename: &str) -> std::io::Result<Option<usize>> {
    let file_contents = std::fs::read_to_string(filename)?;

    let mut word_count: usize = 0;

    for line in file_contents.lines() {
        for text in line.split_whitespace() {
            if word == text { word_count += 1 }
        }
    }
     
    match word_count {
        0 => Ok(None),
        _ => Ok(Some(word_count))
    }
}
