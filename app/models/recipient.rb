class Recipient < ActiveRecord::Base
  has_many :message_recipients
  has_many :messages, through: :message_recipients
end
