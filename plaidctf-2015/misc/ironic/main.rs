#![feature(collections)]

use std::fs::File;
use std::io::prelude::*;
use std::net::{TcpListener, TcpStream};
use std::thread;

fn strcmp(left: &Vec<u8>, other: &Vec<u8>) -> bool {
  let l;
  if left.len() < other.len() {
    l = left.len();
  } else {
    l = other.len();
  }
  for i in 0..l {
    if left[i] != other[i] {
      return false;
    }
  }
  return true;
}

#[derive(Debug)]
enum Call {
  Lock(Vec<u8>),
  Get(Vec<u8>),
  Write(Vec<u8>),
  List,
} impl Call {
  fn encode(&self) -> [u8; 128] {
    let mut res = [0; 128];
    match *self {
      Call::Lock(ref s) => {
        res[0] = 0;
        for i in 0..s.len() {
          res[i+1] = s[i];
        }            
      }
      Call::Get(ref s) => {
        res[0] = 1;
        for i in 0..s.len() {
          res[i+1] = s[i];
        }            
      }
      Call::Write(ref s) => {
        res[0] = 2;
        for i in 0..s.len() {
          res[i+1] = s[i];
        }            
      }
      Call::List => res[0] = 3,
    }

    res
  }

  fn decode(s: &Vec<u8>) -> Call {
    let mut s = s.clone();
    let t = s.remove(0);
    match t {
      0 => Call::Lock(s),
      1 => Call::Get(s),
      2 => Call::Write(s),
      3 => Call::List,
      _ => panic!(),
    }
  }
}

#[derive(Debug)]
enum Resp {
  Fail,
  LockAcquired,
  File(Vec<u8>),
  PP(Vec<u8>),
} impl Resp {
  fn encode(&self) -> [u8; 128] {
    let mut res = [0; 128];
    match *self {
      Resp::Fail => {}
      Resp::LockAcquired => res[0] = 1,
      Resp::File(ref s) => {
        res[0] = 2;
        for i in 0..s.len() {
          res[i+1] = s[i];
        }
      }
      Resp::PP(ref s) => {
        res[0] = 3;
        for i in 0..s.len() {
          res[i+1] = s[i];
        }
      }
    }
    res
  }
  
  fn decode(s: &Vec<u8>) -> Resp {
    let mut s = s.clone();
    let t = s.remove(0);
    match t {
      0 => Resp::Fail,
      1 => Resp::LockAcquired,
      2 => Resp::File(s),
      3 => Resp::PP(s),
      _ => panic!(),
    }
  }  
}

fn client(mut stream: TcpStream) {
  let mut keyf = File::open("key").unwrap();
  let mut s = String::new();
  keyf.read_to_string(&mut s).unwrap();

  println!("loaded key: {}", s);
  
  let mut files: Vec<(Vec<u8>, Vec<u8>)> = Vec::new();
  let mut locks: Vec<Vec<u8>> = Vec::new();
  locks.push(Vec::from("key"));
  files.push((Vec::from("key"), String::into(s)));
  
  'top: loop {
    let mut res = vec![0; 128];

    if let Ok(len) = stream.read(&mut res) {
      if len <= 0 {
        return
      }
      match Call::decode(&res) {
        Call::Lock(ref s) => {
          for i in 0..files.len() {
            let (ref f, _) = files[i];
            if strcmp(&f, &s) {
              for j in 0..locks.len() {
                let ref l = locks[j];
                if strcmp(&s, &l) {
                  let _ = stream.write(&Resp::Fail.encode());
                  break 'top;
                }
              }

              if locks.len() >= 5 {
                let _ = locks.remove(0);
              }
              locks.push(s.clone());
            }
          }
          let _ = stream.write(&Resp::LockAcquired.encode());
        }
        Call::Get(s) => {
          for i in 0..locks.len() {
            let ref l = locks[i];
            if strcmp(&s, &l) {
              let _ = stream.write(&Resp::Fail.encode());
              break 'top;
            }
          }
          for i in 0..files.len() {
            let (ref f, ref d) = files[i];
            if strcmp(&f, &s) {
              let _ =
                stream.write(&Resp::File(d.clone()).encode());
              break 'top;
            }
          }
          let _ = stream.write(&Call::Get(s.clone()).encode());
          let _ = stream.read(&mut res).unwrap();
          match Resp::decode(&res) {
            Resp::File(t) => {
              if files.len() >= 15 {
                let _ = files.remove(0);
              }
              files.push((s.clone(), t.clone()));
            }
            _ => {
              let _ = stream.write(&Resp::Fail.encode());
              return;
            }
          }
        }
        Call::Write(ref s) => {
          for i in 0..locks.len() {
            let ref l = locks[i];
            if strcmp(&s, &l) {
              let _ = stream.write(&Resp::Fail.encode());
              break 'top;
            }
          }
          for i in 0..files.len() {
            let (ref f, _) = files[i];
            if strcmp(&f, &s) {
              let _ = stream.write(&Resp::Fail.encode());
              break 'top;
            }
          }
          if files.len() >= 15 {
            let _ = files.remove(0);
          }
          files.push((s.clone(), Vec::new()));
          let _ = stream.write(&Resp::File(s.clone()).encode());
        }
        Call::List => {
          let mut acc = Vec::new();
          for i in 0..files.len() {
            let (ref f, _) = files[i];
            acc.push_all(f);
            acc.push(0);
          }
          let _ = stream.write(&Resp::PP(acc).encode());
        }
      }
    }
  } /* end of loop */
}

fn main() {
  let listener = TcpListener::bind("0.0.0.0:9999").unwrap();

  for stream in listener.incoming() {
    match stream {
      Ok(stream) => {
        thread::spawn(move|| {
          client(stream)
        });
      }
      Err(e) => {
        println!("Error from connector: {:?}", e);
      }
    }
  }
  drop(listener);

}
