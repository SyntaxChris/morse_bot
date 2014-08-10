$(document).on('page:change', function(){
  var decrypt_button  = $('#decrypt-message'),
      message_content = $('#message-content').text(),
      navIn = $('#nav-inbox'),
      navSent = $('#nav-sent'),
      navTrash = $('#nav-trash'),
      inbox = $('#inbox'),
      sent = $('#sent'),
      trash = $('#trash');

  decrypt_button.on("click", function(ev){
    ev.preventDefault();
    $.getJSON('/decrypt', { message: message_content });
  });

  navIn.on("click", function(ev){
    ev.preventDefault();
    inbox.toggle("slow");
  });

  navSent.on("click", function(ev){
    ev.preventDefault();
    sent.toggle("slow");
  });

  navTrash.on("click", function(ev){
    ev.preventDefault();
    trash.toggle("slow");
  });

});
