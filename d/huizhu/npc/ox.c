inherit NPC;

void create()
{
   set_name("��ţ", ({ "mao niu","niu" }) );
   set("race", "Ұ��");
   set("age", 12);
   set("long", "һͷ��ŭ�Ĺ�ţ,��������΢΢���Ž�⡣\n");
   
   set("str", 25);
   set("cor", 24);
   set("combat_exp",15000);
   set("kee",400);
   set("max_kee",400);

   set("limbs", ({ "ͷ��", "����", "β��", "ǰ��","����" "ţ��"}) );
   set("verbs", ({ "bite", "claw" }) );

   set_temp("apply/attack", 15);
   set_temp("apply/armor", 25);
   
   set("chat_chance",5);
   set("chat_msg",({
     "��ţ���������۾�,��ϸ�о�����.\n",
     "��ţ��������������,��ȴû����һ������.\n",
     }));

   setup();
}

void die()
{
      object corpse;
         if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
  message_vision("$Nŭ��һ��,һͷײ��ɽ��,������.\n",this_object());
  new(__DIR__"obj/niujiao.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}