class User < ActiveRecord::Base
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable,
         :authentication_keys => [:username]

  has_many :message_recipients
  has_many :messages
  has_many :messages, through: :message_recipients



  attr_accessor :login
  # what this does:

  # def login=(login)
  #   @login = login
  # end
  #
  # def login
  #   @login || self.username || self.email
  # end

  # def self.find_user query
  #   self.where("email LIKE ?", "%#{query}%")
  # end

  def self.find_first_by_auth_conditions(warden_conditions)
    conditions = warden_conditions.dup
    if login = conditions.delete(:login)
      where(conditions).where(["lower(username) = :value OR lower(email) = :value", { :value => login.downcase }]).first
    else
      where(conditions).first
    end
  end
end
