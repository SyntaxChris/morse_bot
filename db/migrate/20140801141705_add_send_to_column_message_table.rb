class AddSendToColumnMessageTable < ActiveRecord::Migration
  def change
    add_column :messages, :send_to, :string
  end
end
