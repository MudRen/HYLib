
inherit NPC;
void create()
{
   
   set_name("��������",({ "gu niang","gu","niang","girl" }) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "���ǻ�����������\n");
   set("combat_exp", 2000);
   set("str", 10);
   set("per", 23);
     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
