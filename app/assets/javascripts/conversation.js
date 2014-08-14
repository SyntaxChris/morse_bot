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

$(function() {
  $(".conversations").each(function(){
    $(this).click(function(e) {
      e.preventDefault();

      if($(this).parents().eq(2).attr("id") === "inbox-container"){

        $.get(document.location.origin + $(this).attr("href"), function(html) {
          $("#show_inbox_convo").append(html);
        });

      }

      if($(this).parents().eq(2).attr("id") === "sent-container"){
        $.get(document.location.origin + $(this).attr("href"), function(html) {
          $("#show_sent_convo").append(html);
        });
      }

      if($(this).parents().eq(2).attr("id") === "trash-container"){
        $.get(document.location.origin + $(this).attr("href"), function(html) {
          $("#show_trash_convo").append(html);
        });
      }

    });
  });
});
