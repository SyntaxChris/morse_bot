Rails.application.routes.draw do

  root 'conversations#index'

  devise_for :users
  resources :conversations, only: [:index, :show, :new, :create] do
    member do
      post :reply
      post :trash
      post :untrash
    end
  end
end
