class MessagesController < ApplicationController
  before_action :authenticate_user!
  # before_action :correct_user, except: [:index, :new, :create ]

  def index
    @messages = Message.all.where("user_id = #{current_user.id}")
  end

  def show
    @message = Message.find(params[:id])

    if @message
      @message.read = true
      @message.save
    end
  end

  def new
    @message = current_user.messages.build
  end

  def create
    @message = Message.create(message_params)
    @message.user_id = current_user.id
    @message.save

    redirect_to @message.save ? messages_path : new_message_path
  end

  def destroy
    Message.destroy(params[:id])
    redirect_to messages_path
  end

private
  def message_params
    params.require(:message).permit(:title, :content, :urgent)
  end

  def correct_user
    @message = current_user.messages.find(params[:id]) if user_signed_in?
    redirect_to messages_path if @message.nil?
  end
end
