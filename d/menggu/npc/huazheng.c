inherit NPC;
void create()
{
   set_name("���ݹ���",({"hua zheng"}));
   set("gender","Ů��");
   set("long","��ľ���СŮ��,������δ������!\n");
   set("score",30000);
   set("combat_exp",60000);
   
     set("per",30);
     set("age",16);
   set("kee",900);
   set("max_kee",900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",10);

   set_skill("dodge",50);
   set_skill("force",50);
   set_skill("parry",50);
   set_skill("unarmed",50);
   set_skill("whip",50);

   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/whip")->wield();
}
