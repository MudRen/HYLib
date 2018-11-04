// Last Modified by Winder on May. 29 2601
// Npc: /kungfu/class/nanshaolin/tianjing.c

#include "tian.h";
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_yes();
string ask_me();
string ask_murenxiang();

void create()
{
	set_name("�쾵��ʦ", ({ "tianjing dashi", "tianjing", "dashi"}));
	set("long",
		"����һλ�������ɮ����һϮ��˿������ġ�����Ĳ��ߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 120);
	set("max_qi", 30000);
	set("max_jing", 12600);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali",260);
	set("combat_exp", 2600000);
	set("score", 10000);
set_skill("ruying-leg", 360);
		set_skill("zhanzhuang-gong", 360);
	set_skill("shaolin-cuff", 360);
	set_skill("shaolin-leg", 360);
	set_skill("yiwei-dujiang", 360);
	set_skill("boluomi-hand", 360);
	set_skill("jingang-strike", 360);
	set_skill("wuxiang-finger", 360);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 260);
	set_skill("yijinjing", 260);
	set_skill("force", 260);
	set_skill("yijinjing", 260);
	set_skill("dodge", 260);
	set_skill("shaolin-shenfa", 300);
	set_skill("cuff", 260);
	set_skill("hunyuan-yiqi", 300);
	set_skill("luohan-quan", 300);
	set_skill("jingang-quan", 300);
	set_skill("leg", 260);
	set_skill("zui-gun", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("hand", 260);
	set_skill("fengyun-shou", 300);
	set_skill("ranmu-daofa", 300);
	set_skill("qianye-shou", 300);
	set_skill("strike", 260);
	set_skill("sanhua-zhang", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("weituo-gun", 300);
	set_skill("banruo-zhang", 300);
	set_skill("finger", 260);
	set_skill("yizhi-chan", 300);
	set_skill("yizhi-chan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("yizhi-chan", 300);
	set_skill("claw", 260);
	set_skill("qianye-shou", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("longzhua-gong", 300);
	set_skill("staff", 260);
	set_skill("pudu-zhang", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("blade", 260);
	set_skill("cibei-dao", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("club", 260);
	set_skill("weituo-chu", 300);
	set_skill("zui-gun", 300);
	set_skill("sword", 260);
	set_skill("damo-jian", 300);
	set_skill("wuying-jian", 300);
	set_skill("whip", 260);
	set_skill("riyue-bian", 300);
	set_skill("riyue-bian", 300);
	set_skill("riyue-bian", 300);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("leg", "nianhua-zhi");
	map_skill("hand", "ranmu-daofa");
	map_skill("strike", "banruo-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("staff", "wuchang-zhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");
	map_skill("parry", "wuxiang-finger");
  map_skill("parry","wuxiang-finger");
  map_skill("unarmed","wuxiang-finger");
  map_skill("finger","wuxiang-finger");
  map_skill("hand","boluomi-hand");
  map_skill("strike","jingang-strike");
	//prepare_skill("finger", "wuxiang-finger");
	prepare_skill("hand", "boluomi-hand");
	prepare_skill("strike", "jingang-strike");

	
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry",([
		"ľ����" : (: ask_murenxiang :),
	]));
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);

	create_family("��������", 18, "��ĦԺ����");
	setup();
	//carry_object(__DIR__"changbian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yes", "yes");
	add_action("do_nod", "nod");
}

string ask_murenxiang()
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query("muren_winner") && !wizardp(me)) 
		return RANK_D->query_respect(me) + "�����Ѿ�����ľ������ô���ɲ�Ҫ�����Ŀ������Ц��";
	if (me->query("combat_exp", 1) < 10000)
		return RANK_D->query_respect(me) + "�Ĺ������������ǲ�Ҫ��ľ����Ϊ�ã�";
//	if (me->query("score") < 10000)
//	        return RANK_D->query_respect(me) + "�������������ǲ�Ҫ��ľ����Ϊ�ã�"; 
	command("look " + this_player()->query("id"));
	command("nod");
	me->set_temp("ask_muren", 1);
	say(HIC"�쾵��ʦ����˵����ľ��������������Ϊ���յ�ȥ��֮һ�����б鲼�ֳ�������ľ�ˣ�\n������ֻ����ǰ�ߣ����޷���֮·������һ����Ҫͣ��̫��ʱ�䡣\n"NOR);
	return "��������Ѷ����͸�����(yes)��\n";
}

int do_yes()
{
	object me = this_player();

	if( !me->query_temp("ask_muren") ) return 0;
	message_vision("$nת������ƿ����ķ��񣬺���¶��һ��С�ţ�\n\n$n�������$N��һ�ƣ���$N�ƽ����ڣ�\n\n$nѸ�ٽ������ƻ�ԭλ��\n\n", me, this_object());
	me->move("/d/nanshaolin/entrance");
	me->look();
	return 1;
}

