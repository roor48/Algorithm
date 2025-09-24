use std::io::stdin;

fn main() {
    let mut input = String::new();
    
    stdin().read_line(&mut input).expect("");
    let t: i32 = input.trim().parse().expect("");
    
    let mut dp: Vec<usize> =  vec![0; 10001];
    for _ in 0..t {
        dp.fill(0);

        input.clear();
        stdin().read_line(&mut input).expect("");
        let n: usize = input.trim().parse().expect("");
        
        input.clear();
        stdin().read_line(&mut input).expect("");
        let arr: Vec<usize> = input
            .split_whitespace()
            .map(|s| s.parse().expect(""))
            .collect();

        input.clear();
        stdin().read_line(&mut input).expect("");
        let M: usize = input.trim().parse().expect("");
        for i in 0..n {
            dp[arr[i]] += 1;

            for m in arr[i]..=M {
                dp[m] += dp[m-arr[i]];
            }
        }

        println!("{}", dp[M]);
    }
}
