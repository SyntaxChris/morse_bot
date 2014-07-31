// $(document).ready(function(){});
$(document).on('page:change', function(){
  var decrypt_button  = $('#decrypt-message'),
      message_content = $('#message-content').text();

  decrypt_button.click(function(ev){
    ev.preventDefault();

    $.getJSON('/decrypt', {message: message_content}).success(function(response){
      console.log("It's working");
    });
  });
});
