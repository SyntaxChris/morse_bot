class Message < ActiveRecord::Base
  has_many :message_recipients
  has_many :recipient, through: :message_recipients

  belongs_to :user
end
