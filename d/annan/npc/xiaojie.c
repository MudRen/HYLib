
inherit NPC;

void create()
{
   set_name("����С��",({ "xiaojie"}) );
        set("gender", "Ů��" );
        set("age", 18);
   set("long", "���ǰ��ϳ��ڵ�С�㡣\n");
       
   set("combat_exp", 10000);
   set("str", 14);
   set("per", 25);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
}

