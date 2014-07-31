Rails.application.routes.draw do
  
  devise_for :users
  root 'messages#index'
  get '/decrypt' => 'messages#arduino'
  resources :messages

end
