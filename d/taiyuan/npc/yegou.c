inherit NPC;
void create()
{
   set_name("Ұ��",({ "dog","gou"}) );
   set("race","Ұ��");
  set("long", "����һֻҰ��������������ˡ�\n");
   set("combat_exp", 20000);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"Ұ��������е�����������\n",
   	(:random_move:),
}));
   set("verbs",({"bite"}));
   set("limbs",({"ͷ","��","����","β��"}));
   setup();
  
}
