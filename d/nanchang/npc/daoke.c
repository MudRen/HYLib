
inherit NPC;

void create()
{
   set_name("����",({ "dao ke","ke"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ�����߽����ĵ��͡�\n");
       
   set("combat_exp",100000);
   set("str",30);
   set_skill("blade",100);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/blade")->wield();
  
}

