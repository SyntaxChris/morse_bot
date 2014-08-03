class RemoveUserNameFromTableUsers < ActiveRecord::Migration
  def change
    remove_column :users, :username, :string
  end
end
