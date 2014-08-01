$(document).on('page:change', function(){
  var decrypt_button  = $('#decrypt-message'),
      message_content = $('#message-content').text(),
      message_send_to = $('#message_send_to');

  decrypt_button.click(function(ev){
    ev.preventDefault();
    $.getJSON('/decrypt', {message: message_content});
  });

  message_send_to.on('keyup', function(ev){
    ev.preventDefault();
    current_value = $(this).val();
    // console.log(current_value);

    if(current_value.length > 0 && current_value.length < 10) {

      $.getJSON('/find-username').success(function(){

      });

    }
  });
});