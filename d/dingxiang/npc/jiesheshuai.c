
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("������",({ "jie sheshuai","jie","sheshuai" }) );
   set("gender", "����" );		
   set("age",38);
   set("long", "������ͻ��֮�ܽ����ʣ�������ս����ͻ���ĵ���������\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("club",150);
   set_skill("literate",150);
  

  
   set("max_jing",2000);
   set("max_qi",2000);
   set("max_sen",2000);
   set("neili",2000);
   set("max_neili",2000);
   create_family("ͻ��",5,"��ʿ");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/spear")->wield();
  
}
