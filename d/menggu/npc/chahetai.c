inherit NPC;
void create()
{
   set_name("���̨",({"cha hetai"}));
   set("gender","����");
   set("long","��ľ��Ķ�����,���Դ�³,�������¶���촽��!\n");
   set("shen",-15000);
   set("combat_exp",100000);
   
     set("per",14);
   set("age",34);
   set("kee",1000);
   set("max_kee",1000);
   set("food",250);
   set("water",250);
   set("force",800);
   set("max_force",800);
   set("force_factor",40);
   
   set("chat_chance",5);
   set("chat_msg",({
  "���ܿ���˳��������С�ӣ��ϸ������ԡ�\n",
  "������ɵС�Ӿ�Ȼ������ϲ������������Ҫ����ɱ��.\n",
  }));

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
	set_skill("club", 40);
	set_skill("zhongping-qiang", 40);
	map_skill("club", "zhongping-qiang");


   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/yinqiang")->wield();
}
