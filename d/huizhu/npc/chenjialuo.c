#include <ansi.h>
inherit NPC;
void create()
{
   set_name("�¼���",({"chen jialuo"}));
   set("gender","����");
	set("title", HIR "��ػ�"HIM"�ܶ���"NOR );
     set("long", 
		"\n����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");

   set("score",120000);
	set("combat_exp",2000000);
   
set("per",25);
set("age",25);
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 200);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 200);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 200);
	set_skill("yunlong-bian", 200);
	set_skill("yunlong-shou", 200);
	set_skill("yunlong-zhua", 200);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("������",1, "��ɽ��ʦ");

   setup();
   add_money("silver",50);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/sword")->wield();
}
