
inherit NPC;

void create()
{
   set_name("����",({ "man" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ����ס���ϲ����������ӡ�\n");
       
   set("combat_exp", 50000);
   set("str", 25);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

