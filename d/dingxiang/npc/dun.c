
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("������",({ "dun yugu","dun" }) );
   set("gender", "����" );
   set("age", 42);
   
   set("long", "�����Ǳ����ĵܵܣ����ͻ�ʴ󺹵����Σ�\n");
       
   set("combat_exp",1000000);
 
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("whip",200);
   set_skill("literate",200);
  

   set("max_jing",3000);
   set("max_qi",3000);
   set("max_sen",3000);
   set("neili",3000);
   set("max_neili",3000);
   create_family("ͻ��",3,"��ʿ");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}
