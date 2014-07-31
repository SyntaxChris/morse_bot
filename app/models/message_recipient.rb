class MessageRecipient < ActiveRecord::Base
  belongs_to :recipient
  belongs_to :message
  belongs_to :user
end