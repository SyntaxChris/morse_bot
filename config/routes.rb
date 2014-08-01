Rails.application.routes.draw do
  
  devise_for :users
  root 'messages#index'
  get '/decrypt'       => 'messages#arduino'
  get '/find-username' => 'messages#user_display'
  resources :messages

end
