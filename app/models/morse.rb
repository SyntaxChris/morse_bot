require 'rest-client'

class Morse
  def convert_message message
    message.upcase.chars.each do |letter|
      send_letter(letter)
    end
  end

  def send_letter(letter)
    LTR_TO_MORSE[letter.to_sym].each{|beep| beep.call }
  end

  def self.request(base_url, mode="digital", pin="8", state)
    RestClient.get("#{base_url}/#{mode}/#{pin}/#{state}")
  end

  short = lambda {
    request("http://arduino.local/", "digital", "8", "1")
    sleep(250)
    request("http://arduino.local/", "digital", "8", "0")
    sleep(250)
  }

  long = lambda {
    request("http://arduino.local/", "digital", "8", "1")
    sleep(500)
    request("http://arduino.local/", "digital", "8", "0")
    sleep(250)
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
    Z: [long, long, short, short],
    1: [short, long, long, long, long],
    2: [short, short, long, long, long],
    3: [short, short, short, long, long],
    4: [short, short, short, short, long],
    5: [short, short, short, short, short],
    6: [long, short, short, short, short],
    7: [long, long, short, short, short],
    8: [long, long, long, short, short],
    9: [long, long, long, long, short],
    0: [long, long, long, long, long]
  }
end

test_morse = Morse.new
test_morse.convert_message("b")
