inherit NPC;
void create()
{
   set_name("�ܱ�",({"zhe bie"}));
   set("gender","����");
   set("long","��ľ�������ͽ�֮һ,�ǹ����ļ���ʦ��!\n");
   set("shen",25000);
   set("combat_exp",160000);
   set("title","�����");
   
set("age",35);
   set("kee",2000);
   set("max_kee",2000);
set("food",250);
set("water",250);
   set("neili",1500);
   set("max_neili",1500);
   set("force_factor",60);

   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("parry",160);
   set_skill("unarmed",160);
	set_skill("club", 140);
	set_skill("zhongping-qiang", 140);
	map_skill("club", "zhongping-qiang");


   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tieqiang")->wield();
}
