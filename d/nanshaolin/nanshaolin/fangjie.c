// Last Modified by winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/fangjie.c

inherit NPC;
inherit F_MASTER;
mixed carry_water();

void create()
{
	set_name("����", ({ "fang jie", "fang", "jie"}));
	set("long",
		"����һλ�����ӵ�������У���һϮ�಼������ġ�����Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("leg", 50);
	set_skill("zui-gun", 50);
	set_skill("staff", 50);
	set_skill("pudu-zhang", 50);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "hunyuan-yiqi");
	map_skill("leg", "zui-gun");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");
	prepare_skill("cuff", "hunyuan-yiqi");
	prepare_skill("leg", "zui-gun");

	set("inquiry", ([
		"��ˮ":	(: carry_water :)
	]));
	create_family("��������", 21, "����");
	setup();

	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"chanzhang")->wield();
}

mixed carry_water()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query("carry_count"))
		if (present("liao kao", me))
		{
			destruct(present("liao kao", me));
			return "��Ļ��Ѿ������ˣ��Ұ���⿪����";
		}
		else
			return RANK_D->query_respect(me) + "���ǿ���Ц�ɣ�";
	if (present("tie tong", me))
		return "�㲻��������Ͱ�𣿿�ȥ�ɻ�ɡ�";
	if (present("tie tong", environment()))
		return "��Ͱ�����ڵ��Ϸ�������ȥ�ɻ�ɡ�";
	command("buddhi");
	new("/d/nanshaolin/obj/tie-tong")->move(environment());
	command("say ���Ǹɻ�ļ�ʲ����ȥ�ðɡ�");
	message_vision("$N������ó�һ�Դ���Ͱ���ڵ��ϡ�\n", ob);
	return 1;
}

#include "fang.h";
