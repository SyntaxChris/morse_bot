class CreateJoinTable < ActiveRecord::Migration
  def change
    create_table :message_recipients do |t|
      t.integer :user_id
      t.integer :recipient_id
      t.integer :message_id

      t.timestamps
    end
  end
end
