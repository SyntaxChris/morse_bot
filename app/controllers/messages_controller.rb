class MessagesController < ApplicationController
  before_action :authenticate_user!
  respond_to :json

  def index
    # @messages = current_user.messages.all
    @messages = Message.all.where("user_id = #{current_user.id}")
  end

  def show
    @message = Message.find(params[:id])

    if @message
      @message.read = true
      @message.save
    end
  end

  def arduino
    message = params[:message].downcase.gsub(" ", "+")
    RestClient.get("arduino.local/morse?params=#{message}")
    render nothing: true, status: 200
  end

  def user_display
    users = User.find_user(params[:query])
    respond_with users
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
    params.require(:message).permit(:send_to, :title, :content, :urgent)
  end

  def correct_user
    @message = current_user.messages.find(params[:id]) if user_signed_in?
    redirect_to messages_path if @message.nil?
  end
end
