require 'rest-client'

class Morse
  short = lambda {
    url = 'http://'
  }
  long = lambda {
    url = 'http://'
  }

  LTR_TO_MORSE = {
    A: [short, long],
    S: [short, short, short]
  }

  def send_letter(letter)
    LTR_TO_MORSE[letter].each{|beep| beep.call }
  end
end