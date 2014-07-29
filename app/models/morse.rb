require 'rest-client'

class Morse

  def initialize(title)
    @title = title
  end

  short = lambda {
    request("http://arduino.local/", "digital", "8", "1")
    sleep(0.25)
    request("http://arduino.local/", "digital", "8", "0")
  }

  long = lambda {
    request("http://arduino.local/", "digital", "8", "1")
    sleep(0.5)
    request("http://arduino.local/", "digital", "8", "0")
  }

  LTR_TO_MORSE = {
    A: [short, long],
    B: [long, short, short, short],
    C: [long, short, long, short],
    D: [long, short, short],
    E: [short],
    F: [short, short, long, short],
    G: [long, long, short],
    H: [short, short, short, short],
    I: [short, short],
    J: [short, long, long, long],
    K: [long, short, long],
    L: [short, long, short, short],
    M: [long, long],
    N: [long, short],
    O: [long, long, long],
    P: [short, long, long, short],
    Q: [long, long, short, long],
    R: [short, long, short],
    S: [short, short, short],
    T: [long],
    U: [short, short, long],
    V: [short, short,short, long],
    W: [short, long, long],
    X: [long, short, short, long],
    Y: [long, short, long, long],
    Z: [long, long, short, short]
  }

  def send_letter(letter)
    LTR_TO_MORSE[letter].each{|beep| beep.call }
  end

  def request(base_url, mode= "digital", pin= "8", state)
    RestClient.get("#{base_url}/#{mode}/#{pin}/#{state}")
  end

end

test_morse = Morse.new
