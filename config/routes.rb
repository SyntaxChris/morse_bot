Rails.application.routes.draw do

  devise_for :users

  root 'conversations#index'

  resources :conversations, only: [:index, :show, :new, :create] do
    member do
      post :reply
      post :trash
      post :untrash
    end
  end

  get '/decrypt' => 'conversations#arduino'

end
