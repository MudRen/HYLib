
inherit NPC;

void create()
{
   set_name("Ϸ��",({ "xi you","xi","you" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����һλ������Ϸ��Ϸ�ԡ�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

