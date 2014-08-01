class RenameFullNameColumnToUsername < ActiveRecord::Migration
  def change
    rename_column :users, :full_name, :username
  end
end
