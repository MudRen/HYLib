
inherit NPC;
void create()
{
   
   set_name("С��",({ "xiao fan","xiao","fan"}) );
        set("gender", "����" );
        set("age",25);
   set("long", "����һ���ִ߽����С����\n");
   set("combat_exp",5000);
   set("str",25);
   set("chat_chance",60);
   set("chat_msg",({
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
