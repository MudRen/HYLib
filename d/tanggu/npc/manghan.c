
inherit NPC;
#include <ansi.h>


void create()
{
	set_name("ç��", ({ "mang han", "han"}));
	set("long", HIY"�����Ҳ��ʮ�ֿ��ֻ࣬��������Щ���͡��ƺ�������Ѱ��ʲô��\n"NOR);
	set("long_base", HIY"�����Ҳ��ʮ�ֿ��ֻ࣬��������Щ���͡��ƺ�������Ѱ��ʲô��\n"NOR);
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 5500);
	set("max_jing", 5500);
	set("eff_jingli",5400);
	set("neili", 5100);
	set("max_neili", 5100);
	set("jiali", 20);
	set("combat_exp", 58000+random(500));

	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("unarmed", 170);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set("chat_chance", 3);
	set("chat_msg", ({
		"ç����ͷ���Եؿ��˿���Χû�ˣ������Դ����������غߺ��ţ�·�ߵ�Ұ�����㲻Ҫ�ɰ�...���ɰײ���ѽ��\n",
			"ç�������մ���ɵЦ�ţ�������Ҫ����������\n",
			"ç�������촽���������촽��\n",
		"ç�����˿����˵��촽�����˿���Һ��\n",
		"ç��ҡҡͷ��̾�������������ˣ�������...��\n",
	}));
	set("inquiry", ([
		"��������" : "����С椶࿡�Σ�Ҫ���������ֲ��ɣ�Ҳ����ȥ���ԡ���\n",
		"����" : "����С椶࿡�Σ�Ҫ���������ֲ��ɣ�Ҳ����ȥ���ԡ���\n",
	]));
	setup();
	//carry_object("/clone/armor/caoxie")->wear();
	carry_object("/clone/misc/cloth")->wear();
}
