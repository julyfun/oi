trait MaxEle {
    type Iter;
    fn max_ele(mut self) -> Self::Iter;
}

impl<I> MaxEle for I
where
    I: Iterator + Clone,
    I::Item: PartialOrd,
{
    type Iter = Self;
    fn max_ele(mut self) -> Self::Iter {
        let mut max_iter = self.clone();
        let mut max_val = None;
        while let Some(val) = self.next() {
            if max_val.as_ref().map_or(true, |max| &val > max) {
                max_val = Some(val);
                max_iter = self.clone();
            }
        }

        max_iter
    }
}

fn main() {
    let s = String::from("hello");
    let v = vec![1, 2, 3];
    println!("{}", v.max_ele().next().unwrap());
}
