#include <ansi.h>

inherit NPC;

void create()
{
   set_name("�����",({ "li caizhu","li","caizhu" }) );
        set("gender", "����" );
        set("age", 52);
   set("long", "�����ϲ��Ĵ������������������ΪŮ���ٰ�������ס�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");

   set("chat_chance",80);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

