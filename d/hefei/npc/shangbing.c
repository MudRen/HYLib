
inherit NPC;

void create()
{
   set_name("�˱�",({ "shang bing","shang","bing" }) );
   set("gender", "����" );
   set("age",30);

   set("long", "����һ���˱�����׼��ȥ������\n");
       
   set("combat_exp", 200000);
   set("str",25);
   set("per",15);
   
   set("eff_jing",1500);
   set("eff_qi",1000);
   set("max_qi",1500);
   set("eff_jing",1500);
   set("max_force",1000);
   set("force",1000);
   
   set_skill("blade",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   
   
   
   setup();
   
   set("eff_qi",1500);
   carry_object(__DIR__"obj/blade")->wield();

}

