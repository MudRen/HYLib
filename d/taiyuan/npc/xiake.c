inherit NPC;
void create()
{
   set_name("����",({ "xia ke","xia","ke" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����׼��Ͷ�����һ�����͡�\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
