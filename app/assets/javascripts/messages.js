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

      // $('ul#user-results').html('');
      $.getJSON('/find-username', {query: current_value}).success(function(response){
        // console.log(response);

        $.each(response, function(index, user){
          // $('ul#user-results').html('<li>'+user.email+'</li>');

          $('ul#user-results').html('<li>'+user.email+'</li>').prototype.getUnique = function(){
            var u = {}, a= [];
            for(var i = 0, l = this.length; i < l; ++i){
              if(u.hasOwnProperty(this[i])){
                continue;
              }
              a.push(this[i]);
              u[this[i]] = 1;
            }
            return a;
          }
        });

      });

    }
  });

});
