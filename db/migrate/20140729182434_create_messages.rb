class CreateMessages < ActiveRecord::Migration
  def change
    create_table :messages do |t|
      t.string :title
      t.text :content
      t.boolean :urgent, default: false
      t.boolean :read, default: false

      t.timestamps
    end
  end
end
