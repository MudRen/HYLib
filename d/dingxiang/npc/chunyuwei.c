
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("����ޱ",({ "chun yuwei","chun","yuwei" }) );
   set("gender", "Ů��" );		
   set("age",22);
   set("per",24);
   set("long", "�����Ǳ�����ͽ�ܡ�\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("literate",150);
  

  
   set("max_jing",2000);
   set("max_qi",2000);
   set("max_sen",2000);
   set("neili",2000);
   set("max_neili",2000);
   create_family("ͻ��",5,"��ʿ");
   set("inquiry",([
     "����":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}
