
inherit NPC;
void create()
{
   
   set_name("�����",({ "li dianzhu","li","dianzhu"}) );
        set("gender", "����" );
        set("age",40);
   set("long", "����̫ԭ������ĵ�����\n");
   set("combat_exp", 200000);
   set("str", 30);     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
