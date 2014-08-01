class User < ActiveRecord::Base
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable

  has_many :message_recipients
  has_many :messages
  has_many :messages, through: :message_recipients

  def self.find_user query
    self.where("email LIKE ?", "%#{query}%")
  end

end
