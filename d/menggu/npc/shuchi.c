inherit NPC;
void create()
{
   set_name("����",({"shu chi"}));
   set("gender","����");
   set("long","��ľ��Ĵ����,����������,������թ!\n");
   set("shen",-20000);
   set("combat_exp",70000);
   
set("age",39);
set("kee",1200);
   set("max_kee",1200);
set("food",250);
set("water",250);
   set("neili",900);
   set("max_neili",900);
   set("force_factor",50);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
	set_skill("club", 80);
	set_skill("zhongping-qiang", 40);
	map_skill("club", "zhongping-qiang");

   set("chat_chance",5);
   set("chat_msg",({
"����ٺ���Ц����:���̨�Ǹ�����,��[��]��λ�ó������ҵ�.\n",
"����������ϵĽ���,��Ѫɫ�����Ѿ�һ������.\n",
}));

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/tiejia")->wear();
carry_object(__DIR__"obj/jinqiang")->wield();
}
//void init()
