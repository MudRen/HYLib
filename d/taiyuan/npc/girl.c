inherit NPC;
void create()
{
   set_name("��Ů",({ "girl"}) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "��������̫ԭ��һλ��Ů��\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",10);
   set_temp("apply/dodge",10);
   set_temp("apply/armor",10);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
