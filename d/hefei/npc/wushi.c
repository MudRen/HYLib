
inherit NPC;

void create()
{
   set_name("��ʿ",({ "wu shi","wu","shi" }) );
   set("gender", "����" );
   set("age",25);

   set("long", "����һ����ʿ��\n");
       
   set("combat_exp", 100000);
   set("str",25);
   set("per",15);
   
   set("eff_jing",1000);
   set("eff_qi",1000);
   set("eff_jing",1000);
   set("max_force",1000);
   set("force",1000);
   
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);

   
   
   setup();
   
   carry_object(__DIR__"obj/blade")->wield();

}

