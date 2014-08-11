$(document).on('page:change', function(){
  var decrypt_button  = $('#decrypt-message'),
      message_content = $('#message-content').text(),
      navNew = $('#nav-new.text-center'),
      navIn = $('#nav-inbox.text-center'),
      navSent = $('#nav-sent.text-center'),
      navTrash = $('#nav-trash.text-center'),
      newMessage = $('#new_message'),
      inbox = $('#inbox'),
      sent = $('#sent'),
      trash = $('#trash');

  decrypt_button.on("click", function(ev){
    ev.preventDefault();
    $.getJSON('/decrypt', { message: message_content });
  });

  navNew.on("click", function(ev){
    ev.preventDefault();
    newMessage.toggle("slow");
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
