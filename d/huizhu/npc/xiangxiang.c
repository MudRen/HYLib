inherit NPC;
void create()
{
   set_name("���㹫��",({"gong zhu"}));
   set("gender","Ů��");
   set("long","ľ׿�׵�СŮ��,������������!\n");
   set("score",2000);
   set("combat_exp",40000);
   set("area_name","������Ⱥ");
   
set("per",35);
set("age",17);
   set("qi",900);
   set("max_qi",900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",10);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("whip",80);

   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/whip")->wield();
}
