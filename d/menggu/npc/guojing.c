inherit NPC;
void create()
{
   set_name("����",({"guo jing"}));
   set("gender","����");
   set("long","�����������ɹ�,�潭������ѧ��!\n");
   set("shen",50000);
   set("combat_exp",100000);
   
set("age",17);
   set("kee",900);
   set("max_kee",900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
	set_skill("club", 40);
	set_skill("zhongping-qiang", 40);
   set_skill("whip",80);
   set_skill("sword",80);
   set_skill("blade",80);

   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/jindao")->wield();
}
