
inherit NPC;
void create()
{
   
   set_name("Ů����",({ "nv dianzhu","dianzhu" }) );
        set("gender", "Ů��" );
        set("age",38);
   set("long", "���ǻ��۵��Ů������\n");
   set("combat_exp", 5000);
   set("str", 10);
     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
