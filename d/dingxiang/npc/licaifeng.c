
inherit NPC;
void create()
{
   
   set_name("��÷�",({ "li caifeng","li","caifeng"}) );
        set("gender", "����" );
        set("age",50);
   set("long", "����һ������Ĳ÷죬��˵���ղ���\n");
   set("combat_exp", 200000);
   set("str", 30);     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
