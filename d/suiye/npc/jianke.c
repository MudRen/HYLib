
inherit NPC;

void create()
{
   set_name("����",({ "jianke" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������������Ҷ��һ�����͡�\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set_skill("sword",100);
  
   set_skill("dodge",100);

   set_skill("force",100);
   
   set("max_gin",800);
   set("max_kee",800);
   set("max_sen",800);
   set("max_force",1000);
   set("force",1000);
    setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

