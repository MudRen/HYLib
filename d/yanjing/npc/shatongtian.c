inherit NPC;
void create()
{
   set_name("ɳͨ��",({"sha tongtian"}));
   set("gender","����");
   set("mingwang",-19000);
   set("combat_exp",153000);
   set("title","��������");
   set("long","�͹���ͺͷ������û���ͷ����˫Ŀ������˿����ͻ��.\n");

   set("age",54);
   set("qi",880);
   set("max_qi",880);
   set("food",250);
   set("water",250);
   set("neili",880);
   set("max_neili",880);
   set("force_factor",80);

   set_skill("dodge",80);
   set_skill("force",57);
   set_skill("parry",130);
   set_skill("unarmed",57);
   set_skill("club",37);
   set_skill("blade",78);
 
   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
}
