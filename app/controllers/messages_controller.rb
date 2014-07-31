class MessagesController < ApplicationController
  def index
    @messages = Message.all
  end

  def show
    @message = Message.find(params[:id])
  end

  def new
    @message = Message.new
  end

  def create
    message = Message.create(message_params)

    if message.save
      redirect_to messages_path
    else
      redirect_to new_message_path
    end
  end

  def destroy
    Message.destroy(params[:id])
    redirect_to messages_path
  end

private
  def message_params
    params.require(:message).permit(:title, :content, :urgent)
  end
end
