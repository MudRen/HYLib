
inherit NPC;
void create()
{
   
   set_name("Ѿ��",({ "yahuan"}) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "����һ��СѾ�ߡ�\n");
   set("combat_exp", 2000);
   set("str", 10);
   set("per", 23);
     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
