
inherit NPC;

void create()
{
   set_name("Ů��",({ "girl"}) );
        set("gender", "Ů��" );
        set("age", 18);
   set("long", "����һ�����������С���\n");
   set("combat_exp", 1000);
   set("str", 10);
   set("per", 24);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

